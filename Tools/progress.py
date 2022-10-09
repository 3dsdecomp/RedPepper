from time import sleep
from diff import *
from colorama import Fore
import json

def main():

    syms_undefined = 0
    syms_major = 0
    syms_minor = 0
    syms_ok = 0
    syms_total = 0
    addrs = []
    addrs_changed = False

    unnamed_syms = read_sym_file('Symbols/Unnamed.sym')
    for sym in unnamed_syms:
        addrs.append(sym[1])

    for subdir, dirs, files in os.walk('Symbols'):
        for file in files:
            filepath = os.path.join(subdir, file)
            syms = read_sym_file(filepath)
            for sym in syms:
                if "Unnamed.sym" not in file and sym[1] in addrs:
                    addrs.remove(sym[1])
                    print("Unnamed function at " + "{:08x}".format(sym[1]) + " moved to " + sym[0])
                    addrs_changed = True
                    syms_undefined -= 1
                    syms_total -= 1
                syms_total += 1
                match sym[2]:
                    case 'U':
                        syms_undefined += 1
                    case 'M':
                        syms_major += 1
                    case 'm':
                        syms_minor += 1
                    case 'O':
                        syms_ok += 1

    def percentage(amount: int):
        return (amount / syms_total) * 100;
    def print_type(name: str, amount: int, number_color: Fore):
        print(name + ": " + (32 - len(name) - 2 ) * " " + number_color + str(amount) + Fore.RESET + " (" + number_color + "{:.2f}%".format(percentage(amount)) + Fore.RESET + ")")
    def write_type(rank: str, name: str, amount: int, color: str):
        out = {
            "label": name,
            "message": "{:.2f}%".format(percentage(amount)),
            "color": color,
            "schemaVersion": 1
        }
        with open('Data/' + rank + '.json','w') as f:
            f.write(json.dumps(out))


    print_type("Total Functions", syms_total, Fore.RESET);
    print_type("Decompiled", syms_ok, Fore.GREEN);
    print_type("Non-matching (minor problems)", syms_minor, Fore.YELLOW);
    print_type("Non-matching (major problems)", syms_major, Fore.RED);
    print_type("Not decompiled", syms_undefined, Fore.RESET);
    print_type("Non-matching/Not decompiled", syms_undefined + syms_major + syms_minor, Fore.LIGHTRED_EX);

    write_type('OK', "Decompiled", syms_ok, "success");
    write_type('NonMatchingMinor',"Non-matching (minor problems)", syms_minor, "yellow");
    write_type('NonMatchingMajor', "Non-matching (major problems)", syms_major, "critical");
    write_type('NonMatchingDecompiled', "Non-matching/Not decompiled", syms_undefined + syms_major + syms_minor, "critical");
    write_type('NotDecompiled', "Not decompiled", syms_undefined, "lightgrey");

    if addrs_changed:
        print("Rewriting Unnamed.sym, do not interrupt", end='\r')
        with open('Symbols/Unnamed.sym', 'w') as f:
            for addr in addrs:
                addr_str = "{:08x}".format(addr)
                f.write("FUN_" + addr_str + "," + addr_str + ",4,U\n")


if __name__ == "__main__":
    main()