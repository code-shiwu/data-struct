#include <iostream>
#include <string>

const int STATCK_DEFAULT_COUNT = 10;

/**
 * @brief 使用动态数组实现的栈
 */
class CStackArray
{
public:
    CStackArray(const int &nCount = STATCK_DEFAULT_COUNT)
    {
        if (nullptr == m_data)
        {
            m_data = new std::string[nCount];
            if (nullptr == m_data)
            {
                std::cout << "malloc data failed!" << std::endl;
                return;
            }

            m_count = nCount;
            m_index = 0;
        }
    }

    ~CStackArray()
    {
        if (nullptr != m_data)
        {
            delete[] m_data;
            m_data = nullptr;
        }
    }

    bool empty()
    {
        return 0 == m_index;
    }

    bool full()
    {
        return m_count == m_index;
    }

    int size()
    {
        return m_index;
    }

    bool push(const std::string &str)
    {
        if (full())
        {
            // 需要扩容
            std::string *temp = new std::string[2 * m_count];
            if (nullptr == temp)
            {
                std::cout << "fail to malloc!" << std::endl;
                return false;
            }

            for (int i = 0; i < size(); ++i)
            {
                temp[i] = m_data[i];
            }

            if (nullptr != m_data)
            {
                delete[] m_data;
                m_data = nullptr;
            }

            m_data = temp;
        }

        // 简单入栈
        m_data[m_index++] = str;

        return true;
    }

    bool pop(std::string &str)
    {
        if (empty())
        {
            std::cout << "stack is empty!" << std::endl;
            return false;
        }

        str = m_data[--m_index];
        return true;
    }

    std::string getdata(const int &index)
    {
        if (0 > index || index > m_index)
        {
            return "";
        }
        return m_data[index];
    }

private:
    std::string *m_data = nullptr;  // 数据内容
    int m_count = 0;                // 栈的容量
    int m_index = 0;                // 入栈指针
};

int main()
{
    CStackArray stack(2);
    std::cout << "empty stack size:" << stack.size() << std::endl;
    std::cout << "is empty stack" << stack.empty() << std::endl;

    stack.push("hello");
    stack.push("world");
    std::cout << "empty stack size:" << stack.size() << std::endl;
    for (int i = 0; i < stack.size(); ++i)
    {
        std::cout << "index:" << i << '\t' << stack.getdata(i) << std::endl;
    }

    stack.push("shiwu");
    for (int i = 0; i < stack.size(); ++i)
    {
        std::cout << "index:" << i << '\t' << stack.getdata(i) << std::endl;
    }

    std::cout << "-----------------pop----------------------" << std::endl;

    std::string str = "";
    stack.pop(str);
    std::cout << str << std::endl;

    stack.pop(str);
    std::cout << str << std::endl;

    stack.pop(str);
    std::cout << str << std::endl;

    return 0;
}