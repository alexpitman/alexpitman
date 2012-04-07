#-------------------------------------------------------------------------------
# Script used to build the export library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

# include dependencies
script.include(script.cwd("../attribute/use.cake"))
script.include(script.cwd("../image/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/DevIL/include"))
compiler.addDefine("EPT_DLL")
compiler.addLibrary(script.cwd("../../3rdParty/DevIL/lib/DevIL.lib"))

source = script.cwd([
  "ExportImage.cpp",
  ])

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/export"),
  sources=source,
  )

module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/export.dll"),
  sources=objects,
  )

lib = script.cwd("../../../build/testbed/bin/export.lib")

script.setResult(library=lib)
