n,m=map(int,raw_input().split())
left=[0]
right=[0]
ans=0
for i in range(n):
    a=input()
    if a>0:right+=[a]
    elif a<0:left+=[a]
    else:ans+=m
    
left.sort() 
right.sort()
left.reverse()

#memo[R][L][R or L]=(time,total)
#           0    1  
#memo=[[ [[0,0]for k in range(2) ] for j in range(500) ] for i in range(500)]
maxl=500
Rtimememo=[[[0,0]for j in range(maxl)]for i in range(maxl)]
Ltimememo=[[[0,0]for j in range(maxl)]for i in range(maxl)]
Rtotalmemo=[[[0,0]for j in range(maxl)]for i in range(maxl)]
Ltotalmemo=[[[0,0]for j in range(maxl)]for i in range(maxl)]
#print memo

Rtimememo[0][0] = [0, 0]
Ltimememo[0][0] = [0, 0]
Rtotalmemo[0][0] = [0, 0]
Ltotalmemo[0][0] = [0, 0]

maxval=0
#right
for i in range(1,len(right)):
    atime, atotal = Rtimememo[i-1][0]
    Rtimememo[i][0] = [right[i], atotal + m - right[i]]
    Rtotalmemo[i][0] = [right[i], atotal + m - right[i]]
    maxval = max(maxval, atotal + m - right[i])
    Ltimememo[i][0] = [m*m, 0]
    Ltotalmemo[i][0] = [m*m, 0]
#left
for i in range(1,len(left)):
    atime, atotal = Ltimememo[0][i-1]
    Ltimememo[0][i] = [-left[i], atotal + m + left[i]]
    Ltotalmemo[0][i] = [-left[i], atotal + m + left[i]]
    maxval = max(maxval, atotal + m + left[i])
    Rtimememo[0][i] = [m*m, 0]
    Rtotalmemo[0][i] = [m*m, 0]

for L in range(1,len(left)):
    for R in range(1,len(right)):
        #Rtimememo[R][L]
        atime, atotal = Ltimememo[R-1][L]
        ctime, ctotal = Ltotalmemo[R-1][L]
        aLtime = atime + abs(right[R] - left[L])
        cLtime = ctime + abs(right[R] - left[L])
        aLtotal = atotal + max(m - aLtime, 0)
        cLtotal = ctotal + max(m - cLtime, 0)

        btime, btotal = Rtimememo[R-1][L]
        dtime, dtotal = Rtotalmemo[R-1][L]
        bRtime = btime + abs(right[R] - right[R-1])
        dRtime = dtime + abs(right[R] - right[R-1])
        bRtotal = btotal + max(m - bRtime, 0)
        dRtotal = dtotal + max(m - dRtime, 0)
        time=aLtime
        total=aLtotal
        if time > cLtime:
            time = cLtime
            total = cLtotal
        if time > bRtime:
            time = bRtime
            total = bRtotal
        if time > dRtime:
            time = dRtime
            total = dRtotal
        Rtimememo[R][L]=[time,total]
        maxval = max(maxval, total)

        #Rtotalmemo[R][L]
        atime, atotal = Ltimememo[R-1][L]
        ctime, ctotal = Ltotalmemo[R-1][L]
        aLtime = atime + abs(right[R] - left[L])
        cLtime = ctime + abs(right[R] - left[L])
        aLtotal = atotal + max(m - aLtime, 0)
        cLtotal = ctotal + max(m - cLtime, 0)

        btime, btotal = Rtimememo[R-1][L]
        dtime, dtotal = Rtotalmemo[R-1][L]
        bRtime = btime + abs(right[R] - right[R-1])
        dRtime = dtime + abs(right[R] - right[R-1])
        bRtotal = btotal + max(m - bRtime, 0)
        dRtotal = dtotal + max(m - dRtime, 0)
        time = aLtime
        total = aLtotal
        if total < cLtotal:
            time = cLtime
            total = cLtotal
        if total < bRtotal:
            time = bRtime
            total = bRtotal
        if total < dRtotal:
            time = dRtime
            total = dRtotal
        Rtotalmemo[R][L]=[time,total]
        maxval = max(maxval, total)

        #Ltimememo[R][L]
        atime, atotal = Ltimememo[R][L-1]
        ctime, ctotal = Ltotalmemo[R][L-1]
        aLtime = atime + abs(left[L] - left[L-1])
        cLtime = ctime + abs(left[L] - left[L-1])
        aLtotal = atotal + max(m - aLtime, 0)
        cLtotal = ctotal + max(m - cLtime, 0)

        btime, btotal = Rtimememo[R][L-1]
        dtime, dtotal = Rtotalmemo[R][L-1]
        bRtime = btime + abs(left[L] - right[R])
        dRtime = dtime + abs(left[L] - right[R])
        bRtotal = btotal + max(m - bRtime, 0)
        dRtotal = dtotal + max(m - dRtime, 0)
        time=aLtime
        total=aLtotal
        if time > cLtime:
            time = cLtime
            total = cLtotal
        if time > bRtime:
            time = bRtime
            total = bRtotal
        if time > dRtime:
            time = dRtime
            total = dRtotal
        Ltimememo[R][L]=[time,total]
        maxval = max(maxval, total)

        #Ltotalmemo[R][L]
        atime, atotal = Ltimememo[R][L-1]
        ctime, ctotal = Ltotalmemo[R][L-1]
        aLtime = atime + abs(left[L] - left[L-1])
        cLtime = ctime + abs(left[L] - left[L-1])
        aLtotal = atotal + max(m - aLtime, 0)
        CLtotal = ctotal + max(m - cLtime, 0)

        btime, btotal = Rtimememo[R][L-1]
        dtime, dtotal = Rtotalmemo[R][L-1]
        bRtime = btime + abs(left[L] - right[R])
        dRtime = dtime + abs(left[L] - right[R])
        bRtotal = btotal + max(m - bRtime, 0)
        dRtotal = dtotal + max(m - dRtime, 0)
        time=aLtime
        total=aLtotal
        if total < cLtotal:
            time = cLtime
            total = cLtotal
        if total < bRtotal:
            time = bRtime
            total = bRtotal
        if total < dRtotal:
            time = dRtime
            total = dRtotal
        Ltotalmemo[R][L]=[time,total]
        maxval = max(maxval, total)

l,r =len(left)-1,len(right)-1
"""
for i in Rtimememo:
    print i
print
for i in Rtotalmemo:
    print i
print
for i in Ltimememo:
    print i
print
for i in Ltotalmemo:
    print i
print
"""
print ans + maxval
print maxval
               
               
               
               
   
