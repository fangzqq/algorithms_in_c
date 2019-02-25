# elementary data structure

Organizing the data for processing is an essential step in the development of a computer program. 

The choices of algorithm and of data structure are closely intertwined, and we continually seek ways to save time or space by making the choice properly.

We discuss properties of _arrays, linked lists, and strings_. We consider various __primitive operations__ for manipulating these data structures, to develop a basic set of tools that we can use to develop sophisticated algorithms for difficult problems.

## 3.1 building blocks

In C, our programs are all built from just a few basic types of data:

- Integers (ints).
- Floating-point numbers (floats).
- Characters (chars).

In C, we trade space for accuracy by choosing from among the types _int_, _long int_, or _short int_ for integers and from among _float_ or _double_ for floating-point numbers.

definition 3.1

A __data type__ is a set of values and a collection of operations on those values.

Operations are associated with types. When we perform an operation, we need to ensure that _its operands and result are of the correct type_.


Recommended software engineering practice, is to split the program into three files:

 - An interface, which defines the data structure and declares the functions to be used to manipulate the data structure
 - An implementation of the functions declared in the interface
 - A client program that uses the functions declared in the interface to work at _a higher level of abstraction_

We think of the interface as a definition of the data type. It is _a contract between the client program and the implementation program_. The client agrees to access the data only through the functions defined in the interface, and the implementation agrees to deliver the promised functions.

Pointers are the basis for many data structures and algorithms. A simple and important example of the use of pointers arises when we consider the definition of a function that is to _return multiple values_.


## 3.2 arrays

An array is a fixed collection of same-type data that are stored contiguously and that are accessible by an index.

when we use a computed value to access an array of size N, we are _taking N possibilities into account with just a single operation_. This gain in efficiency is compelling when we can realize it.


## 3.3 linked lists

When our primary interest is to go through a collection of items sequentially, one by one, we can organize the items as a linked list: _a basic data structure where each item contains the information that we need to get to the next item_.

The primary advantage of linked lists over arrays is that the links provide us with the capability to _rearrange the items efficiently_. This flexibility is gained at the expense of quick access to any arbitrary item in the list.

### definition

definition 3.2

A linked list is a set of items where each item is part of a node that also contains a link to a node.


we most often work with lists that correspond to a simple sequential arrangement of a finite set of items, adopting _one of the following conventions_ for the link in the final node:

- It is a null link that points to no node.
- It refers to a dummy node that contains no item.
- It refers back to the first node, making the list a circular list.

 we use pointers for links and structures for nodes:

 ```c
typedef struct node *link;
struct node {Item item; link next;};
 ```

Links are pointers to nodes, and nodes consist of items and links.

we need to create an instance of a node structure and to reserve memory for it:

```c
link x = malloc(sizeof *x);
```

the two fundamental operations that we perform on linked lists:

1. To delete the node following node x

 ```c
t = x->next; x->next = t->next; free(t);
 ```

2. to insert node t into a list at a position following node x

```c
t->next = x->next; x->next = t;
```

## elementary list processing

Working with data that are organized in linked lists is called list processing.

definition 3.3

A linked list is either _a null link_ or a link to a node that contains an item and a link to a linked list.

One of the most common operations that we perform on lists is to traverse them: 

```c
for (t = x; t != NULL; t = t->next) visit(t->item);
```

Program 3.11 is an implementation of another list-processing task: rearranging the nodes of a list to put their items in sorted order. We maintain a _dummy node_ called a head node at the beginning of each list. We ignore the item field in a list’s head node, but maintain its link as the pointer to the node containing the first item in the list.

Below gives implementations of basic list-processing operations with five commonly used conventions. This type of code is used in simple applications where the list-processing code is inline:

```c
// Circular, never empty
// first insert
head -> next = head;
// insert t after x:
t -> next = x -> next;
x -> next = t;
// delete after x:
x -> next = x -> next -> next;
// traversal loop:
t = head;
do { t = t -> next; } while (t != head);
// test if one item
if (head -> next == head)

// Head pointer, null tail
// initialize
head = NULL;
// insert t after x;
if (x == NULL) { head = t; head -> next = NULL;}
else {t -> next = x -> next; x -> next = t;}
// delete after x:
x -> next = x -> next -> next;
// traversal loop:
for (t = head; t != NULL; t = t -> next)
// test if empty
if (head == NULL)

// Dummy head node, null tail
// initialize
head = malloc(sizeof *head);
z = malloc(sizeof *z);
head -> next = NULL;
// insert t after x:
t -> next = x -> next;
x -> next = t;
// delete after x:
x -> next = x -> next -> next;
// traversal loop
for (t = head -> next; t != NULL; t = t -> next)
// test if empty
if (head -> next == NULL)

// Dummy head and tail nodes
// initialize
head = malloc(sizeof *head);
z = malloc(sizeof *z);
head -> next = z; z -> next = z;
// insert t after x:
t -> next = x -> next;
x -> next = t;
// delete after x:
x -> next = x -> next -> next;
// traversal loop:
for (t = head -> next; t != z; t = t -> next)
// test if empty
if (head -> next == z)
```

Identifying the important operations that we use in a computation and defining them in an interface gives us the flexibility to consider different concrete implementations of critical operations and to test their effectiveness.


## memory allocation for lists

The system function _free_ is the counterpart to _malloc_. When we are done using a chunk of allocated memory, we call free to inform the system that the chunk is available for later use. Dynamic memory allocation is the process of managing memory and responding to calls on malloc and free from client programs.

