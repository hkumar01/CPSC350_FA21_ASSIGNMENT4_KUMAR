// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 4

//Implementation of template Stack data structure using a doubly-linked list

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>

using namespace std;

template<class T>
class ListNode
{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();
    T data;
    ListNode *next;
    ListNode *prev;
};

// constructor
template<class T>
ListNode<T>::ListNode()
{
  data = NULL;
  next = NULL;
  prev = NULL;
}

// destructor
template<class T>
ListNode<T>::~ListNode()
{
  //what else goes here
  next = NULL;
  prev = NULL;
  //data = NULL;
}

// overloaded constructor
template<class T>
ListNode<T>::ListNode(T val)
{
  data = val;
  next = NULL;
  prev = NULL;
}

template<class T>
class GenStack
{
  public:
    GenStack();
    ~GenStack();

  void push(T data);
    T pop();

    bool isEmpty();
    int getSize();
    T peek();

    int size;
  private:
    ListNode<T> *front;
    ListNode<T> *back;
};

// constructor
template<class T>
GenStack<T>::GenStack()
{
  front = NULL;
  back = NULL;
  size = 0;
}

// destructor
template<class T>
GenStack<T>::~GenStack()
{
  ListNode<T> *currNode = front;
  ListNode<T> *nextNode = NULL;

  while (currNode != NULL)
  {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

// push() insert data on top of stack
template<class T>
void GenStack<T>::push(T data)
{
  ListNode<T> *newNode = new ListNode<T>(data);

  if (isEmpty())
  {
    front = newNode;
  }
  else
  {
    newNode->prev = back;
    back->next = newNode;
  }
  back = newNode;
  ++size;
}

// pop() will remove and return first element from top of stack
// if stack is empty then runtime_error is thrown
template<class T>
T GenStack<T>::pop()
{
  if (isEmpty())
  {
    throw runtime_error("Stack is empty.");
  }

  ListNode<T> *temp = back;
  if (back->prev == NULL)
  {
    //only one node in List
    front = NULL;
  }
  else
  {
    //more than one node
    back->prev->next = NULL;
  }

  back = back->prev;
  temp->prev = NULL;
  T data = temp->data;

  --size;
  delete temp;

  return data;
}

// isEmpty() return true if stack has no elements
template<class T>
bool GenStack<T>::isEmpty()
{
  return (size == 0);
}

// getSize() return size of stack as integer
template<class T>
int GenStack<T>::getSize()
{
  cout << size << endl;
  return size;
}

// peek() will return data of top element in stack, but does not remove from stack
template<class T>
T GenStack<T>::peek()
{
  return back->data;
}

#endif
