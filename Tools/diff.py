from io import StringIO
import subprocess
import csv
import os
import sys

def fail(msg: str):
    print(msg)
    sys.exit(1)

readelf_data = str(subprocess.check_output(f"{os.environ.get('DEVKITARM')}/bin/arm-none-eabi-readelf Build/RedPepper.axf -sw -W", shell=True)).replace(r'\n', '\n')
def get_elf_symbol(sym_name: str):
    s = StringIO(readelf_data)
    for line in s:
        if sym_name in line:
            arr = line.split()
            return (int(arr[1], 16), int(arr[2]))
    return None

def read_sym_file(file: str):
    with open(file, newline='') as f:
        syms = []
        reader = csv.reader(f, delimiter=',',quotechar='"')
        for row in reader:
            syms.append((row[0], int(row[1], 16), row[3], row[2]))
        return syms

def get_symbol(symbol: str):
    for subdir, dirs, files in os.walk('Symbols'):
        for file in files:
            syms = read_sym_file(os.path.join(subdir, file))
            for sym in syms:
                if sym[0] == symbol:
                    return sym
    return None

def rank_symbol(sym, decomp_sym):
    out = str(subprocess.check_output(f"Tools/asm-differ/diff.py --format json {sym[1] - 0x00100000} {decomp_sym[0]} {sym[3]} {decomp_sym[1]}", shell=True))

    rank = 'O'
    if "diff_change" in out:
        rank = 'm'
    if "diff_add" in out or "diff_remove" in out:
        if out.count('diff_add') == out.count('diff_remove'):
            rank = 'm'
        else:
            rank = 'M'
    
    return rank


def main() -> None:
    if len(sys.argv) != 2:
        fail("diff.py <symbol>")
    symbolname = sys.argv[1]

    symbol = get_symbol(symbolname)
    decomp_symbol = get_elf_symbol(symbolname)

    if (symbol is None):
        fail("Couldn't find symbol")
    if (decomp_symbol[1] is None):
        fail("Couldn't find decomp symbol")

    subprocess.run(f"Tools/asm-differ/diff.py {symbol[1] - 0x00100000} {decomp_symbol[0]} {symbol[3]} {decomp_symbol[1]}", shell=True)



if __name__ == "__main__":
    main()