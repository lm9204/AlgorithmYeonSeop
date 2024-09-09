#include <iostream>
#include <queue>

using namespace std;

 int winConditions[8][3] = {
	{0, 1, 2}, // 가로 첫 줄
	{3, 4, 5}, // 가로 둘째 줄
	{6, 7, 8}, // 가로 셋째 줄
	{0, 3, 6}, // 세로 첫 줄
	{1, 4, 7}, // 세로 둘째 줄
	{2, 5, 8}, // 세로 셋째 줄
	{0, 4, 8}, // 대각선 왼쪽 위에서 오른쪽 아래
	{2, 4, 6}  // 대각선 오른쪽 위에서 왼쪽 아래
};

//0: invalid, 1: valid
int isvalid(const string& tic)
{
	bool xWins = false, oWins = false;
	int cx = 0, co = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (tic[i] == 'X')
			cx++;
		if (tic[i] == 'O')
			co++;
	}
	for (int i = 0; i < 8; ++i)
	{
		if (tic[winConditions[i][0]] != '.'
		&& tic[winConditions[i][0]] == tic[winConditions[i][1]]
		&& tic[winConditions[i][1]] == tic[winConditions[i][2]])
		{
			if (tic[winConditions[i][0]] == 'X') xWins = true;
			if (tic[winConditions[i][0]] == 'O') oWins = true;
		}
	}
	if (xWins && !oWins && cx - co == 1) return 1;
	if (oWins && !xWins && cx == co ) return 1;
	if (!xWins && !oWins && cx == 5 && co == 4) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	while (getline(cin, s))
	{
		if (s == "end")
			break;
		if (isvalid(s))
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
	return (0);
}