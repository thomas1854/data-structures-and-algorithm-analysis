#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


void selectionSort(vector<int>& numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        int max_element = numbers[i], max_position = i;
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[j] > max_element)
            {
                max_element = numbers[j];
                max_position = j;
            }
            swap(numbers[max_position], numbers[i]);
        }
    }
}

int main(void)
{
    int n = 5000;
    vector<int> numbers(n);
    for (int i = 1; i <= n; i++) numbers[i - 1] = i;
    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(numbers);
    cout << "The kth (N/2) largest element is: " << numbers[n / 2 - 1] << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}

/*
-----------------------------
|    N    |Running time (ms)|
-----------------------------
|1000     |13               |
|2000     |31               |
|5000     |221              |
|10000    |785              |
|30000    |7261             |
|40000    |12420            |
|50000    |20321            |
|1000000  |80867            |
-----------------------------
*/