import itertools


class CodeGenerator:
    def __init__(self):
        pass

    @staticmethod
    def to_type_cpp(_type):
        if _type == 's':
            return 'const char *'
        if _type == 'i':
            return 'int'
        if _type == 'I':
            return 'unsigned int'
        if _type == 'd':
            return 'double'

    def get_header_code(self):
        raise NotImplemented()

    def get_module_code(self, _module):
        raise NotImplemented()

    def get_function_code(self, _name, _returns, _arguments):
        raise NotImplemented()

    def get_code(self, _module):
        codes = []

        codes.extend(self.get_header_code())

        for _name, _returns, _arguments in _module:
            codes.append(self.get_function_code(_name, _returns, _arguments))

        codes.extend(self.get_module_code(_module))

        return '\n'.join(codes)



class PythonCodeGenerator(CodeGenerator):
    def __init__(self):
        super().__init__()
        pass

    def get_header_code(self):
        return ['#include <Python.h>', '#include "rabbit_core.h"\n']

    def get_module_code(self, _module):

        ret = []

        _code = 'PyMethodDef _rabbit_methods[] = {\n'
        for _name, _, _ in _module:
            _code += ('    { "%s", _python_%s, METH_VARARGS, NULL },\n' % (_name, _name))
        _code += '    { NULL, NULL, 0, NULL }\n'
        _code += '};\n'
        ret.append(_code)

        return ret

    def get_function_code(self, _name, _returns, _arguments):

        var_returns = []
        var_arguments = []
        for _return, _index in zip(_returns, itertools.count()):
            var_returns.append((self.to_type_cpp(_return), ('ret_%d' % _index)))
        for _argument, _index in zip(_arguments, itertools.count()):
            var_arguments.append((self.to_type_cpp(_argument), ('arg_%d' % _index)))

        ret = ('PyObject * _python_%s(PyObject * self, PyObject * args) {\n' % _name)

        for var_return in var_returns:
            ret += ('    %s %s;\n' % var_return)
        for var_argument in var_arguments:
            ret += ('    %s %s;\n' % var_argument)

        ret += ('    PyArg_ParseTuple(args, "%s"%s);\n'
                % (''.join(_arguments), ''.join([', &' + x[1] for x in var_arguments])))
        ret += ('    rabbit_%s(%s);\n'
                % (_name, ' ,'.join(['&' + x[1] for x in var_returns] + [x[1] for x in var_arguments])))
        ret += ('    return Py_BuildValue("%s"%s);\n'
                % (''.join(_returns), ''.join([', ' + x[1] for x in var_returns])))

        ret += '}\n'

        return ret


class LuaCodeGenerator(CodeGenerator):
    def __init__(self):
        super().__init__()
        pass

    @staticmethod
    def to_type_lua(_type):
        if _type == 's':
            return 'string'
        if _type == 'i' or _type == 'I':
            return 'integer'
        if _type == 'd':
            return 'number'

    def get_header_code(self):
        return ['#include <lua.hpp>', '#include "rabbit_core.h"\n']

    def get_module_code(self, _module):

        ret = []

        _code = 'luaL_Reg _rabbit_methods[] = {\n'
        for _name, _, _ in _module:
            _code += ('    { "%s", _lua_%s },\n' % (_name, _name))
        _code += '    { NULL, NULL }\n'
        _code += '};\n'
        ret.append(_code)

        return ret

    def get_function_code(self, _name, _returns, _arguments):

        var_returns = []
        var_arguments = []
        for _return, _index in zip(_returns, itertools.count()):
            var_returns.append((self.to_type_cpp(_return),
                                ('ret_%d' % _index),
                                self.to_type_lua(_return)))
        for _argument, _index in zip(_arguments, itertools.count()):
            var_arguments.append((self.to_type_cpp(_argument),
                                  ('arg_%d' % _index),
                                  self.to_type_lua(_argument),
                                  _index + 1))

        ret = ('int _lua_%s(lua_State * L) {\n' % _name)

        for var_return in var_returns:
            ret += ('    %s %s;\n' % var_return[0:2])
        for var_argument in var_arguments:
            ret += ('    %s %s = lua_to%s(L, %d);\n' % var_argument)

        ret += ('    rabbit_%s(%s);\n'
                % (_name, ' ,'.join(['&' + x[1] for x in var_returns] + [x[1] for x in var_arguments])))
        for var_return in var_returns:
            ret += ('    lua_push%s(L, %s);\n' % (var_return[2], var_return[1]))
        ret += ('    return %d;\n' % len(_returns))

        ret += '}\n'

        return ret


