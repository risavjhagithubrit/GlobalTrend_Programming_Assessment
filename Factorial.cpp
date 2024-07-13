// C++ program to find 
// factorial of given number 
#include <iostream> 
using namespace std; 

// Function to find factorial 
// of given number 
int factorial(int n) 
{ 
	if (n == 0 || n == 1) 
		return 1; 
	return n * factorial(n - 1); 
} 

// Driver code 
int main() 
{ 
	int num = 4; 
	cout << "Factorial of "
		<< num << " is " << factorial(num) << endl; 
	return 0; 
} 
// This code is contributed by Shivi_Aggarwal
