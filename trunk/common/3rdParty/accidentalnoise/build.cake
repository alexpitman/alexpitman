#-------------------------------------------------------------------------------
# Script used to build the accidenal noise library.
#-------------------------------------------------------------------------------
from cake.tools import compiler, script

compiler.addIncludePath(script.cwd("include"))

source = script.cwd([
  "src/cellulargen.cpp",
  "src/hsv.cpp",
  "src/implicitautocorrect.cpp",
  "src/implicitbasisfunction.cpp",
  "src/implicitbias.cpp",
  "src/implicitblend.cpp",
  "src/implicitbrightcontrast.cpp",
  "src/implicitcache.cpp",
  "src/implicitcellular.cpp",
  "src/implicitclamp.cpp",
  "src/implicitcombiner.cpp",
  "src/implicitconstant.cpp",
  "src/implicitcos.cpp",
  "src/implicitextractrgbachannel.cpp",
  "src/implicitfloor.cpp",
  "src/implicitfractal.cpp",
  "src/implicitfunctiongradient.cpp",
  "src/implicitgain.cpp",
  "src/implicitgradient.cpp",
  "src/implicitinvert.cpp",
  "src/implicitpow.cpp",
  "src/implicitrgbadotproduct.cpp",
  "src/implicitrotatedomain.cpp",
  "src/implicitscaledomain.cpp",
  "src/implicitscaleoffset.cpp",
  "src/implicitselect.cpp",
  "src/implicitsin.cpp",
  "src/implicitsphere.cpp",
  "src/implicittiers.cpp",
  "src/implicittranslatedomain.cpp",
  "src/mapping.cpp",
  "src/noise_gen.cpp",
  "src/noise_lut.cpp",
  "src/rgbablend.cpp",
  "src/rgbablendops.cpp",
  "src/rgbacomposechannels.cpp",
  "src/rgbaconstant.cpp",
  "src/rgbahsvtorgba.cpp",
  "src/rgbaimplicitgrayscale.cpp",
  "src/rgbanormalize.cpp",
  "src/rgbargbatohsv.cpp",
  "src/rgbarotatecolor.cpp",
  "src/rgbaselect.cpp",
  ])

objects = compiler.objects(
  targetDir=script.cwd("obj"),
  sources=source,
  )

lib = compiler.library(
  target=script.cwd("lib/accidentalnoise.lib"),
  sources=objects,
  )

script.setResult(library=lib)
