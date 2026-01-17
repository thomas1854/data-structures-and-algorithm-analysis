#include <iostream>
#include <vector>
using namespace std;

/**
 * @class Rectangle
 * @brief Represents a rectangle with length and width dimensions.
 */
class Rectangle
{
private:
    double length; ///< Length of the rectangle
    double width;  ///< Width of the rectangle
    
public:
    /**
     * @brief Constructs a Rectangle with specified dimensions.
     * @param _length The length of the rectangle
     * @param _width The width of the rectangle
     */
    Rectangle(double _length, double _width)
    {
        length = _length;
        width = _width;
    }

    /**
     * @brief Gets the width of the rectangle.
     * @return The width value
     */
    double getWidth() const 
    {
        return width;
    }

    /**
     * @brief Gets the length of the rectangle.
     * @return The length value
     */
    double getLength() const
    {
        return length;
    }
};

/**
 * @brief Finds the maximum element in a vector using a custom comparator.
 * @tparam Object The type of objects in the vector
 * @tparam Comparator The comparator function object type
 * @param objects Vector of objects to search
 * @param isGreater Comparator that returns true if first argument is greater
 * @return Reference to the maximum object
 */
template<typename Object, typename Comparator>
const Object& findMax(const vector<Object>& objects, Comparator isGreater)
{
    int maxIndex = 0;
    for (int i = 1; i < objects.size(); i++)
    {
        if (isGreater(objects[i], objects[maxIndex]))
            maxIndex = i;
    }

    return objects[maxIndex];
}

/**
 * @class AreaComparator
 * @brief Compares rectangles based on area.
 */
class AreaComparator
{
public:
    /**
     * @brief Compares two rectangles by area.
     * @param rectangle1 First rectangle
     * @param rectangle2 Second rectangle
     * @return true if rectangle1 has greater area than rectangle2
     */
    bool operator()(const Rectangle& rectangle1, const Rectangle& rectangle2) const
    {
        return rectangle1.getLength() * rectangle1.getWidth() > rectangle2.getLength() * rectangle2.getWidth();
    }
};

/**
 * @class PerimeterComparator
 * @brief Compares rectangles based on perimeter.
 */
class PerimeterComparator
{
public:
    /**
     * @brief Compares two rectangles by perimeter.
     * @param rectangle1 First rectangle
     * @param rectangle2 Second rectangle
     * @return true if rectangle1 has greater perimeter than rectangle2
     */
    bool operator()(const Rectangle& rectangle1, const Rectangle& rectangle2) const 
    {
        return 2 * (rectangle1.getLength() + rectangle1.getWidth()) > 2 * (rectangle2.getLength() + rectangle2.getWidth());
    }
};

/**
 * @brief Main function demonstrating rectangle comparison.
 * @return Exit status
 */
int main(void)
{
    vector<Rectangle> rectangles = {{10, 20}, {30, 40}, {50, 50}, {2, 2}, {100, 2}};
    const Rectangle& maxArea = findMax(rectangles, AreaComparator{});
    cout << maxArea.getLength() << ' ' << maxArea.getWidth() << endl;
    const Rectangle& maxPerimeter = findMax(rectangles, PerimeterComparator{});
    cout << maxPerimeter.getLength() << ' ' << maxPerimeter.getWidth() << endl;
    return 0;
}