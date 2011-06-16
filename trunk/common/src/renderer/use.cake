#-------------------------------------------------------------------------------
# Script that can be included to use the renderer library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/gl/include"))
compiler.addLibrary("opengl32.Lib")

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))