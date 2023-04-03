#include "vec.h"

ostream &operator<<(ostream &cout, myVector &rhs)
{

    // for (int i = 0; i < rhs.capacity; i++)
    // {
    //     cout << rhs.ptr[i] << " ";
    // }

    for (int i = 0; i < rhs.number; i++)
    {
        cout << rhs.ptr[i] << " ";
    }

    cout << " || ";

    for (int i = rhs.number; i < rhs.capacity; i++)
    {
        cout << rhs.ptr[i] << " ";
    }

    cout << endl;

    return cout;
}

// Constructor
myVector::myVector()
    : number{0}, capacity{5}, ptr{new int[capacity]}
{
}

myVector::myVector(const initializer_list<int> &list)
    : number{0}, capacity{(int)list.size()+5}, ptr{new int[capacity]}
{
    for (int i : list)
    {
        push_back(i);
    }
}

// Copy Constructor
myVector::myVector(const myVector &rhs)
    : number{rhs.number}, capacity{rhs.capacity + 5}, ptr{new int[capacity]}
{
    for (int i = 0; i < rhs.number; ++i)
    {
        ptr[i] = rhs.ptr[i];
    }
}

// Move Constructor
myVector::myVector(myVector &&rhs)
    : ptr{rhs.ptr}
{
    rhs.ptr = nullptr;
}

// Destructor
myVector::~myVector()
{
    delete[] ptr;
}

// Copy Assignment Constructor
myVector &myVector::operator=(const myVector &rhs)
{
    if (rhs.number > number)
    {
        delete[] ptr;
        capacity = rhs.number + 5;
        ptr = new int[capacity];
    }
    for (int i = 0; i < rhs.number; i++)
    {
        ptr[i] = rhs.ptr[i];
    }
    number = rhs.number;

    return *this;
}

// function to add element at the last
void myVector::push_back(int data)
{
    if (number < capacity)
    {
        ptr[number] = data;
        number++;
    }
    else
    {
        capacity *= 2;
        int *new_ptr = new int[capacity];
        for (int i = 0; i < number; i++)
        {
            new_ptr[i] = ptr[i];
        }
        new_ptr[number] = data;
        number++;
        delete[] ptr;
        ptr = new_ptr;
    }
}

// function to delete last element
void myVector::pop_back()
{
    if (number == 0)
    {
        cout << "Empty vector!";
    }
    number--;
}

// function to check vector empty
bool myVector::empty()
{
    return number == 0;
}

// function to get size of the vector
int myVector::size()
{
    return number;
}

// function to get capacity of the vector
int myVector::capa()
{
    return capacity;
}

// function to get the first element
int myVector::front()
{
    return ptr[0];
}

// function to get the last element
int myVector::back()
{
    return ptr[number - 1];
}

// function to access element at any index
int myVector::operator[](int index)
{
    if ((index < 0) || (index >= number))
    {
        cout << "Index out of range!";
    }

    return ptr[index];
}

// function to add element at any index
void myVector::insert(int data, int index)
{
    if ((index < 0) || (index >= number))
    {
        cout << "Insert - Index out of range!";
    }

    if (number != capacity)
    {
        for (int i = number - 1; i >= index; --i)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        number++;
    }
    else
    {
        capacity *= 2;
        int *new_ptr = new int[capacity];
        for (int i = 0; i < number; i++)
        {
            new_ptr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = new_ptr;
        insert(index, data);
    }
}

// function to erase element at any index
void myVector::erase(int index)
{
    if ((index < 0) || (index >= number))
    {
        cout << "Erase - Index out of range!";
    }

    for (int i = index; i < number - 1; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    number--;
}

// function to clear vector
void myVector::clear()
{
    number = 0;
}
