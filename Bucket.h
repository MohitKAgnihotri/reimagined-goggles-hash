#ifndef REIMAGINED_GOGGLES_HASH_BUCKET_H
#define REIMAGINED_GOGGLES_HASH_BUCKET_H

#include <vector>
#include <iostream>

class Bucket {
public:
    explicit Bucket(int size);

    // Add destructor, copy constructor, and overloaded assignment operator

    ~Bucket();

    Bucket(const Bucket &rhs);

    static bool find(int key);

    void insert(int key);

    static bool remove(int key);

    void print();

    Bucket &operator=(const Bucket &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Bucket &bucket);

private:
    // Add private attributes

    std::vector<int> keys;
    int localDepth;
};


#endif //REIMAGINED_GOGGLES_HASH_BUCKET_H