Programs that can take advantage of specialized knowledge about an application often are more efficient than general-purpose programs for the same task. Memory allocation is no exception to this maxim. another reason to avoid general-purpose library functions is that doing so makes programs more portable—we can protect ourselves against unexpected performance changes when the library changes or when we move to a different system.


## strings

 We use the term _string_ to refer to a variable-length array of characters, defined by a starting point and by a string-termination character marking the end.

 Strings are valuable as low-level data structures, for two basic reasons:

 -  many computing applications involve processing textual data, which can be represented directly with strings
 -  many computer systems provide direct and efficient access to bytes of memory, which correspond directly to characters in strings

 In a great many situations, the string abstraction matches needs of the application to the capabilities of the machine.

 The difference between a string and an array of characters revolves around _length_. Both represent contiguous areas of memory, but the length of an array is set at the time that the array is created, whereas the length of a string may change during the execution of a program.

 With the string-termination character, we can work at a higher level of abstraction, and consider only the portion of the array from the beginning to the string-termination character to contain meaningful information. _In C, the termination character is the one with value 0, also known as '\0'_.

 simple operations that we commonly perform on strings:

 ```c
// indexed array versions
// compute string length (strlen(a))
for (i = 0; a[i] != 0; i++); return i;
// copy (strcpy(a, b))
for (i = 0; (a[i] = b[i]) != 0; i++);
// compare (strcmp(a, b))
for (i = 0; a[i] == b[i]; i++)
    if (a[i] == 0) return 0;
return a[i] - b[i];
// compare (prefix) (strncmp(a, b, strlen(a)))
for (i = 0; a[i] == b[i]; i++)
    if (a[i] == 0) return 0;
if (a[i] == 0) return 0;
return a[i] - b[i];
// append (strcat(a, b))
strcpy(a+strlen(a), b);

// equivalent pointer versions
// compute string length (strlen(a))
b = a; while(*b++) ; return b - a - 1;
// copy (strcpy(a, b))
while (*a++ = *b++);
// compare
while (*a++ == *b++)
    if (*(a-1) == 0) return 0;
return *(a-1) - *(b-1);
 ```

 Numerous applications involve _storing information as strings_, then processing or accessing that information by comparing the strings, so the _compare operation_ is a particularly critical one.


String processing provides a convincing example of the need to be knowledgeable about the performance of library functions:

```c
for(i = 0; i < strlen(a); i++)
    if (strncmp(&a[i], p, strlen(p)) == 0)
        printf("%d ", i);
```

this code fragment takes time proportional to _at least the square of the length of a_, no matter what code is in the body of the loop, because it goes all the way through a to determine its length each time through the loop.

Library functions, all too often, cannot guarantee to provide the best performance for all applications. This issue is critical in the design of algorithms and data structures, and thus is one that we must always bear in mind. 


## compound data structures

Arrays, linked lists, and strings all provide simple ways to structure data sequentially. They provide a first level of abstraction that we can use to group objects in ways amenable to processing the objects efficiently.

In the same way that one-dimensional arrays correspond to _vectors_, two-dimensional arrays, with two indices, correspond to _matrices_, and are widely used in mathematical computations.

```c
// multiply two matrices a and b, leaving the result in a third matrix c.
for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
        for (k = 0, c[i][j] = 0.0; k < N; k++)
            c[i][j] += a[i][k] * b[k][j];
```

### arrays of string

When processing strings, we normally work with pointers into a buffer that contains the strings, because the pointers are easier to manipulate than the strings themselves, which vary in length.

### undirected graphs

 A graph is a fundamental combinatorial object that is defined simply as a set of objects (called vertices) and a set of connections among the vertices (called edges).

We assume that a graph with V vertices and E edges is defined by _a set of E pairs of integers between 0 and V-1_. That is, we assume that the vertices are labeled with the integers 0, 1, ..., V-1, and that the edges are specified as pairs of vertices.

One straightforward method for representing a graph is to use a two-dimensional array, called an _adjacency matrix_. For the undirected graphs that we are considering, if there is an entry in row i and column j, then there also must be an entry in row j and column i, so the matrix is symmetric.




### c 语言中的 void 与 void 指针

作者：Deeper Go
链接：https://www.zhihu.com/question/35831776/answer/122946602
来源：知乎

void的作用:

1. 对函数参数的限定：当不需要传入参数时，即 `function (void)`;
2. 对函数返回值的限定：当函数没有返回值时，即 `void function(void)`;

void指针的作用:

1. void指针可以指向任意的数据类型，即任意类型的指针可以赋值给void指针

```c
int *a;
void *p;
p=a;
```
如果void指针赋值给其他类型，则需要强制转换：`a=（int *）p`;

2. 在ANSI C标准中不允许对void指针进行算术运算，因为没有特定的数据类型，即在内存中不知道移动多少个字节；而在GNU标准中，认为void指针和char指针等同。

void 指针的应用场景：

1. void指针一般用于应用的底层，比如malloc函数的返回类型是void指针，需要再强制转换；
2. 文件句柄HANDLE也是void指针类型，这也是句柄和指针的区别；
3. 内存操作函数的原型也需要void指针限定传入参数：

```c
void * memcpy (void *dest, const void *src, size_t len);
void * memset (void *buffer, int c, size_t num );
```
4. 面向对象函数中底层对基类的抽象。

