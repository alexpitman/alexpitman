# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the renderer library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../geometry/include.cake"))
script.include(script.cwd("../voxel/include.cake"))
script.include(script.cwd("../camera/include.cake"))
script.include(script.cwd("../attribute/include.cake"))
script.include(script.cwd("../../3rdParty/gl/include.cake"))

compiler.addDefine("RENDERER_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/renderer"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/renderer.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/renderer.lib")

script.setResult(library=lib)
