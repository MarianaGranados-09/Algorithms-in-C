//Elementary data structures
//Arrays: fixed numbre of data items that are stored contigously and that are accesible by an index.
//We refer to the ith element of an array a as a[i]
//Primary feature: if the indez is known, any item can de accessed in constant time

//Arrays correspond directly to vectors, the mathematical term for indexed list of objects.
//Similarly, two-dimensional arrays correspond to matrices.


//Linked Lists
//The primary advantage of linked lists over arrays is that linked lists can grow and shrink in size during their lifetime.
//Their maximum size does not need to be known in advance, in practical aplications, this often makes it posible to have several data structures share the same space, without paying attention to their relative size at any time.
//A second advantage of is that they provide flexibility in allowing the items to be rearranged efficiently, this flexibility is gained at the expense of quick access to any arbitrary item in the list.
//A linked list is a set of items organized sequentially, just like an array. In the array, the sequential organization is provided implicitly(by the position in the array);
//In a linked list, we use an explicit arrangement in which each item is part of a "node" that also contains a "link" to the next node.
//-Every node has a link, so the link in the last node of the list must specify some "next" node. 
//Our convention will be to have a dummy node, which we'll call z, for this purpose: the last node of the list will point to z, and z will point to itself.
//In addition, we normally will have a dummy node at the other end of the list, called head, which will point to the first node in the list. The main purpose of dummy node is to make certain manipulations with the links,
// especially those involving the first and last node on the list, more convient.

//More important, we can talk of "inserting" an item into a linked list, an operation that is unnatural and inconvenient in an array. Similarly, we can speak of deleting an item from a linked list.
//On the other hand, there are other operations for which linked lists are not well-suited. The most obvious is "find the kth item" or find an item given its index:
//in an array this is done by simply accesing a[k], but in a list we have to travel through k links.
//Another operation that is unnatural on linked list is "find the item before a given item". 

//C provides primitive operations that allow linked lists to be implemented directly.
//The following code fragment is a sample implementation of the basic functions discussed so far

#include <stdlib.h>
#include <stdio.h>

struct node
{
    int key;
    struct node *next;
};
struct node *head, *z, *t;

listinitialize()
{
    head = (struct node *)malloc(sizeof *head);
    z = (struct node *)malloc(sizeof *z);
    head->next = z; 
    z->next = z;
}
deletenext(struct node *t)
{
    t->next = t->next->next;
}

struct node *insertafter(int v, struct node *t)
{
    struct node *x; 
    x = (struct node *)malloc(sizeof *x);
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
};
//The precise format of the lists is described in the struct declaration: the lists are made up of nodes, each node containing an integer and a pointer to the next
//node on the list. The key is an integer here only for simplicity, and could be arbitrarily complex-the pointer is the key to the list. The variable 'head' is a pointer to the first node on a list: we can examine the other nodes in order by following 
//pointers until reaching z, the pointer to the dummy node representing the end of the list.

//The arrow notation is used in C to follow pointers through structures. We write a reference link followed by this symbol to indicate reference to the node pointed to by that link. 

//E.g. the reference 'head->next->key' refers to the first item on a list and]
// head->next->next->key refers to the second.

//The struct declaration merely describes the formats of the nodes; nodes can be created only when the built-in procedure malloc is called.
//for example, the call z = (struct node *)malloc(sizeof *z) creates a new node, putting a pointer to it in z.
//The purpose of mallac is to relieve the programmer of the burden of allocating storage for the node as the list grows.