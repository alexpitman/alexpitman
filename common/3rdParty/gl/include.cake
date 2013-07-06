from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("include"))

compiler.addLibrary(script.cwd("lib/glu32.lib"))
compiler.addLibrary(script.cwd("lib/opengl32.lib"))