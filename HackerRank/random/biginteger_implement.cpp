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

symmB(void);
bool operator== (const bigint&);
bool isbiggerabsB (const bigint&);
bool operator< (const bigint&);
bool operator> (const bigint&);
bigint operator+ (const bigint&);

//operations

//plusB 1

//multB 2

//divideB 3

//intB 4

//Bstr 5


//don't forget print


}; 

//constructor
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
bool bigint::isbiggerabsB(bigint & test) {
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
bigint bigint::operator+ (const bigint& test) {
	if (length == 0) return test;
	else if (sign * (test.sign) == 1){// ONE
		int i, l = max(length, text.length);
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
		ans.sign = sign;
		ans.length = write_nr.size();
		return ans;
	}
	else // TWO

}



int main(){
    cout << "oi" << endl;
    return 0;
}