# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the export library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../image/include.cake"))
script.include(script.cwd("../../3rdParty/DevIL/include.cake"))

compiler.addDefine("EXPORT_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/export"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/export.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/export.lib")

script.setResult(library=lib)
