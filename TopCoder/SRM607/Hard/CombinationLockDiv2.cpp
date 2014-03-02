#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

class CombinationLockDiv2 {
private:
	int minimum(vector<int> s, vector<int> t) {
		if (s == t) {
			return 0;
		}
		
	}
public:
	int minimumMoves(string S, string T) {
		vector<int> s;
		vector<int> t;
		for (int i = 0; i < S.size(); ++i) {
			s.push_back(S[i] - '0');
			t.push_back(T[i] - '0');
		}
		return minimum(s, t);
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
			string S                  = "123";
			string T                  = "112";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "1";
			string T                  = "7";
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "607";
			string T                  = "607";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "1234";
			string T                  = "4567";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "020";
			string T                  = "909";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "4423232218340";
			string T                  = "6290421476245";
			int expected__            = 18;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			string T                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			string T                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			string T                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
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
