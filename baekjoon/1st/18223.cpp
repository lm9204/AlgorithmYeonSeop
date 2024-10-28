#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int v, e, p;

vector<pair<int, int> > graphs[5001];
int node[5002];

int	dijkstra(int startw, int startnode, int targetnode)
{
	fill(node, node + v + 1, 1e9);
	priority_queue<pair<int, int> > pq;

	node[startnode] = startw;
	pq.push({ -startw, startnode });
	while (!pq.empty())
	{
		auto [ curw, curnode ] = pq.top(); pq.pop();

		for (size_t i = 0; i < graphs[curnode].size(); ++i)
		{
			int nextw = -curw + graphs[curnode][i].first;
			int nextnode = graphs[curnode][i].second;

			if (node[nextnode] > nextw)
			{
				node[nextnode] = nextw;
				pq.push({ -nextw, nextnode });
			}
		}
	}

	return node[targetnode];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> v >> e >> p;
	for (int i = 1; i <= e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graphs[a].push_back({ c, b });
		graphs[b].push_back({ c, a });
	}

	if (dijkstra(0, 1, p) + dijkstra(0, p, v) == dijkstra(0, 1, v))
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";
	return (0);
}