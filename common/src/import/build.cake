#-------------------------------------------------------------------------------
# Script used to build the import library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../system/use.cake"))
script.include(script.cwd("../geometry/use.cake"))
script.include(script.cwd("../topology/use.cake"))
script.include(script.cwd("../object/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addDefine("IMP_DLL")

source = script.cwd([
  "ImportObjFile.cpp",
	])

objects = compiler.objects(
	targetDir=script.cwd("../../../build/testbed/obj/import"),
	sources=source,
	)

module = compiler.module(
	target=script.cwd("../../../build/testbed/bin/import.dll"),
	sources=objects,
	)

lib = script.cwd("../../../build/testbed/bin/import.lib")

script.setResult(library=lib)
