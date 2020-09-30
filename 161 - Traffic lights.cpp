#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>

using namespace std;

bool zielone(vector <int>& v, int c) {
	int it = 0;

	for (int i = 0; i < v.size(); i++)	{
		if (c % (2 * v[i]) < v[i] - 5) {
			it++;
		}
	}

	if (it == v.size()) {
		return true;
	}
	else {
		return false;
	}

}

int main() {
	int a;

	while (cin >> a) {
		if (a == 0)	{
			break;
		}

		vector <int> swiatla;
		swiatla.push_back(a);

		int min = a;
		int b;

		while (cin >> b) {
			if (b == 0)	{
				break;
			}

			swiatla.push_back(b);

			if (min > b) {
				min = b;
			}
		}

		int czas = 0;
		bool spr = false;

		for (int i = min * 2; i <= 20000; i++) {
			if (zielone(swiatla, i)) {
				spr = true;
				czas = i;
				break;
			}
		}


		if (spr == true) {
			cout << setfill('0') << setw(2) << czas / 3600 << ":" << setfill('0') << setw(2) << czas % 3600 / 60 << ":" << setfill('0') << setw(2) << czas % 60 << endl;
		}
		else {
			cout << "Signals fail to synchronise in 5 hours" << endl;
		}
	}
	return 0;
}
