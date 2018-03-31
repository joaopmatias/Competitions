import sys

def answer(str_n):
    # your code here
    #the code uses convergents from the theory of
    #continued fractions
    #each iteration is p/q goes to (2p+2q)/(p+2q)
    nr = int(str_n)
    nume = [1]
    deno = [1]
    while True:
        p = nume[-1]
        q = deno[-1]
        if p%2 == 0:
            p_t = p + q
            q_t = p/2 + q
        else:
            p_t = 2*(p + q)
            q_t = p + 2*q
        if q_t > nr:
            break
        nume.append(p_t)
        deno.append(q_t)
    result = 0
    while nr > 0:
        while deno[-1] > nr:
            nume = nume[:-1]
            deno = deno[:-1]
        result += (nume[-1]-1)*(deno[-1]-1)/2 +\
            (nr - deno[-1] + 1)*nume[-1]
        nr -= deno[-1]
    return result
        