class JavaScriptCodeGenerator(CodeGenerator):
    def __init__(self):
        super().__init__()
        pass

    @staticmethod
    def to_type_lua(_type):
        if _type == 's':
            return 'string'
        if _type == 'i':
            return 'int32'
        if _type == 'I':
            return 'uint32'
        if _type == 'd':
            return 'number'

    def get_header_code(self):
        return ['#include <node.h>', '#include "rabbit_core.h"\n']

    def get_module_code(self, _module):

        ret = []

        _code = 'void _rabbit_init(Local<Object> exports) {\n'
        for _name, _, _ in _module:
            _code += ('    NODE_SET_METHOD(exports, "%s", _javascript_%s);\n' % (_name, _name))
        _code += '};\n'
        ret.append(_code)

        return ret

    def get_function_code(self, _name, _returns, _arguments):

        var_returns = []
        var_arguments = []
        for _return, _index in zip(_returns, itertools.count()):
            var_returns.append((self.to_type_cpp(_return),
                                ('ret_%d' % _index),
                                self.to_type_lua(_return),
                                  _index))
        for _argument, _index in zip(_arguments, itertools.count()):
            var_arguments.append((self.to_type_cpp(_argument),
                                  ('arg_%d' % _index),
                                  self.to_type_lua(_argument),
                                  _index + 1))

        ret = ('void _javascript_%s(const FunctionCallbackInfo<Value>& args) {\n' % _name)

        for var_return in var_returns:
            ret += ('    %s %s;\n' % var_return[0:2])
        for var_argument in var_arguments:
            ret += ('    %s %s = _javascript_to_%s(args, %d);\n' % var_argument)

        ret += ('    rabbit_%s(%s);\n'
                % (_name, ' ,'.join(['&' + x[1] for x in var_returns] + [x[1] for x in var_arguments])))
        if len(var_returns) == 1:
            for var_return in var_returns:
                ret += ('    Value ret = _javascript_to_%s_value(%s);\n' % (var_return[2], var_return[1]))
        if len(var_returns) > 1:
            ret += ('    Handle<Array> ret = Array::New(%d);\n' % len(var_returns))
            for var_return in var_returns:
                ret += ('    ret->Set(%d, _javascript_to_%s_value(%s));\n' % (var_return[3], var_return[2], var_return[1]))
        if len(var_returns) > 0:
            ret += '    args.GetReturnValue().Set(ret);\n'
        ret += '}\n'

        return ret


module_conf = [
    ('sleep', '', 'I'),
    ('keypress', '', 's'),
    ('input', '', 's'),
    ('moveto', '', 'II'),
    ('click', '', ''),
    ('doubleclick', '', ''),
    ('rightclick', '', ''),
    ('findcolor', 'ii', 'IIIIId'),
    ('mouse_fetch_cursor', 'I', ''),
    ('findwindow', 'I', 's'),
    ('find_window', 'I', 'ss'),
    ('get_window_rect', 'iiii', 'I')
]


if __name__ == '__main__':
    gen = PythonCodeGenerator()
    code = gen.get_code(module_conf)

    with open('../src/python/rabbit_python.cpp', 'w') as f:
        f.write(code)

    gen = LuaCodeGenerator()
    code = gen.get_code(module_conf)

    with open('../src/lua/rabbit_lua.cpp', 'w') as f:
        f.write(code)

    gen = JavaScriptCodeGenerator()
    code = gen.get_code(module_conf)

    with open('../src/javascript/rabbit_javascript.cpp', 'w') as f:
        f.write(code)
