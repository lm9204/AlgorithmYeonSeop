#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[1005];
int	dp[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i=1; i <= n; ++i)
		dp[i] = 1;

	for (int i=0; i < m; ++i)
	{
		int left, right;

		cin >> left >> right;
		adj[left].push_back(right);
	}
	
	for (int i=1; i <= n; ++i)
	{
		for (int next : adj[i])
			dp[next] = max(dp[next], dp[i] + 1);
		cout << dp[i] << " ";
	}
}