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
        if _type == '':
            return 'const void *'

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
