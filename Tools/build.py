import os
import subprocess
import multiprocessing
from genLinkerScript import genLDScript
from colorama import Fore, Style
import sys
import shutil
from settings import *

def status(msg: str):
    print(Style.BRIGHT + Fore.CYAN + msg + Fore.RESET + Style.RESET_ALL)


if len(sys.argv) >= 2 and sys.argv[1] == 'clean':
    shutil.rmtree(getBuildPath())

if not os.path.exists(getBuildPath()):
    os.mkdir(getBuildPath())
    os.chdir(getBuildPath())
    subprocess.run("cmake ..", shell=True)
    os.chdir('..')

status("Generating Linker Script")
genLDScript()

os.chdir(getBuildPath())

verbose = ''
if len(sys.argv) >= 2 and sys.argv[1] == 'verbose':
    verbose = 'VERBOSE=1'
result = subprocess.run(f'make -j {multiprocessing.cpu_count()} {verbose}', shell=True)
if result.returncode != 0:
    exit()

def fromelf():
    status("Generating code.bin")
    subprocess.run("\"" + os.environ.get('ARMCC_PATH') + f"/bin/fromelf.exe\" --bincombined {getElfName()} --output code.bin", shell=True)

if os.path.exists('code.bin'):
    if os.path.getmtime('code.bin') < os.path.getmtime(getElfName()):
        fromelf()
else:
    fromelf()

os.chdir('..')