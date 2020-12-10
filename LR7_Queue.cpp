/* LR_7 // Queue */

#include <iostream>

struct Node
{
    int information = 0;
    Node* next = nullptr;
};

struct Queue
{
    Node* head;
    Node* tail;
    unsigned int size;
};

void constructor(Queue& queue)   // A function that initializes the fields of the structure when it is created.
{
    queue.head = nullptr;
    queue.tail = nullptr;
    queue.size = 0;
}

void destructor(Queue& queue)    // A function that will clear the memory that was used for the structure.
{
    while (queue.size != 0)
    {
        queue.size--;
        Node *used = queue.tail;
        queue.tail = queue.tail->next;
        delete used;
    }
}

unsigned int size(const Queue& queue)   // Count the number of elements which are in the structure.
{
    unsigned int size = queue.size;
    return size;
}

void push(Queue& queue, Node& node)    // Adding element.
{
    if (queue.size == 0)
    {
        queue.size++;
        Node* new_element = new Node;
        new_element->information = node.information;
        queue.head = queue.tail = new_element;
    }
    else
    {
        queue.size++;
        Node* new_element = new Node;
        new_element->information = node.information;
        queue.head->next = new_element;
        queue.head = new_element;
    }
}

Node& pop(Queue& queue)    // Deleting element.
{
    queue.size--;
    Node *node = queue.tail;
    queue.tail = queue.tail->next;
    delete node;
    return *node;
}

void print_queue(const Queue& queue)    // Print elements.
{
    for (auto i = queue.tail; i != nullptr; i = i->next)
        std::cout << i->information << ' ';
}

void print_info(const Queue& queue)
{
    if (queue.size != 0)
    {
        std::cout << "Elements of queue: ";
        print_queue(queue);
        std::cout << std::endl;
        std::cout << "Size of queue: " << size(queue);
    }
    else
        std::cout << "There are no elements in queue";
}

int main()
{
    Queue queue;

    constructor(queue);

    for (int i = 0; i < 10; i++)
    {
        Node node;
        node.information = i;
        push(queue, node);
    }

    print_info(queue);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Popped element: " << pop(queue).information << std::endl;
    std::cout << "Popped element: " << pop(queue).information << std::endl;
    std::cout << "Popped element: " << pop(queue).information << std::endl;

    std::cout << std::endl;

    print_info(queue);

    std::cout << std::endl;

    destructor(queue);

    print_info(queue);

    return 0;
}
