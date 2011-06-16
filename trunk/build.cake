from cake.tools import compiler, script, shell, filesys

filesys.copyFiles(
  sources=script.cwd([
    "common/3rdParty/qt/lib/QtCore4.lib",
    "common/3rdParty/qt/lib/QtOpenGL4.lib",
    "common/3rdParty/qt/lib/QtGui4.lib",
    "common/3rdParty/qt/lib/qtmain.lib",
    "common/3rdParty/directx/lib/XInput.lib",
  ]),
  targetDir=script.cwd("build/testbed/lib"),
  )

# Build libraries
script.include(script.cwd("common/src/system/use.cake"))
script.include(script.cwd("common/src/numeric/use.cake"))
script.include(script.cwd("common/src/attribute/use.cake"))
script.include(script.cwd("common/src/geometry/use.cake"))
script.include(script.cwd("common/src/topology/use.cake"))
script.include(script.cwd("common/src/input/use.cake"))
script.include(script.cwd("common/src/camera/use.cake"))
script.include(script.cwd("common/src/viewer/use.cake"))
script.include(script.cwd("common/src/widget/use.cake"))

compiler.addDefine("QT_DLL")
compiler.addIncludePath("common/include")
compiler.addLibrary(script.cwd("common/3rdParty/qt/lib/QtCore4.lib"))
compiler.addLibrary(script.cwd("common/3rdParty/qt/lib/QtGui4.lib"))

# Build the main program.
main_source = script.cwd([
  "testbed/main.cpp",
  ])
	
main_objects = compiler.objects(
  targetDir=script.cwd("build/testbed/obj/"),
  sources=main_source,
  )
	
main_program = compiler.program(
  target=script.cwd("build/testbed/bin/main"),
  sources=main_objects,
  )

# Copy binaries
filesys.copyFiles(
  sources=script.cwd([
    "common/3rdParty/gl/bin/opengl32.dll",
    "common/3rdParty/gl/bin/glu32.dll",
    "common/3rdParty/qt/bin/QtCore4.dll",
    "common/3rdParty/qt/bin/QtOpenGL4.dll",
    "common/3rdParty/qt/bin/QtGui4.dll",
  ]),
  targetDir=script.cwd("build/testbed/bin"),
  )
	
# Execute the program
shell.run(
  args=[main_program.path],
  targets=[],
  sources=[main_program],
  )