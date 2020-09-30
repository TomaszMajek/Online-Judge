#include <iostream>

using namespace std;

int check(int s, int x, int i) {
	if (s == x)
		return i - 1;
	else if (s < x)
		return 0;
	else
		return check(s, x + i + 1, i + 1);
}

int main()
{
	int T, S, answer;
	cin >> T;
	while (T--) {
		cin >> S;
		answer = check(S, 1, 1);
		if (answer == 0)
			cout << "No solution" << endl;
		else
			cout << answer << endl;
	}

	return 0;
}