#include <iostream>


void quick_sort(int *arr, const int begin, const int end);
int parition(int *arr, const int begin, const int end);

void quick_sort(int *arr, const int count)
{
    if (1 >= count)
    {
        return;
    }

    quick_sort(arr, 0, count - 1);
}

void quick_sort(int *arr, const int begin, const int end)
{
    if (begin >= end)
    {
        return;
    }

    int q = parition(arr, begin, end);
    quick_sort(arr, begin, q - 1);
    quick_sort(arr, q + 1, end);
}
 
int parition(int *arr, const int begin, const int end)
{
    int deal_pos = begin;       // 已处理区域的待插入位置
    int undeal_pos = deal_pos;  // 未处理区域的位置
    int pivot = arr[end];       // 选择的分割点数值
    int tmp = 0;

    for (; undeal_pos < end; ++undeal_pos)
    {
        if (arr[undeal_pos] < pivot)
        {
            tmp = arr[undeal_pos];
            arr[undeal_pos] = arr[deal_pos];
            arr[deal_pos] = tmp;

            deal_pos += 1;
        }
    }

    tmp = arr[end];
    arr[end] = arr[deal_pos];
    arr[deal_pos] = tmp;

    return deal_pos;
}

int main()
{
    int arr[] = {4, 5, 6, 1, 2, 3};

    quick_sort(arr, sizeof(arr) / sizeof(int));

    for (auto value : arr)
    {
        std::cout << value << " ";
    }
}