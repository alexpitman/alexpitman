# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the system library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../config/include.cake"))

compiler.addDefine("SYSTEM_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/system"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/system.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/system.lib")

script.setResult(library=lib)
