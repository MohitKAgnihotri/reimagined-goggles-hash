
#include <iostream>
#include "ExtensibleHashTable.h"

using namespace std;



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

    int directory_index = -1;

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
            auto *new_bucket = new Bucket(bucket->getLocalDepth(),bucket_size);

            // Derive the index based on the key which is to be inserted
            directory_index = hash(key);
            directory[directory_index] = new_bucket;

            // re-distribute the keys in the bucket
            for (int i = 0; i < bucket->keys.size(); i++) {
                int key_to_distribute = bucket->keys[i];
                int new_index = hash(key_to_distribute);
                if (new_index != index) {
                    new_bucket->insert(key_to_distribute);
                    bucket->remove(key_to_distribute);
                }
            }
            // Insert the new key
            insert(key);
        } else if (bucket->getLocalDepth() < global_depth) {

            // Get local and global depth
            int local_depth = bucket->getLocalDepth();

            // Create two new buckets
            auto *new_bucket1 = new Bucket(local_depth + 1, bucket_size);
            auto *new_bucket2 = new Bucket(local_depth + 1, bucket_size);


            // Iterate through the keys in the bucket and re-distribute them
            for (int key_to_distribute : bucket->keys) {
                int new_index = hash(key_to_distribute);
                if (((new_index >> local_depth) & 0x1) == 0) {
                    new_bucket1->insert(key_to_distribute);
                } else {
                    new_bucket2->insert(key_to_distribute);
                }
            }

            // Update the directory
            directory[index] = new_bucket1;
            directory[(index ^ (1 << local_depth))] = new_bucket2;

            // Free the memory of the old bucket
            delete bucket;


            // Insert the new key
            insert(key);


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

    // Use the hash function to find the directory index.
    int index = hash(key);

    // Check index is in range
    if (index < 0 || index >= directory.size()) {
        return false;
    }

    // Use the index to find the bucket
    Bucket *bucket = directory[index];

    // Use the bucket to remove the key
    return bucket->remove(key);

}

void ExtensibleHashTable::print() {
    cout << *this << endl;

}

ExtensibleHashTable::~ExtensibleHashTable() {

}



//example.
//0: 000456D8 --> [64,200,-] (2)
std::ostream &operator<<(std::ostream &os, const ExtensibleHashTable &table) {
    for (int i = 0; i < table.directory.size(); i++) {
        os << i << ": " << table.directory[i] <<" --> " << *table.directory[i] << std::endl;
    }
    return os;
}

int ExtensibleHashTable::hash(int key) const {
    return key&((1<<global_depth)-1);
}
