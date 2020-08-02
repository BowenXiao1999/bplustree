#pragma once
#include <iostream>
#include <string>
using namespace std;
class BTree {
    public:
    BTree();
    void Insert(string key, string value);
    bool Search(string key);
    ~BTree();
}