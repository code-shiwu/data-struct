/**
 * @brief 本程序实现选择排序算法
 */

#include <iostream>

void selcet_sort(int *arr, const int &count)
{
    if (1 >= count)
    {
        std::cout << "数组中元素无需排序" << std::endl;
        return;
    }

    for (int i = 0; i < count - 1; ++i)
    {
        int minpos = i;
        for (int j = i; j < count; ++j)
        {
            if (arr[j] < arr[minpos])
            {
                minpos = j;
            }
        }

        int ntemp = arr[minpos];
        arr[minpos] = arr[i];
        arr[i] = ntemp;
    }
}

int main()
{
    int arr[] = {4, 5, 6, 1, 2, 3};

    selcet_sort(arr, sizeof(arr) / sizeof(int));

    for (auto value : arr)
    {
        std::cout << value << " ";
    }
}