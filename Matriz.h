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

    Matriz<T> L();
    Matriz<T> U();

    vector<T> &Lower() { return lower; };
    vector<T> &Upper() { return upper; };
    vector<T> &Data() { return v; }

    void print();

private:
    int l, c;
    vector<T> v;
    vector<T> lower;
    vector<T> upper;
};
template <class T>
Matriz<T>::Matriz()
{
    l = 0;
    c = 0;
    for (int i = 0; i < l * c; i++)
    {
        v.push_back(0);
    }
}

template <class T>
Matriz<T>::Matriz(int l, int c)
{
    this->l = l;
    this->c = c;
    for (int i = 0; i < l * c; i++)
    {
        v.push_back(0);
    }
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
        cout << "| ";
        for (int j = 0; j < c; j++)
        {
            cout << this->operator()(i, j) << " ";
            // v[i * c + j] << " ";
        }
        cout << " |";
        cout << endl;
    }
}

template <class T>
Matriz<T> Matriz<T>::L()
{
        Matriz<T> L(l, c);
        Matriz<T> U(l, c);
    if (this->lower.empty())
    {
        U.Data() = this->v;
        T m, n, d;
        for (int i = 0; i < c; i++)
        {
            d = U(i, i);
            for (int j = 1 + i; j < l; j++)
            {
                m = (this->operator()(j, i) / d);
                L(j, i) = m;
                for(int k = 0; k < c; k++)
                {
                    n = U(j, k) - m * U(i, k);
                    U(j, k) = n;
                }
            }
        }
        this->lower = L.Data();
        this->upper = U.Data();
    }
    else
    {
        Matriz<T> L(l, c, lower);
    }

    return L;
}

template <class T>
Matriz<T> Matriz<T>::U()
{
        Matriz<T> L(l, c);
        Matriz<T> U(l, c);
    if (this->upper.empty())
    {
        U.Data() = this->v;
        T m, n, d;
        for (int i = 0; i < c; i++)
        {
            d = U(i, i);
            for (int j = 1 + i; j < l; j++)
            {
                m = (this->operator()(j, i) / d);
                L(j, i) = m;
                for(int k = i; k < c; k++)
                {
                    n = U(j, k) - (m * U(i, k));
                    U(j, k) = n;
                }
            }
        }
        this->lower = L.Data();
        this->upper = U.Data();
    }
    else
    {
        Matriz<T> U(l, c, upper);
    }

    return U;
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