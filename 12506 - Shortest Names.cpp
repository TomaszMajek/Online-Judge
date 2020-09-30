#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int testy;

	cin >> testy;

	while (testy--) {
		int ilosc_imion;

		cin >> ilosc_imion;

		string imiona[ilosc_imion];

		for (int i = 0; i < ilosc_imion; i++) {
			cin >> imiona[i];
		}

		sort(imiona, imiona + ilosc_imion);

		int j = 0;
		int k = 0;
		int wynik = 0;

		for (int i = 0; i < ilosc_imion; i++) {
			if (i + 1 == ilosc_imion) {
				wynik += j + 1;
				break;
			}

			for (j = 0; imiona[i][j] != '\0' || imiona[i + 1][j] != '\0'; j++) {
				if (imiona[i][j] != imiona[i + 1][j]) {
					break;
				}
			}
			if (j < k) {
				wynik += k;
			}
			else {
				wynik += j + 1;
			}

			k = j + 1;
		}
		cout << wynik << endl;
	}
}
