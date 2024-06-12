#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    // Adjacency list to represent the graph (city connections)
    vector<vector<int>> adj(n + 1);
    // Build the adjacency list from the given city connections
    for (size_t i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // Visited flag to keep track of explored nodes in the graph
    vector<bool> visited(n + 1, false);

    // Distance from the starting node to each node in the graph
    vector<int> distance(n + 1, -1);

    // Use a queue for iterative Breadth-First Search (BFS) traversal
    queue<int> q;
    q.push(s);         // Push the starting node onto the queue
    visited[s] = true; // Mark it visited
    distance[s] = 0;   // Distance to itself is 0

    // While the queue is not empty
    while (!q.empty())
    {
        // Get the front node from the queue
        int node = q.front();
        q.pop();

        // Loop through the neighbors of the current node
        for (size_t i = 0; i < adj[node].size(); i++)
        {
            // Get the neighbor
            int neighbor = adj[node][i];

            // If the neighbor hasn't been visited yet
            if (!visited[neighbor])
            {
                // Mark it visited
                visited[neighbor] = true;
                // Update the distance to the neighbor
                distance[neighbor] = distance[node] + 6;
                // Push the neighbor onto the queue
                q.push(neighbor);
            }
        }
    }

    // Remove the starting node from the distance array
    distance.erase(distance.begin() + s);

    return distance;
    
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
