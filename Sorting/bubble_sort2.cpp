#include <iostream>
using namespace std;

#define SIZE 6

int main() {
	// your code goes here
	int myArray[SIZE] = {50, 12, 65, -5, 10, -8};
	int temp;
	int counter = 0;
	for(int i=0; i<SIZE-1; i++)
    { // passes
		cout << "Pass: " << i << endl;
		for(int j=0; j<SIZE-1-i; j++)
        { // inner loop for comparison
			if(myArray[j] > myArray[j+1]){
				counter++;
				temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
			}
			for(int k=0; k<SIZE; k++)
				cout << myArray[k] << " ";
			cout << endl;
		} // inner loop ends
	} // outer loops ends
	
	cout << "Final Output " << endl;
	for(int i=0; i<SIZE; i++)
		cout << myArray[i] << " ";
	cout << endl;
	
	cout << "Number of swappings: " << counter << endl;
	
	
	return 0;
}