extern crate libc;

use libc::c_char;
use std::ffi::CString;

#[no_mangle]
pub unsafe extern "C" fn hello_world() -> *const c_char {
    let s = CString::new("Hello World").expect("Hello World failed!");
    s.into_raw()
}

// pub mod android {
//     extern crate jni;

//     use self::jni::objects::JClass;
//     use self::jni::sys::jstring;
//     use self::jni::JNIEnv;

//     #[no_mangle]
//     pub unsafe extern "C" fn Java_com_samplesdk_BindingsModule_helloWorld(
//         env: JNIEnv,
//         _: JClass,
//     ) -> jstring {
//         let output = env
//             .new_string("Hello from Rust!")
//             .expect("Couldn't create java string!");
//         output.into_inner()
//     }
// }
