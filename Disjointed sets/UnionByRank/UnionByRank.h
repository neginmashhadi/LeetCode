#ifndef UNIONBYRANK_H
#define UNIONBYRANK_H

#include <vector>
#include <iostream>
using namespace std;

class UnionByRank {
public:
  UnionByRank(int size);
  ~UnionByRank();
  void Union(int a, int b);
  int Find(int a);
  bool isConnected(int a, int b);
private:
  vector<int> set;
  vector<int> rank;
};



#endif //UNIONBYRANK_H
