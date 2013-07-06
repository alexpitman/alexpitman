# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the voxel library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../object/include.cake"))

compiler.addDefine("VOXEL_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/voxel"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/voxel.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/voxel.lib")

script.setResult(library=lib)
