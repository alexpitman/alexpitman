from cake.engine import Script
from cake.library.compilers.msvc import findMsvcCompiler
from cake.library.shell import ShellTool
from cake.library.filesys import FileSystemTool
from cake.filesys import makeDirs

script = Script.getCurrent()
compiler = findMsvcCompiler(script.configuration, '8.0', 'x86')
shell = ShellTool(script.configuration)
filesys = FileSystemTool(script.configuration)

# Set up compiler flags
compiler.addCppFlag("/EHsc")

# Set up include paths
compiler.addIncludePath("common/include")
compiler.addIncludePath("common/3rdParty/boost/include")
compiler.addIncludePath("common/3rdParty/gl/include")
compiler.addIncludePath("common/3rdParty/qt/include")
compiler.addIncludePath("common/3rdParty/qt/include/QtCore")
compiler.addIncludePath("common/3rdParty/qt/include/QtGui")
compiler.addIncludePath("common/3rdParty/qt/include/QtOpenGL")

# Copy libraries
filesys.copyFiles(
  sources=script.cwd([
#    "common/3rdParty/gl/lib/GIU32.Lib",
    "common/3rdParty/qt/lib/QtCore4.lib",
    "common/3rdParty/qt/lib/QtOpenGL4.lib",
    "common/3rdParty/qt/lib/QtGui4.lib",
    "common/3rdParty/qt/lib/qtmain.lib",
  ]),
  targetDir=script.cwd("build/testbed/lib"),
  )

#compiler.addDefine("QT_DLL")

makeDirs("build/common/moc/widget")
#makeDirs("build/common/headers/widget")
#makeDirs("build/common/src/widget")

# Build the moc files
#shell.run(
#  args=[
#    script.cwd("common/3rdParty/qt/bin/moc.exe"), 
#    "-I", script.cwd("common/include"),
#    "-i", script.cwd("common/src/widget/ViewWindow.cpp"),
#    "-o", script.cwd("build/common/src/widget/ViewWindow.cpp") ],
#  targets=[],
#  sources=[],
#  )
shell.run(
  args=[
    script.cwd("common/3rdParty/qt/bin/moc.exe"), 
    "-i", script.cwd("common/include/widget/GLWidget.h"),
    "-o", script.cwd("build/common/moc/widget/mGLWidget.cpp"), "-f" ],
  targets=[],
  sources=[],
  )
shell.run(
  args=[
    script.cwd("common/3rdParty/qt/bin/moc.exe"), 
    "-i", script.cwd("common/include/widget/ViewWindow.h"),
    "-o", script.cwd("build/common/moc/widget/mViewWindow.cpp"), "-f" ],
  targets=[],
  sources=[],
  )
  
#compiler.addIncludePath("build/common/headers")
  
compiler.addLibraryPath("build/testbed/lib")
compiler.addLibrary("opengl32.Lib")
compiler.addLibrary("glu32.Lib")
compiler.addLibrary("QtCore4.lib")
compiler.addLibrary("QtOpenGL4.lib")
compiler.addLibrary("QtGui4.lib")
compiler.addLibrary("qtmain.lib")

#script.include(script.cwd("common/use-geometry.cake"))

# List of sources.
sources = script.cwd([
  "testbed/main.cpp",
  ])

gsources = script.cwd([
  "common/src/attribute/Colour.cpp",
  "common/src/camera/Camera.cpp",
  "common/src/camera/CameraController.cpp",
  "common/src/geometry/Point.cpp",
  "common/src/geometry/Vector.cpp",
  "common/src/geometry/Extent.cpp",
  "common/src/geometry/Rotation.cpp",
  "common/src/geometry/Transform.cpp",
  "common/src/input/Key.cpp",
  "common/src/input/Mouse.cpp",
  "common/src/input/InputController.cpp",
  "common/src/numeric/num.cpp",
  "common/src/renderer/Factory.cpp",
  "common/src/renderer/Renderer.cpp",
  "common/src/widget/ViewWindow.cpp",
  "common/src/widget/GLWidget.cpp",
  "common/src/viewer/View.cpp",
  "common/src/viewer/ViewHandler.cpp",
  "build/common/moc/widget/mViewWindow.cpp",
  "build/common/moc/widget/mGLWidget.cpp",
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