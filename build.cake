from cake.engine import Script
from cake.library.compilers.msvc import findMsvcCompiler
from cake.library.shell import ShellTool
from cake.library.filesys import FileSystemTool

script = Script.getCurrent()
compiler = findMsvcCompiler(script.configuration, '8.0', 'x86')
shell = ShellTool(script.configuration)
filesys = FileSystemTool(script.configuration)

# Set up compiler flags
compiler.addCppFlag("/EHsc")

# Set up include paths
compiler.addIncludePath("common/include")
compiler.addIncludePath("common/3rdParty/gl/include")
compiler.addIncludePath("common/3rdParty/qt/include")
compiler.addIncludePath("common/3rdParty/qt/include/QtGui")
compiler.addIncludePath("common/3rdParty/qt/include/QtOpenGL")

#script.include(script.cwd("common/use-geometry.cake"))

# List of sources.
sources = script.cwd([
  "testbed/main.cpp",
  ])

gsources = script.cwd([
  "common/src/attribute/Colour.cpp",
  "common/src/geometry/Point.cpp",
  "common/src/geometry/Vector.cpp",
  "common/src/geometry/Extent.cpp",
  "common/src/renderer/Factory.cpp",
  "common/src/renderer/Renderer.cpp",
  "common/src/widget/ViewWindow.cpp",
  "common/src/widget/GLWidget.cpp",
  "common/src/viewer/View.cpp",
  ])

# Build the objects.
objects = compiler.objects(
  targetDir=script.cwd("build/testbed/obj/"),
  sources=sources,
  )

gobjects = compiler.objects(
  targetDir=script.cwd("build/common/obj"),
  sources=gsources,
  )

# Copy libraries
filesys.copyFiles(
  sources=script.cwd([
#    "common/3rdParty/gl/lib/GIU32.Lib",
    "common/3rdParty/qt/lib/QtCore4.lib",
    "common/3rdParty/qt/lib/QtOpenGL4.lib",
    "common/3rdParty/qt/lib/QtGui4.lib",
  ]),
  targetDir=script.cwd("build/testbed/lib"),
  )

compiler.addLibraryPath("build/testbed/lib")
compiler.addLibrary("opengl32.Lib")
compiler.addLibrary("glu32.Lib")
compiler.addLibrary("QtCore4.lib")
compiler.addLibrary("QtOpenGL4.lib")
compiler.addLibrary("QtGui4.lib")

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

# Build the program.
program = compiler.program(
  target=script.cwd("build/testbed/bin/main"),
  sources=[objects, gobjects],
  )

# Execute the program
shell.run(
  args=[program.path],
  targets=[],
  sources=[program],
  )