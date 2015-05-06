var age: int

put("What iz ur age")
get age

if age <= 5 then
    put("Damn son, this movie rated R, and you get in for free")
elsif age <= 11 then
    put("$5.99")
elsif age <= 17 then
    put("$7.99")
elsif age <= 64 then
    put("$9.99")
else
    put("$5.99 you old geezer")
end if
