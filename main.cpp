#include <iostream>
#include <bitset>
#include  "pfn.h"
#include "Matriz.h"
#include <vector>

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
    pfn aux1(4);

    cout << "Valor convencionais: "<<endl;
    cout << "a = " << a << ";"<<endl;
    cout << "b = " << b << ";"<<endl;
    cout << "c = " << c << ";"<<endl;
    cout << "d = " << d << ";"<<endl<<endl;

    af = a;
    bf = b;
    cf = c;
    df = d;
    aux1 = 0;


    cout << "Valor ponto flutuante: "<<endl;
    cout << "a = "; af.print(); cout << ";" << endl;
    cout << "b = "; bf.print(); cout << ";" << endl;
    cout << "c = "; cf.print(); cout << ";" << endl;
    cout << "d = "; df.print(); cout << ";" << endl<<endl;

    float n = 0.345;
    pfn nf(4);
    nf = n;
    cout << "Somando o valo n = 0.345 as representação em pontoflutuante:"<<endl;
    cout <<"aux1 = af + n :"<< endl;
    aux1 = af + n;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;
    
    cout << "aux1 = bf + n :"<< endl;
    aux1 = bf + n;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout << "aux1 = cf + nf :"<< endl;
    aux1 = cf + nf;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout << "aux1 = 0; aux1+= nf :"<< endl;
    aux1 = 0; 
    aux1+= nf;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout << "aux1 = 0; aux1+= n :"<< endl;
    aux1 = 0; 
    aux1+= n;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;



    cout << "Teste Subtração"<<endl;

    cout <<"aux1 = cf - n :"<< endl;
    aux1 = cf - n;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;
    
    cout << "aux1 = cf - nf :"<< endl;
    aux1 = cf - nf;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout << "aux1 = 0; aux1-= nf :"<< endl;
    aux1 = 0;
    aux1-= nf;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout << "aux1 = 0; aux1-= n :"<< endl;
    aux1 = 0;
    aux1-= n;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout << "Teste Multiplicação"<<endl;

    cout <<"aux1 = cf * n :"<< endl;
    aux1 = cf * n;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout <<"aux1 = cf * nf :"<< endl;
    aux1 = cf * nf;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout <<"aux1 = 0; aux1*= n :"<< endl;
    aux1 = 0;
    aux1*= n;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout <<"aux1 = 0; aux1*= nf :"<< endl;
    aux1 = 0;
    aux1*= nf;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;


    cout << "Teste Divisão"<<endl;

    cout <<"aux1 = cf / n :"<< endl;
    aux1 = cf / n;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout <<"aux1 = cf / nf :"<< endl;
    aux1 = cf / nf;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout <<"aux1 = 0; aux1/= n :"<< endl;
    aux1 = 0;
    aux1/= n;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout <<"aux1 = 0; aux1/= nf :"<< endl;
    aux1 = 0;
    aux1/= nf;
    cout << "aux1 = "; aux1.print(); cout << ";" << endl<<endl;

    cout<< "Teste Matriz"<<endl;
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    Matriz<int> m(4,4,v);
    m.print();
    cout<< m(0,0)<<endl;
    

    cout << "Fim do programa"<<endl<<endl;


}