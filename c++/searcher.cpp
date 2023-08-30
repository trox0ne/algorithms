#include "searcher.h"

#include <cstdint>

Searcher::Searcher()
{
}

int Searcher::linear_search(int array[], int array_size, int desired_number)
{
    for (size_t i=0; i < array_size; ++i)
        if (array[i] == desired_number)
            return i;

    return -1;
}

int Searcher::binary_search(int array[], int size, int desired_number)
{
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int number = array[mid];

        if (number == desired_number)
            return mid;

        if (number < desired_number)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int Searcher::binary_search(const std::vector<int> &sorted_array, const int &desired_number)
{
    int32_t left_index = 0;
    int32_t right_index = sorted_array.size() - 1;

    while (left_index <= right_index) {
        int middle_index = (left_index + right_index) / 2;
        int number = sorted_array[middle_index];

        if (number == desired_number)
            return middle_index;

        if (number > desired_number)
            right_index = middle_index - 1;
        else
            left_index = middle_index + 1;
    }

    return -1;
}

template <typename T>
int Searcher::binary_search(const std::vector<T> &sorted_array, const T &desired_value)
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

template <typename ForwardIt, typename T, typename Compare>
constexpr ForwardIt Searcher::fast_binary_search(ForwardIt first, ForwardIt last, const T &value, Compare comp) {
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
