#include "priorityq.h"

PriorityQ::PriorityQ()
{
  frontPtr = NULL;
  rearPtr = NULL;
  count = 0;
}

void PriorityQ::MakeEmpty()
{
  if (!IsEmpty())
  {
    Node* tempPtr;
    while (rearPtr != NULL)
    {
      tempPtr = rearPtr;
      rearPtr = rearPtr -> previousPtr;
      delete tempPtr;
    }

    count = 0;
    frontPtr = NULL;
    rearPtr = NULL;
  }
}

void PriorityQ::Enqueue(Message msg)
{
  //check IsFull() to check for room
  if (!IsFull())
  {
    //##########workflow 1: if front and rear PTR == NULL############
    if (frontPtr == NULL && rearPtr == NULL)
    {
          //create new node
          Node* newNode = new Node;

          //assign next and previous values to NULL
          newNode -> nextPtr = NULL;
          newNode -> previousPtr = NULL;
          //assign front and rear to 1 new node
          frontPtr = newNode;
          rearPtr = newNode;
          //insert data into node
          newNode -> data = msg;
    }
    //#####################END workflow 1###########################

    //##########workflow 2: if front and reat PTR != NULL###########
    else
    {

      //########workflow 2-0: create new node########
      //This workflow is ALWAYS run if front and rear != NULL

        // create new node
        Node* newNode = new Node;
        // insert data into new node
        newNode -> data = msg;
      //###########################################

      //@@@@@@@@@@@@@Information@@@@@@@@@@@@@
      //create a new node first then use
      //newNode -> data.GetPriority() to
      //compare priority to the switch
      //(or if else is) statment.
      //then use each workflow to insert
      //the newNode
      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

      switch (newNode -> data.GetPriority())
      {

      //cond 1: priority = L, add to end of queue
        case(LOW):

          //set old rear -> nextPtr
            rearPtr -> nextPtr = newNode;
          //set new L -> nextPtr to NULL
            newNode -> nextPtr = NULL;
          //set new L -> previousPtr to rearPtr
            newNode -> previousPtr = rearPtr;
          //set rearPtr to newNode
            rearPtr = newNode;

          break;

      //cond 2: priority = M, add to end of M, before L
        case(MEDIUM):

        //create temp prt to go from rear to front
        Node* tempPtr;
        tempPtr = rearPtr;

        //loops down the node queue until it finds priority M or priority H or NULL
        while (tempPtr != NULL)
        {

          //############workflow 2-1: if M or H is found###############
          if (tempPtr -> data.GetPriority() == MEDIUM ||
              tempPtr -> data.GetPriority() == HIGH)
          {

            //if it is not the last item and not the only item in the queue
            if (tempPtr != rearPtr)
            {
              //assigns new M -> nextPtr to old M -> nextPtr
                newNode -> nextPtr = tempPtr -> nextPtr;
              //assigns new M -> previousPtr to old M location
                newNode -> previousPtr = tempPtr;
              //assigns old M ->nextPtr to new M location
                tempPtr -> nextPtr = newNode;
              //set ptr -> previousPtr from next node
                tempPtr = newNode -> nextPtr;
                tempPtr -> previousPtr = newNode;
            }
            //if it is the last item in the queue or a size of 1
            else
            {
            //assigns new M -> nextPtr to old M -> nextPtr
              newNode -> nextPtr = tempPtr -> nextPtr;
            //assigns new M -> previousPtr to old M location
              newNode -> previousPtr = tempPtr;
            //assigns old M ->nextPtr to new M location
              tempPtr -> nextPtr = newNode;
            //set new rearPtr
              rearPtr = newNode;
            }
              //break out of loop
              break;
          }
          //##################END workflow 2-1 ######################

          //############workflow 2-2: if M or H is NOT found############
          else if (tempPtr == NULL)
          {
            //assign new M -> previousPtr to NULL
            newNode ->previousPtr = NULL;
            //assign new M -> nextPtr to frontPtr
            newNode -> nextPtr = frontPtr;
            //assign frontPtr to new M
            frontPtr = newNode;

            cout << "\n\n\nELSE IF\n\n\n";

            break;

          }
          //##################END workflow 2-2 ######################

          //move down one step to previous node
          tempPtr = tempPtr -> previousPtr;

          //Extra conditional to catch case where the step down sets temp
          //to NULL and will break loop before handeling
          //############workflow 2-2: if M or H is NOT found############
          if (tempPtr == NULL)
          {
            //assign new M -> previousPtr to NULL
            newNode ->previousPtr = NULL;
            //assign new M -> nextPtr to frontPtr
            newNode -> nextPtr = frontPtr;
            //assign old frontPtr -> previousPtr to new front
            frontPtr -> previousPtr = newNode;
            //assign frontPtr to new M
            frontPtr = newNode;

            //cout << "\n\n\nIF CATCH\n\n\n";

            break;

          }
          //##################END workflow 2-2 ######################

        } // end while

          break;

      //cond 3: priority = H, add to end of H, before M
      case(HIGH):

      //create temp prt to go from rear to front
      tempPtr = rearPtr;

      //loops down the node queue until it finds priority H or NULL
      while (tempPtr != NULL)
      {
        //############workflow 2-3: if H is found###############
        if (tempPtr -> data.GetPriority() == HIGH)
        {
          //if tempPtr != rearPtr (it is not the last item and it is not of size 1)
          if (tempPtr != rearPtr)
          {
            //assigns new H -> nextPtr to old H -> nextPtr
            newNode -> nextPtr = tempPtr -> nextPtr;
            //assigns new H -> previousPtr to old H location
            newNode -> previousPtr = tempPtr;
            //assigns old H ->nextPtr to new H location
            tempPtr -> nextPtr = newNode;
            //set ptr -> previousPtr from next node
            tempPtr = newNode -> nextPtr;
            tempPtr -> previousPtr = newNode;

            break;
          }
        //else node is to go at end
          else
          {
          //assigns new H -> nextPtr to old H -> nextPtr
          newNode -> nextPtr = tempPtr -> nextPtr;
          //assigns new H -> previousPtr to old H location
          newNode -> previousPtr = tempPtr;
          //assigns old H ->nextPtr to new H location
          tempPtr -> nextPtr = newNode;
          //sets rearPtr to new Node
          rearPtr = newNode;

          break;
          }
        }

        //##################END workflow 2-3 ######################

        //############workflow 2-4: if NULL found############
        if (tempPtr == NULL)
        {
          //assign new H -> previousPtr to NULL
          newNode -> previousPtr = NULL;
          //assign new H -> nextPtr to frontPtr
          newNode -> nextPtr = frontPtr;
          //assign old frontPtr -> previousPtr to new H
          frontPtr -> previousPtr = newNode;
          //assign frontPtr to new H
          frontPtr = newNode;

          break;
        }
        //##################END workflow 2-4 ######################

        //move to previousPtr
         tempPtr = tempPtr -> previousPtr;

        //re-run workflow 2-4 to catch loose NULL from decrement
        //############workflow 2-4: if NULL found############
        if (tempPtr == NULL)
        {
          //assign new H -> previousPtr to NULL
          newNode -> previousPtr = NULL;
          //assign new H -> nextPtr to frontPtr
          newNode -> nextPtr = frontPtr;
          //assign old frontPtr -> previousPtr to new H
          frontPtr -> previousPtr = newNode;
          //assign frontPtr to new H
          frontPtr = newNode;

          break;
        }
        //##################END workflow 2-4 ######################
      }//end of while

      break;
      } //end switch
    } //end of else statement
    //##########################END workflow 2#####################

    //ALWAYS RUN
    //increment counter
    count++;

  } //end of IsFull() condition
}

