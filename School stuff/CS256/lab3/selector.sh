#!/bin/bash

a=`grep -n $1 < headandtail | cut -d ":" -f 1 | head -n 1 `
b=`grep -n $2 < headandtail | cut -d ":" -f 1 | head -n 1 `

c=`expr $b - $a `

if((c==0))
	then c=1
fi
if((c<0))
	then echo "Error"
fi
if((c>0))
	then 
	head -n $b < headandtail | tail -n $c
fi
