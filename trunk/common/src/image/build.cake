#-------------------------------------------------------------------------------
# Script used to build the image library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../attribute/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addDefine("IMG_DLL")

source = script.cwd([
  "Image.cpp",
  ])

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
