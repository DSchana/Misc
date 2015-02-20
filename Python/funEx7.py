# funEx7
from functools import *

@lru_cache()
def pascal(row,pos):
    if pos == row+1 or pos == 1:
        return 1
    else:
        return pascal(row-1,pos-1)+pascal(row-1,pos)
