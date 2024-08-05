#include <iostream>
#include <queue>

using namespace std;

int map[105][105];
int visited[105][105][2];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

typedef struct { int x, y, k; } point;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, t;
	cin >> n >> m >> t;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];

	queue<point> q;
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;

	int size;
	for (int i = 0; i <= t; ++i)
	{
		size = q.size();
		while (size--)
		{
			point cur = q.front(); q.pop();
			if (cur.x == m - 1 && cur.y == n - 1)
			{
				cout << i;
				return (0);
			}

			for (int j = 0; j < 4; ++j)
			{
				int nx = cur.x + dir[j][0];
				int ny = cur.y + dir[j][1];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
				if ((cur.k == 1 || map[ny][nx] == 2) && !visited[ny][nx][1])
				{
					visited[ny][nx][1] = 1;
					q.push({ nx, ny, 1 });
				}
				else
				{
					if (!visited[ny][nx][0] && !map[ny][nx])
					{
						visited[ny][nx][0] = 1;
						q.push({ nx, ny, 0});
					}
				}
			}
		}
	}

	cout << "Fail";
	return (0);
}