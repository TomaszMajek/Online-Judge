#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	bool flaga;

	while (cin >> n >> m) {
		flaga = true;
		vector <long> vec;
		vec.push_back(n); //wpisz n do wektora

		if (n < 2 || m < 2 || n < m) {
			cout << "Boring!" << endl;
		}
		else {
			while (n != 1) {
				if (n % m == 0) {
					n = n / m;
					vec.push_back(n);
				}
				else {
					flaga = false;
					break;
				}
			}

			if (flaga == true) {
				for (int i = 0; i < vec.size(); i++) {
					cout << vec[i] << " ";
				}
				cout << endl;
			}
			else
				cout << "Boring!" << endl;
		}
	}

	return 0;
}

