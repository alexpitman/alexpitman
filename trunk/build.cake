from cake.engine import Script
from cake.library.compilers.msvc import findMsvcCompiler
from cake.library.shell import ShellTool
from cake.library.filesys import FileSystemTool
from cake.filesys import makeDirs

script = Script.getCurrent()
compiler = findMsvcCompiler(script.configuration, '10.0', 'x86')
shell = ShellTool(script.configuration)
filesys = FileSystemTool(script.configuration)

# Set up compiler flags
compiler.addCppFlag("/EHsc")

# debug
compiler.addCppFlag("/Zi")
compiler.addCppFlag("/MDd")
compiler.addCppFlag("/LDd")

# Set up include paths
compiler.addIncludePath("common/include")
compiler.addIncludePath("common/3rdParty/boost/include")
compiler.addIncludePath("common/3rdParty/gl/include")
compiler.addIncludePath("common/3rdParty/qt/include")
compiler.addIncludePath("common/3rdParty/qt/include/QtCore")
compiler.addIncludePath("common/3rdParty/qt/include/QtGui")
compiler.addIncludePath("common/3rdParty/qt/include/QtOpenGL")
compiler.addIncludePath("common/3rdParty/directx/include")

# Copy libraries
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
  
compiler.addLibraryPath("build/testbed/lib")
compiler.addLibrary("opengl32.Lib")
compiler.addLibrary("glu32.Lib")
compiler.addLibrary("QtCore4.lib")
compiler.addLibrary("QtOpenGL4.lib")
compiler.addLibrary("QtGui4.lib")
compiler.addLibrary("qtmain.lib")
compiler.addLibrary("XInput.lib")

mainCompiler = compiler.clone()

# Set up compiler defines
compiler.addDefine("QT_DLL")
compiler.addDefine("DLL")

# Build the objects/libs/dlls.
num_source = script.cwd([
	"common/src/numeric/num.cpp",
	])

num_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/numeric"),
	sources=num_source,
	)

num_module = compiler.module(
	target=script.cwd("build/testbed/bin/numeric.dll"),
	sources=num_objects,
	)

num_lib = script.cwd("build/testbed/bin/numeric.lib")
	
geo_source = script.cwd([
	"common/src/geometry/Point.cpp",
  "common/src/geometry/Vector.cpp",
  "common/src/geometry/Extent.cpp",
  "common/src/geometry/Rotation.cpp",
  "common/src/geometry/Transform.cpp",
	])

geo_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/geometry"),
	sources=geo_source,
	prerequisites=[num_module]
	)

geo_module = compiler.module(
	target=script.cwd("build/testbed/bin/geometry.dll"),
	sources=[geo_objects, num_lib],
	)
	
geo_lib = script.cwd("build/testbed/bin/geometry.lib")
	
tpo_source = script.cwd([
	"common/src/topology/Triple.cpp",
	])
	
tpo_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/topology"),
	sources=tpo_source,
	prerequisites=[geo_module]
	)
	
tpo_module = compiler.module(
	target=script.cwd("build/testbed/bin/topology.dll"),
	sources=[tpo_objects, geo_lib],
	)
	
tpo_lib = script.cwd("build/testbed/bin/topology.lib")

att_source = script.cwd([
	"common/src/attribute/Colour.cpp",
	])
	
att_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/attribute"),
	sources=att_source,
	)
	
att_module = compiler.module(
	target=script.cwd("build/testbed/bin/attribute.dll"),
	sources=[att_objects],
	)
	
att_lib = script.cwd("build/testbed/bin/attribute.lib")

obj_source = script.cwd([
	"common/src/object/FacetNetwork.cpp",
	])
	
obj_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/object"),
	sources=obj_source,
	prerequisites=[geo_module, tpo_module]
	)
	
obj_module = compiler.module(
	target=script.cwd("build/testbed/bin/object.dll"),
	sources=[obj_objects, geo_lib, tpo_lib],
	)
	
obj_lib = script.cwd("build/testbed/bin/object.lib")

st_source = script.cwd([
	"common/src/scenetree/Light.cpp",
	"common/src/scenetree/Node.cpp",
	"common/src/scenetree/SceneTreeNode.cpp",
	"common/src/scenetree/FacetNetworkNode.cpp",
	])
	
st_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/scenetree"),
	sources=st_source,
	prerequisites=[geo_module, att_module, tpo_module, obj_module]
	)
	
st_module = compiler.module(
	target=script.cwd("build/testbed/bin/scenetree.dll"),
	sources=[st_objects, geo_lib, att_lib, tpo_lib, obj_lib],
	)
	
