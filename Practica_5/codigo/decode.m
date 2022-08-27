function descodificado=decode(codes,codificado)


chars=convertStringsToChars(codificado);
aux="";
descodificado=[];
for i=1:length(chars)
    aux=aux+string(chars(i));
    
    for j=1:256
        if aux==codes(j)
            aux="";
            descodificado=[descodificado  j-1];
            
            break
        end
    end
    
end




end