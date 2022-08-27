function img=imgfromcode(c,maximo)
    img=[];
    linea=[];
    for i=1:height(c)
        for j=1:8:maximo
            %disp(j)
            %disp(maximo)
            linea=[linea uint8(bin2dec(extractBetween(c(i),j,j+7)))];
        end
        img=[img;linea];
        linea=[];
    end

end