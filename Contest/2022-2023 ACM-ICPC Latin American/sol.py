n , p , h = map ( int , input () . split () )
p -= 1
h -= 1

d = h ^ (h>>1)
A = [0] * n
for i in range ( n ) : A[i] = ( ( (d>>i) & 1 ) + A[i-1] ) % 2
A = [0] + A[:-1]
x = p^d
for i in range ( n ) :
    A[i] = ( x >> ( n - 1 - i ) ) ^ A[i]
    A[i] = 'L' if A[i] else 'R'

print(''.join(A))








