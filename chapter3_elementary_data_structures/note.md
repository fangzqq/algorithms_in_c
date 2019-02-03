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

