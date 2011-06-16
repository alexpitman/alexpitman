#-------------------------------------------------------------------------------
# Script that can be included to use the object library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))