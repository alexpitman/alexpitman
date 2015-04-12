from cake.tools import compiler, script, shell, filesys
from glob import glob
import re
from os import path
from cake.filesys import makeDirs

# Dependent libraries
script.include(script.cwd("common/src/export/include.cake"))
script.include(script.cwd("common/src/import/include.cake"))
script.include(script.cwd("common/src/widget/include.cake"))
script.include(script.cwd("common/src/voxel/include.cake"))

# Build the main program.
source = glob(path.join(script.cwd(), "testbed/*.cpp"))

allHeaders = glob(path.join(script.cwd(), "testbed/*.h"))
mocHeaders = []
for file in allHeaders:
  with open(file, "r") as f:
    fileContent = f.read()
    match = re.search("Q_OBJECT", fileContent)
    if match:
      head, tail = path.split(file)
      mocHeaders.append(file)

makeDirs(script.cwd("build/testbed/moc/testbed"))
for file in mocHeaders:
  head, tail = path.split(file)
  mocFile = script.cwd("build/testbed/moc/testbed/m_" + tail)
  shell.run(
    args=[
      script.cwd("common/3rdParty/qt/bin/moc.exe"),
      "-i", file,
      "-o", mocFile, "-f" ],
    targets=[mocFile],
    sources=[file])
  source.append(mocFile)
  
objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/testbed"),
  sources=source,
  )
  
main_program = compiler.program(
  target=script.cwd("build/testbed/bin/main"),
  sources=objects,
  )

# Execute the program
shell.run(
  args=[main_program.path],
  targets=[],
  sources=[main_program],
  )