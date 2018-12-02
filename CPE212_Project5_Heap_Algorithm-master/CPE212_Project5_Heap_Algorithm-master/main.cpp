//
// main.cpp  2018 Spring CPE 212 - Project05 - Heap Template
//
// Driver program for Heap ADT Template -- The text files (read by this code) contain a series 
// of commands that will help you test your Heap ADT Template code by triggering various class methods.
//
// NOTES:
//
// A pointer variable of type void* may hold the address of any type of object,
// but it cannot be dereferenced with an explicit type cast.
//
// Example:    void* tPtr;                  // Generic pointer variable
//
//      static_cast< Heap<int>* >(tPtr)     // Treat address in tPtr as a pointer to a BSTree of ints
//      static_cast< Heap<Task>* >(tPtr)    // Treat address in tPtr as a pointer to a BSTree of Tasks
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//
#include <iostream>
#include <fstream>
#include "heap.h"
#include "task.h"

using namespace std;


void Bar(int n);                        // Prototype for Bar function



int main (int argc, char * const argv[]) 
{
  void* hPtr = NULL;         // Pointer to a heap
  ifstream inputs;			 // Input file for commands
  char op;					 // Hold operation and optional char input
  int value;                 // Holds integer to add to heap
  string  dtype;             // Holds template datatype information input from file
  string comment;            // Stores comment read from input file
  
  // Output usage message if one input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  program09  <inputfile>\n";
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
  cout << comment << endl << endl;                   // Output file header comment

  // Process commands from input file
  inputs >> op;				// Attempt to input first command
  while (inputs)
  {
    switch (op)
    {
      case '#':   // Test file comment
	        getline(inputs, comment);        // Input and echo the comment appearing in the test file
	        cout << "--------------------------------\n" << op << comment << endl;
	        break;

      case '~':   // Print Bar
	        Bar(40);                         // Output short bar
	        break;	

      case 'c':   // Constructor
                  inputs >> dtype;       // Input datatype information from file
                  cout << endl << "Constructor()";
                  try
				      {
                        // Information from input file determines the type of bstree created
                        if (dtype == "int")
                           hPtr = new Heap<int>;
                        else if (dtype == "Task")
                           hPtr = new Heap<Task>;  
                        cout << endl;
			         }
				      catch ( std::bad_alloc )
				      {
				         cout << "Failed : Terminating now..." << endl;
					      return 1;
				      }
                  break;

      case '+':   // Insert
                  try
                  {
                     if (dtype == "int")
                     {
                        int temp;
                        inputs >> temp;
                        cout << "Insert(" << temp << ")";
                        static_cast< Heap<int>*>(hPtr)->Insert(temp);
                     }                     
                     else if (dtype == "Task")
                     {
                        int priority;
                        string name;
                        inputs >> priority >> name;
                        Task temp(priority, name);
                        cout << "Insert(" << temp << ")";
                        static_cast< Heap<Task>*>(hPtr)->Insert(temp);
                     }
                    
                  }
                  catch (FullHeap)
                  {
                     cout << " -- Failed Full Heap"; 
                  }
                  cout << endl;
                  break;

      case '-':   // DeleteMax
                  cout << "DeleteMax() -- ";
                  try
                  {
                     if (dtype == "int")
                        cout << static_cast< Heap<int>*>(hPtr)->DeleteMax();
                     else if (dtype == "Task")
                        cout << static_cast< Heap<Task>*>(hPtr)->DeleteMax();
                  }
                  catch (EmptyHeap)
                  {
                     cout << "Failed Empty Heap";
                  }
                  cout << endl;
                  break;
			  
      case 'p':   // Print Heap
                  try
                  {
                    cout << "Print() -- ";
                    if (dtype == "int")
                        static_cast< Heap<int>*>(hPtr)->Print();
                     else if (dtype == "Task")
                        static_cast< Heap<Task>*>(hPtr)->Print();
                  }
                  catch (...)
                  {
                      cout << "Unanticipated Print() error" << endl;
                  }
                  break;

      case 's':   // Size of Heap
                  try
                  {
                    if (dtype == "int")
                        cout << "Size() -- " << static_cast< Heap<int>*>(hPtr)->Size() << endl;
                     else if (dtype == "Task")
                        cout << "Size() -- " << static_cast< Heap<Task>*>(hPtr)->Size() << endl;
                  }
                  catch (...)
                  {
                    cout << "Unanticipated Size() error" << endl;
                  }
                  break;  
                  break;
				  
      case 'm':   // Max capacity
                  try
                  {
                    if (dtype == "int")
                        cout << "Capacity() -- " << static_cast< Heap<int>*>(hPtr)->Capacity() << endl;
                     else if (dtype == "Task")
                        cout << "Capacity() -- " << static_cast< Heap<Task>*>(hPtr)->Capacity() << endl;
                  }
                  catch (...)
                  {
                      cout << "Unanticipated Capacity() error" << endl;
                  }
                  break;

      case 'e':   // MakeEmpty
                  try
                  {
                    cout << "MakeEmpty() -- ";
                    if (dtype == "int")
                    {
                        static_cast< Heap<int>*>(hPtr)->MakeEmpty();
                    }
                    else if (dtype == "Task")
                    {
                        static_cast< Heap<Task>*>(hPtr)->MakeEmpty();
                    }
                    cout << "Done" << endl;
                  }
                  catch (...)
                  {
                      cout << "Unanticipated MakeEmpty() error" << endl;
                  }
                  break;

      case 'd':   // Destructor
                  if (dtype == "int")
                    delete static_cast< Heap<int>*>(hPtr);
                  else if (dtype == "Task")
                    delete static_cast< Heap<Task>*>(hPtr);

                  hPtr = NULL;
                  cout << "Destructor()" << endl << endl;
                  break;

      default:    // Error
                  cout << "Error - unrecognized operation '" << op << "'" << endl;
                  cout << "Terminating now..." << endl;
				      return 1;
                  break;
    }
 
    inputs >> op;	// Attempt to input next command
  }

  cout << endl;
  Bar(60);                                           // Output long bar
    
  return 0;
}


void Bar(int n)
// Bar() -- prints horizontal bar
{
	for(int k = 0; k < n; k++)
        cout << '#'; 
    cout << endl;
}  // End Bar()


