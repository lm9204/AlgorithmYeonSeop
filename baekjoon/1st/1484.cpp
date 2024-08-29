#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int g, left, right, curg, mid;
	cin >> g;
	vector<int> ans;
	for (int i = 1; i <= 50000; i++)
	{
		left = 1, right = i;
		while (left <= right)
		{
			mid = (left + right) / 2;
			curg = (i * i) - (mid * mid);
			if (curg == g)
			{
				ans.push_back(i);
				break ;
			}
			else if (curg > g) left = mid + 1;
			else right = mid - 1;
		}
	}
	if (ans.size() == 0) cout << -1;
	else
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << "\n";
	return (0);
}