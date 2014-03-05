#include<iostream>
#include<vector>

namespace partial_sum {
	using namespace std;

	int n, k;
	vector<int> a;

	bool Dfs(int i, int sum) {
		if (i == n) return sum == k;
		if (Dfs(i + 1, sum)) return true;
		if (Dfs(i + 1, sum + a[i])) return true;
		return false;
	}

	void PartialSum(int n, vector<int> a, int k) {
		partial_sum::n = n;
		partial_sum::k = k;
		partial_sum::a = a;
		if (Dfs(0, 0)) cout << "Yes" << endl;
		else cout << "No" << endl;
		return;
	}
}