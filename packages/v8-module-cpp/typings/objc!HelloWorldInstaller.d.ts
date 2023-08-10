declare class HelloWorldInstaller extends NSObject {
  static alloc(): HelloWorldInstaller; // inherited from NSObject

  static install(): void;

  static new(): HelloWorldInstaller; // inherited from NSObject
}
