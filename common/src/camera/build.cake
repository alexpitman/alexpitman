#-------------------------------------------------------------------------------
# Script used to build the camera library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../geometry/use.cake"))
script.include(script.cwd("../input/use.cake"))
script.include(script.cwd("../renderer/use.cake"))
script.include(script.cwd("../scenetree/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/gl/include"))
compiler.addDefine("CMR_DLL")
compiler.addLibrary("glu32.Lib")

source = script.cwd([
	"Camera.cpp",
	"CameraController.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/camera"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/camera.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/camera.lib")

script.setResult(library=lib)
