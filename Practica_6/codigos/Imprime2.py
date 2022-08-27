def ImprimeSimilar(c):
    cad=""
    
    #Creamos los contenedores de cadena:
    #Si es plagio, lo remarcamos de rojo
    #Caso contrario, no se remarca.
    for i in c:
        
        if type(i)==list and i[0]!="":
            h=i[0].replace("<","_")
            h=h.replace(">","_")
            cad=cad+'<span style=" background-color:#ff8888;">'+ h+'</span>'
        elif i!="":
            h=i.replace("<","⋖")
            h=h.replace(">","⋗")
            cad=cad+'<span>'+ h   +'</span>'
            
    return cad