n , k = map ( int , input () . split ( ) )


m = 998244353
def mi ( a ) : return pow ( a , m - 2 , m )


h = 200010
F = [0] * h
F[0] = 1
for i in range ( 1 , h ) :
    F[i] = (F[i-1]*i)%m



ans = 0


for i in range ( 1 , k + 1 ) :

    l = k + 1 - i
    u = n - l

    if u < 0 : continue

    v = pow(l+1,i,m) - pow(l,i,m)
    
    v *= F[ l ]

    v *= F[ n ] 
    
    v *= mi( F[u] )


    ans += v

ans += 1
ans %= m

print(ans)


