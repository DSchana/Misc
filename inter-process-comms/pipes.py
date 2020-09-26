import os
import sys
import time

r, w = os.pipe()

pid = os.fork()
if pid:
    # Patent process will read
    os.close(w)
    r = os.fdopen(r)
    s = r.read()
    print("Parent reads:", s)
else:
    # Child will write
    os.close(r)
    w = os.fdopen(w, 'w')
    time.sleep(3)
    w.write("CONTENT SENT")
    w.close()
