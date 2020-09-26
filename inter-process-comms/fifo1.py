import os
import sys

path = "/tmp/fifo_test"

try:
    os.mkfifo(path)
except OSError as e:
    print("Failed to create FIFO:", e)

fifo = open(path, 'w')

fifo.write("CONTENT1")
fifo.write("CONTENT2")
