#include <cstdio>

#define MAX_P 2000

bool isprime[MAX_P+1];
int lastprime;
int lastprime2;

void build()
{
  isprime[0] = isprime[1] = false;
  for(int i=2; i<=MAX_P; i++)
    isprime[i] = true;

  for(int i=2; i<=MAX_P; i++) 
    if(isprime[i]) {
      lastprime2 = lastprime;
      lastprime = i;
      int x = i+i;
      while(x<=MAX_P) {
        isprime[x] = false;
        x += i;
      }
    }
}

main()
{
  int t;
  build();
  scanf("%d",&t);
  for(int tt=0; tt<t; tt++) {
    int k;
    scanf("%d",&k);
    int sol = lastprime * lastprime2;
    for(int i=2; i<=MAX_P; i++)
      if(isprime[i]) {
        for(int j=i+1; j<=MAX_P; j++)
          if(isprime[j] && (i*j>=k) && (i*j < sol))
            sol = i*j;
      }
    printf("%d\n",sol);
  }
}
