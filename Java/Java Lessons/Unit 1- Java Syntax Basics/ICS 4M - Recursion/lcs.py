# Longest Common Sub-sequence

def lcs(x,y)
   if ( length(x)=0 or length(y)=0 ) 
     return ""

   best = lcs(x[1,n-1],y[1,m])

   if ( length(best) < length(lcs(x[1,n],y[1,m-1])) )
      best = lcs(x[1,n],y[1,m-1])

   if ( x[n] = y[m] and length(best) < length(lcs(x[1,n-1],y[1,m-1]) 1 )
      best = lcs(x[1,n-1],y[1,m-1])   x[n]

   return best
