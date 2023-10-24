#include <iostream>
#include <string>
using namespace std;

class StringReverser{
	private:
    string inputString;
	public:
    StringReverser(const string input){
		inputString = input; 
	}

    string reverse() {
        string reversedString;
        
        for (int i = inputString.length() - 1; i >= 0; i--) {
            reversedString += inputString[i];
        }

        return reversedString;
    }


};

int main(){
    string input;
    cout << "Enter a string: ";
    cin >> input;

    StringReverser reverser(input);
    string reversed = reverser.reverse();

    cout << "Reversed string: " << reversed << endl;

    return 0;
}

