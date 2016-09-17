#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

#define INF 2000000000

using namespace std;

typedef  int dist_type;
typedef  pair<int,dist_type>   pint;
struct classcomp {
    bool operator() (const pint&a, const pint&b) const {
        if (a.second < b.second)
            return true;
        else if ((a.second == b.second) && (a.first < b.first))
            return true;
        return false;
    }
};
typedef  set<pint, classcomp>  spair;
typedef  vector<pint>          vpair;


void PrintVector(vpair A[], int N)
{
    for(int i=0; i<N; i++)
    {   cout << i << " -> " ;
        for(vpair::iterator it=A[i].begin(); it<A[i].end(); it++)
        {
            cout << "(" << it->first << "," << it->second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void ShortestPath(vpair A[], int N, int M, int K)
{
    int KK = K;

    dist_type D[N][K+1];
    for(int i=0; i<N;i++)
        for(int j=0; j<K+1; j++)
            D[i][j] = INF;

    ///Find Shortest Path from node 0 to node N-1
    spair PQ;
    D[0][0] = 0;
    PQ.insert(pint(0,0));

    int u_id, u, u_k, v;
    pint min_elm;
    dist_type du, dv, dist;

    while(!PQ.empty())
    {
        min_elm = *PQ.begin();
        PQ.erase(PQ.begin());

        u_id  = min_elm.first;     // node_id
        du = min_elm.second;       // min distance
        u = (u_id % N);
        u_k = (u_id / N);

        if (u == N-1)
           KK = 0;// the destination is reached. Done!!
        if (u_k > KK)
            continue;

        for(vpair::iterator it=A[u].begin(); it<A[u].end(); it++)
        {
            v  = it->first;         // no k here (from input)
            dist = it->second;

            // Normal
            if (D[v][u_k] > du + dist)
            {
                spair::iterator it2 = PQ.find(pint(v + N*u_k, D[v][u_k] ));
                if (it2 != PQ.end())
                {   PQ.erase(it2);
                }
                dv = du + dist;
                D[v][u_k] = dv;
                PQ.insert(pint(v + N*u_k, dv));
            }

            /// When using a Booster
            if (u_k < K)
            {
                if (D[v][u_k+1] > du + (dist/2))
                {
                    spair::iterator it2 = PQ.find(pint(v + N*(u_k+1), D[v][u_k+1]));
                    if (it2 != PQ.end())
                    {   PQ.erase(it2);
                    }
                    dv = du + (dist/2);
                    D[v][u_k+1] = dv;
                    PQ.insert(pint(v + N*(u_k+1), dv));
                }
            }
        }
    }

    dist_type min_dist = D[N-1][0];
    for (int k=1; k<=K; k++)
        if (min_dist > D[N-1][k])
         {  min_dist = D[N-1][k];
         }
    cout << D[N-1][0]-min_dist << endl;
}

void MainFunction()
{
    int N, M, K;
    cin >> N >> M >> K;
    vpair A[N];
    int x,y;
    dist_type d;

    for(int i=0; i<M; i++)
    {   cin >> x >> y >> d;
        A[x-1].push_back(pint(y-1,d));
        A[y-1].push_back(pint(x-1,d));
    }

    ShortestPath(A,N,M,K);
}

int main()
{
    int number_of_case = -1;
    cin >> number_of_case;
    for(int i=0; i<number_of_case; i++)
        MainFunction();
    return 0;
}
