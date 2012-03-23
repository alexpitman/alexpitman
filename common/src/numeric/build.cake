#-------------------------------------------------------------------------------
# Script used to build the numeric library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../include"))
compiler.addDefine("NUM_DLL")

source = script.cwd([
	"Fractal.cpp",
	"Interpolate.cpp",
	"Noise.cpp",
	"Random.cpp",
	"num.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/numeric"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/numeric.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/numeric.lib")

script.setResult(library=lib)
