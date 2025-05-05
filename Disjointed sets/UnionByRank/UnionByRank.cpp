#include "UnionByRank.h"

UnionByRank::UnionByRank(int size)
{
    set.reserve(size);
    rank.reserve(size);

    for (int i = 0; i < size; i++) {
        set[i] = i;
        rank[i] = i;
    }
}

UnionByRank::~UnionByRank()
{
    set.clear();
    rank.clear();
}

int UnionByRank::Find(int a)
{
    while (set[a] != a)
        a = set[a];
    return a;
}

void UnionByRank::Union(int a, int b)
{
    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA != rootB) {
        if (rank[rootA] > rank[rootB])
            set[rootB] = rootA;
        else if (rank[rootA] < rank[rootB])
            set[rootA] = rootB;
        else
        {
            set[rootB] = rootA;
            rank[rootA] += 1;
        }
    }
}


bool UnionByRank::isConnected(int a, int b)
{
    return Find(a) == Find(b);
}

int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    UnionByRank unionByRank(10);
    // 1-2-5-6-7 3-8-9 4
    unionByRank.Union(1, 2);
    unionByRank.Union(2, 5);
    unionByRank.Union(5, 6);
    unionByRank.Union(6, 7);
    unionByRank.Union(3, 8);
    unionByRank.Union(8, 9);
    cout << unionByRank.isConnected(1, 5) << endl;  // true
    cout << unionByRank.isConnected(5, 7) << endl;  // true
    cout << unionByRank.isConnected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    unionByRank.Union(9, 4);
    cout << unionByRank.isConnected(4, 9) << endl;  // true

    return 0;
}
