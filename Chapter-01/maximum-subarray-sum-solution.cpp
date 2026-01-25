#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(const vector<int>& arr, int left, int right)
{
    if (left == right)
    {
        if (arr[left] > 0)
            return arr[left];
        else 
            return 0; 
    }

    int center = (left + right) / 2;
    int maxLeftSum = maxSubarraySum(arr, 0, center);
    int maxRightSum = maxSubarraySum(arr, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--)
    {
        leftBorderSum += arr[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int i = center + 1; i <= right; i++)
    {
        rightBorderSum += arr[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max({maxLeftSum, maxRightSum, leftBorderSum + rightBorderSum});
}


int maxSubarraySum(const vector<int>& arr)
{
    return maxSubarraySum(arr, 0, arr.size() - 1);
}

int main(void)
{
    const vector<int> arr = {4, -3, 5, -2, -1, 2, 6, -2};
    cout << maxSubarraySum(arr) << endl;
    return 0;
}