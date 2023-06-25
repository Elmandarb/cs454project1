#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <gmpxx.h>
/*
CS 454 Project one
Trent Jones, Eric Fleming

Pre: Will get called during the creation of the DFA table while being passed a buffer queue of chars
Post: Will return an integer that represents what the queue of chars represents.
input/output relationship: A buffer of chars is the input, the output is the buffer converted
to an int that represents the chars in order.
*/
int encode(std::queue<char> buffer) {
	//buffer starts at 0 goes to at most 4 
	int total = 0;
	char value;
	while(! buffer.empty()) {
		value = buffer.front();
		switch(value) {
			case 'a':
				total += (1 * pow(4,buffer.size()-1));
				break;
			case 'b':
				total += (2 * pow(4,buffer.size()-1));
				break;
			case 'c':
				total += (3 * pow(4,buffer.size()-1));
				break;
			case 'd':
				total += (4 * pow(4,buffer.size()-1));
				break;
		}
		buffer.pop();
	}
	return total;
}

//Pre: This will get called during the creation of the DFA table, and will decode an integer given to it
//Post: After this will return a queue buffer of characters that represent the 5 character string of the DFA table.
//input/output relationship: Input is a integer value from the DFA table. Output is a queue of chars that the integer represented within the table.

std::queue<char> decode(int val) {
    // start at 4* 4^4 and keep moving down, subtract the value from int val,
    // if it goes negative move on the next one, if it goes negative for every value in the row put a zero placeholder
    // if it is ever not negative keep the subtraction, add the letter to the queue and move on to the next place.
    // Each case represents the number of characters left in the string
    int place = 4;
    std::queue<char> buffer;
    while(place > -1) {
        switch(place) {
            case 4:
                if(val - (4 * pow(4,place)) >= 85) {
                    buffer.push('d');
                    val -= (4 * pow(4,place));
                }
                //c case
                else if(val - (3 * pow(4,place))>= 85) {
                    buffer.push('c');
                    val -= (3 * pow(4,place));
                }
                //b case
                else if(val - (2 * pow(4,place))>= 85) {
                    buffer.push('b');
                    val -= (2 * pow(4,place));
                }
                //a case
                else if(val - (1 * pow(4,place))>= 85) {
                    buffer.push('a');
                    val -= (1 * pow(4,place));
                }
                place--;
                break;
            case 3:
                if(val - (4 * pow(4,place)) >= 21) {
                    buffer.push('d');
                    val -= (4 * pow(4,place));
                }
                //c case
                else if(val - (3 * pow(4,place))>= 21) {
                    buffer.push('c');
                    val -= (3 * pow(4,place));
                }
                //b case
                else if(val - (2 * pow(4,place))>= 21) {
                    buffer.push('b');
                    val -= (2 * pow(4,place));
                }
                //a case
                else if(val - (1 * pow(4,place))>= 21) {
                    buffer.push('a');
                    val -= (1 * pow(4,place));
                }
                place--;
                break;
            case 2:
                if(val - (4 * pow(4,place)) >= 5) {
                    buffer.push('d');
                    val -= (4 * pow(4,place));
                }
                //c case
                else if(val - (3 * pow(4,place))>= 5) {
                    buffer.push('c');
                    val -= (3 * pow(4,place));
                }
                //b case
                else if(val - (2 * pow(4,place))>= 5) {
                    buffer.push('b');
                    val -= (2 * pow(4,place));
                }
                //a case
                else if(val - (1 * pow(4,place))>= 5) {
                    buffer.push('a');
                    val -= (1 * pow(4,place));
                }
                place--;
                break;
            case 1:
                if(val - (4 * pow(4,place)) >= 1) {
                    buffer.push('d');
                    val -= (4 * pow(4,place));
                }
                //c case
                else if(val - (3 * pow(4,place))>= 1) {
                    buffer.push('c');
                    val -= (3 * pow(4,place));
                }
                //b case
                else if(val - (2 * pow(4,place))>= 1) {
                    buffer.push('b');
                    val -= (2 * pow(4,place));
                }
                //a case
                else if(val - (1 * pow(4,place))>= 1) {
                    buffer.push('a');
                    val -= (1 * pow(4,place));
                }
                place--;
                break;
            case 0:
                if(val - (4 * pow(4,place)) >= 0) {
                    buffer.push('d');
                    val -= (4 * pow(4,place));
                }
                //c case
                else if(val - (3 * pow(4,place))>= 0) {
                    buffer.push('c');
                    val -= (3 * pow(4,place));
                }
                //b case
                else if(val - (2 * pow(4,place))>= 0) {
                    buffer.push('b');
                    val -= (2 * pow(4,place));
                }
                //a case
                else if(val - (1 * pow(4,place))>= 0) {
                    buffer.push('a');
                    val -= (1 * pow(4,place));
                }
                place--;
                break;
        }
    }
    return buffer;
}

