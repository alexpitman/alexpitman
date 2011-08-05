#-------------------------------------------------------------------------------
# Script used to build the system library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addDefine("SYS_DLL")

source = script.cwd([
	"InputStream.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/system"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/system.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/system.lib")

script.setResult(library=lib)
