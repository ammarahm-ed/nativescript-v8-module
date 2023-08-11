import { Observable } from '@nativescript/core';

declare const __non_webpack_require__;

if (__ANDROID__) {
  try {
    __non_webpack_require__('system_lib://libhelloworld.so');
  } catch (error) {
    console.error(`Failed to load libhelloworld.so`);
  }
} else {
  try {
    HelloWorldInstaller.install();
  } catch (e) {
    if (__DEV__) {
      console.error('Failed to install HelloWorld plugin.');
    }
  }
}

export class HelloWorldCommon extends Observable {
  static sayHelloWorld() {
    // HelloWorld.sayHelloWorld();

    return HelloWorld.sayHelloWorldFromRust();
  }
}
