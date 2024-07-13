// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// Function that checks whether
// the string is in alphabetical
// order or not
bool isAlphabaticOrder(string s)
{
	// length of the string
	int n = s.length();

	// create a character array
	// of the length of the string
	char c[n];

	// assign the string
	// to character array
	for (int i = 0; i < n; i++) {
		c[i] = s[i];
	}

	// sort the character array
	sort(c, c + n);

	// check if the character array
	// is equal to the string or not
	for (int i = 0; i < n; i++)
		if (c[i] != s[i]) 
			return false;
		
	return true; 
}

// Driver code
int main()
{
	string s = "aabbbcc";

	// check whether the string is
	// in alphabetical order or not
	if (isAlphabaticOrder(s))
	cout << "true";
	else
	cout << "false";

	return 0;
}
