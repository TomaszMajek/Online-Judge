#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int Pearls, p;

    while (cin >> Pearls) {
        if (Pearls == 0) 
            break;

        vector <int> tab;
        tab.push_back(Pearls);

        while (cin >> p) {
            if (p == 0) 
                break;
            tab.push_back(p);
        }
        if (tab.size() == 1) 
            cout << tab[0] << endl;
        else if (tab.size() % 2 == 0) 
            cout << "NO" << endl;
        else {
            int flag = 0;
            sort(tab.begin(), tab.end());
            for (int i = 0; i < tab.size(); i = i + 2) {
                if (i + 1 < tab.size() && tab[i] != tab[i + 1]) {
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag != 1) {
                int x = 0;
                for (int i = 0; i < tab.size(); i++) {
                    if (i <= tab.size() / 2) {
                        cout << tab[x] << " ";
                        x += 2;
                    }
                    else if (x >= tab.size()) {
                        x -= 3;
                        cout << tab[x] << " ";
                    }
                    else {
                        x -= 2;
                        cout << tab[x] << " ";
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
