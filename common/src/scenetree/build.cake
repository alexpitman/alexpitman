# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the scenetree library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../object/include.cake"))
script.include(script.cwd("../renderer/include.cake"))

compiler.addDefine("SCENETREE_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/scenetree"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/scenetree.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/scenetree.lib")

script.setResult(library=lib)
