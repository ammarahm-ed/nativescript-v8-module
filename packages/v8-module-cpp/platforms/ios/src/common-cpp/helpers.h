using namespace std;

template <typename Lambda>
void AddFunctionToV8Object(v8::Local<v8::Object> target, const char *functionName, Lambda &&callback)
{
  v8::Isolate *isolate = target->GetIsolate();
  v8::Local<v8::FunctionTemplate> funcTemplate = v8::FunctionTemplate::New(isolate, callback);
  v8::Local<v8::Function> function = funcTemplate->GetFunction(
                                                     isolate->GetCurrentContext())
                                         .ToLocalChecked();
  v8::Local<v8::String> funcName = v8::String::NewFromUtf8(isolate,
                                                           functionName)
                                       .ToLocalChecked();
  target->Set(isolate->GetCurrentContext(), funcName, function).Check();
}

#define EnterScope                          \
  v8::Isolate *isolate = info.GetIsolate(); \
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

#define CreateJSModule(moduleName, functionBody)                                                    \
  v8::Local<v8::Context> ctx = (isolate)->GetCurrentContext();                                      \
  v8::Local<v8::Object> global = ctx->Global();                                                     \
  v8::Local<v8::Object> moduleObject = v8::Object::New((isolate));                                  \
  v8::Local<v8::String> moduleObjectName = v8::String::NewFromUtf8(                                 \
                                               (isolate), (moduleName), v8::NewStringType::kNormal) \
                                               .ToLocalChecked();                                   \
  functionBody                                                                                      \
                                                                                                    \
  global->Set(ctx, moduleObjectName, moduleObject)                                              \
          .FromJust();

#define CREATE_FUNCTION(functionName, functionBody)                                                                                     \
  {                                                                                                                                     \
    AddFunctionToV8Object(moduleObject, functionName, [](const v8::FunctionCallbackInfo<v8::Value> &info) { EnterScope                   \
                                                                                                                functionBody }); \
  }

#define CreateFunction(functionName, functionBody)                                                                                      \
  {                                                                                                                                     \
    AddFunctionToV8Object(moduleObject, functionName, [](const v8::FunctionCallbackInfo<v8::Value> &info) { EnterScope                   \
                                                                                                                functionBody }); \
  }

#define ReturnUndefined \
  info.GetReturnValue().SetUndefined();

/*
Convert CPP values  to JS values
*/
#define toJSString(value) \
  v8::String::NewFromUtf8(isolate, value).ToLocalChecked()

#define toJSDouble(value) \
  v8::Number::New(isolate, value)

#define toJSInt32(value) \
  v8::Int32::New(isolate, value)

#define toJSInt64(value) \
  v8::Int64::New(isolate, value)

#define toJSUInt32(value) \
  v8::UInt32::New(isolate, value)

#define toJSUInt32(value) \
  v8::UInt32::New(isolate, value)

#define toJSBoolean(value) \
  v8::Boolean::New(isolate, value)

#define toJSBigInt(value) \
  v8::BigInt::New(isolate, value)

/**
 * Convert JS values to CPP values
 */
#define fromJSInt32(value) \
  (value)->Int32Value(isolate->GetCurrentContext()).FromJust()

#define fromJSUInt32(value) \
  (value)->Uint32Value(isolate->GetCurrentContext()).FromJust()

#define fromJSInt64(value) \
  (value)->IntegerValue(isolate->GetCurrentContext()).FromJust()

#define fromJSBigInt(value) \
  (value)->As<v8::BigInt>.Int64Value().FromJust()

#define fromJSDouble(value) \
  (value).NumberValue(isolate->GetCurrentContext()).FromJust()

#define fromJSBoolean(value) \
  (value)->BooleanValue(isolate)

#define fromJSString(value) \
  std::string(*v8::String::Utf8Value(isolate, (value)->ToString(isolate->GetCurrentContext()).ToLocalChecked()))

#define JSFunction(value) \
  v8::Local<v8::Function>::Cast(value)

#define CallJSFunction(function, argumentsCount, arguments, returnVariableName) \
  v8::Local<v8::Value> argv[argumentsCount] = arguments;                        \
  v8::Local<v8::Value> returnVariableName;                                      \
  callback->Call(context, v8::Undefined(isolate), argumentsCount, argv).ToLocal(&returnVariableName);

#define CreatePersistantJSFunctionHandle(name, value) \
  v8::Persistent<v8::Function> name;                  \
  name.Reset(isolate, value.As<v8::Function>());

#define CallPersistantJSFunctionHandle(functionVariableName, handle, argumentsCount, arguments, returnVariableName) \
  v8::Local<v8::Function> functionVariableName = v8::Local<v8::Function>::New(isolate, handle);                     \
  CallJSFunction(callback, argumentsCount, arguments, returnVariableName)
