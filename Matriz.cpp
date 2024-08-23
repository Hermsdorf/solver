#include "Matriz.h"
#include <vector>

template <class Type> 
Matriz<Type>::Matriz()
{
    l = 0;
    c = 0;
    v = {};
    L = {};
    U = {};
}

template <class Type>
Matriz<Type>::Matriz(int l, int c)
{
    this->l = l;
    this->c = c;
    v.resize(l*c);
    if(l = c)
    {
        L.resize((l*(l-1))/2);
        U.resize( ((l*(l-1))/2) + l);
    }
}

// template <class Type>
// Matriz<Type>::Matriz(int l, int c, vector<Type> v)
// {
//     this->l = l;
//     this->c = c;
//     this->v = v;
//     if(l = c)
//     {
//         L.resize((l*(l-1))/2);
//         U.resize( ((l*(l-1))/2) + l);
//     }
// }

template <class Type>
Matriz<Type>::~Matriz()
{
    v.clear();
    L.clear();
    U.clear();
}

template <class Type>
Type Matriz<Type>::getInfo(int l, int c)
{
    return v[(l-1)*this->c + c];
}

template <class Type>
Type Matriz<Type>::setInfo(int l, int c, Type val)
{
    v[(l-1)*this->c + c] = val;
    return v[(l-1)*this->c + c];
}

// template <class Type>
// Type Matriz<Type>::setInfo(int l, int c, vector<Type> v)
// {
//     this->v = v;
//     return v[(l-1)*this->c + c];
// }

