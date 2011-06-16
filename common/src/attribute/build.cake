#-------------------------------------------------------------------------------
# Script used to build the attribute library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../include"))
compiler.addDefine("ATT_DLL")

source = script.cwd([
	"Colour.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/attribute"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/attribute.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/attribute.lib")

script.setResult(library=lib)
