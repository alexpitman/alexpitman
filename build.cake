from cake.tools import compiler, script, shell, filesys
  
# Dependent libraries
script.include(script.cwd("common/src/widget/include.cake"))
script.include(script.cwd("common/src/export/include.cake"))

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

# Execute the program
shell.run(
  args=[main_program.path],
  targets=[],
  sources=[main_program],
  )