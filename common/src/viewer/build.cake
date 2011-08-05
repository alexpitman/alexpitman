#-------------------------------------------------------------------------------
# Script used to build the viewer library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../attribute/use.cake"))
script.include(script.cwd("../geometry/use.cake"))
script.include(script.cwd("../topology/use.cake"))
script.include(script.cwd("../input/use.cake"))
script.include(script.cwd("../renderer/use.cake"))
script.include(script.cwd("../scenetree/use.cake"))
script.include(script.cwd("../camera/use.cake"))
script.include(script.cwd("../object/use.cake"))
script.include(script.cwd("../import/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addDefine("VWR_DLL")
compiler.addLibrary("glu32.Lib")

source = script.cwd([
  "InputController.cpp",
  "SceneController.cpp",
	"View.cpp",
	"ViewHandler.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/viewer"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/viewer.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/viewer.lib")

script.setResult(library=lib)
