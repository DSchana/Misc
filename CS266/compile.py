import sys
import os

for a in sys.argv:
	os.system("nasm " + "-f elf " + a + ".asm")
	os.system("ld " + a + ".o " + "-o " + a)
