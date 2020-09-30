#include <iostream>

using namespace std;

int main()
{
	int T;
	int N, R;
	int tab[100][100];
	int i, j, k;
	int u, v;
	int s, d;
	int licznik = 1;

	cin >> T;
	while (T-- != 0) {
		
		cin >> N >> R;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				tab[i][j] = (i == j) ? 0 : 100;
			}
		}
		
		while (R--) {
			cin >> u >> v;
			tab[u][v] = 1;
			tab[v][u] = 1;
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (tab[i][j] > tab[i][k] + tab[k][j]) {
						tab[i][j] = tab[i][k] + tab[k][j];
					}
				}
			}
		}
		
		cin >> s >> d;
		int ans = 0;
		for (i = 0; i < N; i++) {
			if (tab[s][i] + tab[i][d] > ans) {
				ans = tab[s][i] + tab[i][d];
			}
		}
		cout << "Case " << licznik++ << ": " << ans << endl;
	}
	return 0;
}
