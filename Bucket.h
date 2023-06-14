#ifndef REIMAGINED_GOGGLES_HASH_BUCKET_H
#define REIMAGINED_GOGGLES_HASH_BUCKET_H

#include <vector>
#include <iostream>

class Bucket {
public:
    explicit Bucket(int depth, int size);

    // Add destructor, copy constructor, and overloaded assignment operator

    ~Bucket();

    Bucket(const Bucket &rhs);

    bool find(int key);

    int insert(int key);

    bool remove(int key);

    void print();

    bool isFull();

    Bucket &operator=(const Bucket &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Bucket &bucket);

    int getLocalDepth() const;
    void increase_depth();
    void decrease_depth();


    std::vector<int> keys;
private:
    // Add private attributes

    int localDepth;
    int bucketSize;
};


#endif //REIMAGINED_GOGGLES_HASH_BUCKET_H
