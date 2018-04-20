#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {
	vector<int> distance(adj.size(), 1000);
	distance[s] = 0;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty())
	{
		int u ;
		u = Q.front();
		Q.pop();
		for (auto i = 0; i < adj[u].size(); i++) 
		{
			if (distance[adj[u][i]] == 1000)
			{
				Q.push(adj[u][i]);
				distance[adj[u][i]] = distance[u] + 1;
				if (adj[u][i] == t)
					return distance[t];
			}
		}


	}
	return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
