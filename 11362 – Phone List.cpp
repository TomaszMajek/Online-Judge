#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int tc, n;
	int i;
	bool flaga;

    cin >> tc;
    while (tc--) {
        flaga = 0;
        cin >> n;
        string tablica[n];
        for (i = 0; i < n; i++){
            cin >> tablica[i];
        }

        sort(tablica, tablica + n);

        for (i = 0; i < n; i++){
            int znajdz = tablica[i].find(tablica[i-1]);
            if (znajdz == 0) {
                flaga = 1;
                break;
            }
        }
        if (flaga == 1){
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;

    }

	return 0;
}
