#include <iostream>
#include <bitset>
#include  "pfn.h"

using namespace std;

int main() 
{
    float a = 123.456;
    float b = 0.00078910;

    pfn af(2);
    pfn bf(2);

    cout << "Valor convencionais: "<<endl;
    cout << "a = " << a << ";"<<endl;
    cout << "b = " << b << ";"<<endl<<endl;

    af = a;
    bf = b;

    //af.set_val(a);
    //bf.set_val(b);

    cout << "Valor ponto flutuante: "<<endl;
    cout << "a = "; af.print(); cout << ";" << endl;
    cout << "b = "; bf.print(); cout << ";" << endl<<endl;

    cout << "Fim do programa"<<endl<<endl;

}