#import "HelloWorldInstaller.h"
#import <NativeScript/runtime/Runtime.h>
#import "hello-world.h"


@implementation HelloWorldInstaller

+ (void) install {
    v8::Isolate* isolate = tns::Runtime::GetCurrentRuntime()->GetIsolate();
    helloworld::install(isolate);
}

@end
