import math

def seive(n) :
    n = int(n)
    prime = [1 for i in range(n+1) ]
    prime[0] = 0
    prime[1] = 0

    for i in range(2,int(math.sqrt(n)+1)) :
        if prime[i] == 1:
            for j in range(i*i,n+1,i) :
                prime[j] = 0

    for i in range (2,n+1) :
        if prime[i] == 1 :
            print(i)

    


x = input()
seive(x)

