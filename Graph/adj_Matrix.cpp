#include <iostream>

#include <bits/stdc++.h>

using namespace std;



int main()

{

    int vertices = 5, edges = 7;

    

    int **adjMatrix = new int*[5];



    for (int i = 0; i < vertices; i++)

    {

        adjMatrix[i] = new int[5];

    }



    for (int i = 0; i < vertices; i++)

    {

        for (int j = 0; j < vertices; j++)

        {

            adjMatrix[i][j] = 0;

        }

    }

   

// memset(adjMatrix, 0, sizeof(int) * vertices * vertices);

    

    int u = 0, v = 0;



    for (int i = 1; i <= edges; i++)    

    {

        cin >> u >> v;

        adjMatrix[u][v] = 1;

        adjMatrix[v][u] = 1;

    }



    for (int i = 0; i < vertices; i++)

    {

        cout << "Nodes which are connected with " << i << " Node are : " << endl;

        

        for (int j = 0; j < vertices; j++)

        {

            if (adjMatrix[i][j] == 1)

            {

                cout << j << " "; 

            }

        }

        

        cout << endl;

    }



    return 0;

}