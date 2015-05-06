var len, width, area, peri: int

put("Enter number")
get len

put("Enter number again")
get width

area = (len*width)
peri = (2*len+2*width)

put("Area: " + intstr(area) + " Parimeter: " + intstr(peri))
