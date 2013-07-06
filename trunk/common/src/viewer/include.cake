# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the viewer library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../scenetree/include.cake"))
script.include(script.cwd("../camera/include.cake"))
script.include(script.cwd("../renderer/include.cake"))
script.include(script.cwd("../input/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