void PriorityQ::Dequeue()
{
  if (!IsEmpty())
  {
    if (frontPtr == rearPtr)
    {
      delete frontPtr;
      frontPtr = NULL;
      rearPtr = NULL;
    }
    else
    {
      delete frontPtr -> previousPtr;
      frontPtr = frontPtr -> nextPtr;
      delete frontPtr ->previousPtr;
      frontPtr -> previousPtr = NULL;
    }

    count--;
  }
  else
  {
    throw EmptyPQ();
  }
}

void PriorityQ::Purge(Priorities p)
{
  if (!IsEmpty())
  {
    //create pointer
    Node* tempPtr;
    Node* stepDownPtr;

    //if p = LOW
    if (p == LOW)
    {
      tempPtr = rearPtr;  //create temp pointer

      while (rearPtr != NULL && rearPtr -> data.GetPriority() == LOW)
      {
        tempPtr = tempPtr -> previousPtr; //step tempPtr down the queue

        if (tempPtr == NULL)  //if the rear finds NULL front of list
        {
          delete rearPtr;
          rearPtr = NULL;
          frontPtr = NULL;
        }
        else                 //if the rearPtr finds a MEDIUM or HIGH
        {
          delete rearPtr;
          tempPtr -> nextPtr = NULL;
          rearPtr = tempPtr;
        }
        count--;              //decrement
      }
    }

    //if p = MEDIUM
    if (p == MEDIUM)
    {
      tempPtr = rearPtr;  //creates temp pointer at end of the list

      //skips any low and moves to medium
      while (tempPtr != NULL && tempPtr -> data.GetPriority() == LOW)
      {
        tempPtr = tempPtr -> previousPtr;
        //sets StepUpPtr to last LOW priority to connect list to last HIGH or NULL
      }

      stepDownPtr = tempPtr; // steps down the queue

////////////////////////////////////MEMORY LEAK////////////////////////////////////

      while (tempPtr != NULL && tempPtr -> data.GetPriority() == MEDIUM)
      {

        //steps pointer down the queue
        stepDownPtr = stepDownPtr -> previousPtr;

        //if stepDownPtr == NULL end of list so clean up
        if (stepDownPtr == NULL)
        {
          //if stepDownPtr == NULL and tempPtr -> nextPtr != NULL
          if (tempPtr -> nextPtr != NULL)
          {
            tempPtr = tempPtr -> nextPtr;
            delete tempPtr -> previousPtr;
            tempPtr -> previousPtr = NULL;
            frontPtr = tempPtr;
          }
          //if stepDownPtr == NULL and tempPtr -> nextPtr == NULL
          else
          {
            delete tempPtr;
            frontPtr = NULL;
            rearPtr = NULL;
          }
        }
        //if stepDownPtr != NULL
        else
        {
          //if StepUpPtr == NULL there is no LOW priorities
          if (tempPtr -> nextPtr == NULL)
          {
            delete tempPtr; //delete current MEDIUM of temp pointer
            stepDownPtr -> nextPtr = NULL;  //set last node -> next to NULL
            tempPtr = stepDownPtr;  //move tempPtr down one level
            rearPtr = tempPtr;  //sets new rearPtr
          }
/////////////////////////////////////////////////////////////////////////////////
          //else if StepUpPtr == a NODE
          else
          {
            tempPtr = tempPtr -> nextPtr;
            delete tempPtr -> previousPtr;
            tempPtr -> previousPtr = stepDownPtr;
            stepDownPtr -> nextPtr = tempPtr;
            tempPtr = stepDownPtr;
          }
        }

        count--;                  //decrement count
      }

    }
    //if p = HIGH
    if (p == HIGH)
    {
      tempPtr = frontPtr;
      while (frontPtr != NULL && frontPtr -> data.GetPriority() == HIGH)
      {
        tempPtr = tempPtr -> nextPtr;
        if (tempPtr == NULL)
        {
          delete frontPtr;
          frontPtr = NULL;
          rearPtr = NULL;
        }
        else
        {
          delete frontPtr;
          tempPtr -> previousPtr = NULL;
          frontPtr = tempPtr;
        }
        count--;
      }
    }
  }
  else
  {
    throw EmptyPQ();
  }
}

