from glob import glob
import os
from os import path

# 3rdParty libraries
thirdPartyLibraries = {
  'accidentalnoise',
  'DevIL',
  'directx',
  'gl',
  'qt',
  }

def thirdParty(library):
  return "3rd_" + library
  
# Common libraries
libraryDependencies = {
  'attribute'        : { 'config' },
  'camera'           : { 'geometry' },
  'config'           : {},
  'export'           : { 'image', thirdParty('DevIL') },
  'geometry'         : { 'numeric' },
  'image'            : { 'attribute' },
  'import'           : { 'system', 'object' },
  'input'            : { 'geometry', thirdParty('qt'), thirdParty('directx') },
  'numeric'          : { 'config', thirdParty('accidentalnoise') },
  'object'           : { 'attribute', 'geometry', 'topology' },
  'renderer'         : { 'attribute', 'camera', 'geometry', 'voxel', thirdParty('gl') },
  'scenetree'        : { 'object', 'renderer' },
  'system'           : { 'config' },
  'topology'         : { 'config' },
  'viewer'           : { 'camera', 'input', 'renderer', 'scenetree' },
  'voxel'            : { 'object' },
  'widget'           : { 'input', 'viewer' },
  }

dir = os.path.dirname(os.path.realpath(__file__))

def dependsOnQt(dependencies):
  if thirdParty('qt') in dependencies:
    return True
    
  for l in dependencies:
    if l in libraryDependencies and dependsOnQt(libraryDependencies[l]):
      return True
    
  return False

def generateInclude(library, dependencies):
  print 'Generating include.cake for %s' % library
  f = open(os.path.join(dir, 'src', library, 'include.cake'), 'w')
  f.write('''# GENERATED
#-------------------------------------------------------------------------------
# Script that can be included to use the %s library.
#-------------------------------------------------------------------------------
''' % library)

  f.write('from cake.tools import compiler, script\n\n')
  
  writeDependencies(f, dependencies)
  
  f.write('compiler.addLibrary(script.getResult(script.cwd("build.cake"), "library"))\n')

  f.close()
  
  
def generateBuild(library, dependencies):
  print 'Generating build.cake for %s' % library
  f = open(os.path.join(dir, 'src', library, 'build.cake'), 'w')
  f.write('''# GENERATED
#-------------------------------------------------------------------------------
# Script that can be run to build the %s library.
#-------------------------------------------------------------------------------
''' % library)

  f.write('from glob import glob\n')
  f.write('import re\n')
  f.write('from os import path\n')
  f.write('from cake.filesys import makeDirs\n')
  f.write('from cake.tools import compiler, script, shell\n\n')
  
  writeDependencies(f, dependencies)
  
  f.write('compiler.addDefine("%s_DLL")\n\n' % library.upper())
  
  f.write('source = glob(path.join(script.cwd(), "*.cpp"))\n\n')
  
  if dependsOnQt(dependencies):
    f.write('allHeaders = glob(path.join(script.cwd(), "../../include/%s/*.h"))\n' % library)
    f.write('mocHeaders = []\n')
    
    f.write('for file in allHeaders:\n')
    f.write('  with open(file, "r") as f:\n')
    f.write('    fileContent = f.read()\n')
    f.write('    match = re.search("Q_OBJECT", fileContent)\n')
    f.write('    if match:\n')
    f.write('      head, tail = path.split(file)\n')
    f.write('      mocHeaders.append(file)\n\n')
  
    f.write('makeDirs(script.cwd("../../../build/testbed/moc/%s"))\n' % library)
    f.write('for file in mocHeaders:\n')
    f.write('  head, tail = path.split(file)\n')
    f.write('  mocFile = script.cwd("../../../build/testbed/moc/%s/m_" + tail)\n' % library)
    f.write('  shell.run(\n')
    f.write('    args=[\n')
    f.write('      script.cwd("../../3rdParty/qt/bin/moc.exe"),\n')
    f.write('      "-i", file,\n')
    f.write('      "-o", mocFile, "-f" ],\n')
    f.write('    targets=[mocFile],\n')
    f.write('    sources=[file])\n')
    f.write('  source.append(mocFile)\n\n')
  
  f.write('''objects = compiler.objects(
  targetDir=script.cwd("../../../build/testbed/obj/%s"),
  sources=source,
  )
''' % library)

  f.write('''module = compiler.module(
  target=script.cwd("../../../build/testbed/bin/%s.dll"),
  sources=objects,
  )
''' % library)

  f.write('lib = script.cwd("../../../build/testbed/bin/%s.lib")\n\n' % library)

  f.write('script.setResult(library=lib)\n')

  
  f.close()

def writeDependencies(file, dependencies):
  for d in dependencies:
    if d.startswith("3rd_"):
      name = d[4:]
      file.write('script.include(script.cwd("../../3rdParty/%s/include.cake"))\n' % name)
    else:
      file.write('script.include(script.cwd("../%s/include.cake"))\n' % d)
  file.write('\n')
  
def isIncludeGenerated(library):
  path = os.path.join(dir, 'src', library, 'include.cake')
  if not os.path.exists(path):
    return True
    
  f = open(path)
  line = f.readline()
  f.close()
  
  return line.startswith('# GENERATED')
  
def isBuildGenerated(library):
  path = os.path.join(dir, 'src', library, 'build.cake')
  if not os.path.exists(path):
    # Check for header only library
    if not glob(os.path.join(dir, 'src', library, '*.cpp')):
      return False
  
    return True

  f = open(path)
  line = f.readline()
  f.close()
  
  return line.startswith('# GENERATED')
  
for l, d in libraryDependencies.items():
  if isIncludeGenerated(l):
    generateInclude(l, d)
  if isBuildGenerated(l):
    generateBuild(l, d)