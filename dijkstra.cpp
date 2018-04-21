#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

struct vertex {
	int idx;
	int key;
	vertex(int a = 0, int b = 0) : idx(a), key(b) {}
};

struct cmp {
	bool operator()(vertex a, vertex b) {
		return a.key > b.key;
	}
};


int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
	vector<int> distance(adj.size(), 1000000);
	vector<int> prev(adj.size(), -1);
	distance[s] = 0;
	priority_queue<vertex, vector<vertex>, cmp> visiting;
	visiting.push(vertex(s, distance[s]));
	while (!visiting.empty())
	{
		vertex current = visiting.top();
		visiting.pop();
		for (auto i = 0; i < adj[current.idx].size(); i++) 
		{
			if (distance[adj[current.idx][i]] > distance[current.idx] + cost[current.idx][i])
			{
				distance[adj[current.idx][i]] = distance[current.idx] + cost[current.idx][i];
				prev[adj[current.idx][i]] = current.idx;
				visiting.push(vertex(adj[current.idx][i], distance[adj[current.idx][i]]));
			}
		}
	}

	if (prev[t] == -1)
	{
		return -1;
	}
	else
	{
		return distance[t];
	}
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
