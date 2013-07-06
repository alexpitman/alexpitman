# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the import library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../object/include.cake"))
script.include(script.cwd("../system/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
