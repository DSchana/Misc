var datFile,x1,y1,x2,y2:int

open:datFile,"Boxes.txt",put

for i : 1..50
    randint(x1,-1000,1000)
    randint(x2,-1000,1000)
    randint(y1,-1000,1000)
    randint(y2,-1000,1000)
    put:datFile, min(x1,x2)," ",min(y1,y2)," ",max(x1,x2)," ",max(y1,y2)
end for

close:datFile
