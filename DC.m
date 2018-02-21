%MATLAB program to take in a a sequence of Bipolar Manchester Coding as
%input and extract clock information and  use this information to give the
%data sequence
%Mahir Jain  16CO123
%Suraj Singh 16CO146


s = 'Enter the sequence of levels separated by spaces\n'
n = input(s, 's')
tmp = strings([1,length(n)]) %array needed to type cast a string to a double array
i =1
for i= 1:length(n)
    tmp(i) = n(i)
end
i =1
while(i<length(tmp))
    if tmp(i) =="-"
        if(tmp(i+1)=="1")
            tmp(i) = "-1"
            tmp(i+1) = [] %deletes the next element. if it finds '-' and  the next element is 1, deleted that 1 and make '-' to '-1'
        
        else
            fprintf("Invalid code sequence A") %if the user enters -0
            return %return basically stops execution of the entire script
        end
        
        
    end
    i= i+1
        
end
     
final = str2double(tmp) %first typecasting to char array and then to a double array

cmp = [-1,0,1]

for i=1:length(final) %making sure the levels entered by the user are valid
    if ~(ismember(final(i),cmp))
        fprintf("Invalid input\n")
        return
        break
    end

end
   
if(mod(length(final), 2) ~=0) %the length of input data sequence should be even
    fprintf("Invalid input, odd number of bits entered\n")
    return
end

i =1
j=1

output = zeros([1,(length(final)/2)])
while(i<length(final))      %loop for deciding the data stream to the intended message
     if(final(i)==-1  & final(i+1) ==1) %condition for '1'
         output(j) = 1
         j = j +1
     elseif (final(i)==1  & final(i+1) ==-1) %condition for '0'
         output(j) = 0
         j = j+1
     else
         fprintf("Invalid data sequence B")
         return
     end
     i = i +2

end







%     final = final'
%     f=10^5;
%     T=1/f;
%     t=0:T:(numel(final)-1)*T;
%     stairs(final,final,'r','linewidth',2)


        
    