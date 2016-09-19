#include <cstdio>

#define MODNUM  93563
int compute(int n, int k)
{
  if(k==1) {
    if(n==1)
      return 1;
    else
      return 0;
  }
  int res = 1;
  for(int i=0; i<n-1; i++)
    res = ((res*(k-1)) % MODNUM);
  res = (res*k) % MODNUM;
  return res;
}

main()
{
  int t;
  int n,k,a,b;
  scanf("%d",&t);
  for(int tt=0; tt<t; tt++) {
    scanf("%d %d",&n,&k);
    for(int i=0; i<n-1; i++)
      scanf("%d %d",&a,&b);
    printf("%d\n",compute(n,k));
  }
}
