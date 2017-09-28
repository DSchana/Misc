from math import *

t = 0.5
a = 4
g = a / 2
ng = (g + a / g) / 2

while abs(ng - g) > t:
	g = (ng + a / ng) / 2
	ng = (g + a / g) / 2

print(g)
