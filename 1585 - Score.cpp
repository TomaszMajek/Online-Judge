#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T-- > 0) {

		//wpisywanie T stringow
		string input;
		cin >> input;

		int wynik = 0;	
		int ciag = 0;

		for (int i = 0; i < input.length(); i++) {
			ciag = input[i] == 'O' ? ciag + 1 : 0; // jesli input[1] wynosi 'O', do zmiennej 'ciag' dodaj 1, a jeśli nie to wynik = 0;
			wynik = wynik + ciag; 
		}
		cout << wynik << endl;
	}

	return 0;
}
