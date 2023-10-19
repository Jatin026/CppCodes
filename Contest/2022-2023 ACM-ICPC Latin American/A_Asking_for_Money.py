n = int(input())

C = []
for i in range ( n ) :
    a, b = map(int,input().split())
    a -= 1
    b -= 1
    C += [[a,b]]

P = [ [] for i in range ( n ) ]
for i in range ( n ) :
    P[C[i][0]]+=[i]
    P[C[i][1]]+=[i]

Ans = ["N"] * n

for i in range (n) :
        
    V = [0] * n
    cur = i
    V[cur] = 0
    cur = [cur]
    while cur :
        curr = []
        for cu in cur :
            for c in P[cu] :
                if V[c] : continue
                if c == i : continue
                V[c] = 1
                curr += [c]
        cur = curr

    V1 = V

    V = [0] * n
    cur = C[i][0]
    V[cur] = 1
    cur = [cur]
    while cur :
        curr = []
        for cu in cur :
            for c in P[cu] :
                if V[c] : continue
                if c == i : continue
                V[c] = 1
                curr += [c]
        cur = curr
    
    V2 = V

    V = [0] * n
    cur = C[i][1]
    V[cur] = 1
    cur = [cur]
    while cur :
        curr = []
        for cu in cur :
            for c in P[cu] :
                if V[c] : continue
                if c == i : continue
                V[c] = 1
                curr += [c]
        cur = curr

    for j in range ( n ) :
        if i != j and V[j] and V1[j] and V2[j] :
            Ans[i] = 'Y'
            break

print(''.join(Ans))






