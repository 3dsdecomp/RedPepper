from diff import *
from settings import *

def read_data_sym_file(file: str):
    with open(file, newline='') as f:
        syms = []
        reader = csv.reader(f, delimiter=',',quotechar='"')
        for row in reader:
            syms.append((row[0], int(row[1], 16)))
        return syms

def genLDScript():
    matching_data = '\n'
    const_data = '\n'
    syms = []
    data_syms = []
    for subdir, dirs, files in os.walk('Symbols'):
        for file in files:
            if "Unnamed.sym" in file:
                continue
            filepath = os.path.join(subdir, file)
            syms += read_sym_file(filepath)
    for subdir, dirs, files in os.walk('DataSymbols'):
        for file in files:
            filepath = os.path.join(subdir, file)
            data_syms += read_data_sym_file(filepath)
    syms = sorted(syms, key=lambda tup: tup[1])
    data_syms = sorted(data_syms, key=lambda tup: tup[1])
    for sym in syms:
        if (sym[2] == 'm' or sym[2] == 'O') and sym[0]:
            matching_data += sym[0] + " " + "0x{:08x}\n".format(sym[1])
            matching_data += "{\n"
            matching_data += "\t" + sym[0] + " " + "0x{:08x}\n".format(sym[1])
            matching_data += "\t{\n"
            if len(sym) == 5 and sym[4] == "gdef":
                matching_data += "\t\t* (:gdef:" + sym[0] + ")\n"
            else:
                matching_data += "\t\t* (i." + sym[0] + ")\n"
            matching_data += "\t}\n"
            matching_data += "}\n"
    for sym in data_syms:
        const_data += sym[0] + " " + "0x{:08x}\n".format(sym[1])
        const_data += "{\n"
        const_data += "\t" + sym[0] + " " + "0x{:08x}\n".format(sym[1])
        const_data += "\t{\n"
        const_data += "\t\t* (" + sym[0] + ")\n"
        const_data += "\t}\n"
        const_data += "}\n"

    with open('Data/Linker.ld', 'r') as template:
        with open(f'{getBuildPath()}/Linker.ld', 'w') as out:
            out.write(template.read().replace("$$$", matching_data).replace("§§§", const_data))
            
def main():
    genLDScript()

if __name__ == '__main__':
    main()