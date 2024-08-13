#include <iostream>
#include <math.h>
#include <iomanip>
#include <limits>

using namespace std;
class pfn
{
    public:
    pfn( int mantissa);
    ~pfn();

    void operator= (float val);
    void operator=(pfn p);
    //pfn operator+ (pfn p);
    float operator+ (float f);
    void set_val(float val);  // Formata o valor de entrada para o formato de ponto flutuante
                              // realizando os arredondamento necessário para o tamanho da mantissa;
    void print();

    private:
    float val;  // valor.
    int m;      //Quantidade de digitos na mantissa
    int b;      // base.
    int e;      // expoente.

};