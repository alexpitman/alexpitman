# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the object library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../geometry/include.cake"))
script.include(script.cwd("../attribute/include.cake"))
script.include(script.cwd("../topology/include.cake"))

compiler.addDefine("OBJECT_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/object"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/object.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/object.lib")

script.setResult(library=lib)
