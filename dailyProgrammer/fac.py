import sys

def fac(n):
    fac = 1
    for i in range(n):
        fac *= (i+1)
    return fac

n = int(sys.argv[1])
print('n!:', fac(n))
