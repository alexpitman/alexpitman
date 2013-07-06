#-------------------------------------------------------------------------------
# Script that can be included to use the config library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../include"))
