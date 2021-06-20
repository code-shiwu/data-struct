
/**
 * @brief 实现计数排序
 * @note  计数排序是桶排序的一种特殊情况
 */

#include <iostream>
#include <vector>
#include <algorithm>

using iter = std::vector<int>::iterator;

void count_sort(std::vector<int> &vec)
{
    
    if (vec.end() - vec.begin() <= 1)
    {
        return;
    }

    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());
    int range = max - min + 1;

    std::vector<int> buckets(range, 0);

    for (auto i = 0; i < vec.size(); ++i)
    {
        buckets[*(vec.begin() + i)]++;
    }

    for (auto i = 1; i <=range; ++i)
    {
        buckets[i] += buckets[i - 1];
    }

    std::vector<int> vec_sort(vec.size());
    // !!!! size()函数返回的无符号类型，若是用auto关键字确定i的类型，会导致以下问题：
    // 1.i不可能小于0，此处陷入死循环
    // 2.i为-1之后转化为无符号数之后会变成一个非常大的数，数组访问会越界崩溃
    for (int i = vec.size() - 1; i >= 0; --i)
    {
        vec_sort[buckets[vec[i]] - 1] = vec[i];
        buckets[vec[i]]--;
    }

    std::copy(vec_sort.begin(), vec_sort.end(), vec.begin());
}


int main()
{
    // std::vector<int> vec{0, 1, 3, 4, 4, 7, 6, 5, 9, 8};
    std::vector<int> vec{1, 3, 4, 2, 5, 8, 6};

    count_sort(vec);

    for (auto value : vec)
    {
        std::cout << value << " ";
    }
}
