#include <iostream>
#include <vector>

using std::vector;
using std::pair;
void explore(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ccnum, int x, int cc)
{
	visited[x] = 1;
	ccnum[x] = cc;
	for (int i = 0; i < adj[x].size(); i++) 
	{
		if (!visited[adj[x][i]])
		{
			explore(adj, visited, ccnum, adj[x][i], cc);
		}
	}

}

int number_of_components(vector<vector<int> > &adj, vector<bool> &visited, int n) {
	int res = 0;
	for (int i = 0; i < visited.size(); i++) 
	{
		visited[i] = 0;
	}

	vector<int> ccnum(n, 0);
	int cc = 0;
	for (int x = 0; x < n; x++) 
	{
		
			if (!visited[x])
			{
				explore(adj, visited, ccnum, x, cc);
				cc++;
			}
		
	}
	res = cc;
	return res;
}



void connected_components_test() 
{
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	vector<bool> visited(n, 0);
	std::cout << number_of_components(adj, visited, n);
}

int main(){
	connected_components_test();
	return 0;
}