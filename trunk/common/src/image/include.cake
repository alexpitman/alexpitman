# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the image library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../attribute/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
