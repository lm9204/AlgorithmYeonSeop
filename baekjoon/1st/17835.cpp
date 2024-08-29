#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> >	road[100005];
int	city[100005];
int n, m, k;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	int left, right, weight;
	for (int i = 0; i < m; ++i)
	{
		road[left].push_back({ right, weight });
		road[right].push_back({ left, weight });
	}
	for (int i = 0; i < k; ++i)
		cin >> city[i];



	return (0);
}