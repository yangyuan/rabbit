from distutils.core import setup, Extension

module_rabbit = Extension('rabbit',
    sources=['main.cpp', 'rabbit_core.cpp', 'rabbit_python.cpp'])

setup(name='rabbit-bot',
version='0.1',
description='Windows Bot Engine (Human Input Simulator)',
ext_modules=[module_rabbit])
