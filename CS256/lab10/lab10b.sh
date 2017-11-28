course=$1

desiredlist=(`grep $course < courses | cut -f 1 -d " "`)
peoplelist=(`cut -f 1 -d " " < emails`)
emaillist=`cat emails`
y=0

if [ "${#desiredlist[*]}" = "0" ]
then
	echo course $course not found
else
	for i in ${desiredlist[*]}
		do
			for j in ${peoplelist[*]} #iterates through a list
				do
					if [ "$i" = "$j" ]
					then
						for k in $emaillist	#iterate through a string
							do
								if [ "$y" = "1" ]
								then
									echo $k
									y=0
								fi
								if [ "$k" = "$i" ]
								then
									y=1
								fi
							done
					fi
				done
		done
fi
