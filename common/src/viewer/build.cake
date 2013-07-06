# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the viewer library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../scenetree/include.cake"))
script.include(script.cwd("../camera/include.cake"))
script.include(script.cwd("../renderer/include.cake"))
script.include(script.cwd("../input/include.cake"))

compiler.addDefine("VIEWER_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

allHeaders = glob(path.join(script.cwd(), "../../include/viewer/*.h"))
mocHeaders = []
for file in allHeaders:
  with open(file, "r") as f:
    fileContent = f.read()
    match = re.search("Q_OBJECT", fileContent)
    if match:
      head, tail = path.split(file)
      mocHeaders.append(file)

makeDirs(script.cwd("../../../build/testbed/moc/viewer"))
for file in mocHeaders:
  head, tail = path.split(file)
  mocFile = script.cwd("../../../build/testbed/moc/viewer/m_" + tail)
  shell.run(
    args=[
      script.cwd("../../3rdParty/qt/bin/moc.exe"),
      "-i", file,
      "-o", mocFile, "-f" ],
    targets=[mocFile],
    sources=[file])
  source.append(mocFile)

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
