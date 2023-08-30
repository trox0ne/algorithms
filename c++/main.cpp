#include <iostream>
#include "searcher.h"


using namespace std;

int binary_search(int array[], int size, int desired_number)
{
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int number = array[mid];

        std::cout << left << " " << right << " " << mid << " " << number << '\n';

        if (number == desired_number)
            return mid;

        if (number < desired_number)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    Searcher s;
    const int size = 10;
    int array[size] = {55, 21, 45, 1, 31, 10, 666, 13, 24, 5};
    int sorted_array[size] = {1, 5, 10, 13, 21, 24, 31, 45, 55, 666};
    int result = s.linear_search(sorted_array, size, 666);
    std::cout << "Linear search: the index of number is " << result << std::endl;

    result = binary_search(sorted_array, size, 24);
    std::cout << "Binary search: the index of number is " << result << std::endl;

    /*std::vector<int> test = {5, 10, 31, 66, 88, 111, 666, 777};
    std::vector<double> test1 = {5.1, 10.1, 31.1, 66.6, 88.8, 111, 666, 777};

    result = s.binary_search(test, 4);
    std::cout << "Binary seacrh: the index of number is " << result << std::endl;

    result = binary_search(test1, 66.6);
    std::cout << "Binary seacrh: the index of number is " << result << std::endl;

    auto compareFunc = [](int a, int b){ return a < b;};
    auto res = fast_binary_search(test.begin(), test.end(), 0, compareFunc);

    result = std::distance(test.begin(), res);
    std::cout << "Fast binary seacrh: the index of number is " << result << std::endl;*/


    return 0;
}
