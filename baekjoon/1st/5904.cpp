#include <iostream>

using namespace std;

int dp[30];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	dp[0] = 3;
	int targetK = 0, sum = 3;

	while (sum < n)
	{
		targetK++;
		sum = sum * 2 + targetK + 3;
		dp[targetK] = sum;
	}

	int curK = targetK;
	int idx = n;

	while (1)
	{
		int shoulder = dp[curK - 1];
		if (shoulder < idx && idx < shoulder + curK + 4)
		{
			if (idx - shoulder == 1)
				cout << "m";
			else
				cout << "o";
			break;
		}
		else
		{
			if (idx > shoulder)
				idx = idx - (shoulder + curK + 3);
			curK--;
		}
	}
	return (0);
}