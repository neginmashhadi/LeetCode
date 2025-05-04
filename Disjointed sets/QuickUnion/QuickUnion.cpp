#include "QuickUnion.h"

QuickUnion::QuickUnion(int size)
{
    set.resize(size);
    for (int i = 0; i < size; i++) {
        set[i] = i;
    }
}

QuickUnion::~QuickUnion()
{
    set.clear();
}

int QuickUnion::find(int x)
{
    while (x != set[x]) {
        x = set[x];
    }
    return x;
}

void QuickUnion::Union(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        set[rootY] = rootX;
    }
}

bool QuickUnion::isConnected(int x, int y)
{
    return find(x) == find(y);
}

int main() {
    cout << boolalpha;
    QuickUnion node(10);

    node.Union(1, 2);
    node.Union(2, 5);
    node.Union(5, 6);
    node.Union(6, 7);
    node.Union(3, 8);
    node.Union(8, 9);
    cout << node.isConnected(1, 5) << endl;  // true
    cout << node.isConnected(5, 7) << endl;  // true
    cout << node.isConnected(4, 9) << endl;  // false
    node.Union(9, 4);
    cout << node.isConnected(4, 9) << endl;  // true

    return 0;
}


