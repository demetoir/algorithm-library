
n=int(raw_input())
l=list(map(int,raw_input().split()))
s,m=0,min(l)
for k in l:
    if s<0:s=k
    else: s+=k
    if m<s:m=s
print(m)
