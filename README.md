# RedPepper

This is a decompilation of the EU version of Super Mario 3D Land.

## Progress

<img src ="https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/fruityloops1/RedPepper/master/Data/OK.json&style=flat-square"/> <img src ="https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/fruityloops1/RedPepper/master/Data/DecompiledNonMatching.json&style=flat-square"/>

<img src ="https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/fruityloops1/RedPepper/master/Data/NonMatchingMinor.json&style=flat-square"/> <img src ="https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/fruityloops1/RedPepper/master/Data/NonMatchingMajor.json&style=flat-square"/>


## Setup

You will need:

- devkitARM

- ARM C/C++ Compiler, 4.1 [Build 1049]

Set the environment variable `DEVKITARM` to the path of devkitARM (the path that contains the 'bin' folder) and `ARMCC_PATH` to the path of the folder that contains the 'bin' folder of ARMCC (need armasm.exe, armar.exe, armcc.exe)

Place the game's code.bin in the root folder of the repository (sha256sum is `e1d7e188ff88467df776c17cec45c44857fadf5b699944baa8cddcae7d939e64`)

Run `Tools/build.py (verbose/clean)` to build the project.

See [DECOMPILING.md](DECOMPILING.md) for instructions on how to decompile functions.