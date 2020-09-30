#include <stdio.h>
#include <iostream>

using namespace std;
int main() {

	int n, s;

	while (cin >> n >> s) 
	{
		int tail = 0;
		int min = n;
		int number[n];
		int sum = 0, k = 0;
		
		for (int i = 0; i < n; i++) 
		{
			cin >> number[i];	
		}
		
			
		for (int i = 0; i < n; i++) 
		{
			sum = sum + number[i];
			
			while (sum >= s) 
			{
				if (min > (i - k + 1))
				{
					 min = i - k + 1;
				}
				
				sum = sum - number[k];
				k++;
				tail = 1;
			}
		}
		
		if (tail == 0) min = 0;
		{
		cout << min << endl;
		}
	}
}
