# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the renderer library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../geometry/include.cake"))
script.include(script.cwd("../voxel/include.cake"))
script.include(script.cwd("../camera/include.cake"))
script.include(script.cwd("../attribute/include.cake"))
script.include(script.cwd("../../3rdParty/gl/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
