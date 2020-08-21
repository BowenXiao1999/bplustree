#include "AbstractNode.hpp"
#include "InteriorNode.hpp"
#include <tuple>
#include <algorithm>
using namespace std;


const int MAXKC = 511;

struct kc
{
    int key;
    AbstractNode child;
    /* data */
};

typedef kc kcs[MAXKC+1];

class interiorNode: public AbstractNode {
    public:
    kcs kcs;
    int count;
    interiorNode* p;

};

interiorNode::interiorNode(kcs c, interiorNode* p, int cnt) {
    kcs = c;
    count = cnt;
    this->p = p;
}

tuple<int, bool> interiorNode::find(std::string key){
    int i = searchFirstLarge(count - 1, key);
    return {i, true};
};

void interiorNode::setParent(interiorNode* P) {
    this->p = P;
};

bool interiorNode::full() {
    return count == MAXKC;
};

interiorNode* interiorNode::parent() {
    return p;
};

void interiorNode::setParent(interiorNode* P) {
    p = P;
};

// search the first index larger than given key
int interiorNode::searchFirstLarge(int mi, int key) {
    for (int i = 0; i < mi; i++){
        if (kcs[i] > key) {
            return i;
        }
    }
}

// insert a node with key into interiorNode
tuple<int, interiorNode*, bool> interiorNode::insert(int key, AbstractNode node) {
    auto [i, f] = find(key);

    if (!full()) {
        // move
        copy(&kcs[i], &kcs[count], &kcs[i+1]);

        kcs[i].key = key;
        kcs[i].child = node;
        kcs[i].setParent(this);

        count++;
        return {0, nullptr, false};
    }

    kcs[MAXKC].key = key;
    kcs[MAXKC].child = node;
    node.setParent(this);

    auto [next, midKey] = split();

    return {midKey, next, true};
}


bool compare(auto i, auto j) {
    return i.key < j.key;
}
tuple<interiorNode*, int> interiorNode::split() {
    sort(&kcs[0], end(kcs), compare);

    // divide by half
    int midIndex = MAXKC/2;
    auto midc = kcs[midIndex];
    auto midk = kcs[midIndex].key;

    auto next = new interiorNode(nullptr, nullptr, 0);
    copy(&kcs[midIndex+1], end(kcs), next.kcs);
    next.count = MAXKC - midIndex;
    // update parent
    for (int i = 0; i < next.count; i++) {
        next.kcs[i].setParent(next);
    }

    count = midIndex + 1;
    kcs[count - 1].key = 0; // ? why set to 0?
    kcs[count - 1].child = midc;
    midc.setParent(this);

    return {next, midKey};

}
