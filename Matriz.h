#ifndef MATRIZ_H__
#define MATRIZ_H__

#include<vector>

template <class Type>
class Matriz
{ 
    public:
    Matriz();
    Matriz(int l, int c);
    Matriz(int l, int c, vector<Type> v);
    ~Matriz();

    Type getInfo(int l, int c);
    Type setInfo(int l, int c, Type val);
    Type setInfo(int l, int c, vector<Type> v);

    private:

    int l, c;
    vector<Type> v;
    vector<Type> L;
    vector<Type> U;

};

#endif