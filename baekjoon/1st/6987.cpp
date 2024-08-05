#include <iostream>
#include <memory.h>

using namespace std;

int arr[6][3];
bool flag = false;

void	dfs(int idx, int next, int depth)
{
	if (idx == 5 && depth == 15)
	{
		flag = true;
		for (int i = 0; i < 6; ++i)
			for (int j = 0; j < 3; ++j)
				if (arr[i][j]) flag = false;
		return;
	}

	//두 국가간의 승 패가 있는 경우
	if (arr[idx][0] > 0 && arr[next][2] > 0)
	{
		arr[idx][0]--;
		arr[next][2]--;
		dfs(idx, next + 1, depth + 1);
		arr[idx][0]++;
		arr[next][2]++;
	}
	//두 국가가 모두 무승부가 있을 경우
	if (arr[idx][1] > 0 && arr[next][1] > 0)
	{
		arr[idx][1]--;
		arr[next][1]--;
		dfs(idx, next + 1, depth + 1);
		arr[idx][1]++;
		arr[next][1]++;
	}
	if (arr[idx][2] > 0 && arr[next][0] > 0)
	{
		arr[idx][2]--;
		arr[next][0]--;
		dfs(idx, next + 1, depth + 1);
		arr[idx][2]++;
		arr[next][0]++;
	}
	if (idx < 5) dfs(idx + 1, idx + 2, depth);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 4; ++i)
	{
		memset(arr, 0, sizeof(arr));
		int c = 0;
		for (int j = 0; j < 18; ++j)
		{
			cin >> arr[j / 3][c++];
			if (c == 3) c = 0;
		}
		dfs(0, 1, 0);
		if (flag) cout << 1 << " ";
		else cout << 0 << " ";
		flag = false;
	}
	return (0);
}