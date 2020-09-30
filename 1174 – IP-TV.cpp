#include <iostream>
#include <stdio.h>
#include <string>
#include <map>


using namespace std;

int graf[2000][2000];
int odwiedzone[10000];
int waga[10000];

int main()
{
	int n, m;
	int testy;
	int wiersz, wierzcholki, koszt, i;

	cin >> testy;

	for (int z = 0; z < testy; z++) {
		cin >> n >> m;
		for (int e = 0; e < n; e++) {
			odwiedzone[e] = 0;
			waga[e] = 1000;
			for (int r = 0; r < n; r++) {
				graf[e][r] = 0;
			}
		}

		int x = 0, y = 0, rozmiar = 0;

		map<string, int> network;
		map<string, int>::iterator node;

		for (int q = 0; q < m; q++)
		{
			string miastoa, miastob;
			int wagaa;
			cin >> miastoa >> miastob >> wagaa;

			node = network.find(miastoa);
			if (node == network.end()) {
				network[miastoa] = rozmiar;
				x = rozmiar;
				rozmiar++;
			} 
			else {
				x = node->second;
			}

			node = network.find(miastob);

			if (node == network.end()) {
				network[miastob] = rozmiar;
				y = rozmiar;
				rozmiar++;
			}
			else {
				y = node->second;
			}

			graf[x][y] = graf[y][x] = wagaa;
		}
		
		wiersz = 1;
		waga[wiersz] = 0;
		wierzcholki = 1;
		odwiedzone[wiersz] = 1;

		while (wierzcholki != n) {
			for (i = 0; i < n; i++)	{
				if (graf[wiersz][i] != 0) {
					if (odwiedzone[i] == 0)	{
						if (waga[i] > graf[wiersz][i]) {
							waga[i] = graf[wiersz][i];
						}
					}
				}
			}
			koszt = 1000;
			for (i = 0; i < n; i++)	{
				if (odwiedzone[i] == 0) {
					if (waga[i] < koszt) {
						koszt = waga[i];
						wiersz = i;
					}
				}
			}
			odwiedzone[wiersz] = 1;
			wierzcholki++;
		}

		koszt = 0;

		for (i = 0; i < n; i++) {
			koszt += waga[i];
		}
		cout << koszt << endl;
	}
	return 0;
}
