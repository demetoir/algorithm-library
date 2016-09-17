import math

maxseive = (10**5)
seive =  [0,0]+[1]*(maxseive)
prime =[]
for i in range(2,maxseive):
    if seive[ i ] == 0 :continue
    prime += [i]
    for j in range(i+i,maxseive,i):
        seive[j] = 0

# print prime[:10]



n = 10**4
ans = -1


for i in range(n//2,n+1):
    isprime =True
    val =i
    L=[]
    j=2
    t=1
    while 1:

        if val%j==0:
            t*=j
            val = val//j
        else:

            if t*2>n:
                ans = i
                break
            j+=1
            t=1
        if val==1: break
    if ans >-1: break
print ans
# print t











