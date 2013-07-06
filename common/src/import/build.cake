# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the import library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../object/include.cake"))
script.include(script.cwd("../system/include.cake"))

compiler.addDefine("IMPORT_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/import"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/import.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/import.lib")

script.setResult(library=lib)
