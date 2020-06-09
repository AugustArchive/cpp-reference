// Program basically calculates a number that is inputted by the user and then we find the prime number of it and print it out.

// #include is basically a big file of code that can be referenced in the program
#include <iostream>
#include <vector>

// Namespaces can make variables a tad bit easier to not "copy/paste" primitive values, it wont duplicate it
// Also removes the usage of "std::", the namespace is included so it's not needed
using namespace std;

// The sieve function basically adds values to the array
// when we calculate "(index + 2) * 2" and then we add the value
// from `j`
void sieve(vector<int>& array) { // We add `&` to the parameter to make a reference of pointer
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == 0) {
            for (int j = (i + 2) * 2; j < array.size(); j += i + 2) {
                array[j]++;
            }
        }
    }
}

// The main function is the entrypoint of the program
int main() {
    // "cout" is basically an output stream to print out stuff
    // << is used to add stuff to the output stream
    // "endl" basically adds a new line to the terminal
    cout << "enter the value you want to see the prime number of:" << endl;

    // "vector" is just a fancy term of an ArrayList (C#/Java)
    // Note: If you use "new vector," you're storing it in the heap
    // Without using "new vector," it's storing it in the stack, so we'll need to define the size
    // in compile time.
    vector<int> arr;
    int num;
    cin >> num; // Gets the input from the terminal
    arr.resize(1000000); // Resizes the array's size to a million
    sieve(arr); // "sieve" is the function we created above the main function

    // auto is auto typecasting the value to what we added (ex: `0` would be int, and `"<content>"` would be a string without annotating it yourself)
    auto c = 0;
    for (int idx = 0; idx < arr.size(); idx++) {
        auto value = arr[idx];
        if (value == 0) {
            c++;
            if (c == num) {
                cout << idx + 2 << " is the prime we needed!" << endl;
                break;
            }
        }
    }

    return 0;
}