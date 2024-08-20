#include "Matriz.h"

Matriz::Matriz(int l, int c)
{
    this->l = l;
    this->c = c;
    info.resize(l*c);
}

Matriz::Matriz(int l, int c, vector<float> v)
{
    this->l = l;
    this->c = c;
    for(int i = 0; i < l*c; i++)
    {
        info.push_back(v[i]);
    }
}

Matriz::Matriz(int l, int c, vector<pfn> v)
{
    this->l = l;
    this->c = c;
    for(int i = 0; i < l*c; i++)
    {
        info_pfn.push_back(v[i]);
    }
}

Matriz::~Matriz()
{
    info.clear();
    info_pfn.clear();
}

void Matriz::printM()
{
    for(int i = 0; i < l; i++)
    {
        cout << "| ";
        for(int j = 0; j < c; j++)
        {
            cout << info[i*c+j] << " ";
        }
        cout << "|";
        cout << endl;
    }
}

void Matriz::setInfo(vector<float> v)
{
    for(int i = 0; i < l*c; i++)
    {
        info.push_back(v[i]);
    }
}

void Matriz::setInfo(vector<pfn> v)
{
    for(int i = 0; i < l*c; i++)
    {
        info_pfn.push_back(v[i]);
    }
}

void Matriz::getInfo(int i, int j)
{
    cout << info[i*c+j] << endl;
} 
