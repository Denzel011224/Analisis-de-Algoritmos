'''
	Instituto Politecnico Nacional
	Escuela Superior de Computo
	Analisis de Algoritmos | 3CV11
	Integrantes del equipo:
		Luis Francisco Renteria Cedillo
		Denzel Omar Vazquez Perez
	Profesor: Benjamin Luna Benoso
	Fecha: 30/03/2022

    El siguiente codigo implementa dos 
    funciones para rotar una imagen
    90°, uno es aplicando la estrategia
    de Divide y Venceras y la otra es
    mediante fuerza bruta.

'''

import cv2 
import numpy as np
global z
z=0
def rotar(i,n):
    
    global z    
    #%% si la matriz es 2x2
    if n==2:
        t=np.array([[i[0][1],i[1][1]],[i[0][0],i[1][0]]])
        z=z+4
        return t
    else:
        t=np.zeros((n,n),dtype="uint8")
        #%% la imagen se divide en 4 cuadrantes y se trasladan
        t[0:n//2,0:n//2]=rotar(i[0:n//2, n//2:],n//2)
        t[n//2: ,0:n//2]=rotar(i[0:n//2,0:n//2],n//2)
        t[0:n//2, n//2:]=rotar(i[n//2: , n//2:],n//2)
        t[n//2: , n//2:]=rotar(i[n//2: ,0:n//2],n//2)
        z=z+(n*n)//4
        return t
    
def rotar2(ii,i,n):
    global z
    for y in range(n):
        ii[-y,:]=np.transpose(i[:,y])
        z=z+n
    return ii   
        
#%% algoritmo 1
img=cv2.imread("r2d2.bmp")
n=img.shape[0]
#img=cv2.resize(img, (n*2,n*2), interpolation = cv2.INTER_AREA)
#n=n*2

for d in range(2):
    if d!=0:
        img=cv2.resize(img, (n//2,n//2), interpolation = cv2.INTER_AREA)
        n=n//2
    b,g,r=cv2.split(img)
    
    #Imagen con DyV
    
    new=cv2.merge([rotar(b,n),rotar(g,n),rotar(r,n)])
    cv2.imshow("Imagen", new)
    cv2.waitKey(0)
    
    print(f"Ejecuciones Algoritmo 1:{(n,z)}")
    #Reset ejecuciones
    z=0
    
    #%% algoritmo 2
    bb,gg,rr=cv2.split(img)
    
    #Imagen con fuerza bruta
    new2=cv2.merge([rotar2(bb,b,n),rotar2(gg,g,n),rotar2(rr,r,n)])
    cv2.imshow("Imagen 2", new2)
    cv2.waitKey(0)
     
    print(f"Ejecuciones Algoritmo 2:{(n,z)}")   
    z=0