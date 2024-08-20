#include <vector>
#include <iostream>
#include "pfn.h"

using namespace std;
class Matriz
{
    public:
    Matriz(int l, int c);
    Matriz(int l, int c, vector<float> v);
    Matriz(int l, int c, vector<pfn> v);
    ~Matriz();

    void printM();
    void setInfo(vector<float> v);
    void setInfo(vector<pfn> v);
    void getInfo(int i, int j);


    private:

    int l,c;
    vector<float> info;
    vector<pfn> info_pfn;

};