#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph 
{ 
    int V;    // No. of vertices' 
  
    // Pointer to an array containing adjacency listsList 
    list<int> *adj; 
  
    // A function used by topologicalSort 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // prints a Topological Sort of the complete graph 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack which stores result 
    Stack.push(v); 
}

void Graph::topologicalSort(){
    stack<int> Stack;

    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;
    
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack);

    while (Stack.empty() == false) 
    { 
        cout << (char) ('a' + Stack.top()) << " "; 
        Stack.pop(); 
    }
}

int min(int x, int y) 
{ 
    return (x < y)? x : y; 
}

void printOrder(string words[], int n, int alpha){
    Graph g(alpha);

    for(int i=0;i<n-1;i++){
        string word1 = words[i], word2 = words[i+1];

        for (int j = 0; j < min(word1.length(), word2.length()); j++){
            // If we find a mismatching character, then add an edge 
            // from character of word1 to that of word2 
            if (word1[j] != word2[j]) 
            { 
                g.addEdge(word1[j]-'a', word2[j]-'a'); 
                break; 
            }
        }
    }
    g.topologicalSort();
}

int main(){
    string words[] = {"caa", "aaa", "aab"}; 
    printOrder(words, 3, 3);
    cout<<endl;
    return 0;
}