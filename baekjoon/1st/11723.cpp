#include <iostream>

using namespace std;

int arr[21];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, target;
	string cmd;

	cin >> n;

	while (n--)
	{
		cin >> cmd;

		if (cmd == "add")
		{
			cin >> target;
			arr[target] = 1;
		}
		else if (cmd == "remove")
		{
			cin >> target;
			arr[target] = 0;
		}
		else if (cmd == "check")
		{
			cin >> target;
			if (arr[target])
				putchar('1');
			else
				putchar('0');
			putchar('\n');
		}
		else if (cmd == "toggle")
		{
			cin >> target;
			if (arr[target])
				arr[target] = 0;
			else
				arr[target] = 1;
		}
		else if (cmd == "all")
		{
			for (int i = 1; i <= 20; ++i)
				arr[i] = 1;
		}
		else if (cmd == "empty")
		{
			for (int i = 1; i <= 20; ++i)
				arr[i] = 0;
		}
	}

	return (0);
}