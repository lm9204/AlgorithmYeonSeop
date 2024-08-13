#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9

vector<pair<int, int> > v[50005];
int dist[50005];
priority_queue<pair<int, int> > q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, start, end, w;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end >> w;
		v[start].push_back({ end, w });
		v[end].push_back({ start, w });
	}

	for (int i = 0; i <= n; ++i) dist[i] = INF;
	q.push({ 0, 1 });
	dist[1] = 0;
	while (!q.empty())
	{
		int cost = -q.top().first;
		int cur = q.top(). second;
		q.pop();
		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int newcost = v[cur][i].second + cost;
			if (dist[next] > newcost)
			{
				dist[next] = newcost;
				q.push({ -dist[next], next });
			}
		}
	}
	cout << dist[n];
	return (0);

}