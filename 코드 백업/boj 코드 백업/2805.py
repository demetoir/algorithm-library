
n,m=map(int,raw_input().split())
l=map(int,raw_input().split())


def f(x):
    ret=0
    for i in l:
        if i>x:
            ret+=i-x
    return ret

lo=0
hi=1234567890
ans=0
while lo<=hi:
    mid=(lo+hi)//2
    
    x=f(mid)
    if x>=m:
        ans=max(mid,ans)
        lo=mid+1
    else:
        hi=mid-1
print ans



"""
n,m=map(int,raw_input().split())
L=map(int,raw_input().split())
l=0;h=10**9;a=0
while l<=h:
 d=(l+h)//2;x=0
 for i in L:
  if i>d:x+=i-d
 if x>=m:a=max(d,a);l=d+1
 else:h=d-1
print a
"""






            






"""
import sys
n,m=map(int,sys.stdin.readline().split())
L=map(int,sys.stdin.readline().split())
L.sort(reverse=True)
a=l[0]+[0]*(n+1)
for i in range(1,n):a[i]=a[i-1]+l[i]
def f(x):
    l=-1;h=n-1;s=0
    while l<=h:
        m=(l+h)//2
        if mid==-1:return 0
        if L[m]>x:
            if m>s:s=m
            l=m+1
        else:h=m-1      
    return a[s]-(s+1)*x     

l=0
h=10**9
ans=0
while l<=h:
    m=(l+h)//2    
    x=f(m)
    #print x
    if x>=m:
        if m>ans:ans=m
        l=m+1
    else:h=m-1
print ans
"""

