file=fopen('truepositivechiTUDPT.txt');
Mean=zeros(5,1);
str1=0;str2=0;str3=0,str4=0,str5=0;
while ~feof(file)
    str1=str2double(fgetl(file))+str1;
    %str1=str2double(str);
    Mean(1,1)=str1;
    str2=str2double(fgetl(file))+str2;
    Mean(2,1)=str2;
    str3=str2double(fgetl(file))+str3;
    Mean(3,1)=str3;
    str4=str2double(fgetl(file))+str4;
    Mean(4,1)=str4;
    str5=str2double(fgetl(file))+str5;
    Mean(5,1)=str5;
        str=fgetl(file);
end
n=1;
l=0;
fseek(file,0,'bof');
tline=fgetl(file);
while (ischar(tline) && ~feof(file))
    tline=fgetl(file);
    if (size(tline)==0)
        l=l+1;
    end
    n=n+1;
end
fileM=fopen('MeanTrueposchiTUDP.txt','w');
num=(n-l)/5;
for i=1:5
    Mean(i,1)=Mean(i,1)/num;
    fprintf(fileM,'%2.2f\r\n',Mean(i,1));
end
