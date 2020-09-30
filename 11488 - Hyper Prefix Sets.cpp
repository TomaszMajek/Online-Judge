#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct nodes {
    int next[2];
    int count;
}

nodes[1000000];

void drzewo(int y) {
    nodes[y].next[0] = -1;
    nodes[y].next[1] = -1;
    nodes[y].count = 1;
}

int last = 1;

int dodaj(char chain[200], int str_length, int spr) {
    int y = 0;

    for (int i = 0; i < str_length; i++) {
        int x = chain[i] - 48;

        if (nodes[y].next[x] == -1) {
            nodes[y].next[x] = last;
            drzewo(last++);
            y = nodes[y].next[x];
        } else {
            y = nodes[y].next[x];
            nodes[y].count++;

            int score = (i + 1) * nodes[y].count;

            if (score > spr) {
                spr = score;
            } else {
                spr = spr;
            }
        }
    }

    return spr;
}


int main()
{
    int T, amount;
    char str[200];

    cin >> T;

    while (T--) {
        int spr = 0;
        int max_str_length = 0;
        int score;

        drzewo(0);

        cin >> amount;

        while (amount--) {
            cin >> str;

            int str_length = strlen(str);

            if (str_length > max_str_length) {
                max_str_length = str_length;
            } else {
                max_str_length = max_str_length;
            }
            spr = dodaj(str, str_length, spr);
        }

        if (max_str_length > spr) {
            score = max_str_length;
        } else {
            score = spr;
        }

        cout << score << endl;

    }
    return 0;
}
