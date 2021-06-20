/**
 * @brief 本程序实现归并排序算法
 */

#include <iostream>

void sort(int *arr, int *tmp, const int &start, const int &end);
void merge(int *arr, int *tmp, const int &start, const int &mid, const int &end);

void merge_sort(int *arr, const int &ncount)
{
    // 避免递归内部频繁申请内存，提前申请好临时数组
    int *temp = new int[ncount];
    if (nullptr == temp)
    {
        return;
    }

    sort(arr, temp, 0, ncount - 1);

    if (nullptr != temp)
    {
        delete[] temp;
        temp = nullptr;
    }
}

void sort(int *arr, int *tmp, const int &start, const int &end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        sort(arr, tmp, start, middle);
        sort(arr, tmp, middle + 1, end);
        merge(arr, tmp, start, middle, end);
    }
}

void merge(int *arr, int *tmp, const int &start, const int &mid, const int &end)
{
    int left_start = start;
    int left_end   = mid;
    int right_start = mid + 1;
    int right_end   = end;

    int i = start;
    int j = right_start;
    int t = 0;
    // 对数据进行排序
    while (i <= left_end && j <= right_end)
    {
        if (arr[i] <= arr[j])
        {
            tmp[t++] = arr[i++];
        }
        else
        {
            tmp[t++] = arr[j++];
        }
    }

    while (i <= left_end)
    {
        tmp[t++] = arr[i++];
    }

    while (j <= right_end)
    {
        tmp[t++] = arr[j++];
    }

    t = 0;
    // 将合并排序好数据拷贝到原始数据中
    while(left_start <= right_end)
    {
        arr[left_start++] = tmp[t++];
    }
}

int main()
{
    int arr[] = {4, 5, 6, 1, 2, 3};

    merge_sort(arr, sizeof(arr) / sizeof(int));

    for (auto value : arr)
    {
        std::cout << value << " ";
    }
}