#include <iostream>
#include <string>

/**
 * @brief 基于数组实现队列
 */

class CArrayQueue
{
public:
    CArrayQueue(const int &ncount = 10) : m_ncount(ncount)
    {
        if (nullptr != m_strData)
        {
            delete m_strData;
            m_strData = nullptr;
        }

        m_strData = new std::string[ncount];
        if (nullptr == m_strData)
        {
            return;
        }
    }

    ~CArrayQueue()
    {
        if (nullptr != m_strData)
        {
            delete[] m_strData;
            m_strData = nullptr;
        }
    }

    int size()
    {
        return m_ntail - m_nhead;
    }

    bool empty()
    {
        return m_nhead == m_ntail;
    }

    bool full()
    {
        return size() == m_ncount;
    }

    bool enqueue(const std::string &strElem)
    {
        if (full())
        {
            return false;
        }

        if (m_ntail == m_ncount)
        {
            int ntemp  = 0;
            // 执行一次数据搬移操作
            for (int i = m_nhead; i < m_ntail; ++i)
            {
                m_strData[ntemp++] = m_strData[i];
            }
            
            m_ntail = m_ntail - m_nhead;
            m_nhead = 0;
        }

        m_strData[m_ntail++] = strElem;

        return true;
    }

    bool dequeue(std::string &strElem)
    {
        if (empty())
        {
            return false;
        }

        strElem = m_strData[m_nhead++];

        return true;
    }

    void print()
    {
        for(int i = m_nhead; i < m_ntail; ++i)
        {
            std::cout << "队列元素_" << i << "内容：" << m_strData[i] << std::endl;
        }
    }

private:
    std::string *m_strData = nullptr; // 队列内容
    int m_ncount = 0;        // 队列容量
    int m_nhead  = 0;        // 队首指针
    int m_ntail  = 0;        // 队尾指针
};

int main()
{
    CArrayQueue queue;
    std::cout << "空队列size" << queue.size() << std::endl;

    queue.enqueue("hello");
    queue.enqueue("world");
    queue.enqueue("huoyin");
    queue.enqueue("wanmei");
    std::cout << "队列size" << queue.size() << std::endl;
    queue.print();

    std::string str = "";
    queue.dequeue(str);
    std::cout << "队列size" << queue.size() << std::endl;
    std::cout << "出队元素：" << str << std::endl;
    queue.print();

    queue.enqueue("hello");
    queue.print();
    queue.enqueue("world");
    queue.print();
    queue.enqueue("huoyin");
    queue.print();
    queue.enqueue("wanmei");
    queue.print();
    queue.enqueue("hello_1");
    queue.print();
    queue.enqueue("world_2");
    queue.print();
    queue.enqueue("huoyin_3");
    queue.print();

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    queue.dequeue(str);
    std::cout << "出队元素：" << str << std::endl;
    queue.dequeue(str);
    std::cout << "出队元素：" << str << std::endl;
    queue.dequeue(str);
    std::cout << "出队元素：" << str << std::endl;

    queue.enqueue("banyi");
    queue.print();

    return 0;
}