# HW9: Graph Dynamic Programming & Exhaustive Search

The goal of this homework is to better understand graph algorithms that use Dynamic Programming and practice writing code using Exhaustive Search/Backtracking. This assignment is due on April 25 at 11:59pm.

### Submitting & Grading
In order to submit this assignment, you must download your code as a ZIP file and upload it to Gradescope. Please include all files.

Your grade on this homework will be out of 21 points:
- Autograder (6 points)
- Non-Autograder Questions (9 points)
- LeetCode (3 points)
- Documentation (2 points)
- Code Style (1 point)

### Corrections
If you miss points on this assignment, there will be an opportunity to earn up to half back by doing homework corrections, so don't worry about the grade if you're having a tough time on some of the questions.


## Q1. Bellman-Ford Analysis (4 points)

Unlike Dijkstra's, Bellman-Ford finds the Single-Source Shortest Path (SSSP) even if there are negative edge weights. Given the following pseudocode for Bellman-Ford, answer the questions below.

```
algorithm Bellman-Ford(G, s)
  Input:
    Graph G = (V, E) with weights l(u, v) for each (u, v) in E
    Starting node s
  Output:
    array dist, where dist[u] is the shortest paths from s to u
    array prev, where prev[u] is the node before u along the shortest path

0   for each vertex v in G
1     dist[v] = inf
2     prev[v] = null
3   dist[s] = 0
4
5   Repeat |V| - 1 times
6     for each edge (u, v) in E
7       temp = dist[u] + l(u, v)
8       if temp < dist[v]
9         dist[v] = temp
10        prev[v] = u
11
12  for each edge (u, v) in G
13   if dist[u] + l(u, v) < dist[v]
14     throw error("Negative Cycle Exists")
15
16  return dist, prev
```

**Q1.A (2 points)** Explain in a few sentences why we have to relax all edges |V| - 1 times (i.e. where does |V| - 1 come from in line 5?).
Then, explain how we could make this algorithm more efficient if we were only interested in paths from s to u that were at most T edges long.

**Q1.B (2 points)** Explain why the last for loop in the pseudocode can detect a negative cycle in the graph. Recall that a negative cycle is a cycle within the graph whose net total weight is negative.


## Q2. Floyd-Warshall Analysis (5 points)
Floyd-Warshall is an algorithm to efficiently find the shortest paths between **every single pair of vertices** in a graph. Instead of solving the Single-Source Shortest Path (SSSP) problem like Dijkstra and Bellman-Ford, this approach solves the All-Pairs Shortest Path (APSP) problem.

Use the dynamic programming outline for Floyd-Warshall to answer the questions below.

*Floyd-Warshall Dynamic Programming Outline:*
- *(1) Subproblem*
  - `DP[k][u][v] = the weight of the best path from vertex u to vertex v with access of any of u, v, and the vertices labeled 1...k along the way`
  - Note: we label each vertex with 1, 2, 3 ... n before we start working with the graph.
- *(2) Relating Subproblems*
  - `DP[k][u][v] = min(DP[k-1][u][v], DP[k-1][u][k] + DP[k-1][k][v])`
  - Base cases: `DP[0][u][v] = edge weight from u to v (if it exists, otherwise inf)`
- *(3) Order of Solving Bottom-Up*
  - For each k = 1...n, create a new adjacency matrix and solve for every u-v pair
- *(4) Final Answer*
  - Return 2d DP matrix at k = n (i.e. DP[n])

**Q2.A (1 point)** Describe in a few sentences why the 2D matrix at k = n (i.e. DP[n]) returned in step 4 is the solution to APSP by referencing step 1.

**Q2.B (2 points)** Describe in a few sentences what the two choices we are taking the minimum over in step 2 are.

**Q2.C (2 points)** How many subproblems does Floyd-Warshall have? What is the time per subproblem? Use this to calculate the time complexity.


## Q3. findAllPermutations (6 points)
Mathematically, a permutation of a vector is an arrangement or rearrangement of its elements into a sequence. For example, for the vector `{1, 2, 3}`, valid permutations include `{2, 3, 1}` and `{1, 3, 2}`; of course, `{1, 2, 3}` itself is also a valid permutation.

You may know from Discrete Math that there are `3! = 6` permutations for the vector `{1, 2, 3}`, which are, in lexicographic order,
```
{1, 2, 3}
{1, 3, 2}
{2, 1, 3}
{2, 3, 1}
{3, 1, 2}
{3, 2, 1}
```
Implement the function `findAllPermutations` in `HW9.cpp` which takes a parameter `N` and returns all permutations of the vector `{1, 2, ..., N}` in lexicographic order.

For the purpose of this exercise, you may not use `std::next_permutation` or `std::prev_permutation` in `<algorithm>`. Instead, you must use the exhaustive search strategies we covered in lecture (with a helper which chooses, explores, then unchooses). We've provided some starter code in `HW9.cpp` (with a helper for you to fill in), though you may modify it as long as you do not modify the `HW9.h` file.


## Q4. LeetCode: Letter Combinations of a Phone Number (3 points)


Problem: [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

**Q4.A** Provide one set of expected inputs and outputs that is not provided to be sure you understand the question in `Q4.txt`.

**Q4.B** Describe your approach in words in `Q4.txt`. Then, solve the problem. After clicking "Submit" and getting status "Accepted", take a screenshot of the entire window (with the time submitted and your code). Attach the complete and successful screenshot as an image named `Q4.jpg` in your code submissions. You must use a recursive helper as done in class. You may use the letterMapping below.
```
        unordered_map<char, vector<char>> letterMapping({
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        });
```

**Optional:** A classic Exhaustive Search problem, which is a LeetCode Hard that you may submit for LeetCode extra credit, is [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/).

## Q5. Feedback (Not Graded)
Your responses to these questions will not affect your grade. They help improve or adjust homework assignments or lecture material in the future.

Q5.A Approximately how much time (in hours) did you spend on this homework?

Q5.B Which problem was the most difficult? Any other thoughts?
