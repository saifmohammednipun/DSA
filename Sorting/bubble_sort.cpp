#include <iostream>
using namespace std;

#define SIZE 6

int main()
{

    int myArray[SIZE] = {50, 12, 65, -5, 10,-8};
    int temp = 0;
    
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE-i; j++)
        {
            if(myArray[j]>myArray[j+1])
            {
                temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        }

    }

for(int i; i<SIZE; i++)
     cout<< myArray[i] << " ";

    
    

    return 0;
}



// #include <iostream>
// using namespace std;

// #define SIZE 6

// int main() {

// 	int myArray[SIZE] = {50, 12, 65, -5, 10, -8};
// 	int temp;
	
//     for(int i=0; i<SIZE; i++)
//     { 
// 		for(int j=0; j<SIZE-i; j++)
//         { 
// 			if(myArray[j] > myArray[j+1]){
// 				temp = myArray[j];
// 				myArray[j] = myArray[j+1];
// 				myArray[j+1] = temp;
// 			}

// 		 } 
//         }
	
// 	for(int i=0; i<SIZE; i++)
// 		cout << myArray[i] << " ";
	
// 	return 0;
// }