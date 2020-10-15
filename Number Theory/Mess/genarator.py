#date:2020.10.15
#given a range
#search a prime q which satisfy p=2q+1 is prime in the given range
#choose an element h in Z_p^*
#let g=h^2,use g to generator a group(mod p)

import math

# naive version of is_prime
def is_prime(n):
    for i in range(2,int((math.sqrt(n)))+1):
        if (n%i)==0:
            return False
    return True

# find an int q that q is prime and 2q+1 is prime too
def special_p(q):
    if is_prime(q) and is_prime(2*q+1):
        return True
    return False

#return a^e mod n
def power(a,e,n):
    res=1
    while e:
        if e&1:
            res = (res*a)%n
        a = (a*a)%n
        e >>= 1
    return res

# q is prime and p=2q+1 is prime
# h in Z_p^*
# g=h^2
# <g> is a cyclic group and a subgroup of Z_p^*
# order(<g>) | 2q => order (<g>)=2 or order(<g>)=q  
def gener(g,q):
    i=1
    while power(g,i,2*q+1) != 1:
        yield power(g,i,2*q+1)
        i += 1
    yield 1

r=int(input("The range you want to search:\n"))
print("List:")
for i in range(2,r+1):
    if special_p(i):
        print(i)
print("Every element x in the list is prime,and 2x+1 is prime too\n")
q=int(input("Choose a prime p that you like in the list\n"))
h=int(input("Choose a number in [2,2p]\n"))
g=h*h
print("Generator ",g," generate a group <g>:")
order=0
G=gener(g,q)
for n in G:
    order += 1
    print(n)
print("The order of <g>:",order)
