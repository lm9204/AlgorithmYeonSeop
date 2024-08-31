#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, q;
vector<pair<int, long long> > graph[5001];
int visited[5001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n - 1; ++i)
	{
		int p, q;
		long long r;
		cin >> p >> q >> r;
		graph[p].push_back({ q, r });
		graph[q].push_back({ p, r });
	}

	for (int i = 0; i < q; ++i)
	{
		long long k;
		int v;

		cin >> k >> v;
		memset(visited, 0, sizeof(visited));
		int count = 0;
		queue<pair<int, long long> > q;
		visited[v] = 1;
		q.push({ v, k });

		while (!q.empty())
		{
			int cur = q.front().first;
			int curw = q.front().second;
			q.pop();

			for (int i = 0; i < graph[cur].size(); ++i)
			{
				int next = graph[cur][i].first;
				int nextw = graph[cur][i].second;

				if (visited[next] || nextw < k) continue;
				visited[next] = 1;
				count++;
				q.push({ next, nextw });
			}
		}
		cout << count << "\n";
	}
	return (0);
}