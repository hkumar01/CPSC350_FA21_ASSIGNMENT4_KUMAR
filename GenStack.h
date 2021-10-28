#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>

using namespace std;

template<class T>
class ListNode
{
  ListNode();
  ListNode(T d);
  ~ListNode();
  T data;
  ListNode *next;
  ListNode *prev;
};

template<class T>
ListNode<T>::ListNode()
{
  data = NULL;
  next = NULL;
  prev = NULL;
}

template<class T>
ListNode<T>::~ListNode()
{
  //what else goes here
  next = NULL;
}

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
  private:
    T top;
    int size;
    ListNode<T> *front;
    ListNode<T> *back;
};

template<class T>
GenStack<T>::GenStack()
{
  front = NULL;
  back = NULL;
  size = 0;
}

template<class T>
GenStack<T>::~GenStack()
{
  //destructor
}

template<class T>
void GenStack<T>::push(T data)
{
  ListNode<T> *newNode = new ListNode(data);

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

template<class T>
bool GenStack<T>::isEmpty()
{
  return (size == 0);
}

template<class T>
int GenStack<T>::getSize()
{
  return size;
}

template<class T>
T GenStack<T>::peek()
{
  return back->data;
}

#endif