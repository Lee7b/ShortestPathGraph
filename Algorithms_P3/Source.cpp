#include<iostream>
#include<string>
#define INFINITY 99999
#define V 19
using namespace std;


void addEdge(int am[][19], int src, int dest, int cost)
{
	am[src][dest] = cost;
	return;
}

int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INFINITY, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void displayResult(int dist[], int n, int s, int parent[])
{
	//v0 = College Square
	//v1 = Prince Center
	//v2 = Lewis Science Center
	//v3 = Math-Comp Sci
	//v4 = Torreyson Library
	//v5 = Old Main
	//v6 = Police Dept.
	//v7 = Fine Art
	//v8 = McAlister Hall
	//v9 = Student Center
	//v10 = Student health Center
	//v11 = Speech Language Hearing
	//v12 = Burdick
	//v13 = Maintenance College
	//v14 = Wingo
	//v15 = New Business Building
	//v16 = Oak Tree Apt.
	//v17 = Brewer-Hegeman
	//v18 = Bear Village Apt

	printf("Vertex   Place \t \t \t Distance from Source %d \t Parent\n", s);
	for (int i = 0; i < V; i++)
	{
		string place;
		switch (i)
		{
		case 0:
			place = "College Square";
			break;
		case 1:
			place = "Prince Center";
			break;
		case 2:
			place = "Lewis Science Center";
			break;
		case 3:
			place = "Math-Comp Sci";
			break;
		case 4:
			place = "Torreyson Library";
			break;
		case 5:
			place = "Old Main";
			break;
		case 6:
			place = "Police Dept.";
			break;
		case 7:
			place = "Fine Art";
			break;
		case 8:
			place = "McAlister Hall";
			break;
		case 9:
			place = "Student Center";
			break;
		case 10:
			place = "Student Health Center";
			break;
		case 11:
			place = "Speech Language Hearing";
			break;
		case 12:
			place = "Burdick";
			break;
		case 13:
			place = "Maintenance College";
			break;
		case 14:
			place = "Wingo";
			break;
		case 15:
			place = "New Business Building";
			break;
		case 16:
			place = "Oak Tree Apt";
			break;
		case 17:
			place = "Brewer-Hegeman";
			break;
		case 18:
			place = "Bear Village";
			break;
		default:
			place = "Problem";
		}
		// max length of place is 23
		// pad the space to make it look nice
		string space;
		for (int j = place.length(); j < 23; j++)
		{
			space.append(" ");
		}
		//printf("%d \t %s \t \t %d \t \t %d\n", i, place, dist[i], parent[i]);

		if (parent[i] != -858993460)
		{
			cout << i << "\t " << place << space << " \t" << dist[i] << "\t \t \t   " << parent[i] << endl;
		}
		else
			cout << i << "\t " << place << space << " \t" << dist[i] << "\t \t \t   " << "N/A" << endl;
	}
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];     // The output array.  dist[i] will hold the shortest distance from src to i
	int parent[V]; //Array to hold the parent vertex

	bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

					// Initialize all distances as INFINITE and stpSet[] as false				
	for (int i = 0; i < V; i++)
		dist[i] = INFINITY, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;
	parent[0] = -1;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INFINITY
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v], parent[v] = u;
	}

	//Display the distances
	displayResult(dist, V, src, parent);
}

void bellman_ford(int graph[V][V], int src)
{
	int dist[V];     // The output array.  dist[i] will hold the shortest distance from src to i
	int parent[V]; //Array to hold the parent vertex

	bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

					// Initialize all distances as INFINITE and stpSet[] as false				
	for (int i = 0; i < V; i++)
		dist[i] = INFINITY, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;
	parent[0] = -1;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++)
	{
		// for V-1 times, update all the edges
		for (int v = 0; v < V; v++) //update edges with index v
		{
			for (int u = 0; u < V; u++) // update edgies with index u
			{
				if (!sptSet[v] && graph[u][v] && dist[u] != INFINITY
					&& dist[u] + graph[u][v] < dist[v])
					dist[v] = dist[u] + graph[u][v], parent[v] = u;
			}
		}
	}

	//Display the distances
	displayResult(dist, V, src, parent);
}

