#-------------------------------------------------------------------------------
# Script used to build the voxel library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../object/use.cake"))
script.include(script.cwd("../geometry/use.cake"))
script.include(script.cwd("../topology/use.cake"))
script.include(script.cwd("../numeric/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addDefine("VXL_DLL")

source = script.cwd([
  "Factory.cpp",
  "SubBlock.cpp",
  "Triangulate.cpp",
  "Voxel.cpp",
  ])

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
