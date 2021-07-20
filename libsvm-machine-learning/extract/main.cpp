#include <string>
#include<fstream>
#include<iostream>
using namespace std;
int main()

{ofstream outTCP("/media/farzane/SP PHD U3/outspidTTcpcopy/outputVuze/outTCP.txt",ios::out |ios::app|ios::binary);
    ofstream outUDP("/media/farzane/SP PHD U3/outspidTTcpcopy/outputVuze/outUDP.txt",ios::out |ios::app|ios::binary);
    ifstream file("/media/farzane/SP PHD U3/outspidTTcpcopy/outputVuze/learningfile.txt",ios::in|ios::binary);
    string line;
    if(file.is_open())
    {

        while(!file.eof()){
        getline(file,line);
        int length=line.size();
        if(length>1){
        if (line[2]=='0')
           {line.erase(1,2);

        outTCP<<line;
        outTCP<<'\n';}
       // if (line[2]== '1')
        else if(line[2]=='1')
           {line.erase(1,2);
        outUDP<<line;
        outUDP<<'\n';}

        }} }
    else
    cout<<"not opened";
    file.close();
    outTCP.close();
    outUDP.close();
    return 0;
}
