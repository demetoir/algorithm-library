//min cost max flow (mcmf)
//
//시간 복잡도
//
//참고자료
//https://en.wikipedia.org/wiki/Minimum-cost_flow_problem
//https://jmk.pe.kr/read/mcmf
//https://www.topcoder.com/community/data-science/data-science-tutorials/minimum-cost-flow-part-two-algorithms/
//http://blog.naver.com/PostView.nhn?blogId=wnsgh224&logNo=220665956037&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
//http://koosaga.myungwoo.kr/entry/%EC%9C%A0%EB%9F%89-%EA%B4%80%EB%A0%A8-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%A0%95%EB%A6%AC
//http://hongjun-7.blogspot.kr/2014/11/2013-kaist-acm-icpc-cleaning.html
//
//
//
//문제
//
//
#include <vector>
#include <queue>
using namespace std;




//For search : Min cost max flow.Min - cost max flow.
//
//Alright I finally wrote a MCMF library after all these years.
//
//Version 1 : Uses repeat - until - not- updated Dijkstra.Push unit amount per augmenting path
//Version 2 : Use priority queue, but still repeat until updated
//Version 3 : Use adjacent list instead, push max amount of flow per augmenting path
//Version 4 : Use potentials to ensure all edge weights are nonnegative
//Runtime for some random data : Version 1 (89s) Version 2 (12s) Version 3 (3.2s) Version 4 (3s)
//
//I don't know whether the big jump in speed (12 to 3) comes from adjacent list or pushing multiple units at once. I'm suspecting pushing multiple units.
//
//Tested on : TCO10 R1 Hard.SRM506 Medium.UVA10594 Data Flow.
// ASSUMPTIONS:
// no more than one edge between two vertices
// small number of vertices
#define INF 987654321


//Version 1 : Uses repeat - until - not- updated Dijkstra.Push unit amount per augmenting path
struct MCMF1 {
	int V, totalFlow, totalCost;
	vector<vector<int> > cap, cost, flow;
	MCMF1(int n) : V(n), totalFlow(0), totalCost(0) {
		cap = cost = flow = vector<vector<int> >(n, vector<int>(n));
	}
	void setEdge(int u, int v, int cap, int cost) {
		this->cap[u][v] = cap;
		this->cost[u][v] = cost;
	}

	int improve(int s, int t) {
		vector<int> distance(V, INF);
		vector<int> parent(V, -1);
		parent[s] = s;
		distance[s] = 0;
		bool changed = true;
		while (changed) {
			changed = false;
			for (int cur = 0; cur < V; cur++) {
				if (distance[cur] >= INF) continue;

				for (int next = 0; next < V; next++) {
					int cand;
					if (flow[next][cur] > 0)
						cand = distance[cur] - cost[next][cur];
					else if (cap[cur][next] > flow[cur][next])
						cand = distance[cur] + cost[cur][next];
					else
						continue;
					if (cand < distance[next]) {
						distance[next] = cand;
						parent[next] = cur;
						changed = true;
					}
				}
			}
		}

		if (distance[t] == INF) return INF;

		int next = t;
		while (next != s) {
			int cur = parent[next];
			flow[cur][next]++;
			flow[next][cur]--;
			next = cur;
		}
		totalFlow++;
		totalCost += distance[t];
	
		return distance[t];
	}
};


//Version 2: use priority queue
struct MCMF2 {
	int V, totalFlow, totalCost;
	vector<vector<int> > cap, cost, flow;
	MCMF2(int n) : V(n), totalFlow(0), totalCost(0) {
		cap = cost = flow = vector<vector<int> >(n, vector<int>(n));
	}
	void setEdge(int u, int v, int cap, int cost) {
		this->cap[u][v] = cap;
		this->cost[u][v] = cost;
	}
	inline int getCost(int u, int v) {
		return flow[v][u] > 0 ? -cost[v][u] : cost[u][v];
	}
	int improve(int s, int t) {
		vector<int> distance(V, INF);
		vector<int> parent(V, -1);
		priority_queue<pair<int, int> > pq;
		parent[s] = s;
		distance[s] = 0;
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (distance[cur] < cost) continue;

			for (int next = 0; next < V; ++next) {
				if (cap[cur][next] - flow[cur][next] <= 0) continue;

				int nextcost = distance[cur] + getCost(cur, next);
				if (nextcost < distance[next]) {
					parent[next] = cur;
					distance[next] = nextcost;
					pq.push(make_pair(-nextcost, next));
				}
			}
		}

		if (distance[t] >= INF)return INF;
	
		int next = t;
		while (next != s) {
			int cur = parent[next];
			flow[cur][next]++;
			flow[next][cur]--;
			next = cur;
		}
		totalFlow++;
		totalCost += distance[t];
	
		return distance[t];
	}
};

//Version 3: use adjacent list
struct MCMF3 {
	int V, totalFlow, totalCost;
	struct Edge {
		int target, capacity, cost, flow;
		Edge* dual;

