//
// main.cpp
//
// Driver program which is used to test each
// class member function.
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

#include <iostream>
#include <fstream>
#include <new>
#include <cstddef>
#include "ministack.h"
#include "bigstack.h"

using namespace std;

void Bar(int n);                        // Prototype for Bar function


int main(int argc, char* argv[])
{
  ifstream inputs;						// Input file for commands
  char op, ch;							// Hold operation and optional char input
  BigStack* bStackPtr = NULL;			// Will point to BigStack object
  MiniStack* mStackPtr = NULL;          // Will point to MiniStack object
  string comment;                       // Stores comment read from input file
  
  
  // Output usage message if one input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  program03  <inputfile>\n";
	return 1;
  }
  
  // Attempt to open input file -- terminate if file does not open
  inputs.open(argv[1]);
  if (!inputs)
  {
    cout << "Error - unable to open input file" << endl;
	return 1;
  }

  Bar(60);                                           // Output long bar

  // Process comment line from input file
  getline(inputs, comment);                          // Input file header comment
  cout << endl << comment << endl << endl;           // Output file header comment

  // Process commands from input file
  inputs >> op;				// Attempt to input first command
  while (inputs)
  {
    switch (op)
    {
      case '#':   // Test file comment
	        getline(inputs, comment);      // Input and echo the comment appearing in the test file
	        cout << '#' << comment << endl;
	        break;

      case '~':   // Print Bar
	        Bar(40);                         // Output short bar
	        break;	

      case 'c':   // Constructor
                  inputs >> op;
                  
                  try
				  {
                    if (op == 'B')
                    {
                        cout << "BigStack::BigStack() -- Status = ";
				        bStackPtr = new BigStack;
                        cout << "Completed" << endl;
                    }
                    else if (op == 'M')
                    {
                        cout << "MiniStack::MiniStack() -- Status = ";
				        mStackPtr = new MiniStack;
                        cout << "Completed" << endl;
                    }
                    
				  }
				  catch ( std::bad_alloc )
				  {
				    cout << "Failed : Terminating now..." << endl;
					return 1;
				  }
                  break;

      case '+':   // Push
                  inputs >> ch;
                  try
                  {
                      if (bStackPtr != NULL)
                      {
                         cout << "BigStack::Push('" << ch << "') -- Status = ";
                      }
                      else if (mStackPtr != NULL)
                      {
                         cout << "MiniStack::Push('" << ch << "') -- Status = ";
                      }

                      if ( (bStackPtr != NULL) && (!bStackPtr->IsFull()) )
                      {
                         bStackPtr->Push(ch);
                         cout << "Completed" << endl;
                      }
                      else if ( (mStackPtr != NULL) )
                      {
                         try
                         {
                            mStackPtr->Push(ch);
                            cout << "Completed" << endl;
                         }
                         catch ( MiniStackFull )
                         {
                            cout << "Failed -- MiniStackFull Exception" << endl;
                         }
                      }
                  }
                  catch ( ... )
                  {
                      cout << "Failed due to exception" << endl;
                  }
                  break;

      case '-':   // Pop
                  try
                  {
                      if (bStackPtr != NULL)
                      {
                         cout << "BigStack::Pop() -- Status = ";
                      }
                      else if (mStackPtr != NULL) 
                      {
                         cout << "MiniStack::Pop() -- Status = ";
                      }

                      if ( (bStackPtr != NULL) && (!bStackPtr->IsEmpty()) )
                      {
                         bStackPtr->Pop();
                         cout << "Completed" << endl;
                      }
                      else if ( (mStackPtr != NULL) )
                      {
                         try
                         {
                            mStackPtr->Pop();
                            cout << "Completed" << endl;
                         }
                         catch ( MiniStackEmpty )
                         {
                            cout << "Failed -- MiniStackEmpty Exception" << endl;
                         }
                      }
                      else
                      {
                         cout << "Failed" << endl;
                      }
                  }
                  catch ( ... )
                  {
                      cout << "Failed due to exception" << endl;
                  }
                  break;

      case 't':   // Top
                  try
                  {
                      if (bStackPtr != NULL)
                      {
                         cout << "BigStack::Top() -- Status = ";
                      }
                      else if (mStackPtr != NULL) 
                      {
                         cout << "MiniStack::Top() -- Status = ";
                      }

                      if ( (bStackPtr != NULL) && (!bStackPtr->IsEmpty()) )
                      {
                         ch = bStackPtr->Top();
                         cout << "Completed, Value = '" << ch << "'" << endl;
                      }
                      else if ( (mStackPtr != NULL) )
                      {
                         try
                         {
                            ch = mStackPtr->Top();
                            cout << "Completed, Value = '" << ch << "'" << endl;
                         }
                         catch ( MiniStackEmpty )
                         {
                            cout << "Failed -- MiniStackEmpty Exception" << endl;
                         }
                      }
                      else
                      {
                         cout << "Failed" << endl;
                      }
                  }
                  catch ( ... )
                  {
                      cout << "Failed due to exception" << endl;
                  }
                  break;

      case 'e':   // IsEmpty
                  try
                  {
                      if (bStackPtr != NULL)
                      {
                         cout << "BigStack::IsEmpty() -- Status = ";
                      }
                      else if (mStackPtr != NULL) 
                      {
                         cout << "MiniStack::IsEmpty() -- Status = ";
                      }

                      if (bStackPtr != NULL)
                      {
                         if (bStackPtr->IsEmpty())
                            cout << "Empty" << endl;
                         else
                            cout << "Not Empty" << endl;
                      }
                      else if (mStackPtr != NULL) 
                      {
                         if (mStackPtr->IsEmpty())
                            cout << "Empty" << endl;
                         else
                            cout << "Not Empty" << endl;
                      }
                      else
                      {
                         cout << "Failed" << endl;
                      }
                  }
                  catch ( ... )
                  {
                      cout << "Failed due to exception" << endl;
                  }
                  break;

      case 'f':   // IsFull
                  try
                  {
                      if (bStackPtr != NULL)
                      {
                         cout << "BigStack::IsFull() -- Status = ";
                      }
                      else if (mStackPtr != NULL) 
                      {
                         cout << "MiniStack::IsFull() -- Status = ";
                      }

                      if (bStackPtr != NULL)
                      {
                         if (bStackPtr->IsFull())
                            cout << "Full" << endl;
                         else
                            cout << "Not Full" << endl;
                      }
                      else if (mStackPtr != NULL) 
                      {
                         if (mStackPtr->IsFull())
                            cout << "Full" << endl;
                         else
                            cout << "Not Full" << endl;
                      }
                      else
                      {
                         cout << "Failed" << endl;
                      }
                  }
                  catch ( ... )
                  {
                      cout << "Failed due to exception" << endl;
                  }
                  break;

      case 'x':   // MakeEmpty
                  try
                  {
                      if (bStackPtr != NULL)
                      {
                         cout << "BigStack::MakeEmpty() -- Status = ";
                      }
                      else if (mStackPtr != NULL)
                      {
                         cout << "MiniStack::MakeEmpty() -- Status = ";
                      }

                      if (bStackPtr != NULL)
                      {;
                         bStackPtr->MakeEmpty();
                         cout << "Completed" << endl;
                      }
                      else if (mStackPtr != NULL)
                      {
                         mStackPtr->MakeEmpty();
                         cout << "Completed" << endl;
                      }
                      else
                      {
                         cout << "Failed" << endl;
                      }
                  }
                  catch ( ... )
                  {
                      cout << "Failed due to exception" << endl;
                  }
                  break;
				  
      case 'p':   // Print
                  try
                  {
                      if (bStackPtr != NULL)
                      {
                        cout << "BigStack::Print() -- ";
                        bStackPtr->Print();	
                      }
                      else if (mStackPtr != NULL)
                      {
                        cout << "MiniStack::FwdPrint() -- ";
                        mStackPtr->FwdPrint();	
                        cout << endl;
                      }
                  }
                  catch ( ... )
                  {
                      cout << "Failed due to exception" << endl;
                  }		  
                  break;
				  
      case 'd':   // Destructor
                  try
                  {
                      if (bStackPtr != NULL)
                      {
                          cout << "BigStack::~BigStack() -- Status = ";
                          delete bStackPtr;
                          bStackPtr = NULL;
                          cout << "Completed" << endl;
                      }
                      else if (mStackPtr != NULL)
                      {
                          cout << "MiniStack::~MiniStack() -- Status = ";
                          delete mStackPtr;
                          mStackPtr = NULL;
                          cout << "Completed" << endl;
                      }
                  }
                  catch ( ... )
                  {
                      cout << "Failed due to exception" << endl;
                  }
				  break;

      default:    // Error
                  cout << "Error - unrecognized operation : Terminating now..." << endl;
				  return 1;
                  break;
    }
 
    inputs >> op;	// Attempt to input next command
  }
  
  cout << endl;
  Bar(60);                                           // Output long bar

  return 0;
} // End main()

void Bar(int n)
// Bar() -- prints horizontal bar
{
	for(int k = 0; k < n; k++)
        cout << '#'; 
    cout << endl;
}  // End Bar()



