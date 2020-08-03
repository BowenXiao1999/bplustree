#include "BTree.hpp"
#include <string>
int main(int argc, const char** argv) {
    BTree b;
    b.Insert("test", "a");
    bool find = b.Search("test");
    std::cout << "The search result for `test` is " << find << std::endl;
    
    return 0;
}