from diff import *
from settings import *

def genLDScript():
    replace_data = '.text : {\n'
    syms = []
    for subdir, dirs, files in os.walk('Symbols'):
        for file in files:
            if "Unnamed.sym" in file:
                continue
            filepath = os.path.join(subdir, file)
            syms += read_sym_file(filepath)
    syms = sorted(syms, key=lambda tup: tup[1])
    for sym in syms:
        if sym[2] != 'U':
            replace_data += "\t\t*(i." + sym[0] + ")\n"
    replace_data += '\t}'

    with open('Data/Linker.ld', 'r') as template:
        with open(f'{getBuildPath()}/Linker.ld', 'w') as out:
            out.write(template.read().replace("$$$", replace_data))
            
def main():
    genLDScript()

if __name__ == '__main__':
    main()