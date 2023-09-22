// CS311 stack.h
// INSTRUCTION:
// Stack class - header file template
// You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
// You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: Clément Muth
// Compiler:  g++
// File type: headher file stack.h
// @brief This file defines a Stack class that is implemented using an _array
//=======================================================

#pragma once
#include <iostream>

using namespace std;

/**
 *A template Stack class
 */
template <typename T>
class Stack
{
private:
    // data _array
    T *_array;
    // Number of elements in use
    int _count;
    // allocation size of the _array, in number of elements
    int _allocation_size;

    /**
     *@brief Resize the data _array to double its allocation size
     *Make sure to release memory allocation correctly.
     */
    void resize_Array();

public:
    // Constructor
    Stack(int capacity = 4);

    // Destructor
    ~Stack();

    // Copy constructor
    Stack(const Stack<T> &stk);

    // Assignment operator
    Stack<T> &operator=(const Stack<T> &stk);

    /**
     *@brief Push a value to the stack.
     *The _array will be resized if it reaches its capcity
     *@param val Value to be pushed onto the stack
     */
    void push(const T &val);

    /**
     *@brief If not empty, removes and gives back the top element;
     *@param val variable to receive the popped element (by ref)
     */
    void pop(T &val);

    /**
     *@brief Returns a reference to the top most element of the stack
     *@return reference to top element of the stack
     */
    T &top();

    /**
     *@brief Check if the stack is empty
     *@return true if stack is empty
     */
    bool isEmpty();

    /**
     *@brief Returns the number of elements in the stack
     *@return int the number of elements in the stack
     */
    int size();

    /**
     *@brief Display the content of the stack
     */
    void displayAll();

    /**
     *@brief Clear the stack to make it empty
     */
    void clearAll();
};

template <typename T>
Stack<T>::Stack(int capacity) : _count{0}
{
    if (capacity <= 0)
        return;

    _allocation_size = capacity;
    _array = new T[_allocation_size];
    _count = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    clearAll();
    delete[] _array;
}

// For a template class, the implementation should be included in the header file.

//@brief Resize the data _array to double its allocation size
template <typename T>
void Stack<T>::resize_Array()
{
    T *new__array = new T[_allocation_size * 2];
    for (int i = 0; i < _count; i++)
    {
        new__array[i] = _array[i];
    }

    _allocation_size *= 2;
    delete[] _array;
    _array = new__array;
}

// @brief Push a value to the stack.
template <typename T>
void Stack<T>::push(const T &val)
{
    if (_count == _allocation_size)
        resize_Array();
    _array[_count] = val;
    _count++;
}

// @brief If not empty, removes and gives back the top element;
template <typename T>
void Stack<T>::pop(T &val)
{
    if (isEmpty())
        return;
    val = _array[_count - 1];
    _count--;
}

// @brief Returns a reference to the top most element of the stack
template <typename T>
T &Stack<T>::top()
{
    if (isEmpty())
        return _array[0];
    return _array[_count - 1];
}

// @brief Check if the stack is empty
template <typename T>
bool Stack<T>::isEmpty()
{
    return _count == 0;
}

// @brief Returns the number of elements in the stack
template <typename T>
int Stack<T>::size()
{
    return _count;
}

// @brief Display the content of the stack
template <typename T>
void Stack<T>::displayAll()
{
    if (_count == 0)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        for (int i = 0; i < _count; i++)
        {
            cout << _array[i] << " ";
        }

        cout << endl;
    }
}

// @brief Clear the stack to make it empty
template <typename T>
void Stack<T>::clearAll()
{
    _count = 0;
    delete[] _array;
    _allocation_size = 4;
    _array = new T[_allocation_size];
}

// @brief Copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T> &stk)
{
    _allocation_size = stk._allocation_size;
    _count = stk._count;
    _array = new T[_allocation_size];
    for (int i = 0; i < _count; i++)
        _array[i] = stk._array[i];
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &stk)
{
    if (this == &stk)
        return *this;
    delete[] _array;
    _allocation_size = stk._allocation_size;
    _count = stk._count;
    _array = new T[_allocation_size];
    for (int i = 0; i < _count; i++)
        _array[i] = stk._array[i];
    return *this;
}
