

head=[1]*10
tail=[0]*10

direct = [[],[1,2,3,4,5,6,7,8,9],[1,2,3,4,5,6,7,8,9],[3,6,9],[2,4,6,8],[1,2,3,4,5,6,7,8,9],[3,6,9],[7],[4,8],[9]]
for i in range(10):
    print  i,direct[i]

n=2
for k in range(n-1):
    for i in range(1,10):
        for j  in  direct[i]:
            tail[i]+=head[j]
    print head
    print tail
    head =tail[:]
    tail=[0]*10

print sum(head)





















