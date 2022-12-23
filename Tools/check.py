from diff import *
from colorama import Fore
import multiprocessing
import threading
import time
import shutil

def getRankName(rank: str):
    match rank:
        case 'O':
            return Fore.GREEN + "OK" + Fore.RESET
        case 'm':
            return Fore.YELLOW + "Minor problems" + Fore.RESET
        case 'M':
            return Fore.RED + "Major problems" + Fore.RESET
        case 'U':
            return "Undecompiled"
    return '?'

def clear_line():
    print(' ' * shutil.get_terminal_size((80, 20)).columns, end='\r')

def check_file(subdir: str, file: str):
    filepath = os.path.join(subdir, file)
    syms = read_sym_file(filepath)
    newsyms = []
    for sym in syms:
        decomp_symbol = get_elf_symbol(sym[0])
        if (decomp_symbol is None):
            newsyms.append((sym[0], sym[1], 'U', sym[3], sym[4]))
            if (sym[2] != 'U'):
                clear_line()
                print(sym[0] + ' ' + getRankName(sym[2]) + ' -> ' + getRankName('U'))
        else:
            clear_line()
            print("Checking " + sym[0], end='\r')
            rank = rank_symbol(sym, decomp_symbol)
            newsyms.append((sym[0], sym[1], rank, sym[3], sym[4]))
            if (sym[2] != rank):
                clear_line()
                print(sym[0] + ' ' + getRankName(sym[2]) + ' -> ' + getRankName(rank))
    with open(filepath, 'w') as f:
        for sym in newsyms:
            f.write(sym[0] + ',' + "{:08x}".format(sym[1]) + ',' + sym[3] + ',' + sym[2])
            if sym[4] != '':
                f.write(',' + sym[4] + '\n')
            else:
                f.write('\n')

def check_batch(batch: list):
    for i in range(len(batch)):
        check_file(batch[i][0], batch[i][1])

class batch_thread(threading.Thread):
    def __init__(self, batch: list):
        threading.Thread.__init__(self)
        self.batch = batch
    def run(self):
        check_batch(self.batch)

def main():
    start = time.time()

    checkdir = 'Symbols'
    if len(sys.argv) == 2:
        checkdir = 'Symbols/' + sys.argv[1]
    print('Checking ' + checkdir + '/')

    sym_files = []
    for subdir, dirs, files in os.walk(checkdir):
        for file in files:
            if "Unnamed.sym" in file:
                continue
            sym_files.append((subdir, file))
    
    file_num = len(sym_files)
    batch_size = int(file_num / multiprocessing.cpu_count())
    batches = []
    cur_batch = []
    j = 0
    for i in range(file_num):
        if j == batch_size:
            batches.append(cur_batch)
            cur_batch = []
            j = 0
        cur_batch.append(sym_files[i])
        j += 1

    threads = []
    for batch in batches:
        thread = batch_thread(batch)
        thread.start()
        threads.append(thread)
    for thread in threads:
        thread.join()

    clear_line()
    print(f"{int(time.time() - start)}s elapsed")


if __name__ == "__main__":
    main()