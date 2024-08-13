#include <iostream>
#include <bitset>
#include  "pfn.h"

using namespace std;

int main() 
{
    float a = 123.456;
    float b = 0.00078910;
    float c = 0.5500;
    float d = 1.0700;

    pfn af(2);
    pfn bf(2);
    pfn cf(4);
    pfn df(4);

    cout << "Valor convencionais: "<<endl;
    cout << "a = " << a << ";"<<endl;
    cout << "b = " << b << ";"<<endl;
    cout << "c = " << c << ";"<<endl;
    cout << "d = " << d << ";"<<endl<<endl;

    af = a;
    bf = b;
    cf = c;
    df = d;


    cout << "Valor ponto flutuante: "<<endl;
    cout << "a = "; af.print(); cout << ";" << endl;
    cout << "b = "; bf.print(); cout << ";" << endl;
    cout << "c = "; cf.print(); cout << ";" << endl;
    cout << "d = "; df.print(); cout << ";" << endl<<endl;

    float n = 0.345;
    cout << "Somando o valo n = 0.345 as representação em pontoflutuante:"<<endl;
    cout <<"a = a + n :"<< endl;
    af = af + n;
    cout << "a = "; af.print(); cout << ";" << endl<<endl;
    
    cout << "b = b + n :"<< endl;
    bf = bf + n;
    cout << "b = "; bf.print(); cout << ";" << endl<<endl;

    cout << "c = c + n :"<< endl;
    cf = cf + n;
    cout << "c = "; cf.print(); cout << ";" << endl<<endl;

    cout << "d = d + n :"<< endl;
    df = df + n;
    cout << "d = "; df.print(); cout << ";" << endl<<endl;

    cout << "Fim do programa"<<endl<<endl;

}