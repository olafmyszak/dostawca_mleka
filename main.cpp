#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using graph = map<int, vector<int>>;

int BFS(graph& villages, int src, int dest)
{
	queue<int> queue;
	size_t size = villages.size();

	vector<bool> visited(size, false);
	vector<int> dist(size);

	visited[src] = true;
	dist[src] = 0;
	queue.push(src);

	while(!queue.empty())
	{
		int u = queue.front();
		queue.pop();

		size = villages[u].size();

		for(int i=0; i<size; ++i)
		{
			int curr = villages[u][i];
			if(!visited[curr])
			{
				visited[curr] = true;
				dist[curr] = dist[u] + 1;
				queue.push(curr);

				if(curr == dest)
				{
					return dist[curr];
				}
			}
		}

	}

	return 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	unsigned int n, m;

	cin>>n>>m;

	graph villages;

	map<string, int> village_names;


	for (int i = 0; i < n; ++i)
	{
		string village_name;
		cin>>village_name;

		village_names[village_name] = i;
	}

	vector<int> neighbours;

	for (int i = 0; i < n; ++i)
	{
		string line;

		while (true)
		{
			cin>>line;

			if(line != "X")
			{
				neighbours.push_back(village_names[line]);
			}
			else
				break;
		}

		villages[i] = neighbours;
		neighbours.clear();
	}

	string src;
	cin>>src;

	vector<string> dest(m);

	for(int i=0; i<m; ++i)
	{
		string line;
		cin>>line;
		dest[i] = line;
	}

	int max_dist = BFS(villages, village_names[src], village_names[dest[0]]);

	for(int i = 1; i<m; ++i)
	{
		int dist = BFS(villages, village_names[src], village_names[dest[i]]);

		if(dist > max_dist)
		{
			max_dist = dist;
		}
	}

	cout<<max_dist;

	return 0;
}