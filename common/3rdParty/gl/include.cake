from cake.tools import compiler, script, filesys

compiler.addIncludePath(script.cwd("include"))

compiler.addLibrary(script.cwd("lib/glu32.lib"))
compiler.addLibrary(script.cwd("lib/opengl32.lib"))
compiler.addLibrary(script.cwd("lib/glew32.lib"))

# Copy binaries
filesys.copyFiles(
  sources=script.cwd([
    "bin/opengl32.dll",
    "bin/glu32.dll",
    "bin/glew32.dll",
  ]),
  targetDir=script.cwd("../../../build/testbed/bin"),
  )