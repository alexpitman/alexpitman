#-------------------------------------------------------------------------------
# Script that can be included to use the numeric library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))