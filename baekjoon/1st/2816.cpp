#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, arr[101], kbs1, kbs2;
	string str;

	memset(arr, 0, sizeof(arr));

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		if (str == "KBS1")
		{
			arr[i] = 1;
			kbs1 = i;
		}
		if (str == "KBS2")
		{
			arr[i] = 2;
			kbs2 = i;
		}
	}

	if (kbs1 > kbs2)
		kbs2++;

	for (int i = 0; i < kbs1; ++i)
		putchar('1');
	
	for (int i = 0; i < kbs1; ++i)
		putchar('4');

	for (int i =0; i < kbs2; ++i)
		putchar('1');
	
	for (int i = 0; i < kbs2 - 1; ++i)
		putchar('4');


	return (0);
}