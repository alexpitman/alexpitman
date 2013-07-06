from cake.tools import compiler, script, shell, filesys

compiler.addDefine("QT_DLL")

compiler.addIncludePath(script.cwd("include"))
compiler.addIncludePath(script.cwd("include/QtCore"))
compiler.addIncludePath(script.cwd("include/QtGui"))
compiler.addIncludePath(script.cwd("include/QtOpenGL"))

compiler.addLibrary(script.cwd("lib/QtCore4.lib"))
compiler.addLibrary(script.cwd("lib/QtGui4.lib"))
compiler.addLibrary(script.cwd("lib/QtOpenGL4.lib"))

# Copy binaries
filesys.copyFiles(
  sources=script.cwd([
    "bin/QtCore4.dll",
    "bin/QtOpenGL4.dll",
    "bin/QtGui4.dll",
  ]),
  targetDir=script.cwd("../../../build/testbed/bin"),
  )


  