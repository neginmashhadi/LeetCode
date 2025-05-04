#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <iostream>
using namespace std;

class disjointSet {
public:
    disjointSet(int size);
    ~disjointSet();
    void unionSet(int x, int y);
    int find(int x);
    bool isDisjoint(int x, int y);
private:
    vector<int> set;
};

#endif //DISJOINTSET_H
