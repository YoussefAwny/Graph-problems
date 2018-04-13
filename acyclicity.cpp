#include <iostream>
#include <vector>

using std::vector;
using std::pair;

using namespace std;

bool iscyclic(vector<vector<int> > &adj, vector<bool> &visited, vector<bool> &stack, int v)
{
	if (!visited[v]) 
	{
		visited[v] = true;
		stack[v] = true;

		for (auto i = 0; i < adj[v].size(); i++)
		{
			if (!visited[adj[v][i]] && iscyclic(adj, visited, stack, adj[v][i]))
			{
				return 1;
			}
			else if (stack[adj[v][i]])
			{
				return 1;
			}
		}
	}
	stack[v] = false;
	return 0;
}

int main() {
  	size_t n, m;
	bool cycle = 0;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<bool> visited(n, 0);
	vector<bool> stack(n, 0);
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	for (int i = 0; i < n; i++)
	{
		if (iscyclic(adj, visited, stack, i))
			cycle = 1;
	}
	cout << cycle;

}
