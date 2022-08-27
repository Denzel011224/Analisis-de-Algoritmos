% Code by Jay Kanakiya
% http://blog.jaykanakiya.com

classdef Huffman
   properties
      leftNode = []
      rightNode = []
      probability
      code = ''
      character
      bits
   end
   
   methods
       function obj=setbits(obj,value)
           obj.bits=value;
       end
   end
end