
#ifndef REIMAGINED_GOGGLES_HASH_EXTENSIBLEHASHTABLE_H
#define REIMAGINED_GOGGLES_HASH_EXTENSIBLEHASHTABLE_H

#include <vector>
#include "Bucket.h"

#include <iostream>

class ExtensibleHashTable {
public:
    ExtensibleHashTable();

    ExtensibleHashTable(int bucketSize);

    bool find(int key);

    void insert(int key);

    bool remove(int key);

    void print();

    // Add destructor, copy constructor, and overloaded assignment operator

    ~ExtensibleHashTable();

    ExtensibleHashTable(const ExtensibleHashTable &rhs);

    ExtensibleHashTable &operator=(const ExtensibleHashTable &rhs);

    friend std::ostream &operator<<(std::ostream &os, const ExtensibleHashTable &table);




private:
    // Add private helper methods and attributes

    std::vector<Bucket *> directory;
};


#endif //REIMAGINED_GOGGLES_HASH_EXTENSIBLEHASHTABLE_H

