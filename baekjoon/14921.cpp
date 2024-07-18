#include <iostream>
#include <cmath>

using namespace std;

int	MAX = 1e8;
int N;
int arr[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=0;i<N;++i) cin >> arr[i];

	int left = 0;
	int right = N - 1;
	int allmin = arr[left] + arr[right];

	while (left < right)
	{
		int sum = arr[left] + arr[right];
		if (abs(sum) < abs(allmin))
			allmin = sum;
		if (sum < 0)
			left++;
		else
			right--;
	}

	cout << allmin;
}