#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int N, n;
	
	while (cin >> N) {
		if (N == 0)
			return 0;

		int suma = 0;
		int max = -1000;
		
		for (int i = 0; i < N; i++) {
			cin >> n;
			suma = suma + n;

			if (suma > max)
				max = suma;
			if (suma < 0)
				suma = 0;
		}

		if (suma > 0)
			cout << "The maximum winning streak is " << max << "." << endl;
		else
			cout << "Losing streak." << endl;

	}

}
