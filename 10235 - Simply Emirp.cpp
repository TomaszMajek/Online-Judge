#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int reverse_prime(int n) {
	int mod, reverse_n = 0;

	while (n != 0) {
		mod = n % 10;
		reverse_n = reverse_n * 10 + mod;
		n = n / 10;
	}
	return reverse_n;
}

int main()
{
	int N;
	vector<int> pr;
	const int max = 1000000;
	bool tab[max];



    //sito Eratostenesa
    tab[0] = tab[1] = 0;
    for (int i = 2; i < max; i++)
        tab[i] = 1;
    for (int i = 2; i< sqrt(max); i++)
        if (tab[i] == 1)
            for (int j = 2; i*j < max; j++) {
                tab[i*j] = 0;
            }

	while (cin >> N) {
		if (N > max)
			return 0;

		int emirp = reverse_prime(N);

		if (tab[N] == true) {
			if (tab[emirp] == true && N > 9 && N != emirp) {
				cout << N << " is emirp." << endl;
			}
			else
				cout << N << " is prime." << endl;
		}
		else {
			cout << N << " is not prime." << endl;
		}
	}

	return 0;
}
