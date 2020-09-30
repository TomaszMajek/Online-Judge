#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring> 

#define RANGE 10
using namespace std;

int main()
{
	int tc;
	int N;
	int being_summed[RANGE];
	int temp;
	cin >> tc;
	while (tc--)
	{
		cin >> N;
		memset(being_summed, 0, sizeof(int) * RANGE);

		for (int i = 0; i <= N; i++) {
			temp = i;
			while (temp) {
				switch (temp % 10) {
					case 0: being_summed[0]++; break;
					case 1: being_summed[1]++; break;
					case 2: being_summed[2]++; break;
					case 3: being_summed[3]++; break;
					case 4: being_summed[4]++; break;
					case 5: being_summed[5]++; break;
					case 6: being_summed[6]++; break;
					case 7: being_summed[7]++; break;
					case 8: being_summed[8]++; break;
					case 9: being_summed[9]++; break;
				}
				temp /= 10;
			}
		}
		for (int i = 0; i < RANGE; i++)
		{
			cout << being_summed[i];
			if (i == 9) 
				cout << endl;
			else 
				cout << " ";
		}
	}
	return 0;
}