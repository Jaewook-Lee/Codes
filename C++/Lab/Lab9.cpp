#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Node
{
    int data;
    Node *link;
    public:
        Node() {};
        Node (int n) : link(0) { data = n; }
};

class Graph
{
    private:
        Node **array; // An array of Node pointers
    public:
        int size;
        Graph() {}
        Graph(int n)
        {
            size = n;
            array = new Node*[n];
            for (int i=0; i<size; i++) { *(array + i) = 0; } // Initialize all of elements to null
        }
        ~Graph() { delete array; }
        void addEdge(int start, int end)
        {
            Node *start_vertex = new Node(start);
            Node *end_vertex = new Node(end);
            start_vertex->link = end_vertex;

            if (array[start] == 0) array[start] = start_vertex; // If array's element is null, update new data.
            else // Linking end_vertex right after existing end_vertex in array.
            {
                Node *temp = array[start];
                while (temp->link != 0) temp = temp->link;
                temp->link = end_vertex;
            }
        }
        void printGraph()
        {
            for (int i=0; i<size; i++)
            {
                cout << "Vertex " << i << ": ";
                Node *printed = array[i]->link;
                while (printed != 0)
                {
                    cout << printed->data;
                    if (printed->link!= 0) cout << "->";

                    printed = printed->link;
                }
                cout << endl;
            }
        }
        void dfs(bool *visited, int start_vertex=0) 
        {
            *(visited + start_vertex) = true;
            cout << "Vertex " << start_vertex << "->";
        }
};

void makeGraph(string, Graph&);
int main()
{
    Graph g;
    makeGraph("lab9.dat", g); // Data is looks like a two-dimensional array.

    g.printGraph();

    bool visited[g.size] = {false};
    //g.dfs(visited);
    return 0;
}

void makeGraph(const string file_name, Graph &graph)
{
    const int BUFFER_SIZE = 100;
    ifstream reader;
    reader.open(file_name);

    char buffer[BUFFER_SIZE];
    int row_size = 0; // For making a graph by using size.
    int vertex_number = 0; // Initialized start vertex's number.
    while (!reader.eof())
    {
        reader.getline(buffer, BUFFER_SIZE);
        if (reader.eof()) break;

        if (row_size == 0) // Call constructor of graph
        {
            for (int i=0; i<strlen(buffer); i++)
            {
                if (buffer[i] == ' ') continue;
                else row_size++;
            }
            graph = Graph(row_size);
        }

        for (int i=0; i<strlen(buffer); i++)
        {
            if (buffer[i] == ' ') continue;
            if (buffer[i] - '0' == 1) graph.addEdge(vertex_number, i/2);
        }

        vertex_number++;
    }
    reader.close();
}