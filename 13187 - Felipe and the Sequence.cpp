#include <iostream>

using namespace std;

int main()
{
	int t;
	long long liczba;
	cin >> t;
	while (t--) {
		cin >> liczba;
		
		cout << liczba * (liczba + 2) << endl;
	}

	return 0;
}
