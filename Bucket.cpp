
#include "Bucket.h"

Bucket::Bucket(int size) {
    keys = std::vector<int>(size);
    localDepth = 0;
}

Bucket::~Bucket() {

}

Bucket &Bucket::operator=(const Bucket &rhs) {
    if (this != &rhs) {
        keys = rhs.keys;
        localDepth = rhs.localDepth;
    }
    return *this;
}
//[64,200,-] (2)
std::ostream &operator<<(std::ostream &os, const Bucket &bucket) {
    for(int i = 0; i < bucket.keys.size(); i++) {
        os << bucket.keys[i] << ",";
    }
    os << " (" << bucket.localDepth << ")";
}

Bucket::Bucket(const Bucket &rhs) {
    keys = rhs.keys;
    localDepth = rhs.localDepth;
}

bool Bucket::find(int key) {
    return false;
}

void Bucket::insert(int key) {

}

bool Bucket::remove(int key) {
    return false;
}

void Bucket::print() {

}
