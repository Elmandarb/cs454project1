# cs454project1
Group Members: Eric Fleming, Trenton Jones

We believe all functions work correctly, tested on all given test inputs, and outputs matched what was expected.

to compile: g++ main.cpp -lgmpxx -lgmp
to run: ./a.out

Functions worked on by Eric:
int encode(std::queue<char> buffer);
//Pre: Will get called during the creation of the DFA table while being passed a buffer queue of chars
//Post: Will return an integer that represents what the queue of chars represents.
//input/output relationship: A buffer of chars is the input, the output is the buffer converted
to an int that represents the chars in order.

int deltaFunction(int i, int c);
//Pre: This will get called after the user gives an input of length to the program, and will create a DFA table
// of values that represent a valid string that contains a, b, c, and d. If the input is invalid, it will store
// 1366 as a value.
//Post: This will return a table that contains all valid and invalid inputs of the DFA table.

//input/output relationship: Two ints are entered, the first is an encoded string, the second is the
//char to add. The output is an encoded new sequence of chars after popping the first value and adding the
//new char. If the sequence is valid it returns the encoded string, if it is not valid it returns the fail state


Functions worked on by Trenton:
bool check(std::queue<char> buffer, char next);
//Pre: This will get called while the DFA table is being created to see if the next input is valid with the
// string as well. 
//Post: After this function returns either a value that is not 1366 which is valid, or will return 1366
// which is invalid.
//input/output relationship: A buffer of chars and another char to represent the 6th character of the string is the input. Output is a bool that returns
//true if the value is valid (which means the string contains all letters of the alphabet), and false if the value is invalid

int main();
//Pre: This is the starter function of the project that will get inputs from the user to test and call
// getNumbStrings while passing the input from the user.
//Post: After an invalid input is given to the program, will exit with code 1
//input/output relationship: An int from the user to represent length of strings. Output is whether the function exitted correctly.

Functions worked on together:

std::queue<char> decode(int val);
//Pre: This will get called during the creation of the DFA table, and will decode an integer given to it
//Post: After this will return a queue buffer of characters that represent the 5 character string of the DFA table.
//input/output relationship: Input is a integer value from the DFA table. Output is a queue of chars that the integer represented within the table.

void getNumStrings(int k);
//Pre: This will get called in main after the user gives the program a length.
//Post: Will call the delta function which creates a dfa table and output the number of strings that are valid
// with the current alphabet of {a, b, c, d}
//input/output relationship: Input is an integer that the user gave. Will output the number of valid strings, but will not return a value.

