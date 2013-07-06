#-------------------------------------------------------------------------------
# Script that can be included to use the accidenal noise library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("include"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))