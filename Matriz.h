#ifndef MATRIZ_H__
#define MATRIZ_H__

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "operadores.h"
using namespace std;

template <class T>
class Matriz
{
public:
    Matriz();
    Matriz(int l, int c);
    Matriz(int l, int c, vector<T> v);
    ~Matriz();

    void setInfo(int l, int c, vector<T> v);
    T &operator()(int l, int c);

    vector<T> &L();

    void print();

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
    v.resize(l * c);
}

template <class T>
Matriz<T>::Matriz(int l, int c, vector<T> v)
{
    this->l = l;
    this->c = c;
    this->v = v;
}

template <class T>
Matriz<T>::~Matriz()
{
    this->v.clear();
    this->L.clear();
    this->U.clear();
}

template <class T>
T &Matriz<T>::operator()(int l, int c)
{
    return v[((l * this->c) + c)];
}

template <class T>
void Matriz<T>::setInfo(int l, int c, vector<T> v)
{
    this->l = l;
    this->c = c;
    this->v = v;
}

template <class T>
void Matriz<T>::print()
{
    for (int i = 0; i < l; i++)
    {
        cout << "| " ;
        for (int j = 0; j < c; j++)
        {
            cout << this->operator()(i, j) <<" ";
            // v[i * c + j] << " ";
        }
        cout << " |";
        cout << endl;
    }
}

// template <class T>
// void Matriz<T>::print()
// {
//     T max = max_element(this->v.begin(), this->v.end());
//     int max_size = to_string(max).size();
//     for (int i = 0; i < l; i++)
//     {
//         cout << "| " ;
//         for (int j = 0; j < c; j++)
//         {
//             int a = this->operator()(i, j);
//             for (int k = 0; k != max_size - to_string(a).size(); k++)
//             {
//                 cout << " ";
//             }
//             cout << a;
//             // v[i * c + j] << " ";
//         }
//         cout << " |";
//         cout << endl;
//     }
// }




#endif