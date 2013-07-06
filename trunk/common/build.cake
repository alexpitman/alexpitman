from cake.tools import script
from os import path
from glob import glob

allLibraryBuildFiles = glob(path.join(script.cwd(), "src/*/build.cake"))

for buildFile in allLibraryBuildFiles:
  script.execute(buildFile)
