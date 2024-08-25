#ifndef PFN_H__
#define PFN_H__

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

    pfn& operator= (float val);
    pfn& operator=(pfn p);
    pfn operator+ (float f);
    pfn operator+ (pfn& a);
    pfn& operator+= (pfn& a);
    pfn& operator+= (float f);

    pfn operator- (float f);
    pfn operator- (pfn& a);
    pfn& operator-= (pfn& a);
    pfn& operator-= (float f);

    pfn operator* (float f);
    pfn operator* (pfn& a);
    pfn& operator*= (pfn& a);
    pfn& operator*= (float f);

    pfn operator/ (float f);
    pfn operator/ (pfn& a);
    pfn& operator/= (pfn& a);
    pfn& operator/= (float f);
    

    friend ostream& operator<<(ostream& out,pfn& p);
    friend istream& operator>>(istream& in,pfn& p);

    void set_val(float val);  // Formata o valor de entrada para o formato de ponto flutuante
                              // realizando os arredondamento necessário para o tamanho da mantissa;
    void print();

    private:
    float val;  // valor.
    int m;      //Quantidade de digitos na mantissa
    int b;      // base.
    int e;      // expoente.

};

#endif
//friend ostream& operator<<(ostream& out,pfn& p);

