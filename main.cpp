
#include <iostream>
#include "ExtensibleHashTable.h"
using namespace std;

int main()
{
    ExtensibleHashTable table(3);


    table.insert(64);
    cout << table;
    table.insert(200);
    cout << table;
    table.insert(66);
    cout << table;
    table.insert(153);

    cout << table;
    table.insert(218);
    cout << table;
    table.insert(67);
    cout << table;
    table.insert(13);
    cout << table;
    table.insert(253);
    cout << table;
    table.insert(109);
    cout << table;





}