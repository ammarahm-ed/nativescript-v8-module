Pod::Spec.new do |s|
    s.name         = "NativeScript"
    s.version      = '1.0.0'
    s.summary      = "Framework for the my_sdk rust library"
    s.license      = "MIT"

    s.authors      = "Ammar Ahmed"
    s.homepage     = "https://github.com/ammarahm-ed/nativescript-v8-module"
    s.platforms    = { :ios => "12.4" }
    s.source       = { :git => "https://github.com/ammarahm-ed/nativescript-v8-module.git", :tag => "v1.0.0" }
    s.cocoapods_version      = ">= 1.10.1"
    s.vendored_framework = "MySdk.xcframework"

  end
