#include <node.h>

using namespace v8;
void _rabbit_javascript_init(Local<Object> exports);

NODE_MODULE(NODE_GYP_MODULE_NAME, _rabbit_javascript_init)