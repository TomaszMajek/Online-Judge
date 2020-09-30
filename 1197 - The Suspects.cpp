#include <iostream>
#include <vector>

using namespace std;


int tmp[30000];
int ans;
vector<int> g[30000];

void dfs(int x) {
	ans++;
	tmp[x] = 1;
	for (vector<int>::iterator it = g[x].begin(); it < g[x].end(); it++) {
		if (tmp[*it] == 0) {
			dfs(*it);
		}
	}
}


int main() {
	int students, groups, members;
	int i, j, x, y;
	while (cin >> students >> groups) {
		if (students == 0 && groups == 0) {
			return 0;
		}
		for (i = 0; i <= students; i++) {
			g[i].clear();
			tmp[i] = 0;
		}
		while (groups--) {
			cin >> members;
			cin >> x;
			members--;
			while (members--) {
				cin >> y;
				g[x].push_back(y);
				g[y].push_back(x);
			}
		}
		ans = 0;
		dfs(0);
		cout << ans << endl;
	}
}