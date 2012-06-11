#-------------------------------------------------------------------------------
# Script that can be included to use the numeric library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../3rdParty/accidentalnoise/include"))

compiler.addLibrary(script.cwd("../../3rdParty/accidentalnoise/lib/accidentalnoise.lib"))

compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))