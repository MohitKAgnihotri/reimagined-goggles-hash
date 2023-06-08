
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

std::ostream &operator<<(std::ostream &os, const Bucket &bucket) {
    return os << "Bucket: " << bucket.keys.size() << " " << bucket.localDepth;
}

Bucket::Bucket(const Bucket &rhs) {
    keys = rhs.keys;
    localDepth = rhs.localDepth;
}
