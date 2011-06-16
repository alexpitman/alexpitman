#-------------------------------------------------------------------------------
# Script used to build the input library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../geometry/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include/QtCore"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include/QtGui"))
compiler.addIncludePath(script.cwd("../../3rdParty/directx/include"))
compiler.addDefine("IN_DLL")
compiler.addLibrary(script.cwd("../../3rdParty/directx/lib/XInput.lib"))

source = script.cwd([
  "Key.cpp",
	"Mouse.cpp",
	"XBox.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/input"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/input.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/input.lib")

script.setResult(library=lib)
