#ifndef COLLECTION_H
#define COLLECTION_H

/**
 * @brief Exception thrown when attempting to insert into a full collection
 */
class CollectionIsFullException {};

/**
 * @brief Exception thrown when attempting operations on an empty collection
 */
class EmptyCollectionException {};

/**
 * @brief Exception thrown when object is not found in the collection
 */
class ObjectNotFoundException {};

/**
 * @brief A dynamic array-based collection template class
 * @tparam Object Type of objects stored in the collection
 */
template <typename Object>
class Collection
{
private:
    int lastPointer;  ///< Index of last element (-1 if empty)
    Object *arr;      ///< Dynamic array to store objects
    int maxSize;      ///< Maximum capacity of the collection

public:
    /**
     * @brief Constructs a collection with specified size
     * @param size Maximum capacity
     */
    Collection(int size)
    {
        maxSize = size;
        arr = new Object[size];
        lastPointer = -1;
    }

    /// Copy constructor deleted - no copying allowed
    Collection(const Collection& collectionObject) = delete;
    
    /// Move constructor deleted - no moving allowed
    Collection(Collection&& collectionObject) = delete;
    
    /// Copy assignment deleted - no copying allowed
    Collection& operator=(const Collection& collectionObject) = delete;
    
    /// Move assignment deleted - no moving allowed
    Collection& operator=(Collection&& collectionObject) = delete;

    /**
     * @brief Inserts an object into the collection
     * @param obj Object to insert
     * @throws CollectionIsFullException if collection is full
     */
    void insert(const Object &obj)
    {
        if (isFull())
        {
            throw CollectionIsFullException();
        }
        else
        {
            lastPointer++;
            arr[lastPointer] = obj;
        }
    }

    /**
     * @brief Checks if collection is full
     * @return true if full, false otherwise
     */
    bool isFull() const
    {
        return lastPointer == maxSize - 1;
    }

    /**
     * @brief Checks if collection is empty
     * @return true if empty, false otherwise
     */
    bool isEmpty() const
    {
        return lastPointer == -1;
    }

    /**
     * @brief Removes all elements from collection
     */
    void makeEmpty() 
    {
        lastPointer = -1;
    }

    /**
     * @brief Removes first occurrence of an object
     * @param obj Object to remove
     * @throws EmptyCollectionException if collection is empty
     * @throws ObjectNotFoundException if object not found
     */
    void remove(const Object &obj)
    {
        if (isEmpty())
        {
            throw EmptyCollectionException();
        }
        else
        {
            for (int i = 0; i <= lastPointer; i++)
            {
                if (obj == arr[i])
                {
                    for (int j = i + 1; j <= lastPointer; j++)
                        arr[j - 1] = arr[j];
                    lastPointer--;
                    return;
                }
            }
            throw ObjectNotFoundException();
        }
    }

    /**
     * @brief Checks if object exists in collection
     * @param obj Object to search for
     * @return true if found, false otherwise
     */
    bool contains(const Object &obj) const
    {
        for (int i = 0; i <= lastPointer; i++)
        {
            if (obj == arr[i])
            {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Destructor to free allocated memory
     */
    ~Collection()
    {
        delete[] arr;
    }
};
#endif