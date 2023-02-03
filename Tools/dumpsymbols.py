import diff
import check
import sys
import os

def main():
    sym_files = []
    for subdir, dirs, files in os.walk('Symbols'):
        for file in files:
            sym_files.append((subdir, file))

    syms = []
    for file in sym_files:
        filesyms = diff.read_sym_file(file[0] + "/" + file[1])
        for sym in filesyms:
            syms.append(sym)
            
    syms.sort(key=lambda a: a[1])
    for sym in syms:
        a = "{:08x}".format(sym[1])
        print(f"{sym[0]},{a},{sym[3]},{sym[2]}")

if __name__ == "__main__":
    main()