st_lib = script.cwd("build/testbed/bin/scenetree.lib")

cmr_source = script.cwd([
	"common/src/camera/Camera.cpp",
	"common/src/camera/CameraController.cpp",
	])
	
cmr_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/camera"),
	sources=cmr_source,
	prerequisites=[geo_module, st_module]
	)
	
cmr_module = compiler.module(
	target=script.cwd("build/testbed/bin/camera.dll"),
	sources=[cmr_objects, geo_lib, st_lib],
	)
	
cmr_lib = script.cwd("build/testbed/bin/camera.lib")

ree_source = script.cwd([
	"common/src/renderer/Factory.cpp",
	"common/src/renderer/Renderer.cpp",
	])
	
ree_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/renderer"),
	sources=ree_source,
	)
	
ree_module = compiler.module(
	target=script.cwd("build/testbed/bin/renderer.dll"),
	sources=[ree_objects],
	)
	
ree_lib = script.cwd("build/testbed/bin/renderer.lib")

in_source = script.cwd([
	"common/src/input/Key.cpp",
	"common/src/input/Mouse.cpp",
	"common/src/input/XBox.cpp",
	])
	
in_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/input"),
	sources=in_source,
	prerequisites=[geo_module, st_module, cmr_module]
	)
	
in_module = compiler.module(
	target=script.cwd("build/testbed/bin/input.dll"),
	sources=[in_objects, geo_lib, st_lib, cmr_lib],
	)
	
in_lib = script.cwd("build/testbed/bin/input.lib")

vwr_source = script.cwd([
	"common/src/viewer/View.cpp",
	"common/src/viewer/ViewHandler.cpp",
	"common/src/viewer/InputController.cpp",
	])
	
vwr_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/viewer"),
	sources=vwr_source,
	prerequisites=[geo_module, tpo_module, att_module, in_module, ree_module, st_module, cmr_module, obj_module]
	)
	
vwr_module = compiler.module(
	target=script.cwd("build/testbed/bin/viewer.dll"),
	sources=[vwr_objects, geo_lib, tpo_lib, att_lib, in_lib, ree_lib, st_lib, cmr_lib, obj_lib ],
	)
	
vwr_lib = script.cwd("build/testbed/bin/viewer.lib")

# Build the moc files
makeDirs("build/testbed/moc/widget")
shell.run(
  args=[
    script.cwd("common/3rdParty/qt/bin/moc.exe"), 
    "-i", script.cwd("common/include/widget/GLWidget.h"),
    "-o", script.cwd("build/testbed/moc/widget/mGLWidget.cpp"), "-f" ],
  targets=[],
  sources=[],
  )
shell.run(
  args=[
    script.cwd("common/3rdParty/qt/bin/moc.exe"), 
    "-i", script.cwd("common/include/widget/ViewWindow.h"),
    "-o", script.cwd("build/testbed/moc/widget/mViewWindow.cpp"), "-f" ],
  targets=[],
  sources=[],
  )

qt_lib = script.cwd([
	"build/testbed/lib/QtCore4.lib",
	"build/testbed/lib/QtOpenGL4.lib",
	"build/testbed/lib/QtGui4.lib",
	"build/testbed/lib/qtmain.lib",
	])

wid_source = script.cwd([
	"common/src/widget/ViewWindow.cpp",
  "common/src/widget/GLWidget.cpp",
	"build/testbed/moc/widget/mViewWindow.cpp",
  "build/testbed/moc/widget/mGLWidget.cpp",
	])

wid_objects = compiler.objects(
	targetDir=script.cwd("build/testbed/obj/widget"),
	sources=wid_source,
	prerequisites=[geo_module, vwr_module, st_module, in_module]
	)
	
wid_module = compiler.module(
	target=script.cwd("build/testbed/bin/widget.dll"),
	sources=[wid_objects, geo_lib, vwr_lib, st_lib, in_lib],
	)
	
wid_lib = script.cwd("build/testbed/bin/widget.lib")

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

# Build the main program.
main_source = script.cwd([
  "testbed/main.cpp",
  ])
	
main_objects = mainCompiler.objects(
  targetDir=script.cwd("build/testbed/obj/"),
  sources=main_source,
	prerequisites=[geo_module, ree_module, st_module, wid_module]
  )
	
main_program = mainCompiler.program(
  target=script.cwd("build/testbed/bin/main"),
  sources=[main_objects, geo_lib, ree_lib, st_lib, wid_lib],
  )

# Execute the program
shell.run(
  args=[main_program.path],
  targets=[],
  sources=[main_program],
  )