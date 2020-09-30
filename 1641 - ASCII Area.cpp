#include <iostream>
#include <string>

using namespace std;

int main()
{
	//char polygon[101][101];
	string polygon;
	int h, w;
	int i, j, k;
	int licznik, licznik2;

	while (cin >> h >> w) {
		licznik = 0;
		licznik2 = 0;
		for (i = 0; i < h; i++) {
			cin >> polygon;
			bool flaga = false;
			for (j = 0; j < w; j++) {
				if (polygon[j] == '/' || polygon[j] == '\\') {
					licznik = licznik + 1; // polowka
					flaga = !flaga;
				}
				else if (flaga) {
					licznik2 = licznik2 + 1; // pelny
				}
			}
		}
		cout << licznik2 + (licznik / 2) << endl;
	}
	return 0;
}
