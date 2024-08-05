#include <iostream>
#include <string>

using namespace std;

string r = "IVXLCDM";
string r2 = "IVIXXLXCCDCM";
int	arr[] = {1, 5, 10, 50, 100, 500, 1000};
int arr2[] = {0, 4, 9, 40, 90 ,400 ,900};

int	getNum(char s);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int sum = 0;
	for (int i = 0; i < s1.length(); ++i)
	{
		int	n = getNum(s1[i]);
		if (n < getNum(s1[i + 1]))
			sum -= n;
		else
			sum += n;
	}

	for (int i = 0; i < s2.length(); ++i)
	{
		int	n = getNum(s2[i]);
		if (n < getNum(s2[i + 1]))
			sum -= n;
		else
			sum += n;
	}

	string output;
	int n = sum;

	while (n != 0)
	{
		for (int i = 6; i >= 0; --i)
		{
			if (n / arr[i] != 0)
			{
				n -= arr[i];
				output.push_back(r[i]);
				break;
			}
			if (i > 0 && n / arr2[i] != 0)
			{
				n -= arr2[i];
				output.push_back(r2[(i - 1) * 2]);
				output.push_back(r2[(i - 1) * 2 + 1]);
				break;
			}
		}
	}

	cout << sum << endl << output << endl;
}

int	getNum(char s)
{
	if (s == 0)
		return 0;
	return arr[r.find(s)];
}