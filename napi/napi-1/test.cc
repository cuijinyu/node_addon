#include <node_api.h>
#include <iostream>

using namespace std;

napi_value echo (napi_env env, napi_callback_info info) {
    napi_status status;

    size_t argc = 1;
    napi_value argv[1];
    status = napi_get_cb_info(env, info, &argc, argv, 0, 0);
    if (status != napi_ok || argc < 1) {
        napi_throw_type_error(env, "EBADARGS", "Wrong number of arguments");
        return 0;
    }
    return argv[0];
}

napi_value init(napi_env env, napi_value exports) {
    napi_status status;

    napi_property_descriptor desc = {"echo", 0, echo, 0, 0, 0, napi_default, 0};
    status = napi_define_properties(env, exports, 1, &desc);
    if (status != napi_ok) {
        return NULL;
    } else {
        return exports;
    }
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init);
