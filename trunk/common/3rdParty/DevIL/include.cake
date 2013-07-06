from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("include"))

compiler.addLibrary(script.cwd("lib/DevIL.lib"))