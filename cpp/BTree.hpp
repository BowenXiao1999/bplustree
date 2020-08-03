#ifndef BTREE
#define BTREE
#pragma once
#include <iostream>
#include <string>
class BTree {
    public:
    BTree();
    void Insert(std::string key, std::string value);
    bool Search(std::string key);
    ~BTree();
};
#endif // !BTREE