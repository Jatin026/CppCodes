// A C++ Program to generate test cases for
// an unweighted undirected graph
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 1

// Define the maximum number of vertices of the graph
#define MAX_VERTICES 10

// Define the maximum number of edges
#define MAX_EDGES 10
ofstream out("in.txt");
int main()
{
	set<pair<int, int>> container;
	set<pair<int, int>>::iterator it;

	// Uncomment the below line to store
	// the test data in a file
 

	// For random values every time
	srand(time(NULL));

	ll NUM; // Number of Vertices
	ll NUMEDGE; // Number of Edges
    ll NUMEDGE2; 
    
	for (int i=1; i<=RUN; i++)
	{
		NUM = 1 + rand() % MAX_VERTICES;

		// // Define the maximum number of edges of the graph
		// // Since the most dense graph can have N*(N-1)/2 edges
		// // where N = number of vertices in the graph
		NUMEDGE = 1 + rand() % MAX_EDGES;
		NUMEDGE2 = 1 + rand() % MAX_EDGES;
		while (NUMEDGE > NUM*(NUM-1)/2)
		NUMEDGE = 1 + rand() % MAX_EDGES;
		while (NUMEDGE2 > NUM*(NUM-1)/2)
		NUMEDGE2 = 1 + rand() % MAX_EDGES;
		// First print the number of vertices and edges
		out<<NUM<<" "<<NUMEDGE<<" "<<NUMEDGE2<<"\n";

		// Then print the edges of the form (a b)
		// where 'a' is connected to 'b'
		for (int j=1; j<=NUMEDGE; j++)
		{
			int a = rand() % NUM;
			int b = rand() % NUM;
			pair<int, int> p = make_pair(a, b);
			pair<int, int> reverse_p = make_pair(b, a);

			// Search for a random "new" edge everytime
			// Note - In a tree the edge (a, b) is same
			// as the edge (b, a)
			while (container.find(p) != container.end() ||
					container.find(reverse_p) != container.end())
			{
				a = rand() % NUM;
			 
				b = rand() % NUM;
				 
				p = make_pair(a, b);
				reverse_p = make_pair(b, a);
			}
			container.insert(p);
		}

		for (it=container.begin(); it!=container.end(); ++it){
			out<<max(it->first,1)<<" "<<max(it->second,1)<<"\n";
		}
		container.clear();
	 
		for (int j=1; j<=NUMEDGE2; j++)
		{
			int a = rand() % NUM;
			int b = rand() % NUM;
			pair<int, int> p = make_pair(a, b);
			pair<int, int> reverse_p = make_pair(b, a);

			// Search for a random "new" edge everytime
			// Note - In a tree the edge (a, b) is same
			// as the edge (b, a)
			while (container.find(p) != container.end() ||
					container.find(reverse_p) != container.end())
			{
				a = rand() % NUM;
				b = rand() % NUM;
				p = make_pair(a, b);
				reverse_p = make_pair(b, a);
			}
			container.insert(p);
		}

		for (it=container.begin(); it!=container.end(); ++it)
			out<<max(it->first,1)<<" "<<max(it->second,1)<<"\n";

		container.clear();
		out<<"\n";
	}

	// // Uncomment the below line to store
	// // the test data in a file
	// fclose(stdout);
	return(0);
}
