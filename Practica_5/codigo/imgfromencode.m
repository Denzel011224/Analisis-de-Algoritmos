function m=imgfromencode(im,codes,maximo)
m=zeros(height(im),maximo);
for i=1:height(im)
    linea=dec2bin(im(i,:),8);
    chars=convertCharsToStrings(linea');
    aux="";
    descodificado=[];
    for k=1:strlength(chars)-1
        aux=aux+string(extractBetween(chars,k,k));
        
        

        if aux==codes(1)
            aux="";
            break
        end
        

        
%         for j=2:256
%             if aux==codes(j)
%                 aux="";
%                 descodificado=[descodificado  j-1];
%                 
%                 break
%             end
%         end
        ind=find(ismember(codes,aux));
        if ~isempty(ind) 
            aux="";
            descodificado=[descodificado  ind-1];
        end
        
        
    end
    %disp("******")
    %disp(i)
    %disp(j)
    %disp(k)
%     if j==256
%         disp(aux)
%     end
    %disp(m)
    %disp(length(descodificado))
    m(i,:)=descodificado(1:maximo);
    %disp(m)
    %disp(m)
end


m=uint8(m);

end