# config.cake
from cake.library.script import ScriptTool
from cake.library.filesys import FileSystemTool
from cake.library.variant import VariantTool
from cake.library.shell import ShellTool
from cake.library.compilers.msvc import findMsvcCompiler
import os

# First import some classes we'll need
from cake.engine import Script, Variant

# Every cake script that is executed has a corresponding Script object.
# You can find the currently executing script like this.
script = Script.getCurrent()
configuration = script.configuration

# Each Cake script is executed in the context of a Configuration object.
# We can obtain the Configuration object via a property of the Script.
configuration = script.configuration

# Create a new Variant
base = Variant()

base.tools["script"] = ScriptTool(configuration=configuration)
filesys = base.tools["filesys"] = FileSystemTool(configuration=configuration)
base.tools["variant"] = VariantTool(configuration=configuration)
shell = base.tools["shell"] = ShellTool(configuration=configuration)
shell.update(os.environ)
compiler = base.tools["compiler"] = findMsvcCompiler(script.configuration, '14.0', 'x86')

# Set up compiler flags
compiler.addCppFlag("/EHsc")

# debug
compiler.addCppFlag("/bigobj")
compiler.addCppFlag("/c")
compiler.addCppFlag("/MDd")
compiler.addCppFlag("/LDd")
compiler.debugSymbols = True

# And register it with the Configuration
configuration.addVariant(base)
