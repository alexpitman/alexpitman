#-------------------------------------------------------------------------------
# Script that can be included to use the widget library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/gl/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include/QtCore"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include/QtGui"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include/QtOpenGL"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))