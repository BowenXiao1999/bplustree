#pragma once
#include <iostream>
#include <string>
#include "InteriorNode.hpp"
#include <tuple>

//using namespace std;



class AbstractNode {
    public:
    virtual interiorNode* parent() = 0;
    virtual void setParent(interiorNode*) = 0;
    virtual bool full() = 0;
    virtual std::tuple<int, bool> find(std::string key) = 0;
};
