#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int conns[30][30];
    int a, b;
    int NC, starting_node, TTL;
    int iter = 1;
    while (scanf("%d", &NC)) {
        if (NC == 0) 
            break;
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++)
                conns[i][j] = 100;
            conns[i][i] = 0;
        }
        map<int, int> network;
        map<int, int>::iterator node;
        int x = 0, y = 0, rozmiar = 0;
        while (NC--) {
            cin >> a >> b;

            node = network.find(a);

            if (node == network.end()) { 
                network[a] = rozmiar; x = rozmiar; rozmiar++; }
            else 
                x = node->second;

            node = network.find(b);

            if (node == network.end()) { 
                network[b] = rozmiar; y = rozmiar; rozmiar++; }
            else 
                y = node->second;

            conns[x][y] = conns[y][x] = 1;

            if (x == y) 
                conns[x][x] = 0;
        }
        for (int k = 0; k < rozmiar; k++)
            for (int i = 0; i < rozmiar; i++)
                for (int j = 0; j < rozmiar; j++) {
                    if (conns[i][j] > conns[i][k] + conns[k][j])
                        conns[i][j] = conns[i][k] + conns[k][j];
                }

        while (scanf("%d", &starting_node) && scanf("%d", &TTL)) {
            if (starting_node == 0 && TTL == 0) 
                break;
            node = network.find(starting_node);
            int counter = 0;
            for (int i = 0; i < rozmiar; i++) {
                if (conns[i][node->second] > TTL) {
                    counter++;
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", iter, counter, starting_node, TTL);
            iter++;
        }
    }

    return 0;
}
