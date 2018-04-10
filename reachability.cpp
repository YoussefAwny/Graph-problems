#include <iostream>
#include <vector>

using std::vector;
using std::pair;


int reach(vector<vector<int> > &adj, vector<bool> &visited, int x, int y) {
	visited[x] = 1;
	int k = 0;
	for (int i = 0; i < adj[x].size(); i++)
	{
		if (!visited[adj[x][i]]) 
		{
			if (adj[x][i] == y)
			{
				k = 1;
				break;
			}
			else
			{
				k = reach(adj, visited, adj[x][i], y);
				if(k) break;

			}
			
			
		}
		
	}
	return k;
}
void reach_test() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	std::cin >> x >> y;
	vector<bool> visited(n, 0);
	std::cout << reach(adj, visited, x - 1, y - 1);
}

int main() {
reach_test();
}
