#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

using graph = unordered_map<int, vector<int>>;

int BFS(graph& villages, int src, const vector<int>& dest)
{
	queue<int> queue;
	size_t size = villages.size();

	vector<bool> visited(size, false);
	vector<int> dist(size);
	int *dist_to_dest = new int [dest.size()];
	int counter = 0;

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

				if(curr == dest[counter])
				{
					dist_to_dest[counter] = dist[curr];
					++counter;
				}
			}
		}

	}
	int *max_el = max_element(dist_to_dest, dist_to_dest+dest.size());

	int max = *max_el;

	delete [] dist_to_dest;

	return max;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	unsigned int n, m;

	cin>>n>>m;

	graph villages;

	unordered_map<string, int> village_names;

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

	vector<int> dest(m);

	for(unsigned int i=0; i<m; ++i)
	{
		string line;
		cin>>line;
		dest[i] = village_names[line];
	}

	int max_dist = BFS(villages, village_names[src], dest);

	cout<<max_dist;

	return 0;
}