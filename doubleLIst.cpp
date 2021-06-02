/**
 * @brief 实现了双向链表的基本操作
 */

#include <iostream>


typedef int data_type;

struct SNode
{   
    SNode *m_prev = nullptr;
    data_type m_data = 0;
    SNode *m_next = nullptr;
};

class CDoubleList
{
public:
    CDoubleList()
    {
        if (nullptr == m_head)
        {
            m_head = new SNode();
            if (nullptr == m_head)
            {
                std::cout << "fail to create head node"  << std::endl;
            }
        }
    }
    ~CDoubleList()
    {
        SNode *temp = nullptr;
        while (nullptr !=  m_head)
        {
            temp = m_head->m_next;

            if (nullptr != m_head)
            {
                delete m_head;
                m_head = nullptr;
            }

            m_head = temp;
        }
    }

    bool empty()
    {
        return nullptr == m_head->m_next;
    }

    int size()
    {
        int size = 0;

        SNode *temp = m_head->m_next;
        while (nullptr != temp)
        {
            ++size;

            temp = temp->m_next;
        }

        return size;
    }

    SNode *findbyindex(const int index)
    {
        int size = 0;

        SNode *temp = m_head->m_next;
        while (nullptr != temp)
        {
            ++size;

            if (size == index)
            {
                return temp;
            }

            temp = temp->m_next;
        }

        return nullptr;
    }

    SNode *findbydata(const data_type data)
    {
        int size = 0;

        SNode *temp = m_head->m_next;
        while (nullptr != temp)
        {
            ++size;

            if (temp->m_data == data)
            {
                return temp;
            }

            temp = temp->m_next;
        }

        return nullptr;
    }

    void insert(const data_type &data)
    {
        // 可能是头节点
        SNode *lastnode = size() ? findbyindex(size()) : m_head;
        if (nullptr == lastnode)
        {
            return ;
        }

        SNode *node = new SNode();
        if (nullptr == node)
        {
            std::cout << "fail to create node" << std::endl;
            return;
        }

        node->m_data = data;
        node->m_next = nullptr;
        node->m_prev = lastnode;

        lastnode->m_next = node;
    }

    void remove(const int &pos)
    {
        SNode *node = findbyindex(pos);
        if (nullptr == node)
        {
            return;
        }

        SNode *prev = node->m_prev;
        if (nullptr == prev)
        {
            return;
        }

        // 可能是尾节点，不能简单判空退出
        SNode *next = node->m_next;

        prev->m_next = next;

        if (nullptr != next)
        {
            next->m_prev = prev;
        }

        if (nullptr != node)
        {
            delete node;
            node = nullptr;
        }
    }

private:
    SNode *m_head = nullptr;   // 头节点
};

int main()
{
    CDoubleList list;
    std::cout << "empty list size:" << list.size() << std::endl;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    std::cout << "list size:" << list.size() << std::endl;

    list.remove(3);
    list.remove(2);
    std::cout << "list size:" << list.size() << std::endl;

    list.remove(1);
    list.remove(0);
    std::cout << "list size:" << list.size() << std::endl;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    std::cout << "first node:" << list.findbyindex(1)->m_data << std::endl;
    std::cout << "sedond node:" << list.findbyindex(2)->m_data << std::endl;
    std::cout << "third node:" << list.findbyindex(3)->m_data << std::endl;

    list.remove(2);
    std::cout << "first node:" << list.findbyindex(1)->m_data << std::endl;
    std::cout << "sedond node:" << list.findbyindex(2)->m_data << std::endl;

    list.insert(2);
    std::cout << "first node:" << list.findbyindex(1)->m_data << std::endl;
    std::cout << "sedond node:" << list.findbyindex(2)->m_data << std::endl;
    std::cout << "third node:" << list.findbyindex(3)->m_data << std::endl;

    return 0;
}