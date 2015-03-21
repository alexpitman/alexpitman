# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the test library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../config/include.cake"))

compiler.addDefine("TEST_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/test"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/test.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/test.lib")

script.setResult(library=lib)
