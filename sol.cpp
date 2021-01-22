#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<string> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		double total_time = 0;
		for (int i = 0; i < n; i++) {
			// create a temporary variable to count the total time of a word
			// reset it back to zero once the the word changes
			double temp_total = 0;
			// create a 'prev' variable to check the previous character
			char prev = ' ';
			for (int j = 0; j < (int) s[i].size(); j++) {
				// check the current letter if the previous character is written
				// using the same hand
				// if it's the same, then add 0.4
				// otherwise, add 0.2
				if (s[i][j] == 'd' || s[i][j] == 'f') {
					if (prev == 'd' || prev == 'f') {
						temp_total += 0.4;
					} else {
						temp_total += 0.2;
					}
				} else if (s[i][j] == 'j' || s[i][j] == 'k') {
					if (prev == 'j' || prev == 'k') {
						temp_total += 0.4;
					} else {
						temp_total += 0.2;
					}
				}
				// store the current character in the 'prev' variable to be used in the next iteration
				prev = s[i][j];
			}
			// check if the current word was already encountered before
			bool checker = false;
			for (int j = 0; j < i; j++) {
				if (s[i] == s[j]) {
					checker = true;
					break;
				}
			}
			if (checker) {
				// if the current word was encountered, then divide the current time by 2,
				// before it's added to the overall time
				total_time += (temp_total / 2);
			} else {
				// otherwise, just add the current time to the overall time
				total_time += temp_total;
			}
		}
		// multiply the answer to 10 since the unit needs to be in tenths of seconds
		cout << total_time * 10 << '\n';
	}
	return 0; 
}
