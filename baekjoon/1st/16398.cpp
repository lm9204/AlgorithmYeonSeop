#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1001];
int map[1001][1001];
vector<pair<int, pair<int, int> > > v;

// 해당 노드의 루트를 찾음 (최종 부모)
int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	v.reserve(n * n + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> map[i][j];
	
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 1;  i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			v.push_back({ map[i][j], { i, j }});

	sort(v.begin(), v.end());
	long long ans = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		if (find(v[i].second.first) == find(v[i].second.second)) continue;
		ans += v[i].first;
		merge(v[i].second.first, v[i].second.second);
	}

	cout << ans;
	return (0);
}