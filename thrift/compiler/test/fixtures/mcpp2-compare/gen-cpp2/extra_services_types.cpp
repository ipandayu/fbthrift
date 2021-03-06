/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "src/gen-cpp2/extra_services_types.h"
#include "src/gen-cpp2/extra_services_types.tcc"

#include <algorithm>
#include <folly/Indestructible.h>

#include "src/gen-cpp2/extra_services_data.h"

namespace extra { namespace svc {

void containerStruct2::__clear() {
  // clear all fields
  fieldA = 0;
  req_fieldA = 0;
  opt_fieldA.clear();
  fieldB.clear();
  req_fieldB.clear();
  opt_fieldB.clear();
  fieldC.clear();
  req_fieldC.clear();
  opt_fieldC.clear();
  fieldD = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  fieldE = apache::thrift::StringTraits< std::string>::fromStringLiteral("somestring");
  req_fieldE = apache::thrift::StringTraits< std::string>::fromStringLiteral("somestring");
  opt_fieldE.clear();
}

bool containerStruct2::operator==(const containerStruct2& rhs) const {
  if (!((fieldA == rhs.fieldA))) {
    return false;
  }
  if (!((req_fieldA == rhs.req_fieldA))) {
    return false;
  }
  if (!((opt_fieldA == rhs.opt_fieldA))) {
    return false;
  }
  if (!((fieldB == rhs.fieldB))) {
    return false;
  }
  if (!((req_fieldB == rhs.req_fieldB))) {
    return false;
  }
  if (!((opt_fieldB == rhs.opt_fieldB))) {
    return false;
  }
  if (!((fieldC == rhs.fieldC))) {
    return false;
  }
  if (!((req_fieldC == rhs.req_fieldC))) {
    return false;
  }
  if (!((opt_fieldC == rhs.opt_fieldC))) {
    return false;
  }
  if (!((fieldD == rhs.fieldD))) {
    return false;
  }
  if (!((fieldE == rhs.fieldE))) {
    return false;
  }
  if (!((req_fieldE == rhs.req_fieldE))) {
    return false;
  }
  if (!((opt_fieldE == rhs.opt_fieldE))) {
    return false;
  }
  return true;
}

void containerStruct2::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "fieldA") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_BOOL;
  }
  else if (_fname == "req_fieldA") {
    fid = 101;
    _ftype = apache::thrift::protocol::T_BOOL;
  }
  else if (_fname == "opt_fieldA") {
    fid = 201;
    _ftype = apache::thrift::protocol::T_BOOL;
  }
  else if (_fname == "fieldB") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "req_fieldB") {
    fid = 102;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "opt_fieldB") {
    fid = 202;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "fieldC") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_SET;
  }
  else if (_fname == "req_fieldC") {
    fid = 103;
    _ftype = apache::thrift::protocol::T_SET;
  }
  else if (_fname == "opt_fieldC") {
    fid = 203;
    _ftype = apache::thrift::protocol::T_SET;
  }
  else if (_fname == "fieldD") {
    fid = 4;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "fieldE") {
    fid = 5;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "req_fieldE") {
    fid = 105;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "opt_fieldE") {
    fid = 205;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

void swap(containerStruct2& a, containerStruct2& b) {
  using ::std::swap;
  swap(a.fieldA, b.fieldA);
  swap(a.req_fieldA, b.req_fieldA);
  swap(a.opt_fieldA, b.opt_fieldA);
  swap(a.fieldB, b.fieldB);
  swap(a.req_fieldB, b.req_fieldB);
  swap(a.opt_fieldB, b.opt_fieldB);
  swap(a.fieldC, b.fieldC);
  swap(a.req_fieldC, b.req_fieldC);
  swap(a.opt_fieldC, b.opt_fieldC);
  swap(a.fieldD, b.fieldD);
  swap(a.fieldE, b.fieldE);
  swap(a.req_fieldE, b.req_fieldE);
  swap(a.opt_fieldE, b.opt_fieldE);
}

template uint32_t containerStruct2::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t containerStruct2::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t containerStruct2::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t containerStruct2::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t containerStruct2::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t containerStruct2::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t containerStruct2::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t containerStruct2::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t containerStruct2::read<>(apache::thrift::SimpleJSONProtocolReader*);
template uint32_t containerStruct2::write<>(apache::thrift::SimpleJSONProtocolWriter*) const;
template uint32_t containerStruct2::serializedSize<>(apache::thrift::SimpleJSONProtocolWriter const*) const;
template uint32_t containerStruct2::serializedSizeZC<>(apache::thrift::SimpleJSONProtocolWriter const*) const;

}} // extra::svc
