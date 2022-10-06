# Decompiling Functions

Add your function in a .sym file in the Symbols folder, in this format:

`_Z8functionv,ADDRESS,FUNCTIONSIZE,STATUS`

Note that the base of ADDRESS is at 0x00100000

STATUS can be 4 things:

- `O`: OK
  - The function is matching
- `m`: Minor problems
  - The function is mismatching with the same size as the original
- `M`:  Major problems
  - The function is mismatching with a different size than the original
- `U`: Undecompiled
  - The function is not defined

You don't have to input STATUS manually, `Tools/check.py` will automatically rank it for you, so just use 'U' when adding new functions.

Your function should now be placed in a .cpp file that is equivalent to the symbol file path, e.g. `Path/To/Object.sym` -> `Path/To/Object.cpp` 

If your function is not marked as OK, wrap it in an `#ifdef NON_MATCHING`, and explain which part of the function is mismatching in a comment, if you can.



(note: if you add a .cpp file, you will have to modify/touch the CMakeLists.txt file for it to compile the new .cpp file)