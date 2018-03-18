from decimal import *
getcontext().prec = 50

def gcd(m,n):
    i = min(m,n)
    j = max(m,n)
    while i > 0:
        k = i;
        i = j % i
        j = k
    return j

def successor(arr):
    l = len(arr)
    if arr[l-1] == 1:
        arr[0] = l
        for i in range(1, l):
            arr[i] = 0
    else:
        k = arr[0]
        i = 1
        while i + 1 > k:
            k += arr[i]*(i + 1)
            i += 1
        arr[i] += 1
        arr[0] = k - i -1
        for j in range(1, i):
            arr[j] = 0
    return None
            
def factl(n):
    ans = 1
    for i in range(1, n + 1):
        ans *= i
    return ans

def sumgcd(gamma, delta):
    w = len(gamma)
    h = len(delta)
    ans = 0
    for i in range(w):
        for j in range(h):
            ans += gamma[i]*delta[j]*gcd(i+1, j+1)
    return ans
    
def denominator(gamma, delta):
    w = len(gamma)
    h = len(delta)
    ans = 1
    for i in range(w):
        if gamma[i] > 0:
            ans *= factl(gamma[i]) * ((i+1)**gamma[i])
    for j in range(h):
        if delta[j] > 0:
            ans *= factl(delta[j]) * ((j+1)**delta[j])
    return ans


def answer(w, h, s):
    gamma = [0]*w
    gamma[0] = w
    delta = [0]*h
    delta[0] = h
    ans = Decimal(0)
    while True:
        de = denominator(gamma, delta)
        sumsum = sumgcd(gamma, delta)
        ans = ans + Decimal(s**sumsum)/(Decimal(de))
        if gamma[w - 1] == 1:
            if delta[h - 1] == 1:
                break
            else:
                successor(delta)
        successor(gamma)
    print ans
    return ans
 
grab = raw_input().split()
w, h, s = map(int, grab)
print(int(answer(w,h,s)))