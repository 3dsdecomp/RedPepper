# RedPepper

This is a decompilation of the EU version of Super Mario 3D Land.

### Setup

You will need:

- devkitARM

- RVCT v4.0 Build 821

Set the environment variable `DEVKITARM` to the path of devkitARM (the path that contains the 'bin' folder) and `ARMCC_PATH` to the path of the folder that contains the 'bin' folder of RVCT (need armasm.exe, armar.exe, armcc_4.exe)

Place the game's code.bin in the root folder of the repository (sha256sum is e1d7e188ff88467df776c17cec45c44857fadf5b699944baa8cddcae7d939e64)

Run:

```
mkdir Build
cd Build
cmake ..
```

Then use `make` to build the project.