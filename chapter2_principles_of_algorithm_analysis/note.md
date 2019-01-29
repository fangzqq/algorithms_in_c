# Principles of Algorithms analysis

basics of algorithms analysis, aims to:
- illustrate the process
- describe in one place the mathematical conventions that we use
- provide a basis for discussion of higher-level issues

understand what our algorithms are and how we can use them effectively.

We design and develop algorithms by __layering abstract operations__ that help us to understand the essential nature of the computational problems that we want to solve.

在构建真正的系统时除了算法之外，还需要考虑其他方面，例如：

- error conditions must be checked and reported
- can be changed easily, read and understood quickly by others
- interface well with other parts of the system
- be amenable to being moved to other environments

理解算法性能的第一步是进行 __经验分析__，直接得到性能指标并对数学分析进行验证。当经验分析非常耗时时，采用 __数学分析__ 。

进行经验分析的挑战:
- 开发出正确完整的实现
- 确定输入数据，actual data, random data, perverse data
- 其他影响因素, machines, compilers, systems, implementation careful level

One approach that we often use in this book, we strive to identify essential abstract operations, and start by _comparing algorithms on the basis of their use of such operations_.

对于给定的问题，在不同算法间选择时，应该避免以下两个错误：
- 最常见的错误是忽视了算法的性能特征。当我们处理的问题规模很大时，我们只能选择更好的算法。
- 次最常见的错误可能是过度关注了算法的性能特征。比如：10倍量级提升毫秒级程序、提升很少需要运行的程序等例子。

算法分析者与程序员之间的关系：

- it is the task of the algorithm analyst to discover as much information as possible about the performance of algorithms; 
- it is the task of the programmer to apply such information in selecting algorithms for particular applications.

steps in the analysis of an algorithm:

1. identify the abstract operations on which the algorithm is based, to separate the analysis from the implementation.
2. we can often use approximate analytic results in conjunction with empirical studies to predict performance accurately.
3. to model the input that might be presented to the algorithm:
  - either assume that the input is random, and study the average-case performance of the program
  - we look for perverse input, and study the worst-case performance of the program


## growth of functions

Most algorithms have a primary parameter _N_ that affects the running time most significantly. The parameter N is most often directly _proportional to the size of the data set being processed_.

When there is more than one such parameter, we often reduce the analysis to just one parameter by expressing one of the parameters as a function of the other or by considering one parameter at a time (holding the other constant).

 Our goal is to express the _resource requirements_ of our programs (most often running time) in terms of N, using mathematical formulas.

 The algorithms in this book typically have running times proportional to one of the following functions:

 1. If all the instructions of a program are executed once or at most only a few times. we say that the program’s running time is _constant_.
 2. _logN_ When the running time of a program is logarithmic. This running time commonly occurs in programs that solve a big problem by _transformation into a series of smaller problems_, cutting the problem size by some constant fraction at each step.
 3. _N_ When the running time of a program is linear. it is generally the case that a small amount of processing is done on each input element. This situation is optimal for an algorithm that _must process N inputs (or produce N outputs)_.
 4. _N*logN_ when algorithms solve a problem by breaking it up into smaller subproblems, solving them independently, and then combining the solutions.
 5. _N*N_ When the running time of an algorithm is quadratic. Quadratic running times typically arise in algorithms that _process all pairs of data items_ (perhaps in a double nested loop).
 6. _N*N*N_ Similarly, an algorithm that processes triples of data items (perhaps in a triple-nested loop) has a cubic running time and is _practical for use on only small problems_.
 7. _2N_ Few algorithms with exponential running time are likely to be appropriate for practical use, even though such algorithms arise naturally as _brute-force solutions_ to problems.

we generally regard _loglogN_ as a constant, for practical purposes, because it is so small, even when N is huge.

The smallest integer larger than lgN is _the number of bits_ required to represent N in binary.

the mathematical notation that we use for functions and constants that arise in formulas describing the performance of algorithms:

- floor and ceiling functions
- binary logarithm
- fibonacci numbers
- harmonic numbers
- factorial function


## big-O notation

大 O 表示法的三个意义：

- To bound the error that we make when we ignore small terms in mathematical formulas
- To bound the error that we make when we ignore parts of a program that contribute a small amount to the total being analyzed
-  To allow us to classify algorithms according to _upper bounds_ on their total running times

The O-notation allows us to keep track of the _leading terms_ while ignoring smaller terms when manipulating approximate mathematical expressions, and ultimately allows us to make _concise statements_ that give accurate approximations to the quantities that we analyze

We refer to a formula with one O-term as an asymptotic expression.


## basic recurrences

 a great many algorithms are based on the principle of _recursively decomposing a large problem into one or more smaller ones_, using solutions to the subproblems to solve the original problem.

 Understanding the mathematical properties of the formulas in this section will give us insight into the performance properties of algorithms throughout the book.

类似求数列的通项公式。


## examples of algorithm analysis

以顺序查找和二分查找为例。

## 算法复杂度

为了表示代码在不同情况下的不同时间复杂度，我们需要引入三个概：

- 最好情况时间复杂度。在最理想的情况下，执行这段代码的时间复杂度
- 最坏情况时间复杂度。在最糟糕的情况下，执行这段代码的时间复杂度。
- 平均情况时间复杂度。加权平均时间复杂度或者期望时间复杂度


### 均摊时间复杂度

摊还分析：

对一个数据结构进行一组连续操作中，大部分情况下时间复杂度都很低，只有个别情况下时间复杂度比较高，而且这些操作之间存在前后连贯的时序关系，这个时候，我们就可以将这一组操作放在一块儿分析，看是否能将较高时间复杂度那次操作的耗时，平摊到其他那些时间复杂度比较低的操作上。

在能够应用均摊时间复杂度分析的场合，一般均摊时间复杂度就等于最好情况时间复杂度。


之所以引入这几个复杂度概念，是因为，同一段代码，在不同输入的情况下，复杂度量级有可能是不一样的。

