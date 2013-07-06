# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the voxel library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../object/include.cake"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))
