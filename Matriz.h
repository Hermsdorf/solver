#ifndef MATRIZ_H__
#define MATRIZ_H__

#include <vector>
//#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

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
    Matriz<T> G();

    vector<T> &Lower() { return lower; };
    vector<T> &Upper() { return upper; };
    vector<T> &Data() { return v; }

    void print();

private:
    int l, c;
    vector<T> v;
    vector<T> lower;
    vector<T> upper;
    vector<T> g;
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
        std::cout << "| ";
        for (int j = 0; j < c; j++)
        {
            std::cout << this->operator()(i, j) << " ";
            // v[i * c + j] << " ";
        }
        std::cout << " |";
        std::cout << endl;
    }
}

template <class T>
Matriz<T> Matriz<T>::L()
{
    Matriz<T> L(l, c);
    if (this->lower.empty())
    {
        Matriz<T> U(l, c);
        U.Data() = this->v;
        T m, n, d;
        for (int i = 0; i < c; i++)
        {
            d = U(i, i);
            for (int j = i + 1; j < l; j++)
            {
                m = (U(j, i) / d);
                L(j, i) = m;
                for (int k = i; k < c; k++)
                {
                    n = U(j, k) - m * U(i, k);
                    cout << n << endl;
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
    Matriz<T> U(l, c, this->upper);
    if (this->upper.empty())
    {
        Matriz<T> L(l, c, lower);
        U.Data() = this->Data();
        T m, n, d;
        for (int i = 0; i < c; i++)
        {
            d = U(i, i);
            for (int j = 1 + i; j < l; j++)
            {
                m = (U(j, i) / d);
                L(j, i) = m;
                for (int k = i; k < c; k++)
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
        Matriz<T> U(l, c, this->upper);
    }

    return U;
}

template <class T>
Matriz<T> Matriz<T>::G()
{
    Matriz<T> G(this->l, this->c);
    int n = this->l;
    for (int j = 0; j < n; j++)
    {
        T sum = 0;
        for (int k = 0; k < j-1; k++)
        {
            T val = G(j, k);
            sum += pow(val, 2);
        }

        T val2 = this->operator()(j, j) - sum;
        G(j, j) = sqrt(val2);
        for (int i = j + 1; i < n; i++)
        {
            T sum2 = 0;
            for (int k = 0; k < j-1; k++)
            {
                sum2 += G(i, k) * G(j, k);
            }
            G(i, j) = (this->operator()(i, j) - sum2) / G(j, j);
        }
    }
    this->g = G.Data();

    return G;
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