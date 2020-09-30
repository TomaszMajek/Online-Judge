#include <iostream>
#include <map>

using namespace std;

int main()
{
    int p, r, w = 1;
    string a, b;
    int tab[50][50];

    while (cin >> p >> r) {
        if (p == 0 && r == 0) 
            break;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                tab[i][j] = 1000000;
            }
            tab[i][i] = 0;
        }
        map <string, int> people;
        map <string, int>::iterator name;
        int x = 0, y = 0;
        int size = 0;
        while (r > 0) {
            cin >> a >> b;
            name = people.find(a);
            if (name == people.end()) {
                people[a] = size; 
                x = size; 
                size++;
            }
            else 
                x = name->second;

            name = people.find(b);
            if (name == people.end()) {
                people[b] = size;
                y = size;
                size++;
            } 
            else 
                y = name->second;

            tab[x][y] = tab[y][x] = 1;
            r--;
        }

        for (int k = 0; k < p; k++)
            for (int i = 0; i < p; i++)
                for (int j = 0; j < p; j++) {
                    if ((tab[i][k] == 1000000) || (tab[k][j] == 1000000)) 
                        continue;
                    if (tab[i][j] > tab[i][k] + tab[k][j])
                        tab[i][j] = tab[i][k] + tab[k][j];
                }
        int max = 0;
        int truth = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (tab[i][j] == 1000000) truth = 1;
                if (max < tab[i][j]) max = tab[i][j];

            }
        }

        if (truth == 1) 
            cout << "Network " << w << ": " << "DISCONNECTED" << endl << endl;
        else 
            cout << "Network " << w << ": " << max << endl << endl;
        w++;
    }
}