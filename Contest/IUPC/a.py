





n = int ( input ( ) )
C = [ [] for i in range ( n ) ]

for i in range ( n -1 ) :
    u , v = map ( int , input ( ) . split ( ) )
    u -= 1
    v -= 1
    C[u] += [v]
    C[v] += [u]
    







for i in range (n ) :
    C[i].sort()
    
Cs = [ -1 for i in range ( n ) ]
Css = [ -1 for i in range ( n ) ]

for i in range ( n ) :
    Cs[i] = C[i][0]
    if len ( C[i] ) > 1 :
        Css[i] = C[i][1]

As = [ -1 for i in range ( n ) ]

    
def findS ( a  , b )  :
    if b == -1 :
        As[a] = findS( Cs[a] , a )
    
    else:
        if Cs[a] == b :
            if len(C[a]) == 1 : 
                return a
            else:
                return findS( Css[a] , a )
        else:
            As[a] = findS( Cs[a] , a )
            return As[a]
    

for i in range (n) :
    if As[i] == -1 :
        findS(i,-1)    

        
        
        
        
        
Ass = list(As)


for i in range (n ) :
    C[i].sort(reverse=True)
    
Cs = [ -1 for i in range ( n ) ]
Css = [ -1 for i in range ( n ) ]

for i in range ( n ) :
    Cs[i] = C[i][0]
    if len ( C[i] ) > 1 :
        Css[i] = C[i][1]

As = [ -1 for i in range ( n ) ]
    
    
def findS ( a  , b )  :
    if b == -1 :
        As[a] = findS( Cs[a] , a )
    
    else:
        if Cs[a] == b :
            if len(C[a]) == 1 : 
                return a
            else:
                return findS( Css[a] , a )
        else:
            As[a] = findS( Cs[a] , a )
            return As[a]
    

for i in range (n) :
    if As[i] == -1 :
        findS(i,-1)    







        
for i in range ( n ) :
    print(As[i]+1,Ass[i]+1)