#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > arr[1005];

int bfs(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int visited[1005] = {0, };

	visited[start] = 1;
	pq.push({0, start});
	while(!pq.empty())
	{
		int w = pq.top().first;
		int curnode = pq.top().second;
		pq.pop();

		if (curnode == end)
			return (w);

		for (int i = 0; i < arr[curnode].size(); ++i)
		{
			int next = arr[curnode][i].first;
			int nextw = w + arr[curnode][i].second;

			if (visited[next]) continue;
			visited[next] = 1;
			pq.push({ nextw, next });
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	int left, right, weight;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> left >> right >> weight;
		arr[left].push_back({ right, weight });
		arr[right].push_back({ left, weight });
	}

	while(m--)
	{
		cin >> left >> right;
		cout << bfs(left, right) << "\n";
	}
	
	return (0);
}