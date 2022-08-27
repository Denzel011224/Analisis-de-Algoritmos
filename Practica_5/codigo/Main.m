clc %limpia pantalla
clear %limpia todo
close all %cierra todo
disp('Inicio de Practica 5')
%% Creamos archivo codes.mat
codes=strings(256,1);
save("codes.mat",'codes');
%% Leer y mostrar imagen original
im = imread('horse.bmp');
im=im(:,:,1);
subplot(3,2,1)
imshow(im)
title("Original")

%% Histograma original
subplot(3,2,2)
h=imhist(im);
plot(h)
title("Histograma 1")

%% Escogemos valores
num = 8;
im(im==0)=1;
[K,valores ]= imsegkmeans(im,num);

%% Creamos nueva imagen a partir de valores seleccionados
imb=K;
ima=imb*0;
for i=1:num
    ima(imb==i)=valores(i);
end
imb=ima;
subplot(3,2,3)
imshow(imb)
title("Imagen con solo "+num+" valores")

%% Histograma de valores seleccionados
subplot(3,2,4)

h2=imhist(imb);
plot(h2)
title("Histograma 2")

%% Creamos arreglos 
a=[];b=[];
for i=1:256
    if h2(i)~=0
        b=[b i];
        a=[a h2(i)];
    end
end

%% Agregamos limite de linea
b=[1 b];
a=[height(imb) a];

%% Obtenemos S/N


%sn=10*log10(sumsqr(a)/sumsqr(a-b));
%disp(sn);

%% Codificamos
codificado=[];
[codes, NodoRaiz]=precode(a,b);
for i=1:height(imb)
    codificado=[codificado; encode(codes,imb(i,:))];
end
%% Rellenamos valores faltantes 
temp=[];
for i=1:height(imb)
    temp=[temp ; strlength(codificado(i))];
end
maximo=max(temp);
if mod(maximo,8)~=0
maximo=maximo+8-mod(maximo,8);
end

for i=1:height(imb)
    codificado(i)=codificado(i)+strzeros(maximo-temp(i));
end

%% Mostramos imagen Codificada
imagencodificada=imgfromcode(codificado,maximo);
subplot(3,2,5)
imshow(imagencodificada)
title("Imagen Codificada")

%% Decodificacion
%imagendescodificada=imgfromencode(imagencodificada,codes,width(im));

%% Mostramos Imagen Descodificada

subplot(3,2,6)
%imshow(imagendescodificada)

h=imhist(imagencodificada);
plot(h)
title("Histograma 3")
%% Compresion de datos
disp("Compresion:"+width(imagencodificada)/width(imb)*100+"%")


