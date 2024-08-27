#ifndef MATRIZ_H__
#define MATRIZ_H__

#include<vector>
using namespace std;

template <class T>
class Matriz
{ 
    public:
    Matriz();
    Matriz(int l, int c);
    Matriz(int l, int c, vector<T> v);
    ~Matriz();

    
    T setInfo(int l, int c, vector<T> v);
    T& operator()(int l, int c);

    private:

    int l, c;
    vector<T> v;
    vector<T> L;
    vector<T> U;

};
template <class T> 
Matriz<T>::Matriz()
{
    l = 0;
    c = 0;
    v = {};
    L = {};
    U = {};
}

template <class T>
Matriz<T>::Matriz(int l, int c)
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

 template <class T>
 Matriz<T>::Matriz(int l, int c, vector<T> v)
 {
     this->l = l;
     this->c = c;
     this->v = v;
     if(l = c)
     {
         L.resize((l*(l-1))/2);
         U.resize( ((l*(l-1))/2) + l);
     }
 }

template <class T>
Matriz<T>::~Matriz()
{
    v.clear();
    L.clear();
    U.clear();
}

template <class T>
T& Matriz<T>::operator()(int l, int c)
{
    return v[(l-1)*this->c + c];
}

 template <class T>
 T Matriz<T>::setInfo(int l, int c, vector<T> v)
 {
     this->v = v;
     return v[(l-1)*this->c + c];
 }



#endif