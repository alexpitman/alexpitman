# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the numeric library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../../3rdParty/accidentalnoise/include.cake"))
script.include(script.cwd("../config/include.cake"))

compiler.addDefine("NUMERIC_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/numeric"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/numeric.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/numeric.lib")

script.setResult(library=lib)
