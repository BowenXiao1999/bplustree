#pragma once
#include <iostream>
#include <string>
using namespace std;

class AbstractNode {
    public:
    virtual *findResult find(string key) = 0;
    virtual void parent() = 0;
    virtual void setParent() = 0;
    virtual bool full() = 0;

}

struct findResult {
    string value;
    bool ok;
}