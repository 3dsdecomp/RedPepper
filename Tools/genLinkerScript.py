from diff import *
from settings import *

def genLDScript():
    matching_data = '\n'
    syms = []
    for subdir, dirs, files in os.walk('Symbols'):
        for file in files:
            if "Unnamed.sym" in file:
                continue
            filepath = os.path.join(subdir, file)
            syms += read_sym_file(filepath)
    syms = sorted(syms, key=lambda tup: tup[1])
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

    with open('Data/Linker.ld', 'r') as template:
        with open(f'{getBuildPath()}/Linker.ld', 'w') as out:
            out.write(template.read().replace("$$$", matching_data))
            
def main():
    genLDScript()

if __name__ == '__main__':
    main()