#include <iostream>
#include <vetor>
using namespace std; 

#define MAX 50 

// Function to shift the matrix 
// in the given direction 
void moveMatrix(char d[], int n, 
				int a[MAX][MAX]) 
{ 

	// For right shift move. 
	if (d[0] == 'r') { 

		// for each row from 
		// top to bottom 
		for (int i = 0; i < n; i++) { 
			vector<int> v, w; 
			int j; 

			// for each element of 
			// row from right to left 
			for (j = n - 1; j >= 0; j--) { 
				// if not 0 
				if (a[i][j]) 
					v.push_back(a[i][j]); 
			} 

			// for each temporary array 
			for (j = 0; j < v.size(); j++) { 
				// if two element have same 
				// value at consecutive position. 
				if (j < v.size() - 1 && v[j] == v[j + 1]) { 
					// insert only one element 
					// as sum of two same element. 
					w.push_back(2 * v[j]); 
					j++; 
				} 
				else
					w.push_back(v[j]); 
			} 

			// filling the each row element to 0. 
			for (j = 0; j < n; j++) 
				a[i][j] = 0; 

			j = n - 1; 

			// Copying the temporary 
			// array to the current row. 
			for (auto it = w.begin(); 
				it != w.end(); it++) 
				a[i][j--] = *it; 
		} 
	} 

	// for left shift move 
	else if (d[0] == 'l') { 

		// for each row 
		for (int i = 0; i < n; i++) { 
			vector<int> v, w; 
			int j; 

			// for each element of the 
			// row from left to right 
			for (j = 0; j < n; j++) { 
				// if not 0 
				if (a[i][j]) 
					v.push_back(a[i][j]); 
			} 

			// for each temporary array 
			for (j = 0; j < v.size(); j++) { 
				// if two element have same 
				// value at consecutive position. 
				if (j < v.size() - 1 && v[j] == v[j + 1]) { 
					// insert only one element 
					// as sum of two same element. 
					w.push_back(2 * v[j]); 
					j++; 
				} 
				else
					w.push_back(v[j]); 
			} 

			// filling the each row element to 0. 
			for (j = 0; j < n; j++) 
				a[i][j] = 0; 

			j = 0; 

			for (auto it = w.begin(); 
				it != w.end(); it++) 
				a[i][j++] = *it; 
		} 
	} 

	// for down shift move. 
	else if (d[0] == 'd') { 
		// for each column 
		for (int i = 0; i < n; i++) { 
			vector<int> v, w; 
			int j; 

			// for each element of 
			// column from bottom to top 
			for (j = n - 1; j >= 0; j--) { 
				// if not 0 
				if (a[j][i]) 
					v.push_back(a[j][i]); 
			} 

			// for each temporary array 
			for (j = 0; j < v.size(); j++) { 

				// if two element have same 
				// value at consecutive position. 
				if (j < v.size() - 1 && v[j] == v[j + 1]) { 
					// insert only one element 
					// as sum of two same element. 
					w.push_back(2 * v[j]); 
					j++; 
				} 
				else
					w.push_back(v[j]); 
			} 

			// filling the each column element to 0. 
			for (j = 0; j < n; j++) 
				a[j][i] = 0; 

			j = n - 1; 

			// Copying the temporary array 
			// to the current column 
			for (auto it = w.begin(); 
				it != w.end(); it++) 
				a[j--][i] = *it; 
		} 
	} 

	// for up shift move 
	else if (d[0] == 'u') { 
		// for each column 
		for (int i = 0; i < n; i++) { 
			vector<int> v, w; 
			int j; 

			// for each element of column 
			// from top to bottom 
			for (j = 0; j < n; j++) { 
				// if not 0 
				if (a[j][i]) 
					v.push_back(a[j][i]); 
			} 

			// for each temporary array 
			for (j = 0; j < v.size(); j++) { 
				// if two element have same 
				// value at consecutive position. 
				if (j < v.size() - 1 && v[j] == v[j + 1]) { 
					// insert only one element 
					// as sum of two same element. 
					w.push_back(2 * v[j]); 
					j++; 
				} 
				else
					w.push_back(v[j]); 
			} 

			// filling the each column element to 0. 
			for (j = 0; j < n; j++) 
				a[j][i] = 0; 

			j = 0; 

			// Copying the temporary array 
			// to the current column 
			for (auto it = w.begin(); 
				it != w.end(); it++) 
				a[j++][i] = *it; 
		} 
	} 
} 

int main() 
{ 
	char d[2] = "l"; 
	int n = 5; 
	int a[MAX][MAX] = { { 32, 3, 3, 3, 3 }, 
						{ 0, 0, 1, 0, 0 }, 
						{ 10, 10, 8, 1, 2 }, 
						{ 0, 0, 0, 0, 1 }, 
						{ 4, 5, 6, 7, 8 } }; 

	moveMatrix(d, n, a); 

	// Printing the final array 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) 
			cout << a[i][j] << " "; 

		cout << endl; 
	} 

	return 0; 
} 
