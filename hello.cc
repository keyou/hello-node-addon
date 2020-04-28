// hello.cc using N-API
#include <node_api.h>

namespace demo {

napi_value Hello(napi_env env, napi_callback_info args) {
  napi_value greeting;
  napi_status status;

  status = napi_create_string_utf8(env, "world", NAPI_AUTO_LENGTH, &greeting);
  if (status != napi_ok) return nullptr;
  return greeting;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value hellofn;

  status = napi_create_function(env, nullptr, 0, Hello, nullptr, &hellofn);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "hello", hellofn);
  if (status != napi_ok) return nullptr;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo
