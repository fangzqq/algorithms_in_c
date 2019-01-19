
abstraction layers

Developing ever more powerful layers of abstraction is an essential process in computer science in general and in algorithm design in particular.

the steps to developing an algorithm to solve a given problem:

- Decide on a complete and specific problem statement, including identifying fundamental _abstract operations_ that are intrinsic to the problem
- Implement a simple algorithm that solves the problem
  - may finish the job when problem instances turn out to be easy
  - provide us with a correctness check
  - a baseline for evaluating performance
- Develop improved implementations through a process of stepwise refinement, validating the efficacy of ideas for improvement through empirical analysis, mathematical analysis, or both
- Find high-level abstract representations of data structures or algorithms in operation that enable effective high-level design of improved versions
- Strive for worst-case performance guarantees when possible, but accept good performance on actual data when available


improve the weighted quick-union algorithm:

- We can approach the ideal simply by making all the nodes that we do examine point to the root
-  path compression, 
  - by adding another pass through each path during the union operation, setting the id entry corresponding to each vertex encountered along the way to point to the root. 