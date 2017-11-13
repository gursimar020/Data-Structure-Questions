#include <iostream>

#include <vector>

using namespace std;



int main()

{

    int vertices = 5, edges = 7;

    

    int u, v;

    vector <int> adj_list[vertices];



    for (int i = 1; i <= edges; i++)

    {

        cin >> u >> v;



        adj_list[u].push_back(v);

        adj_list[v].push_back(u);

    }

   

    cout << endl;

 

    for (int i = 0; i < vertices; i++)

    {

        cout << "adjaceny list for vertex " << i << " : ";

        

        for (int j = 0; j < adj_list[i].size(); j++)

        {

            cout << adj_list[i][j];

            if (j != adj_list[i].size() - 1)

                cout << " -> ";

        }

        cout << endl;

    } 

    

    return 0;

}