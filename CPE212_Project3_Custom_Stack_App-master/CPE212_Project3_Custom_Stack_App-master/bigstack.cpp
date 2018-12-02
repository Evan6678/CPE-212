#include "bigstack.h"

BigStack::BigStack()
{
  headPtr = NULL;                                 //creates new empty stack
}

void BigStack::Push(char ch)
{
  if(!IsFull())                                  //test if BigStack is full
  {

    //////////////////////////////////////
    ///////TEST CODE//////////////////////
    //////////////////////////////////////
    // ListNode* tempPtr = new ListNode;
    // tempPtr->stackPtr = new MiniStack;
    // cout << tempPtr->stackPtr->IsFull() << endl;
    /////////////////////////////////////

     if (headPtr == NULL)
     {
       headPtr = new ListNode;
       headPtr->stackPtr = new MiniStack;
       headPtr->nextPtr = NULL;
       headPtr->previousPtr = NULL;
     }

     if (!headPtr->stackPtr->IsFull())          //test if stackPrt is full
     {
      headPtr->stackPtr->Push(ch);              //Push Val if not full
     }
     else
     {
       ListNode* tempPtr;                      //create new temp ptr
       tempPtr = new ListNode;                 //creates new node
       tempPtr->stackPtr = new MiniStack;

       tempPtr->stackPtr->Push(ch);            //push val into new stack

       headPtr->previousPtr = tempPtr;             //Assign nextPtr for current Head
       tempPtr->nextPtr = headPtr;         //assign New Head to previous head

       headPtr = tempPtr;                      //set Head to new temp holder

     }
   }
}

void BigStack::Pop()
{
   if (!IsEmpty())                             //if BigStack is not empty
   {
      if (!headPtr->stackPtr->IsEmpty())        //if stackPtr is not empty
      {
         headPtr->stackPtr->Pop();
      }
      else
      {
        delete headPtr->stackPtr;                     //delete ministack member
        headPtr = headPtr->nextPtr;               //step back headPtr
        delete headPtr->previousPtr;                      //delete the old empty node
        headPtr->previousPtr = NULL;
        headPtr->stackPtr->Pop();
      }

      if (headPtr->stackPtr->IsEmpty())             //catches empty nodes
      {
        delete headPtr->stackPtr;
        if (headPtr->nextPtr == NULL)
        {
          delete headPtr;
          headPtr = NULL;
        }
        else
        {
          headPtr = headPtr->nextPtr;
          delete headPtr->previousPtr;
          headPtr->previousPtr = NULL;
        }
      }
   }
}

char BigStack::Top()
{
  if (!IsEmpty())
  {
      return headPtr->stackPtr->Top();
  }
}

void BigStack::MakeEmpty()
{
  if(!IsEmpty())
  {
    ListNode* tempPtr;
    while (headPtr != NULL)
    {
      tempPtr = headPtr;
      headPtr = headPtr->nextPtr;
      delete tempPtr->stackPtr;
      delete tempPtr;
    }
    headPtr = NULL;
  }
}

bool BigStack::IsFull() const
{
  try
  {
    ListNode* testPtr = new ListNode;             //creates new ListNode

    delete testPtr;                               //deletes node
  }
  catch (bad_alloc)
  {
    return true;                                  //if hit means full and return true
  }
  return false;                                   //else return false
}

bool BigStack::IsEmpty() const
{
  if (headPtr != NULL)
  {
    return false;
  }
  else
  {
    return true;
  }
}

BigStack::~BigStack()
{
  ListNode* tempPtr;
  while (headPtr != NULL)
  {
    tempPtr = headPtr;
    delete headPtr->stackPtr;
    headPtr = headPtr->nextPtr;
    delete tempPtr;
  }
}
