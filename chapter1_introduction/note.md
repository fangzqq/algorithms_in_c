# Introduction

## abstraction layers

Developing ever more powerful layers of abstraction is an essential process in computer science in general and in algorithm design in particular.

the steps to developing an algorithm to solve a given problem:

- Decide on a complete and specific problem statement, including identifying fundamental _abstract operations_ that are intrinsic to the problem (适用于计算机解决的方法，操作). Model the problem
- Implement a simple algorithm that solves the problem (正确性第一)
  - may finish the job when problem instances turn out to be easy
  - provide us with a correctness check
  - a baseline for evaluating performance
- Develop improved implementations through a process of stepwise refinement, validating the efficacy of ideas for improvement through empirical analysis, mathematical analysis, or both  (提高效率)
- Find high-level abstract representations of data structures or algorithms in operation that enable effective high-level design of improved versions
- Strive for worst-case performance guarantees when possible, but accept good performance on actual data when available (努力保证最坏情况性能)

## Union-find

### modeling the objects

when programming, convenient to name objects 0 to N-1:

- Use integers as array index
- Suppress details not relevant to union-find

### modeling the connections

we assume "is connected to" is an equivalence relation:

- Reflexive: p is connected to p
- Symmetric: if p is connected to q, then q is connected to p
- Transitive: if p is connected to q and q is connected to r, then p is connected to r

Connected components, can be considered as maximal _set_ of objects that are mutually connected.

### quick-find

data structure:

- integer array id[] of length N.
- interpretaton: p and q are connected iff they have the same id

find:

- check if p and q have the same id

union:

- to merge components containing p and q, change all entries whose id equals id[p] to id[q]

### quick-union

data structure:

- integer array id[] of length N
- interpretation: id[i] is parent of i. (keep going until it doesn't change)
- root of i is `id[id[id[...id[i]...]]]`

find:

- check if p and q have the same root

union:

- to merge components containing p and q, set the id of p's root to the id of q's root

### quick-find and quick-union are too slow

cost model. number of array accesses (for read or write)

|algorithm|initialize|union|find|
|:-----:|:-----:|:------:|:----:|
|quick-find|N|N|1|
|quick-union|N|N+|N|

`+`: includes cost of finding roots.

quick-find defect:

- union too expensive (N array accesses)
- trees ar flat, but too expensive to keep them flat

quick-union defect:

- trees can get tall
- find too expensive (could be N array accesses)

### improvement 1: weighting

weighted quick-union:

- modify quick-union to avoid tall trees
- keep track of size of each tree(number of objects)
- balance by linking root of smaller tree to root of larger tree (reasonable alternatives: union by height or "rank")

data structure:

- integer array id[] of length N
- interpretation: id[i] is parent of i. (keep going until it doesn't change)
- root of i is `id[id[id[...id[i]...]]]`
- maintain extra array `sz[i]` to count number of objects in the tree rooted at i.

find:

- check if p and q have the same root.

union:

- link root of smaller tree to root of larger tree
- update the `sz[]` array

running time:

- find: takes time proportional to depth of p and q
- union: takes constant time, given roots

proposition: depth of any node x is at most lgN


|algorithm|initialize|union|connected|
|:-----:|:-----:|:------:|:----:|
|quick-find|N|N|1|
|quick-union|N|N+|N|
|weighted QU|N|lgN+|lgN|

`+`: includes cost of finding roots

### improvement 2: path compression

quick union with path compression. just after computing the root of p, set the id of each examined node to point to that root.

tow-pass implementation:

- add second loop to `root()` to set the `id[]` of each examined node to the root.

simpler one-pass variant:

- make every other node in path point to its grandparent (thereby halving path length)

```c
int root(int i)
{
    while(i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}
```

### weighted quick-union with path compression

bottom line: weighted quick union (with path compression) makes it possible to problems that could not otherwise be addressed.

summary:

|algorithm|worst-case time|
|:------:|:--------------:|
|quick-find|MN|
|quick-union|MN|
|weighted QU|N + M logN|
|QU + path compression|N + MlogN|
|weighted QU + path compression|N + M lg* N|

`lg* N` iterate log function:

|N|lg* N|
|-|-|
|1|0|
|2|1|
|4|2|
|16|3|
|65536|4|
|2**65536|5|

Ex. `10**9` unions and finds with `10**9` objects:

- WQUPC reduces time from 30 years to 6 seconds
- supercomputer won't help much, good algorithm enables solution.

### applications

steps to developing a usable algorithm:

- model the problem
- find an algorithm to solve it
- fast enough? fits in memory?
- if not, figure out why
- find a way to address the problem
- iterate until satisfied
