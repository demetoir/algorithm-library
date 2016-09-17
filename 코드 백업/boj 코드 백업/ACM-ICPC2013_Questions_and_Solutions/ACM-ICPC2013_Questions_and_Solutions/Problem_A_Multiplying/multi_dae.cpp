#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_K 200000

int prime[MAX_K/2];
bool pb[MAX_K/2];
int pCount;
bool ans[MAX_K+1];


void init() {
  //seive for prime
  for (int i = 0;i < MAX_K/2;i++) {
    pb[i] = true;
  }
  pb[0]=pb[1]=false;
  for (int i = 2;i < MAX_K/2;i++) {
    if (pb[i]) {
      for (int j = i*2;j < MAX_K/2;j+=i) {
        pb[j] = false;
      }
    }
  }
  for (int i = 0;i < MAX_K/2;i++) {
    if (pb[i]) {
      prime[pCount] = i;
      pCount++;
    }
  }

  // compute the answer
  for (int i = 0;i <= MAX_K;i++) ans[i] = false;
  for (int i = 0;i < pCount;i++) {
    if (prime[i] > sqrt(MAX_K)) break;
    for (int j = i+1;j < pCount;j++) {
      if (prime[i] * prime[j] == 100001) printf("%d %d\n",prime[i],prime[j]);
      if (prime[i] * prime[j] <= MAX_K) ans[prime[i] * prime[j]] = true;
      else break;
    }
  }

}

int main() {
  init();
  int T;
  scanf("%d\n",&T);
  for (int i = 0;i < T;i++) {
    int k;
    scanf("%d",&k);
    while (ans[k] == false) k++;
    printf("%d\n",k);

  }
}
