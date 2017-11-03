#!/bin/python

import sys

def minimumNumber(n, password):
    # Return the minimum number of characters to make the password strong
    lower = 0
    upper = 0
    special = 0
    digit = 0
    for i in password:
        if i in "0123456789":
            digit += 1
        elif i in "abcdefghijklmnopqrstuvwxyz":
            lower += 1
        elif i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            upper += 1
        else:
            special += 1
    return max(6 - n, 0, (digit == 0) + (special == 0) + (lower == 0) + (upper == 0) )

if __name__ == "__main__":
    n = int(raw_input().strip())
    password = raw_input().strip()
    answer = minimumNumber(n, password)
    print answer
