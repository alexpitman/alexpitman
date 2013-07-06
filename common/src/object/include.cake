# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the object library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../geometry/include.cake"))
script.include(script.cwd("../attribute/include.cake"))
script.include(script.cwd("../topology/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
