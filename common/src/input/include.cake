# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the input library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../geometry/include.cake"))
script.include(script.cwd("../../3rdParty/qt/include.cake"))
script.include(script.cwd("../../3rdParty/directx/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
