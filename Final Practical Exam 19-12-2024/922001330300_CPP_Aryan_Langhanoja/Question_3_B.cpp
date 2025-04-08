#include <bits/stdc++.h>
using namespace std;

int findCutVertex (vector<vector<int>> &graph, int node) {
	int min_degree = INT_MAX ;
	int cut_vertices = -1 ;
	
	for(int i = 0 ; i < node ; i++) {
		int curr_degree = 0 ;
		
		for(int j = 0 ; j < node ; j++) {
			if(graph[i][j] != 9999 && graph[i][j] != 0) {
				curr_degree++;
			}
		}
		
		if(curr_degree < min_degree) {
			cut_vertices = i ;
		}
	}
	
	return cut_vertices;
}


int main()
{
    int node;

    cout << "Enter The Number of Nodes :- ";
    cin >> node;

    vector<vector<int>> graph(node, vector<int>(node, 9999));

    cout << "Enter The Adjacency Matrix :- " << endl;

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << "Enter The Edge from " << i << " to " << j << " (9999 for no edge) :- ";
            cin >> graph[i][j];
        }
    }

    int cut_vertices = findCutVertex(graph, node);
    
    if(cut_vertices != -1) {
    	cout << "The Cut Vertex Is " << cut_vertices << endl ;
	}
	
	else {
		cout << "All Vertex Having the Strong Connectiveity." << endl ;
	}

    return 0;
}
