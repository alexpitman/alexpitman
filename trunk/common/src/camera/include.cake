# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the camera library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../geometry/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
