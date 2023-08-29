#include <iostream>
#include <vector>

using namespace std;

int linear_search(int array[], int array_size, int number)
{
    for (size_t i=0; i < array_size; ++i)
        if (array[i] == number)
            return i;

    return -1;
}

template <typename ForwardIt, typename T, typename Compare>
constexpr ForwardIt fast_binary_search(ForwardIt first, ForwardIt last, const T &value, Compare comp) {
    auto lenght = last - first;
    while (lenght > 0) {
        auto rem = lenght % 2;
        lenght /= 2;
        if (comp(first[lenght], value)) {
            first += lenght + rem;
        }
    }

    return first;
}

template <typename T>
int binary_search(const std::vector<T> &sorted_array, const T &desired_value)
{
    int32_t left_index = 0;
    int32_t right_index = sorted_array.size() - 1;
    while (left_index <= right_index) {
        size_t middle_index = (left_index + right_index) / 2;
        T value = sorted_array[middle_index];

        if (desired_value == value)
            return middle_index;

        if (desired_value < value)
            right_index = middle_index - 1;
        else
            left_index = middle_index + 1;
    }

    return -1;
}

/*int binary_search(int array[], int array_size, int number)
{
    return -1;
}
*/

int binary_search(const std::vector<int> &sorted_array, const int &desired_number)
{
    int_fast32_t left_index = 0;
    int_fast32_t right_index = sorted_array.size() - 1;

    while (left_index <= right_index) {
        int middle_index = (left_index + right_index) / 2;
        int number = sorted_array[middle_index];

        std::cout << "left_index = " << left_index << " right_index = " << right_index << " middle_index = " << middle_index << " number = " << number << std::endl;

        if (number == desired_number)
            return middle_index;

        if (number > desired_number)
            right_index = middle_index - 1;
        else
            left_index = middle_index + 1;
    }

    return -1;
}

int main()
{
    const int size = 10;
    int array[size] = {55, 21, 45, 1, 31, 10, 666, 13, 24, 5};
    int result = linear_search(array, size, 666);
    std::cout << "Linear search: the index of number is " << result << std::endl;
    std::vector<int> test = {5, 10, 31, 66, 88, 111, 666, 777};

    std::vector<double> test1 = {5.1, 10.1, 31.1, 66.6, 88.8, 111, 666, 777};

    result = binary_search(test, 4);
    std::cout << "Binary seacrh: the index of number is " << result << std::endl;

    /*result = binary_search(test1, 66.6);
    std::cout << "Binary seacrh: the index of number is " << result << std::endl;

    auto compareFunc = [](int a, int b){ return a < b;};
    auto res = fast_binary_search(test.begin(), test.end(), 0, compareFunc);

    result = std::distance(test.begin(), res);
    std::cout << "Fast binary seacrh: the index of number is " << result << std::endl;*/


    return 0;
}
