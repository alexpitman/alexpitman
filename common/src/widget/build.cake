#-------------------------------------------------------------------------------
# Script used to build the widget library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script, shell
from cake.filesys import makeDirs

# include dependencies
script.include(script.cwd("../geometry/use.cake"))
script.include(script.cwd("../viewer/use.cake"))
script.include(script.cwd("../scenetree/use.cake"))
script.include(script.cwd("../input/use.cake"))

compiler.addIncludePath(script.cwd("../../include"))
compiler.addIncludePath(script.cwd("../../3rdParty/boost/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/gl/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include/QtCore"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include/QtGui"))
compiler.addIncludePath(script.cwd("../../3rdParty/qt/include/QtOpenGL"))
compiler.addDefine("WID_DLL")
compiler.addDefine("QT_DLL")
compiler.addLibrary(script.cwd("../../3rdParty/qt/lib/QtCore4.lib"))
compiler.addLibrary(script.cwd("../../3rdParty/qt/lib/QtGui4.lib"))
compiler.addLibrary(script.cwd("../../3rdParty/qt/lib/QtOpenGL4.lib"))

moc_exe = script.cwd("../../3rdParty/qt/bin/moc.exe")

moc_files = [
	"GLWidget",
	"ViewWindow",
	]

source = []

# Build the moc files
makeDirs(script.cwd("../../../build/testbed/moc/widget"))
for f in moc_files:
	h_file = script.cwd("../../include/widget/" + f + ".h")
	moc_file = script.cwd("../../../build/testbed/moc/widget/m" + f + ".cpp")
	cpp_file = script.cwd(f + ".cpp")

	shell.run(
		args=[
			moc_exe, 
			"-i", h_file,
			"-o", moc_file, "-f" ],
		targets=[],
		sources=[],
  )
	
	source.append(moc_file)
	source.append(cpp_file)
	
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
