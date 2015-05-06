var userNum: int
var counter:= 0
var num: int

num := Rand.Int(1, 1000)
put(intstr(num))

loop
    put("Guess a number")
    get userNum
    
    counter += 1
    
    if userNum = num then
	if counter <= 10 then
	    put("good job, do you want a cookie")
	end if
	break
    elsif userNum < num then
	put("higher")
    elsif userNum > num then
	put("lower")
    end if

end loop
