#-------------------------------------------------------------------------------
# Script that can be included to use the input library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../3rdParty/qt/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include/QtGui"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))