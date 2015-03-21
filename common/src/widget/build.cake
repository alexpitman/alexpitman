# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the widget library.
#-------------------------------------------------------------------------------
from glob import glob
import re
from os import path
from cake.filesys import makeDirs
from cake.tools import compiler, script, shell

script.include(script.cwd("../viewer/include.cake"))
script.include(script.cwd("../voxel/include.cake"))
script.include(script.cwd("../input/include.cake"))
script.include(script.cwd("../import/include.cake"))

compiler.addDefine("WIDGET_DLL")

source = glob(path.join(script.cwd(), "*.cpp"))

allHeaders = glob(path.join(script.cwd(), "../../include/widget/*.h"))
mocHeaders = []
for file in allHeaders:
  with open(file, "r") as f:
    fileContent = f.read()
    match = re.search("Q_OBJECT", fileContent)
    if match:
      head, tail = path.split(file)
      mocHeaders.append(file)

makeDirs(script.cwd("../../../build/testbed/moc/widget"))
for file in mocHeaders:
  head, tail = path.split(file)
  mocFile = script.cwd("../../../build/testbed/moc/widget/m_" + tail)
  shell.run(
    args=[
      script.cwd("../../3rdParty/qt/bin/moc.exe"),
      "-i", file,
      "-o", mocFile, "-f" ],
    targets=[mocFile],
    sources=[file])
  source.append(mocFile)

objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/widget"),
  sources=source,
  )
module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/widget.dll"),
  sources=objects,
  )
lib = script.cwd("../../../build/testbed/bin/widget.lib")

script.setResult(library=lib)
