# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the geometry library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../numeric/include.cake"))

compiler.addDefine("GEOMETRY_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/geometry"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/geometry.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/geometry.lib")

script.setResult(library=lib)
