#-------------------------------------------------------------------------------
# Script used to build the numeric library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

script.include(script.cwd("../../3rdParty/accidentalnoise/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/accidentalnoise/include"))
compiler.addDefine("NUM_DLL")
compiler.addLibrary(script.cwd("../../3rdParty/accidentalnoise/bin/accidentalnoise.lib"))

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
