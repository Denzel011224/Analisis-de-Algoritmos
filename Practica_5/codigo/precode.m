function [codes,NodoRaiz]=precode(a,b)

% Empty Array of Object Huffman
thearray = Huffman.empty(length(a),0);
% Assign Initial Values
for i=1:length(a)
    thearray(i).probability = a(i);
    thearray(i).character = b(i);
end
temparray = thearray;
% Create the Binary Tree
for k = 1:size(temparray,2)-1
    
    % First Sort the temp array
    
    for i=1:size(temparray,2)
        for j = 1:size(temparray,2)-1
            if (temparray(j).probability > temparray(j+1).probability)
                tempnode = temparray(j);
                temparray(j) = temparray(j+1);
                temparray(j+1) = tempnode;
            end
        end
    end
    
    % Create a new node
    
    newnode = Huffman;
    
    % Add the probailities
    newnode.probability = temparray(1).probability + temparray(2).probability;
    
    % Add Codes
    temparray(1).code = '0';
    temparray(2).code = '1';
    
    % Attach Chlldren Nodes
    newnode.leftNode = temparray(1);
    newnode.rightNode = temparray(2);
    
    % Delete the first two nodes
    
    temparray = temparray(3:size(temparray,2));
    
    % Prepend the new node
    
    temparray = [newnode temparray];
    
end

rootNode = temparray(1);
codec = '';

% Looping though the tree
% See recursive function loop.m


%%
loop(rootNode,codec);
codes=strings(256,1);
load("codes.mat")
save("codes.mat",'codes');

%cadena=[97 98 98 101 101];


NodoRaiz=rootNode;
end