int main()
{
	int am[19][19], i, j;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			am[i][j] = INFINITY;
		}
	}

	//v0 = College Square
	//v1 = Prince Center
	//v2 = Lewis Science Center
	//v3 = Math-Comp Sci
	//v4 = Torreyson Library
	//v5 = Old Main
	//v6 = Police Dept.
	//v7 = Fine Art
	//v8 = McAlister Hall
	//v9 = Student Center
	//v10 = Student health Center
	//v11 = Speech Language Hearing
	//v12 = Burdick
	//v13 = Maintenance College
	//v14 = Wingo
	//v15 = New Business Building
	//v16 = Oak Tree Apt.
	//v17 = Brewer-Hegeman
	//v18 = Bear Village Apt

	//Create the graph
	addEdge(am, 0, 1, 300); //From College Square to Prince Center
	addEdge(am, 0, 2, 200); //From College Square to Lewis Science Center

	addEdge(am, 1, 0, 300); //From Prince Center to College Square
	addEdge(am, 1, 3, 80); //From Prince Center to Math-Comp Sci
	addEdge(am, 1, 4, 30); //From Prince Center to Torreyson Library
	addEdge(am, 1, 6, 100); //From Prince Center to Police Dept.

	addEdge(am, 2, 0, 200); //From Lewis Science Center to College Square
	addEdge(am, 2, 3, 150); //From Lewis Science Center to Math-Comp Sci
	addEdge(am, 2, 11, 250); //From Lewis Science Center to Speech Language Hearing

	addEdge(am, 3, 2, 150); //From Math-Comp Sci to Burdick
	addEdge(am, 3, 1, 80); //From Math-Comp Sci to Burdick
	addEdge(am, 3, 4, 40); //From Math-Comp Sci to Burdick
	addEdge(am, 3, 12, 30); //From Math-Comp Sci to Burdick

	addEdge(am, 4, 3, 40); //From Torreyson Library Math-Comp Sci
	addEdge(am, 4, 1, 30); //From Torreyson Library to Prince Center
	addEdge(am, 4, 5, 30); //From Torreyson Library to Old Main
	addEdge(am, 4, 12, 80); //From Torreyson Library to Burdick


	addEdge(am, 5, 4, 30); //From Old Main to Torreyson Library
	addEdge(am, 5, 6, 200); //From Old Main to Police Dept.
	addEdge(am, 5, 7, 90); //From Old Main to Fine Art
	addEdge(am, 5, 8, 100); //From Old Main to McAlister Hall

	addEdge(am, 6, 1, 100); //From Police Dept. to Prince Center
	addEdge(am, 6, 7, 50); //From Police Dept. to Fine Art
	addEdge(am, 6, 5, 200); //From Police Dept. to Old Main
	addEdge(am, 6, 10, 100); //From Police Dept. to Student Health Center

	addEdge(am, 7, 5, 90); //From Fine Art to Old Main
	addEdge(am, 7, 6, 50); //From Fine Art to Police Dept.
	addEdge(am, 7, 8, 180); //From Fine Art to McAlister Hall
	addEdge(am, 7, 9, 80); //From Fine Art to Student Center

	addEdge(am, 8, 5, 100); //From McAlister Hall to Old Main
	addEdge(am, 8, 7, 180); //From McAlister Hall to Fine Art
	addEdge(am, 8, 9, 100); //From McAlister Hall to Student Center
	addEdge(am, 8, 12, 200); //From McAlister Hall to Burdick
	addEdge(am, 8, 14, 50); //From McAlister Hall to Wingo
	addEdge(am, 8, 13, 150); //From McAlister Hall to Maintenance College

	addEdge(am, 9, 7, 80); //From Student Center to Fine Art
	addEdge(am, 9, 8, 100); //From Student Center to McAlister Hall
	addEdge(am, 9, 10, 50); //From Student Center to Student Health Center
	addEdge(am, 9, 14, 100); //From Student Center to Wingo
	addEdge(am, 9, 15, 110); //From Student Center to New Business Building

	addEdge(am, 10, 6, 100); //From Student Health Center to Police Dept.
	addEdge(am, 10, 9, 50); //From Student Health Center to Student Center
	addEdge(am, 10, 17, 200); //From Student Health Center to Brewer-Hegeman

	addEdge(am, 11, 2, 250); //From Speech Language Hearing to Lewis Science Center
	addEdge(am, 11, 12, 100); //From Speech Language Hearing to Burdick
	addEdge(am, 11, 13, 120); //From Speech Language Hearing to Maintenance College

	addEdge(am, 12, 3, 30); //From Burdick to Math-Comp Sci
	addEdge(am, 12, 4, 80); //From Burdick to Torreyson Library
	addEdge(am, 12, 8, 200); //From Burdick to McAlister Hall
	addEdge(am, 12, 11, 100); //From Burdick to Speech Language Hearing
	addEdge(am, 12, 13, 300); //From Burdick to Maintenance College

	addEdge(am, 13, 11, 120); //From Maintenance College to Speech Language Hearing
	addEdge(am, 13, 12, 300); //From Maintenance College to Burdick
	addEdge(am, 13, 8, 150); //From Maintenance College to McAlister Hall
	addEdge(am, 13, 14, 100); //From Maintenance College to Wingo
	addEdge(am, 13, 15, 150); //From Maintenance College to New Business Building
	addEdge(am, 13, 16, 160); //From Maintenance College to Oak Tree Apt

	addEdge(am, 14, 8, 50); //From Wingo to McAlister Hall
	addEdge(am, 14, 9, 100); //From Wingo to Student Center
	addEdge(am, 14, 15, 50); //From Wingo to New Business Building
	addEdge(am, 14, 13, 100); //From Wingo to Maintenance College

	addEdge(am, 15, 9, 110); //From New Business Building to Student Center
	addEdge(am, 15, 14, 50); //From New Business Building to Wingo
	addEdge(am, 15, 13, 150); //From New Business Building to Maintenance College
	addEdge(am, 15, 16, 30); //From New Business Building to Oak Tree Apt
	addEdge(am, 15, 17, 20); //From New Business Building to Brewer-Hegeman

	addEdge(am, 16, 13, 160); //From Oak Tree Apt to Maintenance College
	addEdge(am, 16, 15, 30); //From Oak Tree Apt to New Business Building
	addEdge(am, 16, 17, 40); //From Oak Tree Apt to Brewer-Hegeman

	addEdge(am, 17, 10, 200); //From Brewer-Hegeman to Student Health Center
	addEdge(am, 17, 15, 20); //From Brewer-Hegeman to New Business Building
	addEdge(am, 17, 16, 40); //From Brewer-Hegeman to Oak Tree Apt
	addEdge(am, 17, 18, 350); //From Brewer-Hegeman to Bear Village Apt


	addEdge(am, 18, 17, 350); //From Bear Village Apt to Brewer-Hegeman


	cout << endl << "Dijkstra" << endl;
	dijkstra(am, 3);
	system("pause");

	cout << endl << "Bellman-Ford" << endl;
	bellman_ford(am, 3);
	system("pause");

	return 0;
}