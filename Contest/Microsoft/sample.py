n = int ( input () )
mod = int(1e9)+7
a = pow(2,n,mod) - 1
a *= 6
a += 13
a *= pow ( 13 , n -1 , mod )
print(a%mod)