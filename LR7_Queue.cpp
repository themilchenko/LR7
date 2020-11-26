/* LR_7 // Queue */

#include <iostream>

struct Node
{
    Node* next = nullptr;
    int information = 0;
};

struct Queue
{
    Node* head;
    Node* tail;
};

void constructor(Queue& queue)
{
    queue.head = nullptr;
    queue.tail = nullptr;
}

void destructor(Queue& queue)
{
    while (queue.head != nullptr)
    {
        Node* used = new Node;
        used = queue.head;
        queue.head = queue.head->next;
        delete used;
    }
}

void push(Queue& queue, Node& node)
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

Node& pop(Queue& queue)
{
    Node* rezulting_value = new Node;
    Node* node = queue.head;
    rezulting_value->information = node->information;
    queue.head = queue.head->next;
    delete node;
    return *rezulting_value;
}

unsigned int size(const Queue& queue)
{
    int counter = 0;
    Node* node = queue.head;
    while (node != queue.tail)
    {
        node = node->next;
        counter++;
    }
    return counter;
}

int main()
{
    Queue queue;
    constructor(queue);
    for (int i = 0; i < 7; i++)
    {
        Node node;
        node.information = i;
        push(queue, node);
    }
    std::cout << "There are " << size(queue) << " elements in queue" << std::endl;
    Node node = pop(queue);
    std::cout << "There are " << node.information << " popped elements in queue" << std::endl;
    destructor(queue);
    std::cout << "There are " << size(queue) << " elements in queue" << std::endl;
    return 0;
}
