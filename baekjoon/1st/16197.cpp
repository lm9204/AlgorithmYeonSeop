#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int board[22][22];

typedef struct coins { int x1, y1, x2, y2, count; } coins;

queue<coins > q;
vector<pair<int, int> > c;
int visited[21][21][21][21];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	char s;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> s;
			if (s == '#')
				board[i][j] = 1;
			if (s == 'o')
				c.push_back({ i, j });
		}
	}
	
	visited[c[0].second][c[0].first][c[1].second][c[1].first] = 1;
	q.push({c[0].second, c[0].first, c[1].second, c[1].first, 0});
	while (!q.empty())
	{
		struct coins co = q.front();
		q.pop();

		if (co.count > 10) continue;
		if ((co.x1 <= 0 || co.x1 > m || co.y1 <= 0 || co.y1 > n)
		&& (co.x2 <= 0 || co.x2 > m || co.y2 <= 0 || co.y2 > n))
			continue;
		if ((co.x1 <= 0 || co.x1 > m || co.y1 <= 0 || co.y1 > n)
		|| (co.x2 <= 0 || co.x2 > m || co.y2 <= 0 || co.y2 > n))
		{
			cout << co.count;
			return (0);
		}

		for (int i = 0; i < 4; ++i)
		{
			int dx1 = co.x1 + dir[i][1];
			int dx2 = co.x2 + dir[i][1];
			int dy1 = co.y1 + dir[i][0];
			int dy2 = co.y2 + dir[i][0];

			if (board[dy1][dx1])
				dx1 = co.x1, dy1 = co.y1;
			if (board[dy2][dx2])
				dx2 = co.x2, dy2 = co.y2;
			if (visited[dx1][dy1][dx2][dy2]) continue;
			visited[dx1][dy1][dx2][dy2] = 1;
			q.push({ dx1, dy1, dx2, dy2, co.count + 1});
		}
	}
	cout << -1;
	return (0);
}