#include <iostream>
#include "collection-template.h"
using namespace std;
int main(void)
{
    try
    {
        Collection<double> collection(5);
        collection.insert(10.5);
        collection.insert(12.5);
        collection.insert(13.5);
        collection.remove(12.5);
        if (collection.contains(13.5))
            cout << "Object is found" << endl;
        else 
            cout << "Object is not found" << endl;
    }
    catch(CollectionIsFullException e)
    {
        cout << "Collection is full!" << endl;
    }
    catch (EmptyCollectionException e)
    {
        cout << "Collection is empty!" << endl;
    }
    catch(ObjectNotFoundException e)
    {
        cout << "Object is not found!" << endl;
    }
    return 0;
}