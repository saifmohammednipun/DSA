#include <iostream>
using namespace std;
  
void Tower(int n, char source, char destination, char auxilary)
{
    // base case
    if (n == 1)
    {
        cout << "Move 1 from " << source << " to " << destination << endl;
        return;
    }

    // recursive case
    else 
    {
        // move n-1 disks from source to auxilary
        Tower(n - 1, source, destination, auxilary); 
        cout << "Move " << n << " from " << source << " to " << auxilary << endl;

        // move n-1 disks from auxilary to destination
        Tower(n - 1, auxilary, source, destination);
        cout << "Move " << n << " from " << auxilary << " to " << destination << endl;
    }
}

int main()
{
    int n = 3;
    Tower(n, 'A', 'C', 'B');
}