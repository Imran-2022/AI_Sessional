//  Water Jug Problem: Write a program to solve the Water Jug problem using uninformed search methods. 

//  Implement the following search algorithms:

//  a. Depth-First Search (DFS)
//  b. Breadth-First Search (BFS)
//  c. Depth-Limited Search
//  d. Iterative Deepening Search

#include <bits/stdc++.h>
using namespace std;

// State representing the amount of water in the 3-liter and 5-liter jugs
struct State {
    int x, y; // x is the amount in the 3-liter jug, y is the amount in the 5-liter jug
};

// Function to print the solution steps
void printState(State s) {
    cout << "(" << s.x << ", " << s.y << ")" << endl;
}

// BFS function to solve the water jug problem
bool bfs() {
    queue<State> q;
    set<pair<int, int>> visited; // To track visited states

    // Start from the initial state (0, 0)
    q.push({0, 0});
    visited.insert({0, 0});

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // Print the current state
        printState(current);

        // Check if the current state contains 4 liters in the 5-liter jug
        if (current.y == 4) {
            cout << "Solution found:" << endl;
            printState(current);
            return true;
        }

        // Generate all possible next states
        vector<State> nextStates = {
            {3, current.y},       // Fill the 3-liter jug
            {current.x, 5},       // Fill the 5-liter jug
            {0, current.y},       // Empty the 3-liter jug
            {current.x, 0},       // Empty the 5-liter jug
            {current.x - min(current.x, 5 - current.y), current.y + min(current.x, 5 - current.y)}, // Pour from 3 to 5
            {current.x + min(current.y, 3 - current.x), current.y - min(current.y, 3 - current.x)}  // Pour from 5 to 3
        };

        // Process each next state
        for (State next : nextStates) {
            // If the state is not visited, add it to the queue and mark as visited
            if (visited.find({next.x, next.y}) == visited.end()) {
                visited.insert({next.x, next.y});
                q.push(next);
            }
        }
    }

    // If no solution found
    return false;
}

int main() {
    if (!bfs()) {
        cout << "No solution found." << endl;
    }
    return 0;
}
