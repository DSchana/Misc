import os
from sys import platform

if platform == "win32":
	os.system("shutdown -s -t 7")
else:
	os.system("sudo shudown -h now")
