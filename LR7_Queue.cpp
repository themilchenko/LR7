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
};

void constructor(Queue& queue)   // A function that initializes the fields of the structure when it is created.
{
    queue.head = nullptr;
    queue.tail = nullptr;
}

void destructor(Queue& queue)    // A function that will clear the memory that was used for the structure.
{
    Node *used = queue.head;
        while (queue.head != queue.tail) {
            queue.head = queue.head->next;
            delete used;
            used = queue.head;
        }
}

unsigned int size(const Queue& queue)   // Count the number of elements which are in the structure.
{
    int counter = 0;
    Node* node = queue.head;
    while(node != queue.tail)
    {
        node = node->next;
        counter++;
    }
    counter++;
    return counter;
}

void push(Queue& queue, Node& node)    // Adding element.
{
    if (queue.head == nullptr)
    {
        Node* new_element = new Node;
        new_element->information = node.information;
        queue.head = new_element;
        queue.tail = new_element;
    }
    else
    {
        Node* new_element = new Node;
        new_element->information = node.information;
        queue.tail->next = new_element;
        queue.tail = new_element;
    }
}

Node& pop(Queue& queue)    // Deleting element.
{
    Node* rezulting_value = new Node;
    Node* node = queue.head;
    rezulting_value->information = node->information;
    queue.head = queue.head->next;
    delete node;
    return *rezulting_value;
}

void print(const Queue& queue)    // Print elements.
{
    for (auto i = queue.head; i != nullptr; i = i->next)
        std::cout << i->information << ' ';
}

int main() {
    Queue queue; // creating queue

    constructor(queue);

    for (int i = 10; i > 0; i--)
    {
        Node node;
        node.information = i;
        push(queue, node);
    }

    std::cout << "There are our elements: ";
    print(queue);

    std::cout << std::endl << "It's size of queue: " << size(queue);

    Node node = pop(queue);
    std::cout << std::endl << node.information;

    destructor(queue);

    std::cout << std::endl << size(queue);
    return 0;
}
