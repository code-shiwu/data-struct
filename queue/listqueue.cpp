#include <iostream>
#include <string>

/**
 * @brief 利用链表实现队列
 */

struct SNode
{
    std::string m_strData;
    SNode       *m_next;
};

class CListQueue
{
public:
    CListQueue()
    {
        m_head = new SNode;
        if (nullptr == m_head)
        {
            return;
        }

        m_head->m_next = nullptr;
        m_first = m_last = nullptr;
    }

    ~CListQueue()
    {
        SNode *node = nullptr;
        while (nullptr != m_head->m_next)
        {
            node = m_head;
            m_head = m_head->m_next;

            delete node;
            node = nullptr;
        }
    }

    int size()
    {
        SNode *temp = m_first;
        int nb = 0;
        while (nullptr != temp)
        {
            nb++;
            temp = temp->m_next;
        }

        return nb;
    }

    bool empty()
    {
        return 0 == size();
    }

    bool enqueue(const std::string &strElem)
    {
        SNode *node = new SNode;
        if (nullptr == node)
        {
            return false;
        }

        node->m_strData = strElem;
        node->m_next = nullptr;

        if (0 == size())
        {
            m_first = m_last = node;
            m_head->m_next = node;

            return true;
        }

        m_last->m_next = node;
        m_last = m_last->m_next;

        return true;
    }

    bool dequeue(std::string &strElem)
    {
        if (empty())
        {
            return false;
        }

        strElem = m_first->m_strData;

        SNode *temp = m_first;

        m_first = m_first->m_next;
        m_head->m_next = m_first;

        if (nullptr != temp)
        {
            delete temp;
            temp = nullptr;
        }
    }

    void print()
    {
        SNode *temp = m_first;
        int nb = 0;
        while (nullptr != temp)
        {
            std::cout << "队列内容：" << temp->m_strData << std::endl;
            temp = temp->m_next;
        }
    }

private:
    SNode *m_head;     // 头节点
    SNode *m_first;    // 第一个节点
    SNode *m_last;     // 最后一个节点
};

int main()
{
    CListQueue queue;
    std::cout << "空队列的大小：" << queue.size() << std::endl;

    queue.enqueue("hello");
    queue.enqueue("world");
    std::cout << "队列的大小：" << queue.size() << std::endl;
    queue.print();

    std::string str;
    queue.dequeue(str);
    std::cout << "出队元素：" << str << std::endl;
    queue.dequeue(str);
    std::cout << "出队元素：" << str << std::endl;
    std::cout << "队列的大小：" << queue.size() << std::endl;
    queue.print();

    queue.enqueue("hello");
    queue.print();

    return true;
}

