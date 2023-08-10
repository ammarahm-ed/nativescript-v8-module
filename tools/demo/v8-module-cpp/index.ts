import { DemoSharedBase } from '../utils';
import { HelloWorldPlugin } from 'v8-module-cpp';

export class DemoSharedV8ModuleCpp extends DemoSharedBase {
  testIt() {
    console.log(HelloWorldPlugin.sayHelloWorld());
  }
}
