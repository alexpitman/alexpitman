# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the input library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../geometry/include.cake"))
script.include(script.cwd("../../3rdParty/qt/include.cake"))
script.include(script.cwd("../../3rdParty/directx/include.cake"))

compiler.addDefine("INPUT_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

allHeaders = glob(path.join(script.cwd(), "../../include/input/*.h"))
mocHeaders = []
for file in allHeaders:
  with open(file, "r") as f:
    fileContent = f.read()
    match = re.search("Q_OBJECT", fileContent)
    if match:
      head, tail = path.split(file)
      mocHeaders.append(file)

makeDirs(script.cwd("../../../build/testbed/moc/input"))
for file in mocHeaders:
  head, tail = path.split(file)
  mocFile = script.cwd("../../../build/testbed/moc/input/m_" + tail)
  shell.run(
    args=[
      script.cwd("../../3rdParty/qt/bin/moc.exe"),
      "-i", file,
      "-o", mocFile, "-f" ],
    targets=[mocFile],
    sources=[file])
  source.append(mocFile)

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
