#-------------------------------------------------------------------------------
# Script used to build the topology library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../include"))
compiler.addDefine("TPO_DLL")

source = script.cwd([
	"Triple.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/topology"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/topology.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/topology.lib")

script.setResult(library=lib)
