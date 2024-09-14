#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r1, r2;

vector<pair<int, int> > rooms[100005];
bool visited[100005];
bool flag = false;

void dfs(int x, int sum, int max_dist)
{
	if (flag) return;
	if (x == r2)
	{
		cout << sum - max_dist;
		flag = true;
		return ;
	}

	for (int i = 0; i < rooms[x].size(); ++i)
	{
		int nextn = rooms[x][i].first;
		int nextw = rooms[x][i].second;

		if (visited[nextn]) continue;
		visited[nextn] = 1;
		dfs(nextn, sum + nextw, max(max_dist, nextw));
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> r1 >> r2;

	for (int i = 0; i < n - 1; ++i)
	{
		int room1, room2, weight;
		cin >> room1 >> room2 >> weight;

		rooms[room1].push_back({ room2, weight });
		rooms[room2].push_back({ room1, weight });
	}

	visited[r1] = 1;
	dfs(r1, 0, 0);
	return (0);
}