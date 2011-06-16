#-------------------------------------------------------------------------------
# Script used to build the renderer library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../attribute/use.cake"))
script.include(script.cwd("../geometry/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/gl/include"))
compiler.addDefine("REE_DLL")
compiler.addLibrary("opengl32.Lib")

source = script.cwd([
  "Factory.cpp",
	"Renderer.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/renderer"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/renderer.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/renderer.lib")

script.setResult(library=lib)
