#-------------------------------------------------------------------------------
# Script used to build the scenetree library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../attribute/use.cake"))
script.include(script.cwd("../geometry/use.cake"))
script.include(script.cwd("../topology/use.cake"))
script.include(script.cwd("../renderer/use.cake"))
script.include(script.cwd("../object/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addDefine("ST_DLL")

source = script.cwd([
  "FacetNetworkNode.cpp",
	"Light.cpp",
	"Node.cpp",
	"PointSetNode.cpp",
	"SceneTreeNode.cpp",
	])

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
