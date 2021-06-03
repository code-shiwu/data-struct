#include <iostream>
#include <string>

/**
 * @brief 使用单链表实现的栈
 */
struct SNode
{
    std::string m_data = "";
    SNode *m_next = nullptr;
};

class CStackList
{
public:
    CStackList()
    {
        if (nullptr == m_head)
        {
            m_head = new SNode;
            if (nullptr == m_head)
            {
                std::cout << "malloc failed" << std::endl;
                return ;
            }

            m_count = 0;
        }
    }

    ~CStackList()
    {
        SNode *node = nullptr;
        while (nullptr != m_head)
        {
            node = m_head->m_next;

            if (nullptr != m_head)
            {
                delete m_head;
                m_head = nullptr;
            }

            m_head = node;
        }
    }

    bool empty()
    {
        return 0 == m_count;
    }

    int size()
    {
        return m_count;
    }

    bool push(const std::string &str)
    {
        // find tail node
        SNode *tail_node = m_head;
        while (nullptr != tail_node->m_next)
        {
            tail_node = tail_node->m_next;
        }

        // create new node
        SNode *new_node = new SNode;
        if (nullptr == new_node)
        {
            return false;
        }

        new_node->m_data = str;
        new_node->m_next = nullptr;

        tail_node->m_next = new_node;
        ++m_count;

        return true;
    }

    bool pop(std::string &str)
    {
        if (empty())
        {
            std::cout << "stack is empty!" << std::endl;
            return false;
        }

        SNode *first_node = m_head->m_next;
        if (nullptr == first_node)
        {
            return false;
        }

        str = first_node->m_data;
        m_head->m_next = first_node->m_next;
        --m_count;

        return true;
    }

private:
    SNode *m_head = nullptr;  // head node 
    int m_count = 0;          // number of stack
};

int main()
{
    CStackList stack;
    std::cout << "empty stack size:" << stack.size() << std::endl;
    std::cout << "is empty stack" << stack.empty() << std::endl;

    stack.push("hello");
    stack.push("world");
    stack.push("shiwu");
    std::cout << "stack size:" << stack.size() << std::endl;

    std::cout << "-----------------pop----------------------" << std::endl;

    std::string str = "";
    stack.pop(str);
    std::cout << str << std::endl;

    stack.pop(str);
    std::cout << str << std::endl;

    stack.pop(str);
    std::cout << str << std::endl;

    stack.pop(str);

    return 0;
}