#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;
using namespace std;

void explore(vector<vector<int>> &adj, vector<bool> &visited, int x, vector<int> &used, vector<int> &order)
{
	visited[x] = 1;

	for (int i = 0; i < adj[x].size(); i++)
	{
		if (!visited[adj[x][i]])
		{
			explore(adj, visited, adj[x][i], used, order);
		}
	}
	vector<int>::iterator it=order.begin();
	if (!used[x])
	{
		order.insert(it, x);
		used[x] = 1;
	}


}

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order,vector<bool> &visited) 
{
	for (int i = 0; i < visited.size(); i++)
	{
		visited[i] = 0;
	}

	for (int j = 0; j < adj.size(); j++)
	{

		if (!visited[j])
		{
			explore(adj, visited, j, used, order);
		}

	}
	
	
}



vector<int> toposort(vector<vector<int> > adj) 
{
	vector<int> used(adj.size(), 0);
	vector<int> order;
	vector<bool> visited(adj.size(), 0);
	dfs(adj, used, order, visited);
	return order;
}
int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
