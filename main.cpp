#include <iostream>
#include <string>
#include <napi.h>

std::string handleBackendRequest(const std::string& input) {

  return "Backend response: " + input;
}
NAPI_MODULE_INIT() {

  NAPI_FUNCTION(handleRequest) {
    std::string input = info[0].As<Napi::String>().Utf8Value();

    std::string response = handleBackendRequest(input);
    return Napi::String::New(env, response);
  }
  exports.Set(Napi::String::New(env, "handleRequest"), handleRequest);
}