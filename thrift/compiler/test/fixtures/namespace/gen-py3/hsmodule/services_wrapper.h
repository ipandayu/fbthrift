/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#pragma once
#include <gen-cpp2/HsTestService.h>
#include <Python.h>

#include <memory>

namespace cpp2 {

class HsTestServiceWrapper : virtual public HsTestServiceSvIf {
  protected:
    PyObject *if_object;
  public:
    explicit HsTestServiceWrapper(PyObject *if_object);
    virtual ~HsTestServiceWrapper();
    folly::Future<int64_t> future_init(
        int64_t int1
    ) override;
};

std::shared_ptr<apache::thrift::ServerInterface> HsTestServiceInterface(PyObject *if_object);
} // namespace cpp2