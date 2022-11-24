#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

struct node
{
  bool visited;
  string name;

  explicit node(string name) : visited(false), name(std::move(name))
  {}
};

using graph = map<string, vector<node>>;


template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector)
{
	for (const auto& element : vector) {
		os << element.name << " ";
	}
	return os;
}

int DFS(const string& starting_village, const string& destination, const graph& villages)
{
	 villages.at(starting_village);

}


int main()
{
	unsigned int n, m;

	cin>>n>>m;

	graph villages;
	string village_name;
	vector<string> village_names;

	for (int i = 0; i < n; ++i)
	{
		cin>>village_name;
		village_names.push_back(village_name);
	}

	vector<node> neighbours;

	for (int i = 0; i < n; ++i)
	{
		string line;

		while (true)
		{
			cin>>line;

			if(line != "X")
			{
				node neighbour = node(line);
				neighbours.push_back(neighbour);
			}
			else
				break;
		}

		villages[village_names[i]] = neighbours;
		neighbours.clear();
	}

	for(const auto& elem : villages)
	{
		std::cout << elem.first << " " << elem.second << "\n";

	}

	return 0;
}
