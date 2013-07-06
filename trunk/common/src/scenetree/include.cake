# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the scenetree library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../object/include.cake"))
script.include(script.cwd("../renderer/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
