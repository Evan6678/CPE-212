//
// priorityq.h -- 2018 Spring -- Project04  Priority Queue
//
// PriorityQ models a linked list implementation of a priority queue that will store
// messages with priorities HIGH, MEDIUM, or LOW.  
//
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include <iostream>
#include "message.h"
using namespace std;

//
// Exception classes for PriorityQ
//
class EmptyPQ { /* No additional code */ };   // Exception class for empty PriorityQ condition

class FullPQ  { /* No additional code */ };   // Exception class for full PriorityQ condition

class InvalidPeekPQ { /* No additional code */ };   // Exception class for invalid PriorityQ peek condition


//
// Priority Queue Node Structure
//
struct Node                   // Linked priority queue node structure
{
	Message   data;				// Field for storing data in the priority queue node
	Node*     nextPtr;			// Points to next priority queue node
    Node*     previousPtr;     // Points to previous priority queue node
};


//
// PriorityQ class declaration
//
class PriorityQ               // Double linked queue of messages sorted by priority
{
private:
	Node*     frontPtr;			// Points to front node of priority queue
    Node*     rearPtr;         // Points to rear node of priority queue
	int       count;				// Number of values stored in priority queue
	
public:
	/**********  Start of functions you must implement for PriorityQ  **************/
	// Implement the following nine public functions in the file named priorityq.cpp
	
	PriorityQ();
	// PriorityQ()
	// Initializes all private variables to indicate an empty priority queue
	
	~PriorityQ();
	//~PriorityQ()
	// Deallocates all priority queue nodes
    // No memory leak allowed
	
	void MakeEmpty();
	// MakeEmpty()
	// Deallocates all priority queue nodes and returns priority queue to empty ready-to-use state 
    // No memory leak allowed
	
   void Enqueue(Message msg);
	// Enqueue()
	// Adds value to priority queue in correct position and increments count.
	// Duplicates are allowed.  
    // Highest priority messages must always be at front of queue
    // Lowest priority messages must always be at rear of queue
    // Add AFTER messages of similar priority
	// If queue is already full, throws FullPQ exception.

	void Dequeue();
	// Dequeue()
	// Removes highest priority message from front of priority queue and decrements count.
	// If queue is empty, throws EmptyPQ exception
    // No memory leak allowed

    void Purge(Priorities p);
    // Purge()
    // Removes all messages of priority p from queue leaving all other messages in priority queue
    // If queue is empty, throws EmptyPQ exception
    // No memory leak allowed
	
	Message Front() const;
	// Front()
	// Returns message at front of priority queue
	// If queue is empty, throws EmptyPQ

	Message Rear() const;
	// Rear()
	// Returns message at rear of priority queue
	// If queue is empty, throws EmptyPQ

	Message Peek(int n) const;
	// Peek()
	// Returns message n positions from front of priority queue
	// If position n does not exist, throws InvalidPeekPQ
	
	bool IsFull() const;
	// IsFull()
	// Returns true if queue is full.  Returns false otherwise.  DOES NOT MODIFY THE PRIORITY QUEUE
	
	bool IsEmpty() const;
	// IsEmpty()
	// Returns true if queue is empty.  Returns false otherwise.  DOES NOT MODIFY THE PRIORITY QUEUE
	
	int Size() const;
	// Size()
	// Returns number of items stored in priority queue.  DOES NOT MODIFY THE PRIORITY QUEUE

	/***********  End of functions you must implement for PriorityQ ***************/
	
	void Print() const
	// Print() -- DO NOT MODIFY OR RELOCATE THIS FUNCTION
	// Prints contents of priority queue without modifying its contents 
	{
		Node* tempPtr = frontPtr;

        // Prints queue nodes Front-to-Rear order
		cout << "Front { ";
		while (tempPtr != NULL)
		{
			//cout << '(' << tempPtr->data.GetMessage() << ')' << ' ';
			tempPtr->data.Print();
			cout << ' ';
			
		    tempPtr = tempPtr->nextPtr;
		}
		cout << "} Rear\n           Rear  { ";

        // Prints queue nodes Rear-to-Front order
        tempPtr = rearPtr;
		while (tempPtr != NULL)
		{
			//cout << '(' << tempPtr->data.GetMessage() << ')' << ' ';
			tempPtr->data.Print();
			cout << ' ';
			
		   tempPtr = tempPtr->previousPtr;
		}
		cout << "} Front";
 
	}  // End Print()
	
};

#endif



