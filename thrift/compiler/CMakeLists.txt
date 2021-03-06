# Set the compiler directory
set(COMPILER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Override default install path for `make install` step
set(CMAKE_INSTALL_PREFIX ${THRIFT_HOME})

# build compiler/parse
aux_source_directory(./parse PARSE_FILES)
add_library(parse_lib ${PARSE_FILES})
target_link_libraries(parse_lib ${OPENSSL_LIBRARIES})

# build the base libraries
add_library(
  thrift_base

  common.h
  globals.h
  mutator.h
  platform.h
  validator.h
  visitor.h

  common.cc
  mutator.cc
  platform.cc
  validator.cc
  visitor.cc
)
target_link_libraries(
  thrift_base

  parse_lib
  ${Boost_LIBRARIES}
)
install(TARGETS thrift_base DESTINATION lib)

# build compiler/generate
aux_source_directory(./generate GENERATOR_FILES)
aux_source_directory(./generate/templates MSTCH_TEMPLATES)
add_library(
  generate_lib

  ${GENERATOR_FILES}
  ${MSTCH_TEMPLATES}
)
target_link_libraries(
  generate_lib

  ${Boost_LIBRARIES}
  ${MSTCH_LIBRARIES}
  ${OPENSSL_LIBRARIES}
)
# Force generate_lib linking (compiler will optimize it out otherwise)
if(MSVC)
  set(GENERATE_LINKED generate_lib) #MSVC WHOLEARCHIVE is set after exe
elseif(APPLE)
  set(GENERATE_LINKED -Wl,-force_load generate_lib)
else()
  set(GENERATE_LINKED -Wl,--whole-archive generate_lib -Wl,--no-whole-archive)
endif(MSVC)

set(TEMPLATE_DIRS
  generate/templates/cpp2
  generate/templates/cpp2/common
  generate/templates/cpp2/module_types_cpp
  generate/templates/cpp2/module_types_h
  generate/templates/cpp2/module_types_tcc
  generate/templates/cpp2/service_client_cpp
  generate/templates/cpp2/service_common
  generate/templates/cpp2/service_cpp
  generate/templates/cpp2/service_h
  generate/templates/cpp2/service_tcc
  generate/templates/cpp2/types
)
foreach(dir ${TEMPLATE_DIRS})
  install(DIRECTORY ${dir} DESTINATION include/thrift/lib/thrift
          FILES_MATCHING PATTERN "*.mustache")
endforeach()

# Flex generates functions that have a different naming convention in
# gcc and msvc (i.e. isatty(...) and _isatty(...)). This flag makes flex use
# the right functions for every platform.
if(WIN32)
  set(FLEX_FLAGS COMPILE_FLAGS) #Command type
  set(FLEX_FLAGS_TYPE "--wincompat") #String type
endif(WIN32)
# Compile Flex and Bison files and tie their dependencies
BISON_TARGET(ThriftParser thrifty.yy ${COMPILER_DIR}/thrifty.cc)
FLEX_TARGET(
  ThriftScanner

  thriftl.ll
  ${COMPILER_DIR}/thriftl.cc
  ${FLEX_FLAGS} ${FLEX_FLAGS_TYPE}
)
ADD_FLEX_BISON_DEPENDENCY(ThriftScanner ThriftParser)

# Create the thrift compiler binary
add_executable(
  thrift1

  main.cc
  ${BISON_ThriftParser_OUTPUTS}
  ${FLEX_ThriftScanner_OUTPUTS}
)
target_link_libraries(
  thrift1

  parse_lib
  thrift_base
  ${GENERATE_LINKED}
)
# Force generate_lib linking (compiler will optimize it out otherwise)
if(MSVC)
  set_target_properties(
    thrift1

    PROPERTIES LINK_FLAGS "/WHOLEARCHIVE:generate_lib"
  )
endif(MSVC)
# Add the parser definition for global variables between lex, parse, main
target_compile_definitions(
  thrift1

  PRIVATE -DTHRIFTY_HH="${COMPILER_DIR}/thrifty.hh"
)
install(TARGETS thrift1 DESTINATION bin)

# Add tests
if(enable_tests)
  set(TEST_DIR ${COMPILER_DIR}/test)
  thrift_gtest(gcommon "${TEST_DIR}/generate_common_test.cc" generate_lib)
  thrift_gtest(tprogram "${TEST_DIR}/t_program_test.cc" parse_lib)
  thrift_gtest(ttype "${TEST_DIR}/t_type_test.cc" parse_lib)
  thrift_gtest(visitor "${TEST_DIR}/visitor_test.cc" thrift_base)

  set(PY_ENV_VARS
    THRIFT_COMPILER_TEST_SKIP_PY_GENERATE=True
    THRIFT_COMPILER_BIN=${THRIFT_BINARY}
    THRIFT_FIXTURES_DIR=${COMPILER_DIR}/test/fixtures
    THRIFT_TEMPLATES_DIR=${COMPILER_DIR}/generate/templates)
  add_test(compiler-gen ${PYTHON_EXECUTABLE} ${TEST_DIR}/compiler_test.py)
  set_tests_properties(compiler-gen PROPERTIES ENVIRONMENT "${PY_ENV_VARS}")
endif(enable_tests)
