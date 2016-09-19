#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <ctype.h>

using namespace std;

const int max_n = 510000;

int pscore[max_n];
map<string,int> cities;
int n,q;
string cname[max_n];

void read_input()
{
  char buff[100];
  char line[1000];
  fgets(buff,99,stdin);
  sscanf(buff,"%d",&n);

  for(int i=0; i<n; i++) {
    fgets(line,999,stdin);
    char *p = line;
    while(*p!=',') {
      p++;
    }
    *p = '\0';
    p++;
    int sc;
    sscanf(p,"%d",&sc);
    pscore[i] = sc;
    string name(line);

    cities[name] = i;
    cname[i] = name;
  }

  fgets(buff,99,stdin);
  sscanf(buff,"%d",&q);
}

char pref[1000];

void find_top_3(int i, int j)
{
  int p[3] = {-1,-1,-1};
  int pi[3] = {-1,-1,-1};

  for(int k=i; k<j; k++) {
    //printf("%s\n",cname[k].c_str());
    if(pscore[k] > p[0]) {
      p[2] = p[1]; p[1] = p[0];
      pi[2] = pi[1]; pi[1] = pi[0];
      p[0] = pscore[k];
      pi[0] = k;
    } else if(pscore[k] > p[1]) {
      p[2] = p[1];
      pi[2] = pi[1];
      p[1] = pscore[k];
      pi[1] = k;
    } else if(pscore[k] > p[2]) {
      p[2] = pscore[k];
      pi[2] = k;
    }
  }
  for(int k=0; k<3; k++)
    if(p[k]!=-1) {
      printf("%s,%d\n",cname[pi[k]].c_str(),p[k]);
    }
}

main()
{
  read_input();
  for(int i=0; i<q; i++) {
    fgets(pref,999,stdin);
    char *p = pref;
    while(*p!='\n' && *p!='\r' && *p!='\0')
      p++;
    *p = '\0';

    printf("%s\n",pref);
    p = pref;
    while(*p!='\0') {
      *p = toupper(*p);
      p++;
    }
    int slen = strlen(pref);
    string s(pref);
    map<string,int>::iterator ci = cities.lower_bound(s);
    //map<string,int>::iterator ci = cities.lower_bound("BAGUA GRANDEA");

    if(ci==cities.end() || ((ci->first).compare(0,slen,pref)!=0)) {
      printf("N/A\n");
      continue;
    }

    string s2 = s + "z";

    map<string,int>::iterator c2 = cities.lower_bound(s2);

    int si = ci->second;
    int ti;
    if(c2 != cities.end())
      ti = c2->second;
    else
      ti = n;


    int num = ti - si;
    //printf("%d %d\n",ti,si);

    if(num <= 1000) {
      find_top_3(si,ti);
    } else {
      //printf("%d %s %d %s %d\n",si,cname[si].c_str(),ti,cname[ti].c_str(),num);
      printf("%d\n",num);
    }
  }
}
