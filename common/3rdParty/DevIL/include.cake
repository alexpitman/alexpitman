from cake.tools import compiler, script, filesys

compiler.addIncludePath(script.cwd("include"))

compiler.addLibrary(script.cwd("lib/DevIL.lib"))

# Copy binaries
filesys.copyFiles(
  sources=script.cwd([
    "bin/DevIL.dll",
  ]),
  targetDir=script.cwd("../../../build/testbed/bin"),
  )