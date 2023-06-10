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

    bool find(int key);

    void insert(int key);

    static bool remove(int key);

    void print();

    bool isFull();

    Bucket &operator=(const Bucket &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Bucket &bucket);

    void setLocalDepth(int depth);
    int getLocalDepth();



private:
    // Add private attributes

    std::vector<int> keys;

    int localDepth;
    int bucketSize{};
};


#endif //REIMAGINED_GOGGLES_HASH_BUCKET_H
