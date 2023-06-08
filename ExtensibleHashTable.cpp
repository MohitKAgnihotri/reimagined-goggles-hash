
#include <iostream>
#include "ExtensibleHashTable.h"



ExtensibleHashTable::ExtensibleHashTable() {
    directory.push_back(new Bucket(4));
}

ExtensibleHashTable::ExtensibleHashTable(int bucketSize) {
    directory.push_back(new Bucket(bucketSize));
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

std::ostream &operator<<(std::ostream &os, const ExtensibleHashTable &table) {
    return std::cout << "Hello World!";
}
