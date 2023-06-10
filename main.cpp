
#include <iostream>
#include "ExtensibleHashTable.h"
using namespace std;

int main()
{
    ExtensibleHashTable table(4);
    ExtensibleHashTable table2;

    table.insert(64);
    table.insert(200);
    cout << table.find(64) << endl;

    cout << table;
    cout << table2;



}