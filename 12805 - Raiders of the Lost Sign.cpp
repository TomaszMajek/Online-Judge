#include <iostream>
#include <cmath>
#include <vector>
#define MAX 100001

int primes[MAX];

void prime() {
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i < MAX; i++) {
        primes[i] = i;
    }
    for (int i = 2; i < sqrt(MAX); i++) {
        if (primes[i] != 0) {
            for (int j = 2; j * i <= MAX; j++) {
                primes[j * i] = 0;
            }
        }
    }
}

using namespace std;

int main()
{
    prime();
    int n;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (primes[n]) {
            if ((n - 1) % 4 == 0) cout << "-" << endl;
            else if ((n + 1) % 4 == 0 || n == 2) cout << "+" << endl;
        }
        else {
            int sub = 2;
            vector <int> d;
            while (!primes[n]) {
                if (n % sub == 0) {
                    n = n / sub;
                    d.push_back(sub);
                    sub = 2;
                }
                else {
                    sub++;
                }
            }

            int znak = 1;
            if ((n - 1) % 4 == 0) znak *= -1;
            for (int i = 0; i < d.size(); i++) {
                if ((d[i] - 1) % 4 == 0) 
                    znak *= -1;
            }
            if (znak < 0) 
                cout << "-" << endl;
            if (znak > 0) 
                cout << "+" << endl;
        }
    }
    return 0;
}
