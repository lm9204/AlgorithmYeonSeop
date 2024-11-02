#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[10002];
int v[10002];
vector<pair<int, int> > e[10002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int V, E; cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		e[a].push_back({ c, b });
		e[b].push_back({ c, a });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (auto np : e[1])
		pq.push(np);
	visited[1] = 1;

	long long count = 0;
	long long weight = 0;
	while (count < V - 1)
	{
		auto [curw, curn] = pq.top(); pq.pop();

		if (visited[curn]) continue;
		visited[curn] = 1;
		count++;
		weight += curw;

		for (auto np: e[curn])
			if (!visited[np.second])
				pq.push(np);
	}

	cout << weight;
	return (0);
}