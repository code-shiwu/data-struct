#include <iostream>
#include <vector>
#include <algorithm>

using iter = std::vector<int>::iterator;
const int BUCKET_SIZE = 3;    // 桶可分配的元素的范围差值

/**
 * @brief 实现桶排序
 */

void bucket_sort(iter begin, iter end)
{
    int min = *std::min_element(begin, end);  // 获取最小值
    int max = *std::max_element(begin, end);  // 获取最大值
    int range = max + 1 - min;                // 获取最大值与最小值差值范围

    int bucket_num = range / BUCKET_SIZE + 1;  // 准备桶的数量

    std::vector<std::vector<int> > buckets(bucket_num);

    for (auto value : buckets)
    {
        value.reserve(2 * BUCKET_SIZE);
    }

    iter b = begin;
    while (b != end)
    {
        buckets[*b / BUCKET_SIZE].emplace_back(*b);   // 将元素放入对应的桶中
        ++b;
    }

    iter dest = begin;
    for (auto value : buckets)
    {
        std::sort(value.begin(), value.end());        // 排序，默认升序
        std::copy(value.begin(), value.end(), dest);  // 拷贝
        dest += value.size();                         // 迭代器向后偏移
    }
}

int main()
{
    std::vector<int> vec{1, 3, 4, 7, 6, 5, 9, 8};

    bucket_sort(vec.begin(), vec.end());

    for (auto value : vec)
    {
        std::cout << value << " ";
    }
}