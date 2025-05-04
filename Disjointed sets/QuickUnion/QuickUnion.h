#ifndef QUICKUNION_H
#define QUICKUNION_H

#include <iostream>
using namespace std;

class QuickUnion
{
public:
    QuickUnion(int size);
    ~QuickUnion();
    void Union(int x, int y);
    int find(int x);
    bool isConnected(int x, int y);

private:
    vector<int> set;
};

#endif //QUICKUNION_H
