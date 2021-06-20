#include <iostream>

void bubble_sort(int *arr, const int &count)
{
    if (1 >= count)
    {
        std::cout << "数组中元素无需排序" << std::endl;
        return;
    }

    // 升序
    int ntemp = 0;
    for (int i = 0; i < count; ++i)
    {
        for (int j = 0; j < count - i- 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                ntemp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = ntemp;
            }
        }
    }
}

// 改进了冒泡排序算法
// 当某一次没有进行交换时，说明数据已经是有序的了，此时直接返回即可
void bubble_sort_pro(int *arr, const int &count)
{
    if (1 >= count)
    {
        std::cout << "数组中元素无需排序" << std::endl;
        return;
    }

    // 升序
    int ntemp = 0;
    bool bSwap = true;
    for (int i = 0; i < count; ++i)
    {
        bSwap = false;
        for (int j = 0; j < count - i- 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                ntemp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = ntemp;

                bSwap = true;
            }
        }

        if (!bSwap)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {6, 3, 4, 2, 5, 1};

    bubble_sort(arr, sizeof(arr) / sizeof(int));
    // bubble_sort_pro(arr, sizeof(arr) / sizeof(int));

    for (auto value : arr)
    {
        std::cout << value << " " << std::endl;
    }
}