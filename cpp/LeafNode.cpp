#include <iostream>
#include <string>
#include "AbstractNode.hpp"
#include <tuple>

struct kv {
    int key;
    std::string value;
};

typedef kv kvs[MAXKV];

class leafNode: public AbstractNode {
public:
    int count;
    kvs kvs;
    leafNode* next;
    leafNode* p;

    bool full();
    std::tuple<int, bool> insert(int key, std::string value);
    std::tuple<int, bool> find(int key);
    leafNode* split();
};

bool leafNode::full() { return count == MAXKV; }

// TODO
std::tuple<int, bool> leafNode::find(int key) {}

std::tuple<int, bool> leafNode::insert(int key, std::string value) {}

leafNode* leafNode::split() {}










