# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the camera library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../geometry/include.cake"))

compiler.addDefine("CAMERA_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/camera"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/camera.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/camera.lib")

script.setResult(library=lib)
