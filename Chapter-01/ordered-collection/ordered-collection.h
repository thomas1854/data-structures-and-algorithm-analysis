#ifndef ORDEREDCOLLECTION_H
#define ORDEREDCOLLECTION_H

/**
 * @brief Exception thrown when attempting to insert into a full collection.
 */
class CollectionIsFullException {};

/**
 * @brief Exception thrown when attempting operations on an empty collection.
 */
class EmptyCollectionException {};

/**
 * @brief Exception thrown when an object is not found in the collection.
 */
class ObjectNotFoundException {};

/**
 * @class OrderedCollection
 * @brief A fixed-size collection that maintains elements in sorted order.
 * * This class uses a contiguous array. It provides efficient min/max access 
 * and uses binary search for insertions and removals.
 * * @tparam Comparable Type of elements stored; must support <, >, and == operators.
 */
template <typename Comparable>
class OrderedCollection
{
private:
    int lastPointer; ///< Index of the current last element. -1 if empty.
    int maxSize;     ///< Maximum capacity of the collection.
    Comparable *arr; ///< Internal array storage.

public:
    /**
     * @brief Construct a new Ordered Collection object.
     * @param size The maximum capacity of the collection.
     */
    OrderedCollection(int size)
    {
        maxSize = size;
        lastPointer = -1;
        arr = new Comparable[maxSize];
    }

    // Disable copy/move semantics to prevent shallow copy issues with the raw pointer
    OrderedCollection(const OrderedCollection &) = delete;
    OrderedCollection &operator=(const OrderedCollection &) = delete;
    OrderedCollection(OrderedCollection &&) = delete;
    OrderedCollection &operator=(OrderedCollection &&) = delete;

    /**
     * @brief Checks if the collection is empty.
     * @return true if no elements exist, false otherwise.
     */
    bool isEmpty() const
    {
        return lastPointer == -1;
    }

    /**
     * @brief Checks if the collection has reached capacity.
     * @return true if no more elements can be added.
     */
    bool isFull() const
    {
        return lastPointer == maxSize - 1;
    }

    /**
     * @brief Inserts an element into the collection while maintaining order.
     * @note Complexity: O(log n) for search, O(n) for element shifting.
     * @param comparable The item to insert.
     * @throw CollectionIsFullException if isFull() is true.
     */
    void insert(const Comparable &comparable)
    {
        if (isFull())
        {
            throw CollectionIsFullException();
        }

        int left = 0, right = lastPointer;
        // Binary search to find the correct insertion index
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if (comparable > arr[mid])
                left = mid + 1;
            else 
                right = mid - 1;
        }

        // Shift elements to the right to create a gap at 'left'
        for (int i = lastPointer; i >= left; i--)
            arr[i + 1] = arr[i];

        arr[left] = comparable;
        lastPointer++;
    }

    /**
     * @brief Removes a specific element from the collection.
     * @note Complexity: O(log n) for search, O(n) for element shifting.
     * @param obj The element to find and remove.
     * @throw EmptyCollectionException if the collection is empty.
     * @throw ObjectNotFoundException if the element does not exist.
     */
    void remove(const Comparable &obj)
    {
        if (isEmpty())
        {
            throw EmptyCollectionException();
        }

        int left = 0, right = lastPointer;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (obj == arr[mid])
            {
                // Shift elements to the left to fill the gap
                for (int j = mid + 1; j <= lastPointer; j++)
                    arr[j - 1] = arr[j];
                
                lastPointer--;
                return;
            }
            else if (obj > arr[mid]) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
        throw ObjectNotFoundException();
    }

    /**
     * @brief Logically clears the collection.
     */
    void makeEmpty()
    {
        lastPointer = -1;
    }

    /**
     * @brief Returns the smallest element in the collection.
     * @return const reference to the first element.
     * @throw EmptyCollectionException if empty.
     */
    const Comparable &findMin() const
    {
        if (isEmpty()) throw EmptyCollectionException();
        return arr[0];
    }

    /**
     * @brief Returns the largest element in the collection.
     * @return const reference to the last element.
     * @throw EmptyCollectionException if empty.
     */
    const Comparable &findMax() const
    {
        if (isEmpty()) throw EmptyCollectionException();
        return arr[lastPointer];
    }

    /**
     * @brief Destructor to release allocated memory.
     */
    ~OrderedCollection()
    {
        delete[] arr;
    }
};

#endif