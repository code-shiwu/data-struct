/**
 * @brief 实现了单向链表的基本操作
 */

#include <iostream>

typedef struct SNode
{
    int m_nData;    // 数据内容
    SNode *m_pNext; // 下一个节点
}*List;


List CreateList(const int &nData)
{
    List list = new SNode;
    if (nullptr == list)
    {
        return nullptr;
    }

    list->m_nData = nData;
    list->m_pNext = nullptr;

    return list;
}

int Length(List list)
{
    if (nullptr == list)
    {
        return 0;
    }

    int nLength = 0;
    List temp = list;
    while(nullptr != temp)
    {
        nLength++;
        temp = temp->m_pNext;
    }

    return nLength;
}

List FindByIndex(const int &nIndex, List list)
{
    int i = 1;
    List temp = list;
    while(nullptr != temp && i < nIndex)
    {
        ++i;
        temp = temp->m_pNext;
    }

    if (i == nIndex)
    {
        return temp;
    }

    return nullptr;
}

List FindByData(const int &nData, List list)
{
    List temp = list;
    while(nullptr != temp)
    {
        if (temp->m_nData == nData)
        {
            return temp;
        }

        temp = temp->m_pNext;
    }

    return nullptr;
}

List Insert(const int &nData, const int &nPos, List list)
{
    if (1 == nPos)
    {
        List node = new SNode;
        if (nullptr == node)
        {
            std::cout << "malloc memory failed" << std::endl;
            return list;
        }

        node->m_nData = nData;
        node->m_pNext = list;

        return node;
    }

    List temp = FindByIndex(nPos - 1, list);
    if (nullptr == temp)
    {
        return list;
    }

    List node = new SNode;
    if (nullptr == node)
    {
        std::cout << "malloc memory failed" << std::endl;
        return list;
    }

    node->m_nData = nData;
    node->m_pNext = temp->m_pNext;
    temp->m_pNext = node;

    return list;
}

List Remove(const int &nPos, List list)
{
    if (1 == nPos)
    {
        if (nullptr == list)
        {
            return list;
        }
        else
        {
            List node = list;
            list = list->m_pNext;

            if (nullptr != node)
            {
                delete node;
                node = nullptr;
            }
        }
        
        return list;
    }

    List temp = FindByIndex(nPos - 1, list);
    if (nullptr == temp)
    {
        return list;
    }

    List node = temp->m_pNext;
    if (nullptr == node)
    {
        return list;
    }

    temp->m_pNext = node->m_pNext;
    if (nullptr != node)
    {
        delete node;
        node = nullptr;
    }

    return list;
}

int main()
{
    List list = CreateList(1);

    list = Insert(2, 2, list);
    list = Insert(3, 3, list);
    list = Insert(4, 4, list);
    list = Insert(0, 1, list);

    // 0 1 2 3 4 

    list = Remove(1, list);
    list = Remove(4, list);

    // 1 2 3

    List temp = list;
    for (int i = 0; i < Length(list); ++i)
    {
        std::cout << temp->m_nData << std::endl;

        temp = temp->m_pNext;
    }

    return 0;
}