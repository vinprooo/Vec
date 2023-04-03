#ifndef _VEC_
#define _VEC_

#include <iostream>

using namespace std;

class myVector
{
private:
    int number;
    int capacity;
    int *ptr;

public:
    friend ostream &operator<<(ostream &cout, myVector &rhs);

    // Constructor
    myVector();

    myVector(const initializer_list<int> &list);

    // Copy Constructor
    myVector(const myVector &rhs);  

    //Move Constructor
    myVector(myVector &&rhs);

    // Destructor
    ~myVector();

    // Copy Assignment Constructor
    myVector &operator=(const myVector &rhs);

    // function to add element at the last
    void push_back(int data);

    // function to delete last element
    void pop_back();

    // function to check vector empty
    bool empty();

    // function to get size of the vector
    int size();

    // function to get capacity of the vector
    int capa();

    // function to get the first element
    int front();

    // function to get the last element
    int back();

    // function to access element at any index
    int operator[](int index);

    // function to add element at any index
    void insert(int data, int index);

    // function to erase element at any index
    void erase(int index);

    // function to clear vector
    void clear();
};

#endif