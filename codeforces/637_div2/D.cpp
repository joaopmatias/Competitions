#include <iostream>
#include <stdio.h>
#include <cstring> 
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <deque>
#include <set>

using namespace std;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int digits_seq[2005][2005];
int sticks_seq[2005][2005];

string digit_sticks[] = {
	"1110111", "0010010",
	"1011101", "1011011",
	"0111010", "1101011",
	"1101111", "1010010",
	"1111111", "1111011"
};

int break_sticks(string original, string broken) {
	int ans = 0;
	for (int i = 0; i < 7; ++i) {
		if (broken[i] > original[i]) {
			ans = -1;
			break;
		} else {
			ans += original[i] - broken[i];
		}
	}

	return ans;
}

int main()
{
	memset(digits_seq, -1, sizeof(digits_seq));
	memset(sticks_seq, -1, sizeof(sticks_seq));
	sticks_seq[0][0] = 0;

	int n, k, nn, i, j, l, b;
	int total_broken = 0;
	string display, digit;

	cin >> n >> k;
	string scoreboard[n];
	for (nn = 0; nn < n; ++nn) {
		cin >> scoreboard[nn];
	}
	for (nn = 0; nn < n; ++nn) {
		display = scoreboard[n - 1 - nn];
		for (i = 9; i > -1; --i) {
			digit = digit_sticks[i];
			b = break_sticks(digit, display);
			if ((b == -1) || (b > k)) continue;
			for (j = 0; (j + b) < (k + 1); ++j) {
				if ((sticks_seq[nn][j] != -1) && sticks_seq[nn + 1][j + b] == -1) {
					sticks_seq[nn + 1][j + b] = b;
					digits_seq[nn + 1][j + b] = i;
				}
			}
		}
	}

	if (sticks_seq[n][k] == -1) {
		cout << -1 << endl;
		return 0;
	} 

	j = k;
	for (nn = n; nn > 0; --nn) {
		cout << digits_seq[nn][j];
		j -= sticks_seq[nn][j];
	}
	cout << endl;
	return 0;
}