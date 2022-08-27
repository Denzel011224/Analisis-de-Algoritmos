def plcs(X, Y):
    m=len(X)
    n=len(Y)
    L = [[0 for i in range(n+1)] for j in range(m+1)]
 
    #Se crea la matriz paraa comparar y obtener los indices
    #de la subsecuencia mas larga
    i=0
    while i < m+1:
        
        j=0
        while j< n+1:
            if i == 0 or j == 0:
                L[i][j] = 0
            elif X[i-1] == Y[j-1]:
                
                L[i][j]   = L[i-1][j-1] + 1
                        
                
            else:
                L[i][j] = max(L[i-1][j], L[i][j-1])
            
            j=j+1
        
        i=i+1
 
    # Creamos una cadena para la susecuencia mas larga (lcs)
    
    lcs = []
    LX=[]
    LY=[]
    
    #%% Ahora crearemos ListaX y ListaY los cuales contienes 
    i = m
    j = n
    while i > 0 and j > 0:
 
        # Si X y Y son los mismos, entonces es una subcadena similar
        
        if X[i-1] == Y[j-1] :#and X[i-1]!="{" and X[i-1]!="}":
            
            LX.insert(0,[X[i-1]])
            LY.insert(0,[Y[j-1]])
            lcs.insert(0, X[i-1])
            i -= 1
            j -= 1
            
 
        # Si no son similares, se busca el que sea mas largo
        # y se asigna el indice con el mas largo
        elif L[i-1][j] > L[i][j-1]:
            LX.insert(0,X[i-1])
            i -= 1
            
             
        else:
            LY.insert(0,Y[j-1])
            j -= 1
            
    
    #lcs=re.sub(r"≪≫",'',lcs)
    #print("LCS :"+ lcs)
    x=[len(e) for e in lcs ]
    x=sum(x)
    #x=len(lcs)
    return lcs,x,LX,LY