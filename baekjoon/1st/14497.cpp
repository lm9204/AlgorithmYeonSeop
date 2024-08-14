#include <iostream>
#include <string>
#include <queue>

using namespace std;

char arr[305][305];
int v[305][305];
int n, m;
typedef struct t { int y, x, w;  bool operator<(const t& other) const {return w > other.w;}} t;
priority_queue<t> q;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int x1, int y1, int x2, int y2)
{
	q.push({ y1, x1, 0 });
	v[y1][x1] = 1;

	while (!q.empty())
	{
		t cur = q.top(); q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int dy = cur.y + dir[i][0];
			int dx = cur.x + dir[i][1];

			if (dx < 0 || dx >= m || dy < 0 || dy >= n || v[dy][dx]) continue;
			v[dy][dx] = 1;
			if (arr[dy][dx] == '#')
				return cur.w + 1;
			if (arr[dy][dx] == '1')
			{
				arr[dy][dx] = '0';
				q.push({ dy, dx, cur.w + 1 });
			}
			else
				q.push({ dy, dx, cur.w });
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> y1 >> x1 >> y2 >> x2;
	x1--; y1--; x2--; y2--;

	string line;
	for (int i = 0; i < n; ++i)
	{
		cin >> line;
		for (int j = 0; j < m; ++j)
			arr[i][j] = line[j];
	}
	
	cout << bfs(x1, y1, x2, y2);
	return (0);
}