# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the geometry library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../numeric/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
