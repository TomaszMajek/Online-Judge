#include <iostream>
#include <algorithm>
#define N 101

using namespace std;

int main()
{
	int map[N], graf[N][N];
	int a, b;
	int tc = 1;

	while (scanf("%d%d", &a, &b) && a&&b)
	{
		int i, j, k, idx = 0;
		if (a == 0 && b == 0)
			return 0;		

		for (i = 0; i < N; i++)
			fill(graf[i], graf[i] + N, 1e9);

		fill(map, map + N, 0);

		do
		{
			if (!map[a])
				map[a] = ++idx;

			if (!map[b])
				map[b] = ++idx;

			graf[map[a]][map[b]] = 1;

		} while (scanf("%d%d", &a, &b) && a&&b);

		//algorytm Floyd-Warshalla
		for (k = 0; k <= idx; k++)
			for (i = 0; i <= idx; i++)
				for (j = 0; j <= idx; j++)
					if (i != j && graf[i][k] + graf[k][j] < graf[i][j])
						graf[i][j] = graf[i][k] + graf[k][j];

		int suma = 0, licznik = 0;

		for (i = 0; i <= idx; i++)
			for (j = 0; j <= idx; j++)
				if (graf[i][j] < 1e9)
				{
					suma += graf[i][j];
					licznik++;
				}

		printf("Case %d: average length between pages = %.3f clicks\n", tc++, (float)suma / licznik);
	}

	return 0;
}