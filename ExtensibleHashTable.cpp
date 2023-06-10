
#include <iostream>
#include "ExtensibleHashTable.h"



ExtensibleHashTable::ExtensibleHashTable() {
    bucket_size = 4;
    global_depth = 1;
    directory.push_back(new Bucket(bucket_size));
    directory.push_back(new Bucket(bucket_size));
}

ExtensibleHashTable::ExtensibleHashTable(int bucketSize) {
    bucket_size = bucketSize;
    global_depth = 1;

    // Create two buckets
    directory.push_back(new Bucket(bucket_size));
    directory.push_back(new Bucket(bucket_size));
}

void ExtensibleHashTable::insert(int key) {

}

bool ExtensibleHashTable::find(int key) {
    return false;
}

bool ExtensibleHashTable::remove(int key) {
    return false;
}

void ExtensibleHashTable::print() {

}

ExtensibleHashTable::~ExtensibleHashTable() {

}

ExtensibleHashTable::ExtensibleHashTable(const ExtensibleHashTable &rhs) {

}

ExtensibleHashTable &ExtensibleHashTable::operator=(const ExtensibleHashTable &rhs) {

}


//example.
//0: 000456D8 --> [64,200,-] (2)
std::ostream &operator<<(std::ostream &os, const ExtensibleHashTable &table) {
    for (int i = 0; i < table.directory.size(); i++) {
        os << i << ": " << table.directory[i] <<" --> " << *table.directory[i] << std::endl;
    }
}

int ExtensibleHashTable::hash(int key) const {
    return key&((1<<global_depth)-1);
}
