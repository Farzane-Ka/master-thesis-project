#include "chi_square.h"

//float*
//Measurement::chi_square::getFingerprintProEntry(fingerprint* fp) {
//    return fp->chiSquarepro;
//}
//Author Farzane Karami

float*
Measurement::chi_square::getFingerprintCntEntry(fingerprint* fp) {
    return fp->chiSquare;

}
void
Measurement::chi_square::convert(u_char *p_payload , int* pi)
{
    unsigned char byte = static_cast<int>(*p_payload );
    int remainder, digits = 0, dividend = byte;
    while(dividend != 0)
    {
        dividend = dividend / 2;
        digits++;
    }
    dividend = byte;
    for(int i = digits+pi[0]*8; i > pi[0]*8; i--)
    {
        remainder = dividend % 2;
        pi[i+8-digits] = remainder;
        dividend = dividend / 2;
    }
    pi[0]++ ;
}
void Measurement::chi_square:: calculate(bool arr[],int count[],int len) {

    int value[4] ={(int)pow(2.0,(len-1)) , (int)pow(2.0,(len-2)),(int)pow(2.0,(len-3)),(int)pow(2.0,(len-4))} ;//convert 3 or 2 bits to an int
    int result = 0 ;
    for(int i = 0 ; i<len ; i++){
        value[i] *= (arr[i]) ;
        result += value[i] ;

        }
    count[result]++;
     }

//void Measurement::chi_square:: shift(bool ch[],int n){
//     for(int i = 0 ; i<n-1 ; i++){
//     ch[i] = ch[i+4] ;
//    }
//}


float Measurement::chi_square:: chi(int count4[],int n,int m)
{   float c4=0;
    for(int i=0;i<pow(2.0,m);i++)
        c4 += pow((count4[i]-n/pow(2.0,m)),2.0);


    float chi= (pow(2.0,m)/n)*c4;
    for(int i = 0 ; i < 16 ; i++) count4[i] = 0 ;
    return chi;


}


void Measurement::chi_square::fe(int **x,bool*y) {

     fstream d("/home/farzane/Documents/bits.txt", ios::out|ios::app) ;


    for(int i = 0 ; i < 80 ; i++){
        cout << "\n" ;
        for (int  j = 0 ; j < 97 ; j++){
            cout << x[i][j] ;
        d<<x[i][j];}
        d<<"\n";
        }cout<<'\n';

    for (int i = 0 ; i < 7680 ; i++){
        if((i % 320) == 0) {
            d<< "\n";
        d << "line"<<i/80 << " : " ;
        }

        d <<y[i] ;

    }
    d.close();
}
