#include "BTree.hpp"
#include <string>

BTree::BTree() {

}


BTree::~BTree() {

}


void BTree::Insert(std::string key, std::string value) {
    std::cout << "Key: " << key << std::endl;
    std::cout << "Value: " << value << std::endl;
}


bool BTree::Search(std::string key) {
    return true;
}