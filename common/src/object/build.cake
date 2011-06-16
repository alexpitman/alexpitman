#-------------------------------------------------------------------------------
# Script used to build the object library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../attribute/use.cake"))
script.include(script.cwd("../geometry/use.cake"))
script.include(script.cwd("../topology/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addDefine("OBJ_DLL")

source = script.cwd([
  "FacetNetwork.cpp",
	"PointSet.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/object"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/object.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/object.lib")

script.setResult(library=lib)
