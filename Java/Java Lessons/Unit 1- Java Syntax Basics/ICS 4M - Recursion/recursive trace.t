function converge(x,y:int):int
    put x:10,y:10
    if x > y then
	result (x+y) div 2
    else
	result converge((x+y) div 2, y - 10)
    end if
end converge

%put converge(0,100)

function tree(n:int):int
    if n < 5 then
	result n
    else
	result tree(n div 10) + tree(n mod 2)
    end if
end tree
	

function reduce(n:int):int
    if n < 10 then
	result n
    else
	result reduce(n div 10) + reduce(n div 2) 
    end if
end reduce

put reduce(87)

proc lines(x,y:int)
    if y > 0 then
	drawline(x, 200-y, x, 200+y, 7)
	lines(x-20, y-20)
	lines(x+20, y-20)
    end if
end lines

%lines(300,110)
