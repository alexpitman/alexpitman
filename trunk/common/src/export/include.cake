# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the export library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../image/include.cake"))
script.include(script.cwd("../../3rdParty/DevIL/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
