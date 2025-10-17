#include <bits/stdc++.h>
using namespace std;

vector<int> s;

class Graph
{
public:
    Graph(){}

    void addVertex(int v){
        m_graph[v] = {};
    }

    void addEdge(int v1, int v2){
        m_graph[v1].push_back(v2);
        m_graph[v2].push_back(v1);
    }

    bool verifyExistance(int v){
        if(m_graph.find(v) != m_graph.end()){
            return true;
        }
        return false;
    }
    
    int getRooms(){
        int counter = 0;

        while (s.size() != 0)
        {
            int v = s.back();

            s.erase(find(s.begin(), s.end(), v));

            s.pop_back();
        }
        

        return counter;
    }

private:
    map<int, vector<int>>m_graph;
};

int main()
{
    int n, m, temp, rooms = 0, vertex, v1, v2;
    string t;
    Graph graph;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> t;
        for(int j = 0; j < m; j++)
        {
            if(t[j] == '.')
            {
                if(i != 0 && j != 0)
                {
                    vertex = i*10 + j;
                    graph.addVertex(vertex);
                    s.push_back(vertex);
                    v1 = ((i-1)*10 + j);
                    if(graph.verifyExistance(v1)){
                        graph.addEdge(v1, vertex);
                    }
                    v1 = (i*10 + j)-1;
                    if(graph.verifyExistance(v1)){
                        graph.addEdge(v1, vertex);
                    }

                }
                else if(i == 0)
                {
                    vertex = i*10 + j;
                    graph.addVertex(vertex);
                    s.push_back(vertex);
                    v1 = (i*10 + j)-1;
                    if(graph.verifyExistance(v1)){
                        graph.addEdge(v1, vertex);
                    }
                }
                else if(j == 0)
                {
                    vertex = i*10 + j;
                    graph.addVertex(vertex);
                    s.push_back(vertex);
                    v1 = ((i-1)*10 + j);
                    if(graph.verifyExistance(v1)){
                        graph.addEdge(v1, vertex);
                    }
                }
                else
                {
                    vertex = i*10 + j;
                    graph.addVertex(vertex);
                    s.push_back(vertex);
                    v1 = i*10 + j;
                    if(graph.verifyExistance(v1)){
                        graph.addEdge(v1, vertex);
                    }
                }
            }
        }
    }

    rooms = graph.getRooms();

    cout << rooms << endl;
    return 0;
}