// C++ program to compute sum of digits in
// number.
#include <bits/stdc++.h>
using namespace std;

/* Function to get sum of digits */
class gfg {
public:
	int getSum(int n)
	{
		int sum = 0;
		while (n != 0) {
			sum = sum + n % 10;
			n /= 10;
		}
		return sum;
	}
};

// Driver code
int main()
{
	gfg g;
	int n = 123;

	// Function call
	cout <<"Sum of digits: " << g.getSum(n);
	return 0;
}
// This code is contributed by Soumik
