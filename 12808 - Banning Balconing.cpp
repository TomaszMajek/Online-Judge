#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std; 

int main()
{
	int tc;
	float L, D, H, V;
	float s, t;

	cin >> tc;
	while (tc--) {
		cin >> L >> D >> H >> V;
		// na metry
		L /= 1000;
		D /= 1000;
		H /= 1000;
		V /= 1000;					// prędkość
		t = sqrt((2 * H) / 9.81);	// czas
		s = V * t;					// droga

		if ((s >= (D - 0.5) && s <= (D + 0.5)) || (s >= (D + L - 0.5) && s <= (D + L + 0.5)))
			cout << "EDGE" << endl;
		else if (s >= (D + 0.5) && s <= (D + L - 0.5))
			cout << "POOL" << endl;
		else
			cout << "FLOOR" << endl;

	}

	return 0;
}