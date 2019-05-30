#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void initGraph(const string, int(*)[6], int);
void shortestPath(const int(*)[6], int, int=0);
int minDistance(const int*, bool*, int);
int main()
{
    int cost_graph[6][6];
    initGraph("shortest_path_ex_input.dat", cost_graph, 6);
    shortestPath(cost_graph, 6, 5);
    return 0;
}

void initGraph(const string f_name, int (*arr)[6], int size)
{
    ifstream reader;
    reader.open(f_name);
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            int cost;
            reader >> cost;
            *(*(arr + i) + j) = cost;
        }
    }
    reader.close();
}

void shortestPath(const int (*cost)[6], int size, int start)
{
    bool found[size];
    int distance[size];
    for (int i=0; i<size; i++)
    {
        found[i] = false;
        distance[i] = *(*(cost + start) + i);
    }
    found[start] = true;
    distance[start] = 0;

    for (int i=0; i<size-1; i++)
    {
        int min_idx = minDistance(distance, found, size);
        found[min_idx] = true;
        for (int j=0; j<size; j++)
        {
            if (!found[j])
            {
                if (distance[min_idx] + *(*(cost + min_idx) + j) < distance[j])
                {
                    distance[j] = distance[min_idx] + *(*(cost + min_idx) + j);
                }
            }
        }
    }

    cout << "Distance -> ";
    for (int j=0; j<size; j++)
    {
        cout << distance[j] << " ";
    }
    cout << endl;
}

int minDistance(const int* distance, bool* found, int size)
{
    int min = 999;
    int min_idx;
    for (int i=0; i<size; i++)
    {
        if (*(distance + i) < min && !(*(found + i)))
        {
            min = *(distance + i);
            min_idx = i;
        }
    }

    return min_idx;
}