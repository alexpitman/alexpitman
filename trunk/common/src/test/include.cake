# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the test library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../config/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
