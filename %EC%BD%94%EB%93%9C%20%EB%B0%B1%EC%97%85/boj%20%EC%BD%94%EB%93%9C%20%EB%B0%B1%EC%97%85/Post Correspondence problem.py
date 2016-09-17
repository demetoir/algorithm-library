import sys
l=[]
n = int (raw_input())
for i in range(n):
    s,t = raw_input().split()
    l+=[len(s)-len(t)]
# print l


for i in range(n):
    if l[i]==0:
        print "YES"
        print i+1
        exit()

for i in range(n):
    for j in range( n):
        if l[i]+l[j]==0:
            print "YES"
            print i+1,j+1
            exit()


for i in range(n):
    for j in range(n):
        for k in range(n):
            if l[i]+ l[j]+l[k] ==0:
                print "YES"
                print i+1,j+1,k+1
                exit()

for i in range(n):
    for j in range(n):
        for k in range(n):
            for m in range(n):
                if l[i]+ l[j]+l[k]+ l[m] ==0:
                    print "YES"
                    print 4
                    print i+1,j+1,k+1,m+1
                    exit()
for i in range(n):
    for j in range(n):
        for k in range(n):
            for m in range(n):
                for g in range(n):
                    if l[i]+ l[j]+l[k]+ l[m]+l[g] ==0:
                        print "YES"
                        print 5
                        print i+1,j+1,k+1,m+1,g+1
                        exit()
print "NO"


