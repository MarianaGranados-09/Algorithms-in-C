//Elementary data structures
//Arrays: fixed number of data items that are stored contigously and that are accesible by an index.
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

//Other resources describing linked lists:
//A linked lists is a sequence of data structures, which are connected together via links.
//Sequence of links which contains items, each link contains a connection to another link
//-Link: each link of a linked list can store a data called element
//-Next: each link of a linked list contains a link to the next link called Next
//-LinkedList a linked list contains the connection link to the first link called first

//Linked lists have a few advantages over arrays

//1. Items can be added or removed from the middle of the list
//2. There is no need to define initial size

//Disadvantages

//1. There is no "random" access, it is impossible to reach the nth item in the array without first iterating over all items up until that item.
//2. Dynamic memory allocation and pointers are required, which implicates the code and increases the risk of memory leaks and segment faults.
//3. Linked lists have a much larger overhead over arrays, sonce linked list items are dynamically allocated and each item in the list also must store an additional pointer.

//Another definition of linked lists:
//A linked list is a set of dynamically allocated nodes, arranged in such a way that each node contains one value and one pointer. The pointer always points to the next member of the list. If the pointer is NULL, the it is the last node in the list.

//A linked list is held using a local pointer variable which points to the first item of the list. If that pointer is also NULL, then the list is considered to be empty

//Lets define a linked list node:

//Using typedef struct results in a cleaner, more readable code, it is used to define new data type names

//Propociona un mecanismo para la creacion de sinonimos para tipos de datos anteriormente definidos. Por ejemplo, se puede utilizar node_t para declarar variables tipo struct.

//typedef se utiliza a menudo para crear pseudonimos para los tipos de datos basicos. Si tenemos por ejempo un programa que requiere enteros de 4 bytes podria usarse el tipo int en un programa y el tipo long en otro. Para garantizar portabilidad podemos utilizar typedef para crear un alias de los enteros de 4 bytes en ambos sistemas. 

typedef struct node{
    int val;
    struct node *next;
}node_t; //Defining the struct in a recursive manner. We name our node type node_t

//Now we can use the nodes. Lets create a local variable which points to the first item of the list called head

void main(){
    node_t *head = NULL; 
    //La funcion malloc sirve para solicitar un bloque de memoria del tamanio suministrado como parametro. Devuelve un puntero a la zona de memoria concedida. 
    head=(node_t *)malloc(sizeof(node_t));
    if(head == NULL){
        return 1;
    }

    head->val = 1;
    head->next = NULL;
}
//We've created the first variable in the list, we must set the value, and the next item to be empty
//if we want to finish populating the list. Notice that we should always check if malloc returned a NULL value or not.
 
//To add  a variable to the end of the list, we can just continue advancing to the next pointer

void main(){
    node_t *head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    head->val = 1;
    head->next = (node_t*)malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL; //End of list
}

//An arrow operator allows to access elements in Structures and Unions. It is used with a pointer variable pointing to a structure or union. 

    //(pointer_name)->(variable_name)

//IT EXISTS TO ACCESS THE MEMBERS OF THE STRUCTURE OR UNIONS USING POINTERS.

//Iterating over a list
    //Lets build a function that prints out all the items of a list. To do this, we need to use a current pointer that will keep track of the node we are currently printing. After printing the value of the node, we set the current pointer to the next node, and print again, until we've reached the end of the list (the next node is NULL)

void print_list(node_t *head){
    //Current pointer that keeps tract of the node we are currently printing
    node_t *current = head; 

    //While current pointer isnt NULL (not end of list)
    while (current != NULL)
    {
        //Print current pointer that accesses the member val from node structure
        printf("%i\n", current-> val);
        //the current pointer now points to the next value in the linked list
        //add will print it until current is NULL
        current = current -> next;
    }
    
}

//Adding an item to the end of the list

//To iterate all the members of the linked list, we use a pointer called current.
//We set it to start from the head and then in each step, we advance the pointer //to the next item in the list, until we reach the last item.

//The function gets the pointer head and the int value val
void push(node_t *head, int val){

    //the current pointer points to the head or beginning of the list
   
    node_t *current =  head;
    //then we advance the pointer to the next item of the list
    //while the next item of the list isnt the end of the list or NULL:
    while (current -> next != NULL)
    {
        //pointer current points to the next item of the list
        current = current ->next;
    }

    //Now we can add a new variable at the end of the list 
    //current pointer points to next item, creating it with dynamic memory using malloc
    current -> next = (node_t *)malloc(sizeof(node_t));
    //now the pointer current points to next, pointing to the next val, which equals val to the value created before.
    current->next->val = val;
    //End of list 
    current->next->next = NULL;
    
}


//Types of LinkedList
/*
    -Simple linked list: item navigation is forward only
    -Doubly linked list: items can be navigated forward and backward
    -Circular linked list: last item contains link to the first element as next and the first element has a link to the last element as previous.

    //Basic Operations
    
    -Insertion: adds an element at the beginning of the list
    -Deletion: deletes an element at the beginning of the list
    -Display: displays the complete list
    -Search: searches an element using the given key
    -Delete: deletes an element using the given key
*/

//THE BEST USE CASES FOR LINKED LISTS ARE STACKS AND QUEUES 

    //Adding an item to the beginning of the list (pushing to the list)

    //At the beginning of the list, we need to do the following:
        //1. Create a new item and set its value
        //2. Link the new item to point to the head of the list 
        //3. Set the head of the list to be our new item


//Since we use a function to do this operation, we want to be able to modifiy the head variable. To do this, we must pass a pointer to the pointer variable 
//(a double pointer) so we will be able to modify the pointer itself

//A pointer points to a location in memory and thus used to store the address of variables, so when we define A double pointer or also called pointer to pointer, the first pointer is used to store the address  of the variable, and the second pointer is used to store the adrdress of the first pointer. 


void pushHead(node_t **head, int val)
{
    //Create new item
    node_t *new_node;
    //Set its value
    new_node = (node_t *)malloc(sizeof(node_t));

    //Set the new node to val
    new_node -> val = val;
    //Set the new node to the head of the list 
    //new_node points to next which equals to the memory address of head
    new_node-> next = *head;
    *head = new_node;
}

//Removing the first item 
//To pop a variable, we need to reverse this action
//1. Take the next item that the head points to and save it
//2. Free the head item
//3. Set the head to be the next item that we've stored on the side

void pop(node_t **head)
{
    int retval = -1;
    node_t *next_node = NULL;

    if(*head == NULL){
        return -1;
    }

    
    next_node = (*head) -> next;
    retval = (*head) -> val;
    free(*head);
    *head = next_node;

    return retval;

}