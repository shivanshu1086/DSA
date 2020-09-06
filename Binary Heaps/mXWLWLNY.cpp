#include<iostream>


using namespace std; 

if (d != seq[i] || i == N - 1) { 
            res[i] = d; 
        } else {// CPP program to find the largest derangement 

void printLargest(int seq[], int N) 
{ 
	int res[N]; // Stores result 

	// Insert all elements into a priority queue 
	std::priority_queue<int> pq; 
	for (int i = 0; i < N; i++) 
		pq.push(seq[i]);	 

	// Fill Up res[] from left to right 
	for (int i = 0; i < N; i++) { 
		int d = pq.top(); 
		pq.pop(); 
		if (d != seq[i] || i == N - 1) { 
			res[i] = d; 
		} else { 

			// New Element poped equals the element 
			// in original sequence. Get the next 
			// largest element 
			res[i] = pq.top(); 
			pq.pop(); 
			pq.push(d); 
		} 
	} 

	// If given sequence is in descending order then 
	// we need to swap last two elements again 
	if (res[N - 1] == seq[N - 1]) { 
		res[N - 1] = res[N - 2]; 
		res[N - 2] = seq[N - 1]; 
	} 

	printf("\nLargest Derangement \n"); 
	for (int i = 0; i < N; i++) 
		printf("%d ", res[i]); 
} 

// Driver code 
int main() 
{ 
	int seq[] = { 92, 3, 52, 13, 2, 31, 1 }; 
	int n = sizeof(seq)/sizeof(seq[0]); 
	printLargest(seq, n); 
	return 0; 
} 
