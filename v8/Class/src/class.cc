#include <node.h>
#include <iostream>
namespace demo {
    using v8::FunctionCallbackInfo;
    using v8::Local;
    using v8::Object;
    using v8::Isolate;
    using v8::Value;
    using v8::String;
    void Method(FunctionCallbackInfo<Value> &args)
    {
        Isolate * isolate = args.GetIsolate();
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
    }

    void init(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "Class", Method);
    }

    NODE_MODULE(Method, init);
}