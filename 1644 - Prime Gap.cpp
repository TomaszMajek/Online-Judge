#include <iostream>

using namespace std;

void prime(bool* tab, unsigned int n) {
	for (int i = 2; i * i <= n; i++) {
		if (!tab[i]) {
			for (int j = i * i; j <= n; j += i)
				tab[j] = 1;
		}
	}
}


int main()
{
	int liczba;
	int n;
	bool* tab;

	while (cin >> liczba) {
		
		n = liczba + 200;
		tab = new bool[n + 1];
		for (int i = 2; i <= n; i++) {
			tab[i] = 0;
		}
		prime(tab, n);
		int pierwsza, wynik, flaga = 0;

		if (liczba == 0) {
			return 0;
		}


		if (tab[liczba] == 0) {
			wynik = 0;
			flaga = 1;
		}

		if (flaga == 0)	{
			while (tab[liczba] == 1) {
				liczba--;
			}

			for (int i = liczba + 1; i < 1300000; i++) {
				if (tab[i] == 0) {
					pierwsza = i;
					break;
				}
			}

			wynik = pierwsza - liczba;
		}
		cout << wynik << endl;
	}
}
