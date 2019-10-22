#include <iostream>

using namespace std;

int main()
{
    int pokolenie;

    while(cin >> pokolenie){
        if (pokolenie < 0){
            return 0;
        }

        long long m = 0;
        long long f = 1;

        for(int i = 0; i < pokolenie; i++){
            long long past_bees = m;
            m = m + f;
            f = past_bees + 1;
        }
        cout << m << " " << m+f << endl;
    }
    return 0;
}
