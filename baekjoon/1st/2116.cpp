#include <iostream>
#include <vector>

using namespace std;

vector<int[6]> dices;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int dice[6];
		for (int j = 0; j < 6; ++j)
			cin >> dice[j];
		dices.push_back(dice);
	}

	

	return (0);
}