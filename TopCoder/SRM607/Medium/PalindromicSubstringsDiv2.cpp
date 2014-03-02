#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

class PalindromicSubstringsDiv2 {
private:
	bool isPalindrome(string s) {
		for (int i = 0; i <= (s.length()  - 1) / 2; ++i) {
			if (s[i] != s[s.length() - 1 - i]) {
				return false;
			}
		}
		return true;
	}

public:
	int count(vector <string> S1, vector <string> S2) {
		string s;
		for (int i = 0; i < S1.size(); ++i) {
			s += S1[i];
		}
		for (int i = 0; i < S2.size(); ++i) {
			s += S2[i];
		}
		int res = 0;
		for (int l = 1; l <= s.length(); ++l) {
			for (int i = 0; i + l <= s.length(); ++i) {
				string substr = s.substr(i, l);
				if (isPalindrome(substr)) {
					++res;
				}
			}
		}
		return res;
	}
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf_s(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string S1[]               = {"a","a",""};
			string S2[]               = {"a"};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S1[]               = {"zaz"};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>());
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S1[]               = {"top"};
			string S2[]               = {"coder"};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S2[]               = {"daata"};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubstringsDiv2().count(vector <string>(), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string S1[]               = ;
			string S2[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string S1[]               = ;
			string S2[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string S1[]               = ;
			string S2[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
