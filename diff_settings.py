import os

def apply(config, args):
    config["baseimg"] = "code.bin"
    config["myimg"] = "Build/RedPepper.axf"
    config["source_directories"] = ["."]
    config["arch"] = "armel"
    config["arch_objdump"] = "arm"
    config["objdump_executable"] = os.environ.get('DEVKITARM') + "/bin/arm-none-eabi-objdump"