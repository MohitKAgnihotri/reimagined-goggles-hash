
#include "Bucket.h"

Bucket::Bucket(int size) {
    localDepth = 0;
    bucketSize = size;
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
    os << "[";
    for(int i = 0; i < bucket.keys.size(); i++) {
        os << bucket.keys[i] << ",";
    }
    os << "]";
    os << " (" << bucket.localDepth << ")";
}

Bucket::Bucket(const Bucket &rhs) {
    keys = rhs.keys;
    localDepth = rhs.localDepth;
}

bool Bucket::find(int key) {
    // Linear search
    for (int i = 0; i < keys.size(); i++) {
        if (keys[i] == key) {
            return true;
        }
    }
    return false;
}

void Bucket::insert(int key) {
    this->keys.push_back(key);
    setLocalDepth(getLocalDepth() + 1);
}

bool Bucket::remove(int key) {
    return false;
}

void Bucket::print() {

}

bool Bucket::isFull() {
    if (localDepth < bucketSize) {
        return false;
    }
    return true;
}

void Bucket::setLocalDepth(int depth) {
    localDepth = depth;
}

int Bucket::getLocalDepth() {
    return localDepth;
}