
function f = loop(tempNode,codec)
if ~isempty(tempNode)
    codec = [codec tempNode.code];
    
    if ~isempty(tempNode.character)
        disp(tempNode.character-1 +"->"+codec);
        load("codes.mat");
        codes(uint16(char(tempNode.character)))=string(codec);
        %disp("__"+codes(uint16(char(tempNode.character))))
        save("codes.mat",'codes');
    end
    if ~isempty(tempNode.code)
        
    end
    loop(tempNode.leftNode,codec);
    loop(tempNode.rightNode,codec);
end
f = codec;
end