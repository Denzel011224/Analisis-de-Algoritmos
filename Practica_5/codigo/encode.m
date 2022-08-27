function codificado=encode(codes,cadena)
codificado="";
%%


for i=1:length(cadena)
    
    codificado=codificado+codes(uint16(cadena(i))+1);
    
end
end