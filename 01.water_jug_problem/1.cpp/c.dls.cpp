//  Water Jug Problem: Write a program to solve the Water Jug problem using uninformed search methods. 

//  Implement the following search algorithms:

//  a. Depth-First Search (DFS)
//  b. Breadth-First Search (BFS)
//  c. Depth-Limited Search
//  d. Iterative Deepening Search


#include <bits/stdc++.h>
using namespace std;

// State representing the amount of water in the 3-liter zand 5-liter jugs
struct State {
    int x, y; // x is the amount in the 3-liter jug, y is the amount in the 5-liter jug
};

// Function to print the state
void printState(State s) {
    cout << "(" << s.x << ", " << s.y << ")" << endl;
}

// Depth-Limited Search function
bool depthLimitedSearch(State current, int depth, int limit, set<pair<int, int>>& visited) {
    // If the current state is the goal (i.e., 4 liters in the 5-liter jug)

      // Print the current state
        printState(current);
        
    if (current.y == 4) {
        cout << "Solution found:" << endl;
        printState(current);
        return true;
    }

    // If the maximum depth limit is reached, stop searching further
    if (depth >= limit) {
        return false;
    }

    // Mark the current state as visited
    visited.insert({current.x, current.y});

    // Possible next states
    vector<State> nextStates = {
        {3, current.y},       // Fill the 3-liter jug
        {current.x, 5},       // Fill the 5-liter jug
        {0, current.y},       // Empty the 3-liter jug
        {current.x, 0},       // Empty the 5-liter jug
        {current.x - min(current.x, 5 - current.y), current.y + min(current.x, 5 - current.y)}, // Pour from 3 to 5
        {current.x + min(current.y, 3 - current.x), current.y - min(current.y, 3 - current.x)}  // Pour from 5 to 3
    };

    // Explore each possible state
    for (State next : nextStates) {
        // If the next state is not visited, explore it recursively
        if (visited.find({next.x, next.y}) == visited.end()) {
            if (depthLimitedSearch(next, depth + 1, limit, visited)) {
                return true;
            }
        }
    }

    // If no solution found at this depth
    return false;
}

int main() {
    int depthLimit = 10; // You can adjust this limit based on the problem complexity

    // Start from the initial state (0, 0)
    State initialState = {0, 0};
    set<pair<int, int>> visited;

    if (!depthLimitedSearch(initialState, 0, depthLimit, visited)) {
        cout << "No solution found within the depth limit." << endl;
    }

    return 0;
}
