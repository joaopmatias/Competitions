#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int BASE = 65536; 

class bigint:\
public:

vector<int> digits;
int sign;
int length;

bigint();
bigint(int nr = 0);

printB(void);
symmB(void);
absB(void);
bool operator== (const bigint&);
bool isbiggerabsB (const bigint&);
bool operator< (const bigint&);
bool operator> (const bigint&);
bigint sumabsB (const bigint&);
bigint diffabsB (const bigint&);
bigint operator+ (const bigint&);
bigint operator- (const bigint&);
bigint operator* (const bigint&);

//operations

//plusB 1

//multB 2

//divideB 3

//intB 4

//Bstr 5


//don't forget print


}; 


//zero function
bigint zeroB(){
	bigint ans;
	vector<int> write_nr (1, 0);
	ans.digits = write_nr;
	ans.length = 0;
	ans.sign = 1;
	return ans;
}

//prints
bigint::printB() {
	if (length == 0) cout << 0;
	int i;
	for (i = length - 1; i > -1; i++) {
		cout << digits[i];
	}
}


//constructor
bigint::bigint() {}

bigint::bigint(int nr = 0) {
	digits.resize(1);
	digits[0] = nr;
	sign = 1 - 2 * (nr < 0);
	length = 1 - (nr == 0);
}

//more operations: symm and overloading of other operators

bigint::symmB(){
	if (length > 0) {
		sign *= -1;
	}
}

bigint::absB(){
	sign = 1;
}

bool bigint::operator== (const bigint& test) {
	if (sign != test.sign) return false;
	else if (length	!= test.length) return false;
	else {
		int i;
		for (i = 0; i < length; i++) {
			if ( digits[i] != (test.digits)[i] ) return false;
		}
	}
	return true;	
}

// YOU MIGHT WANT TO REPLACE THE INTS IN THE "FOR LOOPS" BY ITERATORS
bool bigint::isbiggerabsB(const bigint & test) {
	if (length == 0) return false;
	else if (length > test.length) return true;
	else if (length < test.length) return false;
	else {
		int i;
		for (i = length - 1; i >= 0; i--) {
			if ( digits[i] > (test.digits)[i] ) return true;
			else if ( digits[i] < (test.digits)[i] ) return false;
		}
	}
	return false;	
}

bool bigint::operator< (const bigint & test) {
	if (sign < test.sign) return true;
	else if (sign > test.sign) return false;
	else return test.isbiggerabsB(*this);
}

bool bigint::operator> (const bigint & test) {
	if (sign > test.sign) return true;
	else if (sign < test.sign) return false;
	else return (*this).isbiggerabsB(test);
}


//next operator: sum
bigint bigint::sumabsB(const bigint& test) {
	if (length == 0) return test.absB();
	else { //maybe use iterators
		int i, l = max(length, test.length);
		vector<int> write_nr (l + 1, 0);
		for (i = 0; i < length; i++) {
			write_nr[i] = digits[i];
		}
		for (i = 0; i < test.length; i++) {
			write_nr[i] += (test.digits)[i];
			if (write_nr[i] >= BASE) {
				write_nr[i] -= BASE;
				write_nr[i + 1]++;
			}
		}
		if (write_nr.back() == 0 ) write_nr.pop_back();
		
		bigint ans;
		ans.digits = write_nr;
		ans.sign = 1;
		ans.length = write_nr.size();
		return ans;
	}
}

bigint bigint::diffabsB(const bigint& test) {//*this* is the largest in abs
	if (length == 0) return zeroB();
	else {
		int i, l = max(length, test.length); //it's length
		vector<int> write_nr (l, 0);
		for (i = 0; i < length; i++) {
			write_nr[i] = digits[i];
		}
		for (i = 0; i < test.length; i++) {
			write_nr[i] -= (test.digits)[i];
			if (write_nr[i] < 0) {
				write_nr[i] += BASE;
				write_nr[i + 1]--;
			}
		}
		i = l - 1;
		while (i > -1 && write_nr[i] == 0) write_nr.pop_back();
		
		if (i == -1) return zeroB();
		
		bigint ans;
		ans.sign = 1;
		ans.length = write_nr.size();
		ans.digits = write_nr;
		return ans;
	}
}

bigint bigint::operator+ (const bigint& test) {
	if (length == 0) return test;
	
	bigint ans;
	if (sign * (test.sign) == 1){
		ans = (*this).sumabsB(test);
		ans.sign = sign;	
	}
	else if( (*this).isbiggerabsB(test) ){
		ans = (*this).diffabsB(test);
		ans.sign = sign;
	}
	else {
		ans = test.diffabsB(*this);
		ans.sign = test.sign;	
	}
	return ans;
}

bigint bigint::operator- (const bigint& test) {
	return (*this) + test.symmB();
}

bigint bigint::operator* (const bigint& test) {
	if (length == 0 || test.length == 0) return zeroB();

	bigint ans;
	vector<int> write_nr (length + test.length + 1, 0);
	int i, j, k, l;
	l = write_nr.size() - 1;
	for (i = 0; i < length; i++) {
		for (j = 0; j < test.length; j++) {
			write_nr[i + j] += digits[i] * (test.digits)[j];
		}
		for (j = i; j < l; j++) {
			write_nr[i + 1] += (write_nr[i]/BASE);
			write_nr[i] = write_nr[i]%BASE;
		}
	}
	
	write_nr.pop_back();
	if (write_nr.back() == 0) write_nr.pop_back();
	
	ans.digits = write_nr;
	ans.sign = sign * (test.sign);
	ans.length = write_nr.size();
	return ans;	
}


int main(){
    cout << "oi" << endl;
    return 0;
}