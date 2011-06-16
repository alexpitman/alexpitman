#-------------------------------------------------------------------------------
# Script used to build the geometry library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../numeric/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addDefine("GEO_DLL")

source = script.cwd([
	"Extent.cpp",
	"Point.cpp",
  "Rotation.cpp",
  "Transform.cpp",
	"Vector.cpp",
	])

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
