# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the widget library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../viewer/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
