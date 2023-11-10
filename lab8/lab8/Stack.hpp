#pragma once

#include <vector>
#include <iostream>

namespace st {

    template<typename T>
    class Stack
    {
    private:
        size_t m_size = 0;
        T* m_stack = new T[m_size];
        int m_top = 0;
        bool m_isEmpty = 1;

    public:
        Stack(size_t size)
        {
            m_size = size;
            delete[] m_stack;
            m_stack = new T[size];
            std::cout << "construction" << std::endl;
        }

        size_t size()
        {
            return m_size;
        }

        bool empty()
        {
            return m_isEmpty;
        }

        void push(const T& el)
        {
            if (m_top >= m_size)
            {
                throw std::out_of_range("Full stack");
            }
            else
            {
                m_stack[m_top] = el;
                m_top++;
                m_isEmpty = 0;
            }
        }

        void pop()
        {
            if (m_isEmpty)
            {
                throw std::out_of_range("Empty stack");
            }
            else
            {
                m_top--;
                if (m_top == 0)
                {
                    m_isEmpty = 1;
                }
            }
        }

        T top()
        {
            if (m_isEmpty == 0)
            {
                return m_stack[m_top - 1];
            }
            else
            {
                throw std::logic_error("Top does not exist");
            }
        }

        ~Stack()
        {
            delete[] m_stack;
            std::cout << "destruction" << std::endl;
        }
    };


}

