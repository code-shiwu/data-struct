#include <iostream>

template<class T>
class CArray
{
private:
    #define MAX_SIZE 1024
public:
    CArray()
    {
        if (nullptr != m_pData)
        {
            delete[] m_pData;
            m_pData = nullptr;
        }

        m_pData = new T[MAX_SIZE];
        if (nullptr == m_pData)
        {
            std::cout << "construct error!" << std::endl;
            return;
        }

        m_nLast = -1;
    }

    ~CArray()
    {
        if (nullptr != m_pData)
        {
            delete[] m_pData;
            m_pData = nullptr;
        }
    }

    CArray(const CArray &resource)
    {
        m_pData = new T[MAX_SIZE];

        if (this != &resource)
        {
            if (nullptr == m_pData)
            {
                std::cout << "fail to new memory!" << std::endl;
                return;
            }

            for (int i = 0; i <= resource.m_nLast; ++i)
            {
                m_pData[i] = resource.m_pData[i];
            }

            m_nLast = resource.m_nLast;
        }
    }

    CArray &operator=(const CArray &right)
    {
        // 赋值之前对象可能有值，要先释放内存
        if (nullptr != m_pData)
        {
            delete[] m_pData;
            m_pData = nullptr;
        }

        if (this != &right)
        {
            m_pData = new T[MAX_SIZE];
            if (nullptr == m_pData)
            {
                std::cout << "fail to new memory!" << std::endl;
                return *this;
            }

            for (int i = 0; i <= right.m_nLast; ++i)
            {
                m_pData[i] = right.m_pData[i];
            }

            m_nLast = right.m_nLast;
        }

        return *this;
    }

    int size()
    {
        return m_nLast + 1;
    }

    T* find(int nIndex)
    {
        if (nIndex > m_nLast)
        {
            std::cout << "error：index out of range!" << std::endl;

            return nullptr;
        }

        return m_pData[nIndex];
    }

    int index(T data)
    {
        for (int i = 0; i <= m_nLast; ++i)
        {
            if (data == m_pData[i])
            {
                return i;
            }
        }

        return -1;
    }

    void insert(int nPos, const T& data)
    {
        if (nPos > size() + 1 || nPos < 0)
        {
            std::cout << "array is full" << std::endl;
            return;
        }

        for (int i = m_nLast; i >= nPos - 1; --i)
        {
            m_pData[i + 1] = m_pData[i];
        }

        m_nLast++;
        m_pData[nPos - 1] = data;
    }

    T del(int nPos)
    {
        if (nPos > m_nLast + 1 || nPos < 1)
        {
            std::cout << "error pos" << std::endl;
            return *m_pData;
        }

        T delData = m_pData[nPos - 1];

        for (int i = nPos; i <= m_nLast; ++i)
        {
            m_pData[i - 1] = m_pData[i];
        }

        m_nLast--;
        return delData;
    }

//private:
public:
    T *m_pData = nullptr;   // 数组指针
    int m_nLast = -1;       // 数字尾部指针
};


int main()
{
    CArray<int> arr_obj;

    arr_obj.insert(1, 2);
    arr_obj.insert(1, 3);
    arr_obj.insert(3, 4);
    arr_obj.insert(4, 5);


    arr_obj.del(3);

    CArray<int> arr_obj_1 = CArray<int>(arr_obj);
    CArray<int> arr_obj_2 = arr_obj;

    return 0;
}