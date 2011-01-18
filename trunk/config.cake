# config.cake

# First import some classes we'll need
from cake.engine import Script, Variant

# Every cake script that is executed has a corresponding Script object.
# You can find the currently executing script like this.
script = Script.getCurrent()

# Each Cake script is executed in the context of a Configuration object.
# We can obtain the Configuration object via a property of the Script.
configuration = script.configuration

# Create a new Variant
variant = Variant()

# And register it with the Configuration
configuration.addVariant(variant)
