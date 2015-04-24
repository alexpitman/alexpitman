# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build and run the tests for the functional library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../include.cake"))
script.include(script.cwd("../../test/include.cake"))

source = glob(path.join(script.cwd(), "*.cpp"))

objects = compiler.objects(
  targetDir=script.cwd("../../../../build/testbed/obj/functional/tests"),
  sources=source,
  )
program = compiler.program(
  target=script.cwd("../../../../build/testbed/bin/test_functional.exe"),
  sources=objects,
  )
  
shell.run(
  args=[program.path],
  targets=[],
  sources=[program],
  )
