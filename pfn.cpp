#include "pfn.h"

pfn::pfn( int mantissa)
{
    m = mantissa;
    b = 0;
    e = 0;
    val = 0;
    string str = to_string(val);
}

pfn::~pfn(){}


void pfn::operator=(float val)
{
    set_val(val);
}

void pfn::operator=(pfn p)
{
    set_val(p.val);
}

float pfn::operator+(float f)
{
    float sum = val * pow(10,e);
    return (sum + f);
}


void pfn::set_val(float val)
{
    int sinal;
    val < 0 ? sinal = -1 : sinal = 1 ;
    int a = sinal * val; // parte inteira
    float b = val - a;   // parte fracionaria
    this->e = 0;
    if (a != 0) // val tem parte inteira
    {
        float aux = 0;
        while (a != 0)
        {
            aux = a;
            a = aux/10;
            aux = aux/10;
            b = (b/10) + (aux-a);
            e++;
        }
    }
    else if(b != 0) // val não tem parte inteira
    {
        a = b*10;
        while (a == 0) 
        {
            b = b*10; //desloca a virgula para a esquerda
            a = b*10; //assume o valor do primeiro digito da mantissa
            e--;            
        }
        
    }

    

    // --------- AJUSTE DA MANTISSA ---------//
                                             // val = 0.1234 e m = 3
    int n = b * (pow(10,this->m));           // n   = 123 
    int x = b * (pow(10,(this->m)+1));       // x   = 1234 
    int y = n*10;                            // y   = 1230

    int dva = x - y;                         // dva =    4
    if(dva > 5)
    {
        n ++;
    }
    if(dva = 5)
    {
        if((n%2)!=0)
            n++;
    }                            // Alguma coisa de errado até aqui.
                                 // Se o valor for 1.0750 e m = 4 ele aredonda para 0.1076... depois arrumo isso 
    b = n ;
    b = b/ (pow(10,this->m));
    this->val = b*sinal;
}

void pfn::print()
{
    cout << fixed;
    cout.precision(this->m);
    cout << this->val << " E" << this->e;
}