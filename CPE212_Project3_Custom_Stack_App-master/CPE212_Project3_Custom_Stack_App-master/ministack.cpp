#include "ministack.h"

MiniStack::MiniStack()
{
  stackPtr = new char[MINI_STACK_SIZE];       //instantiates new stack
  top = -1;                                    //sets top to 0
}

void MiniStack::Push(char ch)
{
  if (!IsFull())
  {
    top++;                                    //incrememnts top
    stackPtr[top] = ch;                      //Pushes val onto top
  }
  else
  {
    throw MiniStackFull();                 //trows exception
  }
}

void MiniStack::Pop()
{
  if (!IsEmpty())                        //if not empty
  {
    top--;                               //decrement top
  }
  else                                    //if empty
  {
    throw MiniStackEmpty();               //throw exception
  }
}

void MiniStack::MakeEmpty()
{
  top = -1;                                //resets top to 0
}

char MiniStack::Top()
{
  if (!IsEmpty())                         //if not empty
  {
    return stackPtr[top];
  }
  else
  {
    throw MiniStackEmpty();               //throw exception
  }
}

bool MiniStack::IsFull() const
{
  if (top < MINI_STACK_SIZE - 1)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool MiniStack::IsEmpty() const
{
  if (top == -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

MiniStack::~MiniStack()
{
  delete stackPtr;
}
