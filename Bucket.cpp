
#include "Bucket.h"

Bucket::Bucket(int depth, int size) {
    localDepth = depth;
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
    return os;
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

int Bucket::insert(int key) {
    bool is_key_present = false;

    // Find if the key is already in the bucket
    std::vector<int>::iterator it;
    for (it = keys.begin(); it != keys.end(); it++) {
        if (*it == key) {
            is_key_present = true;
            break;
        }
    }

    // If the key is not present, add it to the bucket
    // check if the bucket is full
    if (!is_key_present && !isFull()) {
        keys.push_back(key);
        return 1;
    }
    return 0;


}

bool Bucket::remove(int key) {
    // Linear search
    for (int i = 0; i < keys.size(); i++) {
        if (keys[i] == key) {
            keys.erase(keys.begin() + i);
            return true;
        }
    }
}

void Bucket::print() {

}

bool Bucket::isFull() {
    if (keys.size() < bucketSize) {
        return false;
    }
    return true;
}

int Bucket::getLocalDepth() const {
    return localDepth;
}

void Bucket::increase_depth() {
    localDepth++;
}

void Bucket::decrease_depth() {
    localDepth--;
}
