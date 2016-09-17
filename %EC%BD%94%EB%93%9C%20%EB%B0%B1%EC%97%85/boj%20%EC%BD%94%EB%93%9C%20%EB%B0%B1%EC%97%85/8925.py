for T in range(input()):
    n,L=map(int,raw_input().split())
    s=raw_input()

    psum=[0]*(n+1)
    for i in range(1,n+1):
        psum[i]=psum[i-1]+int(s[i-1])
    q=[0]*(n+1)
    get= lambda a,b:(psum[b]-psum[a])*1.0/(b-a)
    qfront=0
    qrear=-1

    anslen=0
    ansstart=0
    ansend=L
    ansval=-1

    for i in range(L,n+1):
        s=i-L
        while qfront<qrear and get(q[qrear],s)<=get(q[qrear-1],q[qrear]):
            qrear-=1
        qrear+=1
        q[qrear]=s
        while qfront<qrear and get(q[qfront],i)<=get(q[qfront+1],i):
            qfront+=1
        curval=get(q[qfront],i)
        curlen=i-q[qfront]+1

        if (curval==ansval and curlen<anslen ) or curval>ansval:
            ansval=curval
            anslen=curlen
            ansstart=q[qfront]
            ansend=i
    print ansstart+1,ansend


def a():

    def b():

