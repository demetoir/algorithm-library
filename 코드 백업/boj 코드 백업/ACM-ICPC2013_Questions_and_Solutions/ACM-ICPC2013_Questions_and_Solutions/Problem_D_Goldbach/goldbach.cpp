#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void solve()
{
    //freopen("goldbach.in","rt",stdin);
    //freopen("goldbach.out","wt",stdout);
    long long m;
    while(true)
    {
        scanf("%lld",&m);
        if(m == 0)
            break;
        printf("Y %lld\n",m*m-m+1);
    }
}

void gen()
{
    freopen("goldbach.in","wt",stdout);
    srand(time(NULL));
    int i,j,r,diff,low = 1,up = 10,t = 2,end;
    for(i=1;i<10;i++)
    {
        diff = up - low;
        if(i >= 6)
            t *= 10;
        if(i == 1)
            end = 3;
        else if(i == 9)
            end = 27;
        else
            end = 10;
        for(j=1;j<=end;j++)
        {
            if(i >= 5)
                r = (rand()%diff)*t + low;
            else
                r = rand()%diff + low;
            printf("%d\n",r);
        }
        low = up;
        up *= 10;
    }
    printf("0\n");
}

int main()
{
    //gen();
    solve();
    return 0;
}
