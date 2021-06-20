/**
 * @brief 本程序实现插入排序算法
 */

#include <iostream>

void insert_sort(int *arr, const int &count)
{
    if (1 >= count)
    {
        std::cout << "数组中元素无需排序" << std::endl;
        return;
    }

    // 升序
    // 自己写的第一版，缺点：必须比较完全部有序部分才行
    /*
    int ntemp = 0;
    for (int i = 1; i < count; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] >= arr[j])
            {
                continue;
            }
            else
            {
                // 插入，搬运
                ntemp = arr[i];
                arr[i] = arr[j];
                arr[j] = ntemp;
            }
        }
    }
    */

    // 借鉴他人的：无需比较全部有序内容 
    for (int i = 1; i < count; ++i)
    {
        int value = arr[i];
        int j = i - 1;
        for (; j >= 0; --j)
        {
            if (arr[j] > value)
            {
                // 数据搬移
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = value;
    }
}

int main()
{
    int arr[] = {4, 5, 6, 1, 2, 3};

    insert_sort(arr, sizeof(arr) / sizeof(int));

    for (auto value : arr)
    {
        std::cout << value << " ";
    }
}