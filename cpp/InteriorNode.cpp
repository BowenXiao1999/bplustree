#include "AbstractNode.hpp"
#include "InteriorNode.hpp"
const int MAXKC = 511;

class interiorNode: public AbstractNode {
    public:
    kcs kcs;
    int count;
    interiorNode* p;
    interiorNode* parent() {
        return this->p;
    };
    bool full() {
        return false;
    };
    findResult* find(std::string key){
    
    };
    void setParent(interiorNode* P) {
        this->p = P;
    };
};

struct kc
{   
    int key;
    AbstractNode child;
    /* data */
};

typedef kc kcs[MAXKC+1];


