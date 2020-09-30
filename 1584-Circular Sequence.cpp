#include <iostream>
#include <string>

#define MAX 101
#define MIN 2

using namespace std;

int main()
{
	int testcases;
	string seq, tmp, ans;

	cin >> testcases;
	while (testcases--) {
		cin >> seq;
		ans = seq;
		int length = seq.size();

		if (length < MIN && length > MAX) {
			return 0;
		}
		else {
			for (int i = 0; i < length; i++) {
				tmp.clear();
				int count = 0;
				for (int j = i; j < length; j++) {
					tmp = tmp + seq[j];					
				}
				while (tmp.size() != seq.size()) {
					tmp = tmp + seq[count];
					count++;
				}
				if (tmp < ans) {
					ans = tmp;
				}
			}	

			cout << ans << endl;
		}
	}


	return 0;
}
