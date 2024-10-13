#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int n;

#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	vector<pair<ll, ll> > arr(n);
	
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;
	arr.push_back(arr[0]);

	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += arr[i].first * arr[i + 1].second - arr[i + 1].first * arr[i].second;

	double d = abs(ans) / 2.0;
		cout << fixed << setprecision(1) << d;
	return (0);
}