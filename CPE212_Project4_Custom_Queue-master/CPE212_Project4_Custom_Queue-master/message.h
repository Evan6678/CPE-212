//
// message.h -- 2018 Spring -- Project05  Priority Queue
//
// Message ADT models a single message that will be stored in Priority Queue.  
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
using namespace std;

//
// Define enumerated Priorities type
//
enum Priorities {UNKNOWN, LOW, MEDIUM, HIGH};

//
// Message class declaration
//
class Message						        // Models a single message with priority
{
private:
	Priorities    priority;            // Stores message priority
	string        message;             // Stores message contents
	
public:
	/**********  Start of functions you must implement for Message  **************/
	// Implement the following five public functions in the file named message.cpp
	
	Message();                         // Initializes message to empty string with UNKNOWN priority

	void SetPriority(Priorities p);    // Sets priority equal to p

	void SetMessage(string msg);       // Sets message equal to msg
	
	Priorities GetPriority() const;    // Returns priority value without modification

	string GetMessage() const;         // Returns message contents without modification
	
	/***********  End of functions you must implement for Message  ***************/
	
	void Print() const                 // DO NOT MODIFY OR RELOCATE THIS FUNCTION
	{
		cout << "[";
		
		if (priority == HIGH)
			cout << "H";
		else if (priority == MEDIUM)
			cout << "M";
		else if (priority == LOW)
			cout << "L";
		else
			cout << "U";
		
		cout << ", " << message << "]";
	}  // End Print() const
};

#endif



