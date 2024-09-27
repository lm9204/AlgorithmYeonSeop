#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

vector<pair<int, int> > walls;
bool visited[9][9][10];
int map[9][9];
int dir[8][2] = {
	{0, 1},
	{-1, 0},
	{0, -1},
	{-1, -1},
	{-1, 1},
	{1, -1},
	{1, 1},
	{0, 0}
};

bool	isMovable(int x, int y, int t)
{
	if (t > 8)
		return true;
	bool flag = true;
	
	for (auto it = walls.begin(); it != walls.end(); )
	{
		if (it->second == x && it->first + t == y)
			flag = false;
		if (it->first + t >= 8)
			it = walls.erase(it);
		else
			++it;
	}
	return flag;
}

int bfs()
{
	queue<tuple<int, int, int> > q;
	q.push({7, 0, 0});

	while (!q.empty())
	{
		auto [y, x, t] = q.front();
		q.pop();

		if (y == 0 && x == 7)
			return 1;
		if (!isMovable(x, y, t))
			continue;

		for (int i = 0; i < 8; ++i)
		{
			int dy = y + dir[i][0];
			int dx = x + dir[i][1];

			if (dx < 0 || dx >= 8 || dy < 0 || dy >= 8) continue;
			if (visited[dy][dx][t] || !isMovable(dx, dy, t)) continue;
			visited[dy][dx][t] = 1;
			q.push({ dy, dx, t + 1 });
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			char c;
			cin >> c;
			if (c == '.')
				map[i][j] = 0;
			else if (c == '#')
			{
				map[i][j] = 1;
				walls.push_back({ i, j });
			}
		}
	}

	cout << bfs();
	return (0);
}