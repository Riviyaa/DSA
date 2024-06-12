#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
    // Check if building libraries is cheaper than building roads
    if (c_lib <= c_road)
    {
        // If so, return the cost of building libraries in every city
        return (long)n * (long)c_lib;
    }
    else
    {
        // Otherwise, perform graph processing to find connected components

        // Adjacency list to represent the graph (city connections)
        vector<vector<int>> adj(n + 1);
        // Build the adjacency list from the given city connections
        for (size_t i = 0; i < cities.size(); i++)
        {
            adj[cities[i][0]].push_back(cities[i][1]);
            adj[cities[i][1]].push_back(cities[i][0]);
        }

        // Visited flag to keep track of explored nodes in the graph
        vector<bool> visited(n + 1, false);

        // Total cost to build libraries and roads
        long cost = 0;

        // Loop through each city (potential starting point of a connected component)
        for (int i = 1; i <= n; i++)
        {
            // If the city hasn't been visited yet (part of a new connected component)
            if (!visited[i])
            {
                // Count the number of nodes in the current connected component
                long componentSize = 0;

                // Use a stack for iterative Depth-First Search (DFS) traversal
                stack<int> s;
                s.push(i);         // Push the starting node onto the stack
                visited[i] = true; // Mark it visited

                // While there are unvisited nodes in the stack
                while (!s.empty())
                {
                    // Pop the current node from the stack
                    int node = s.top();
                    s.pop();

                    // Increment the component size (one more visited node)
                    componentSize++;

                    // Loop through the neighbors of the current node
                    for (size_t j = 0; j < adj[node].size(); j++)
                    {
                        // If a neighbor hasn't been visited yet
                        if (!visited[adj[node][j]])
                        {
                            // Push the neighbor onto the stack for further exploration
                            s.push(adj[node][j]);
                            // Mark the neighbor as visited
                            visited[adj[node][j]] = true;
                        }
                    }
                }

                // Calculate the cost for the current connected component:
                // cost of library + cost of roads (connecting all nodes)
                cost += c_lib + (componentSize - 1) * c_road;
            }
        }
        return cost;
    }
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++)
        {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++)
            {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        cout << result << "\n";
    }

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
