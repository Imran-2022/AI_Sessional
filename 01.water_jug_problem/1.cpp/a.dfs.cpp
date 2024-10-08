//  Water Jug Problem: Write a program to solve the Water Jug problem using uninformed search methods. 

//  Implement the following search algorithms:

//  a. Depth-First Search (DFS)
//  b. Breadth-First Search (BFS)
//  c. Depth-Limited Search
//  d. Iterative Deepening Search


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define all(p) p.begin(), p.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>

// State of the two jugs
struct State {
    int x, y; // x is the amount of water in the 3-liter jug, y is the amount of water in the 5-liter jug
};

// Function to print the solution
void printState(State s) {
    cout << "(" << s.x << ", " << s.y << ")" << endl;
}

// Depth First Search function to solve the problem
bool dfs(int x, int y) {
    stack<State> s;
    set<pair<int, int>> visited; // to keep track of visited states

    // Initial state
    s.push({0, 0});
    visited.insert({0, 0});

    while (!s.empty()) {
        State current = s.top();
        s.pop();

        // Check if we have exactly 4 liters in the 5-liter jug
        if (current.y == 4) {
            cout << "Solution found:" << endl;
            printState(current);
            return true;
        }

        // Possible operations
        vector<State> nextStates = {
            {3, current.y},       // Fill 3-liter jug
            {current.x, 5},       // Fill 5-liter jug
            {0, current.y},       // Empty 3-liter jug
            {current.x, 0},       // Empty 5-liter jug
            {current.x - min(current.x, 5 - current.y), current.y + min(current.x, 5 - current.y)}, // Pour from 3 to 5
            {current.x + min(current.y, 3 - current.x), current.y - min(current.y, 3 - current.x)}  // Pour from 5 to 3
        };

        // Explore the next states
        for (State next : nextStates) {
            if (visited.find({next.x, next.y}) == visited.end()) {
                visited.insert({next.x, next.y});
                s.push(next);
                printState(next);
            }
        }
    }

    // If we reach here, no solution was found
    return false;
}

int main() {
    if (!dfs(0, 0)) {
        cout << "No solution found." << endl;
    }
    return 0;
}
