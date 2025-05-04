#include "disjointSet.h"


disjointSet::disjointSet(int size)
{
    set.resize(size);
    for (int i = 0; i < size; i++) {
        set[i] = i;
    }
}

disjointSet::~disjointSet()
{
    set.clear();
}

int disjointSet::find(int x)
{
    if (x >= 0 && x < set.size())
        return set[x];
    else
        throw out_of_range("Index out of range");
}

void disjointSet::unionSet(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        for (int i = 0; set.size() > i; i++) {
            if (set[i] == rootY) {
                set[i] = rootX;
            }
        }
    }
}

bool disjointSet::isDisjoint(int x, int y)
{
    return find(x) == find(y);
}



int main()
{
    cout << "checking if Disjoint\n";
    disjointSet nodes(10);
    // 1-2-5-6-7 3-8-9 4
    nodes.unionSet(1, 2);
    nodes.unionSet(2, 5);
    nodes.unionSet(5, 6);
    nodes.unionSet(6, 7);
    nodes.unionSet(3, 8);
    nodes.unionSet(8, 9);

    cout << (nodes.isDisjoint(1, 5) ? "True" : "False") << endl;
    cout << (nodes.isDisjoint(5, 7)? "True" : "False") << endl;  // true
    cout <<( nodes.isDisjoint(4, 9)? "True" : "False") << endl;  // false
    nodes.unionSet(9, 4);
    cout << (nodes.isDisjoint(4, 9)? "True" : "False") << endl;  // true

    return 0;
}