Message PriorityQ::Front() const
{
  if (!IsEmpty())
  {
    return frontPtr -> data;
  }
  else
  {
    throw EmptyPQ();
  }
}

Message PriorityQ::Rear() const
{
  if (!IsEmpty())
  {
    return rearPtr -> data;
  }
  else
  {
    throw EmptyPQ();
  }
}

Message PriorityQ::Peek(int n) const
{
  try
  {
    if (!IsEmpty())
    {
      Node* tempPtr;
      tempPtr = frontPtr;
      for (int i = 0; i <= n-1; i++)
      {
        tempPtr = tempPtr -> nextPtr;
        if (tempPtr == NULL)
        {
          throw InvalidPeekPQ();
        }
      }
      return tempPtr -> data;
    }
    else
    {
      throw InvalidPeekPQ();
    }
  }
  catch (...)
  {
    throw InvalidPeekPQ();
  }
}

bool PriorityQ::IsFull() const
{
  try
  {
    Node* testNode = new Node;
    delete testNode;
    return false;
  }
  catch (bad_alloc)
  {
    return true;
  }
}

bool PriorityQ::IsEmpty() const
{
  if (count == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int PriorityQ::Size() const
{
  return count;
}

PriorityQ::~PriorityQ()
{
MakeEmpty();

delete frontPtr;
delete rearPtr;
}
