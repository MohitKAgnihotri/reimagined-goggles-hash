
#include <iostream>
#include "ExtensibleHashTable.h"



ExtensibleHashTable::ExtensibleHashTable() {
    bucket_size = 4;
    global_depth = 1;

    directory = std::vector<Bucket *>(1 << global_depth);

    for (int i = 0; i < 1 << global_depth; i++) {
        // Create a new bucket
        Bucket *bucket = new Bucket(global_depth, bucket_size);
        directory[i] = bucket;
    }
}

ExtensibleHashTable::ExtensibleHashTable(int bucketSize) {
    bucket_size = bucketSize;
    global_depth = 1;

    directory = std::vector<Bucket *>(1 << global_depth);

    for (int i = 0; i < 1 << global_depth; i++) {
        // Create a new bucket
        Bucket *bucket = new Bucket(global_depth, bucket_size);
        directory[i] = bucket;
    }
}

void ExtensibleHashTable::insert(int key) {

    //Use the hash function to find the directory index.
    int index = hash(key);

    // Check if the index is in range
    if (index < 0 || index >= directory.size()) {
        return;
    }

    // Use the index to find the bucket
    Bucket *bucket = directory[index];

    // Check if the bucket is full
    if (bucket->isFull()) {

        //If global depth and local depth are the same
        if (bucket->getLocalDepth() == global_depth) {
            grow_directory_size();

            // Update the local depth of the old bucket
            bucket->increase_depth();

            // re-distribute the keys in the bucket
            // create a new bucket
            Bucket *new_bucket = new Bucket(bucket->getLocalDepth(),bucket_size);

            // Derive the index based on the key which is to be inserted
            int new_index = hash(key);
            directory[new_index] = new_bucket;

            // re-distribute the keys in the bucket
            for (int i = 0; i < bucket->keys.size(); i++) {
                int key = bucket->keys[i];
                int new_index = hash(key);
                if (new_index != index) {
                    new_bucket->insert(key);
                    bucket->remove(key);
                }
            }

            // Insert the new key
            new_bucket->insert(key);
        } else if (bucket->getLocalDepth() < global_depth) {

            // Update the local depth of the old bucket
            bucket->increase_depth();

            // re-distribute the keys in the bucket
            // create a new bucket
            Bucket *new_bucket = new Bucket(bucket->getLocalDepth(),bucket_size);

            // Derive the index based on the key which is to be inserted
            int new_index = hash(key);
            directory[new_index] = new_bucket;

            // re-distribute the keys in the bucket
            for (int i = 0; i < bucket->keys.size(); i++) {
                int key = bucket->keys[i];
                int new_index = hash(key);
                if (new_index != index) {
                    new_bucket->insert(key);
                    bucket->remove(key);
                }
            }
            // Insert the new key
            new_bucket->insert(key);

        } else {

        }

    } else {
        bucket->insert(key);
    }

}

void ExtensibleHashTable::grow_directory_size() {
    // the directory size  must be doubled before creating the new bucket.
    unsigned long directory_size = directory.size();
    for (int i = 0; i < directory_size; i++) {
        directory.push_back(directory[i]);
    }
    global_depth++;
}

bool ExtensibleHashTable::find(int key) {
    //Use the hash function to find the directory index.
    int index = hash(key);

    //Use the index to find the bucket.
    // Check index is in range
    if (index < 0 || index >= directory.size()) {
        return false;
    }

    // Use the index to find the bucket
    Bucket *bucket = directory[index];

    // Use the bucket to find the key
    return bucket->find(key);

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