//Pre: This will get called while the DFA table is being created to see if the next input is valid with the
// string as well. 
//Post: After this function returns either a value that is not 1366 which is valid, or will return 1366
// which is invalid.
//input/output relationship: A buffer of chars and another char to represent the 6th character of the string is the input. Output is a bool that returns
//true if the value is valid (which means the string contains all letters of the alphabet), and false if the value is invalid


bool check(std::queue<char> buffer, char next) {
    //check if array of chars is in accept state
    buffer.push(next);
    int buffLen = buffer.size();
    int valid[4];
    //will check the first value of the queue and will assign the 1 to a corresponding vector if it contains it.
    for(int i = 0; i < buffLen; i++){
        if(buffer.front() == 'a'){
            valid[0] = 1;
        }else if(buffer.front() == 'b'){
            valid[1] = 1;
        }else if(buffer.front() == 'c'){
            valid[2] = 1;
        }else if(buffer.front() == 'd'){
            valid[3] = 1;
        }
        //will pop off the first element of the queue to continue.
		buffer.pop();
    }
    for(int i : valid){
        //if there is not a 1 in all parts of the vector, the input is invalid and will return false
        if(i != 1){
            return false;
        }
    }
    return true;
}

/*
//Pre: This will get called after the user gives an input of length to the program, and will create a DFA table
// of values that represent a valid string that contains a, b, c, and d. If the input is invalid, it will store
// 1366 as a value.
//Post: This will return a table that contains all valid and invalid inputs of the DFA table.

//input/output relationship: Two ints are entered, the first is an encoded string, the second is the
//char to add. The output is an encoded new sequence of chars after popping the first value and adding the
//new char. If the sequence is valid it returns the encoded string, if it is not valid it returns the fail state
*/

int deltaFunction(int i, int c) {
    std::queue<char> buffer = decode(i);
    std::vector<char> letters = {'0', 'a', 'b', 'c', 'd'};
    if(i == 1366) {
        return i;
    }
    //less than size five is always good so push the letter and return the encoded sequence
    if(buffer.size() < 5) {
        buffer.push(letters[c]);
        return encode(buffer);
    }
    //if the sequence is valid pop the first value, push the new char and encode
    else if(check(buffer, letters[c])){
        buffer.pop();
        buffer.push(letters[c]);
        return encode(buffer);
    }
    //if the sequence is not valid send to the fail state
    else {
        return 1366;
    }
}

//Pre: This will get called in main after the user gives the program a length.
//Post: Will call the delta function which creates a dfa table and output the number of strings that are valid
// with the current alphabet of {a, b, c, d}
//input/output relationship: Input is an integer that the user gave. Will output the number of valid strings, but will not return a value.


void getNumStrings(int k){
    int delta[1366][5];

    // fill out our DFA
    for(int ind = 0; ind < 1366; ind++) {
        for(int input = 1; input < 5; input++) {
            delta[ind][input] = deltaFunction(ind, input);
        }
    }

    // our count function done n times
    std::vector<mpz_class> next(1366, 0);
    std::vector<mpz_class> current(1365, 1);
    current.push_back(0);

    //will run for the length k which is the user input
    for(int ind = 0; ind < k; ind++) {
        for(int i = 0; i < 1365; i++) {
            for (int j = 1; j < 5; j++) {
              next[i] += current[delta[i][j]];
            }
        }
        //this will reset the vectors to start the next loop
        for(int copyIdx = 0; copyIdx < 1366; copyIdx++) {
            current[copyIdx] = next[copyIdx];
            next[copyIdx] = 0;
        }
    }

    std::cout << "Testing for length " << k << ": " << '\n';
    std::cout << current[0] << '\n';

}

//Pre: This is the starter function of the project that will get inputs from the user to test and call
// getNumbStrings while passing the input from the user.
//Post: After an invalid input is given to the program, will exit with code 1
//input/output relationship: An int from the user to represent length of strings. Output is whether the function exitted correctly.

int main() {
//encode {a,b,c,d} as {1,2,3,4}
// in our 2d array/dfa skip row 0

    int k = 0;

    std::cout << "Please Enter a length: " << '\n';
    //will continue to get inputs from the user as long as they are within the given range of 0 to 300
    while(std::cin >> k){
        if(k < 0 || k > 300){
            std::cout << "Sorry this number is invalid, exiting..." << '\n';
            exit(1);
        }else{
            getNumStrings(k);
            std::cout << "Please Enter another length: " << '\n';
        }
    }
    return 0;
}
