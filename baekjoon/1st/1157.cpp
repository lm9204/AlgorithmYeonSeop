#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int alphabet[26];
	string line;

	memset(alphabet, 0, sizeof(alphabet));
	cin >> line;

	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] >= 97)
			alphabet[line[i] - 97]++;
		else
			alphabet[line[i] - 65]++;
	}

	int maxn = 0;
	
	for (int i = 0; i < 26; ++i)
	{
		if (alphabet[maxn] < alphabet[i])
			maxn = i;
	}
	sort(alphabet, alphabet + 26);

	if (alphabet[25] == alphabet[24])
		cout << "?";
	else
		cout << (char)(maxn + 65) << "\n";

	return (0);
}