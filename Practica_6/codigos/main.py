'''
	Instituto Politecnico Nacional
	Escuela Superior de Computo
	Analisis de Algoritmos | 3CV11
	Integrantes del equipo:
		Luis Francisco Renteria Cedillo
		Denzel Omar Vazquez Perez
	Profesor: Benjamin Luna Benoso
	Fecha: 06/06/2022

    El siguiente codigo encuentra
    el porcentaje de similitud entre
    dos codigos fuente en c, para
    ayudar a decidir si se trata de
    practicas de plagio o no.
'''
#%% Indicamos nombres de archivos:
archivo1="NQueens.c"
archivo2="NQueensPlagio.c"

#importamos libreria para expresiones regulares
import re 
#Definimos conjuntos de palabras resevadas
tipos={"int","float","double","long","char","void","bool"}
control={"if","else","switch","case","default"}
flujo={"for","while","do"}
extra1={"break","return","void","goto","continue"}
extra2={"sizeof","struct","typedef","union","volatile","enum"}
var={"auto","signed","const","extern","register","unsigned","static"}
boo={"true","false"}
extra3={"printf","scanf","getchar"}

from PrintLongestCommonSub2 import plcs
from Imprime2 import ImprimeSimilar

# funcion unir() concatena simbolos especiales 
# con la cadena anterior o siguiente segun
# el parametro unir
def unir(l1,char,unir=0):
    l2=[]
    i=0
    
    while i <len(l1):
        
        if l1[i]==char:
            if unir==1:
                a=l2.pop()
                l2.append(a+l1[i])
            else:
                l2.append(l1[i]+l1[i+1])
                i=i+1
        else:
            l2.append(l1[i])
        i=i+1
        
    return l2
# funcion lista() regresa una lista de cadenas
# que se asemejan a sentencias simples
def lista(e):
    e=re.split("([(){};\[\]])",e)
    e = list(filter(None, e))
    l1=e
    l1=unir(l1,"[",unir=0)
    l1=unir(l1,"]",unir=1)
    l1=unir(l1,"(",unir=0)
    l1=unir(l1,")",unir=1)
    l1=unir(l1,";",unir=1)
    l1=unir(l1,"{",unir=0)
    l1=unir(l1,"}",unir=1)
    
    
    return l1

#funcion tooken() sustituye variables, funciones, valores,
#y palabras reservadas en general por etiquetas especiales
def token(archivo):
    f=open(archivo, "r")
    c = f.read()
    #Eliminamos comentarios de tipo /**/
    c=re.sub(r"/[*]([^*]|([*][^/]))*[*]+/", '',c)
    #Eliminamos comentarios de tipo //
    c=re.sub(r"//.*?\n",' ',c)
    #Eliminamos la importacion de librerias
    c=re.sub(r"#.*?\n",' ',c)
    #Eliminamos tabuladores extras
    c=re.sub(r'\t+', '', c)
    #Eliminamos espacios y retornos de carro innecesarios
    c=re.sub(r'\n+?\s*?\n*?\s*', '\n', c)
    #Eliminamos puntos y comas extras
    c=re.sub(r';+',';',c)
    
    #c=re.sub(r"(\s|\n|=|<|>|)^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?(,|;|\s)",'≪number≫',c)
    funciones=set()
    #sustituimos funciones por su token
    for l in list(tipos):
        conjunto=re.findall(f"{l}\s+[_A-z]\w*\s*[(]",c)
        for f in conjunto:
            funciones.add(f[0:-1].split()[1])
        c=re.sub(f"{l}\s+[_A-z]\w*\s*[(]","≪_f_≫(",c)
    ids=set()  
    #sustituimos variables por su token
    for l in list(tipos):
        conjunto=re.findall(f"{l}\s+[_A-z]\w*",c)
        for i in conjunto:
            ids.add(i.split()[1])
        c=re.sub(f"{l}\s+(\*)*[_A-z]\w*","≪_v_≫",c)
    #sustituimos valores por su token    
    c=re.sub(r"(0|([1-9][0-9]*))(\.[0-9]+)?",'≪_n_≫',c)
    
    # for l in list(tipos):
    #     conjunto=re.findall(f"{l}\s*(\*)+\w+",c)
    #     print(conjunto)
    #     for i in conjunto:
    #         ids.add(i)
    #     c=re.sub(f"{l}\s*(\*)+\w+","≪_a_≫",c)
    c=re.sub("\s","",c)
    
    #print("IDS:");print(ids)
    #sustituimos cadenas por su token
    c=re.sub(r"(\"\w*\")","_s_",c)
    
    #Eliminamos palabras reservadas innecesarias
    for l in list(extra1):
        c=re.sub(f"{l}","",c)
    for l in list(extra2):
        c=re.sub(f"{l}","",c)
        
    for f in list(funciones):
        
        c=re.sub(f"{f}\\(","≪_f_≫(",c)
       
        
    for i in list(ids):
        
        c=re.sub(r"([\W]){j}([\W])".format(j=str(i)),r'\1≪_v_≫\2',c)
    c=re.sub("_v_","v",c)
    c=re.sub("_n_","n",c)
    c=re.sub("_f_","f",c) 
    c=re.sub("_a_","a",c)
    c=re.sub("_s_","s",c)
    
    for l in list(var):
        c=re.sub(f"{l}","",c)  
    for l in list(flujo):
        c=re.sub(f"{l}","≪F≫",c)  
    for l in list(control):
        c=re.sub(f"{l}","≪c≫",c)
    
    for l in list(extra3):
        c=re.sub(f"{l}","≪p≫",c)
    
    for l in list(boo):
        c=re.sub(f"{l}","≪b≫",c)
    #print(c)
    #print("*********************************")
    
    return c
    # cadenas=c.split("\n")
    # for cad in cadenas:
    #     if cad.c
#%% Archivos

c1=token(archivo1)
c2=token(archivo2)

l1=lista(c1)
l2=lista(c2)     
#%% calculamos lcs y mandamos a imprimir a ventana


l,x,LX,LY=plcs(l1,l2)

a=ImprimeSimilar(LX)

b=ImprimeSimilar(LY)

avg=x/min(len(c1),len(c2));

print(f"Porcentaje de Similitud:{avg*100:.2f}%");
#Construimos inicio y fin del html a mostrar en interfaz visual
inicio='<!DOCTYPE HTML PUBLIC ><html><head><meta name="qrichtext" content="1" /><style type="text/css">p, li { white-space: pre-wrap; }</style></head><body style=" font-family:\'Consolas\'; font-size:8.25pt; font-weight:400; font-style:normal;"><p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;">'
fin='</p></body></html>'

#Importamos interfaz visual
from ventana import Ui_MainWindow
import sys
from PyQt5 import  QtWidgets
app = QtWidgets.QApplication(sys.argv)
MainWindow = QtWidgets.QMainWindow()
ui = Ui_MainWindow()
ui.setupUi(MainWindow)
#Escribimos nombres de archivos
ui.label.setText(archivo1)
ui.label_2.setText(archivo2)

#Escribimos contenido de archivos como html

ui.textEdit.setHtml(inicio+a+fin)
ui.textEdit.setReadOnly(1)

ui.textEdit_2.setHtml(inicio+b+fin)
ui.textEdit_2.setReadOnly(1)

ui.label_3.setText(f"Porcentaje de Similitud: {avg*100:.2f}%")
MainWindow.show()
sys.exit(app.exec_())
