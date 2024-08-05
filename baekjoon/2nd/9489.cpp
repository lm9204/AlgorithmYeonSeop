#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	while (cin >> n >> k)
	{
		if (n == 0 && k == 0)
			break;
		int arr[1005], parent[1000005], num, prev = 0, parent_idx = -1;

		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			arr[i] = num;

			if (i == 0)
				parent[num] = -1;
			else
			{
				if (prev + 1 == num)
					parent[num] = arr[parent_idx];
				else
					parent[num] = arr[++parent_idx];
			}
			prev = num;
		}
		
		int ans = 0;
		if (k != arr[0])
		{
			for (int i = 0; i < n; ++i)
			{
				if (parent[parent[arr[i]]] == parent[parent[k]] && parent[arr[i]] != parent[k])
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return (0);
}