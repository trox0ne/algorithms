#ifndef SEARCHER_H
#define SEARCHER_H

#include <vector>


class Searcher
{
public:
    Searcher();

    /*!
     * @brief Алгоритм линейного поиска
     * @param array массив для поиска
     * @param array_size размер массива
     * @param desired_number искомое число
     * @return индекс элемента в массиве (-1 если элемента нет)
     */
    int linear_search(int array[], int array_size, int desired_number);

    int binary_search(int array[], int array_size, int desired_number);
    template <typename T> int binary_search(const std::vector<T> &sorted_array, const T &desired_value);
    int binary_search(const std::vector<int> &sorted_array, const int &desired_number);
    template <typename ForwardIt, typename T, typename Compare>

    constexpr ForwardIt fast_binary_search(ForwardIt first, ForwardIt last, const T &value, Compare comp);

};

#endif // SEARCHER_H
