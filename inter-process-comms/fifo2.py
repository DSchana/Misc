path = "/tmp/fifo_test"

fifo = open(path, 'r')

s = fifo.read()
print(s)
s = fifo.read()
print(s)
