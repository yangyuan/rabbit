from distutils.core import setup, Extension

module_rabbit = Extension('rabbit',
    sources=['rabbit_core.cpp', 'rabbit_core_utils.cpp', 'rabbit_python.cpp'])

setup(name='rabbit-bot',
    version='0.0.3',
    description='Windows Bot Engine (Human Input Simulator)',
    author = 'Yuan Yang',
    author_email = '6941987@qq.com',
    url = 'https://github.com/yangyuan/rabbit',
    ext_modules=[module_rabbit])
