Rabbit-Bot: Windows Bot Engine (Human Input Simulator)
======================================================

Purposes and Features
---------------------

Rabbit is designed to use programs to simulate human inputs. Which might
be useful in some boring repeating tasks or game bots.

This project contains two sub-projects:

-  Rabbit App: An application with embedded scripting support, an
   alternative of QuickMacro.
-  Rabbit-Bot Packages: Packages for Python (PyPI), JavaScript (NPM),
   Lua (LuaRocks).

Usage
-----

::

    import rabbit

    rabbit.log('Hello World')

    # wait 3 seconds
    rabbit.sleep(3000)
    rabbit.log('rabbit started')

    # If your cursor is in some applications like notepad, you should able to see the text
    rabbit.input('Hello World')

    # wait 1 seconds
    rabbit.sleep(1000)
    rabbit.moveto(1, 1)
    rabbit.rightclick()