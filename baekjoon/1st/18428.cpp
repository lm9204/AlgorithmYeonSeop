#include <iostream>
#include <vector>

using namespace std;

int arr[6][6];
int flag = 0, n;

vector<pair<int, int> > v, b;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int check_side(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int dy = y, dx = x;
		while (1)
		{
			dy += dir[i][0];
			dx += dir[i][1];
			if (dx < 0 || dx >= n || dy < 0 || dy >= n || arr[dy][dx] == 'O') break;
			if (arr[dy][dx] == 'T')
				return (0);
		}
	}
	return (1);
}
void backtracking(int left)
{
	if (flag) return;
	if (left == 0)
	{
		//test
		// cout << "\n";
		// for (int i = 0; i < n; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout << (char)arr[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }

		for (int i = 0; i < v.size(); ++i)
		{
			if (!check_side(v[i].first, v[i].second))
				return ;
		}
		flag = 1;
		return ;
	}
	
	for (int i = 0; i < b.size(); ++i)
	{
		int x = b[i].first;
		int y = b[i].second;

		if (arr[y][x] == 'X')
		{
			arr[y][x] = 'O';
			backtracking(left - 1);
			arr[y][x] = 'X';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;
			arr[i][j] = c;
			if (arr[i][j] == 'S')
				v.push_back({j, i});
			else if (arr[i][j] == 'X')
				b.push_back({j, i});
		}
	}

	backtracking(3);
	cout << (flag ? "YES" : "NO");
	return (0);
}