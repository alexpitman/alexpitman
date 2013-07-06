# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the image library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../attribute/include.cake"))

compiler.addDefine("IMAGE_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/image"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/image.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/image.lib")

script.setResult(library=lib)
