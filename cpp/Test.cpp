#include "BTree.hpp"
#include <string>
int main(int argc, const char** argv) {
    BTree b;
    b.Insert("test", "a");
    b.Search("test");
    return 0;
}