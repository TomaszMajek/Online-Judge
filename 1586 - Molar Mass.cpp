#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int t;
	string input;
	double numbers[100];

	cin >> t;
	while (t--) {
		double sum = 0;
		cin >> input;

		for (int i = 0; i < input.length(); i++) {
			if (input[i] == 'C') {
				numbers[i] = 12.01;
			}
			else if (input[i] == 'H') {
				numbers[i] = 1.008;
			}
			else if (input[i] == 'O') {
				numbers[i] = 16.00;
			}
			else if (input[i] == 'N') {
				numbers[i] = 14.01;
			}
			else {
				numbers[i] = input[i] - '0';
			}

			// 48..57 to liczby od 0..9 w ASCII
			if (input[i] >= 48 && input[i] <= 57) {

				//jeśli mamy np. H i potem dwucyfrową liczbę to:
				if (input[i-1] >= 48 && input[i-1] <= 57) {
					sum = sum - (numbers[i - 2] * numbers[i-1]);
					sum = sum + (numbers[i - 2] * (numbers[i-1] * 10 + numbers[i]));
				}
				else {
					sum = sum + (numbers[i - 1] * numbers[i]);
					sum -= numbers[i - 1];
				}
			}
			else {
				sum += numbers[i];
			}
		}
		cout << setprecision(3) << fixed << sum << endl;
	}
	return 0;
}