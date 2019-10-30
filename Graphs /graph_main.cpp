// Main program for graphs

// Graph represented by an vector<int> adj[L] or a vector of lists  


/* List of functions included. 
1. Add edge to graph 
2. Print graph contents 
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    public:
        // Constructor to initialize the graph with the number of vertices 
        Graph(int V, std::string graphType)
        {
            graphType_= graphType; 
            V_= V; 
            cout << "Initialized graph data structure" << std::endl; 
            vector<vector<int>> adjL(V);
            adjL_= adjL; 
        }

        void addEdge(int u, int v)
        {
            if(graphType_== "directed")
            {
                adjL_[u].push_back(v);
            }

            if (graphType_ == "undirected")
            {
                // Insert the same element both ways
                adjL_[u].push_back(v);
                adjL_[v].push_back(u);
            }
        }

        // A utility function to print the adjacency list 
        // representation of graph 
        void printGraph() 
        { 
            for (int v = 0; v < V_; ++v) 
            { 
                cout << "\n Adjacency list of vertex "
                    << v << "\n head "; 
                for (auto x : adjL_[v]) 
                cout << "-> " << x; 
                printf("\n"); 
            } 
        }

        // Node numbering starts from 0 
        void BFS(int sourceNode)
        {
            queue<int> q;
            bool visited[V_]= {false}; 

            // Push first node to queue
            q.push(sourceNode);
            // Mark source node as visited 
            visited[sourceNode]= true; 
            cout << "Visited vertex: " << sourceNode << endl; 

            // Variable to store the intermediate temporary vertex
            int tempVertex; 
            while(!q.empty())
            {
                tempVertex= q.front();
                // Remove given vertex from queue
                q.pop();
                // Process neighbors of given vertex 
                for (auto w:adjL_[tempVertex])
                {
                    if(!visited[w])
                    {
                        q.push(w);
                        // Mark w as visited 
                        visited[w]= true; 
                        cout << "Visited vertex: " << w << endl; 
                    }

                }
            }
        }

        void DFSMain(int sourceNode)
        {
            bool visited[V_]= {false};
            DFS(sourceNode, visited);
        }
        void DFS(int sourceNode, bool visited[])
        {
            visited[sourceNode]= true; 
            cout << "Visited vertex: " << sourceNode << endl; 

            for(auto w:adjL_[sourceNode])
            {
                if(!visited[w])
                {
                    DFS(w, visited);
                }
            }
        }

    private:
        // No. of vertices in graph
        int V_;  
        // Graph data structure represented as vector of vectors 
        vector<vector<int>> adjL_; 
        string graphType_; 
};

int main()
{
    // Create a graph with 5 vertices without any edges 
    Graph g(4, "directed");
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFSMain(2); 
    return 0; 
}



/* Notes

1. Post-order traversal - How can I use the information of the left and right sub-tree to get information of the current node I am at. 
- Termination condition is the root being NULL. 

2. Pre-order traversal- How can I compute some info for this current node and pass it down to leaf. At leaf, the decision is taken by seeing if the 'ans' has changed in any way. 
- Needs a special if loop for when we are the leaf. 

*/
