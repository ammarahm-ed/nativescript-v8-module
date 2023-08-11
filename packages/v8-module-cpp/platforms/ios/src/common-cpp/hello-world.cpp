#include "hello-world.h"
#include "helpers.h"
#include <my_sdk.h>

namespace helloworld
{
void install(v8::Isolate *isolate)
{

    CreateJSModule("HelloWorld", {

        CreateFunction("sayHelloWorld", {
            info.GetReturnValue().Set(toJSString("hello world"));
        })
        
        CreateFunction("sayHelloWorldFromRust", {
            info.GetReturnValue().Set(toJSString(hello_world()));
        })



    })
}
}