		Edge(int target, int capacity, int cost) :
			target(target), capacity(capacity), cost(cost), flow(0) {
		}

		inline int residual() const {
			if (flow < 0) return -flow;
			return capacity - flow;
		}

		inline int getCost() const {
			if (flow < 0) return -dual->cost;
			return cost;
		}

		void push(int amt) {
			flow += amt;
			dual->flow -= amt;
		}
	};

	vector<vector<Edge*> > adj;
	MCMF3(int n) : V(n), totalFlow(0), totalCost(0), adj(n) {}
	~MCMF3() {
		for (int i = 0; i < V; i++)
			for (int j = 0; j < adj[i].size(); j++)
				delete adj[i][j];
	}
	void setEdge(int u, int v, int uvCapacity, int uvCost, int vuCapacity = 0, int vuCost = 0) {
		Edge* uv = new Edge(v, uvCapacity, uvCost);
		Edge* vu = new Edge(u, vuCapacity, vuCost);
		uv->dual = vu; vu->dual = uv;
		adj[u].push_back(uv); adj[v].push_back(vu);
	}
	int improve(int s, int t) {
		vector<int> distance(V, INF), parent(V, -1), edgeNo(V, -1), capa(V, -1);
		priority_queue<pair<int, int> > pq;

		parent[s] = s;
		distance[s] = 0;
		capa[s] = INF;
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (distance[cur] < cost) continue;
			for (int i = 0; i < adj[cur].size(); ++i) {
				Edge* e = adj[cur][i];
				if (e->residual() <= 0) continue;

				int nextcost = distance[cur] + e->getCost();
				if (nextcost < distance[e->target]) {
					parent[e->target] = cur;
					edgeNo[e->target] = i;
					capa[e->target] = min(capa[cur], e->residual());
					distance[e->target] = nextcost;
					pq.push(make_pair(-nextcost, e->target));
				}
			}
		}

		if (distance[t] >= INF)return INF;
		
		int next = t, amt = capa[t];
		while (next != s) {
			int cur = parent[next];
			adj[cur][edgeNo[next]]->push(amt);
			next = cur;
		}
		totalFlow += amt;
		totalCost += distance[t] * amt;
		
		return distance[t];
	}
};

//version 4: use potentials for fast dijkstra
struct MCMF4 {
	int V, totalFlow, totalCost;
	struct Edge {
		int target, capacity, cost, flow;
		Edge* dual;

		Edge(int target, int capacity, int cost) :
			target(target), capacity(capacity), cost(cost), flow(0) {
		}

		inline int residual() const {
			if (flow < 0) return -flow;
			return capacity - flow;
		}

		inline int getCost() const {
			if (flow < 0) return -dual->cost;
			return cost;
		}

		void push(int amt) {
			flow += amt;
			dual->flow -= amt;
		}
	};
	vector<vector<Edge*> > adj;
	vector<int> pot;
	MCMF4(int n) : V(n), totalFlow(0), totalCost(0), adj(n), pot(n, 0) {}
	~MCMF4() {
		for (int i = 0; i < V; i++)
			for (int j = 0; j < adj[i].size(); j++)
				delete adj[i][j];
	}

	void setEdge(int u, int v, int uvCapacity, int uvCost, int vuCapacity = 0, int vuCost = 0) {
		Edge* uv = new Edge(v, uvCapacity, uvCost);
		Edge* vu = new Edge(u, vuCapacity, vuCost);
		uv->dual = vu; vu->dual = uv;
		adj[u].push_back(uv); adj[v].push_back(vu);
	}
	int improve(int s, int t) {
		vector<int> distance(V, INF), parent(V, -1), edgeNo(V, -1), capa(V, -1);
		priority_queue<pair<int, int> > pq;
		parent[s] = s;
		distance[s] = 0;
		capa[s] = INF;
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (distance[cur] < cost) continue;

			for (int i = 0; i < adj[cur].size(); ++i) {
				Edge* e = adj[cur][i];
				if (e->residual() <= 0) continue;

				int nextcost = distance[cur] + e->getCost() + pot[cur] - pot[e->target];
				if (nextcost < distance[e->target]) {
					parent[e->target] = cur;
					edgeNo[e->target] = i;
					capa[e->target] = min(capa[cur], e->residual());
					distance[e->target] = nextcost;
					pq.push(make_pair(-nextcost, e->target));
				}

			}
		}
		int cost = distance[t] + pot[t] - pot[s];
		for (int i = 0; i < V; i++)
			if (pot[i] < INF)
				pot[i] += distance[i];
		if (distance[t] == INF) return INF;

		int next = t, amt = capa[t];
		while (next != s) {
			int cur = parent[next];
			adj[cur][edgeNo[next]]->push(amt);
			next = cur;
		}
		totalFlow += amt;
		totalCost += cost * amt;
		return cost;
	}
};
