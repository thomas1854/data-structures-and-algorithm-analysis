#include <iostream>
#include "ordered-collection.h"
using namespace std;


int main(void)
{
    OrderedCollection<double> orderedCollection(5);
    orderedCollection.insert(10.5);
    orderedCollection.insert(12.5);
    orderedCollection.insert(125.5);
    orderedCollection.insert(1.5);
    orderedCollection.insert(15.5);
    cout << orderedCollection.findMin() << endl;
    orderedCollection.remove(1.5);
    cout << orderedCollection.findMax() << endl;
    cout << orderedCollection.findMin() << endl;
    orderedCollection.remove(125.5);
    cout << orderedCollection.findMax() << endl;
    return 0;
}