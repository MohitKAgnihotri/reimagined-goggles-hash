
#include <iostream>
#include "ExtensibleHashTable.h"
using namespace std;

int main()
{
    ExtensibleHashTable table(3);


    table.insert(64);
    table.insert(200);
    table.insert(66);
    table.insert(153);

    table.insert(218);
    table.insert(67);
    table.insert(13);

    table.insert(253);

    table.insert(109);


    table.print();


    table.remove(64);
    table.print();




}