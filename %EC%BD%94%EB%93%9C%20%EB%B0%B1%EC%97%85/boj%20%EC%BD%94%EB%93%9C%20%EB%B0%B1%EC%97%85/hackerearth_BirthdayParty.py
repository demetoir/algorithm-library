import sys
t= int(raw_input())
import fractions
import random



for T in range(t):
    n,k = map(int,sys.stdin.readline().split())

    A = []
    B = []
    for i in range(n):
        a,b = map(int,raw_input().split())
        A+=[a]
        B+=[b]


    ans = -1
    ansL = []

    if  k== 1:
        ans  = 1
        ansL = [1]
    if k == 2:
        ans = 2
        ansL = [1,2]

    for loop in range(1000):
        p,q,r= random.randint(0,n-1),random.randint(0,n-1),random.randint(0,n-1)

        if (p==q) or (p==r )or (q==r):
            continue

        if (A[r] -A[p])*(B[q] - B[p])  != (A[q] - A[p])*(B[r] - B[p]):
            continue



        L=[]
        count = 0

        for i in range(n):


            if (A[r] - A[i]) * (B[q] - B[i]) == (A[q] - A[i]) * (B[r] - B[i]):
                count +=1

                L+=[i+1]

        if count > ans:
            ans = count
            ansL = L[:]



    if ans >= k:
        print ans
        print " ".join(map(str,ansL))
    else:
        print -1









































