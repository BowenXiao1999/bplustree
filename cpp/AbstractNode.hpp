#pragma once
#include <iostream>
#include <string>
#include "InteriorNode.hpp"
using namespace std;

const int MAXKV = 255;
const int MAXKC = 511;
struct findResult {
    string value;
    bool ok;
};
class AbstractNode {
    public:
    virtual interiorNode* parent();
    virtual void setParent(interiorNode*);
    virtual bool full();
    virtual findResult* find(std::string key);
};
