/* LR_7 // Stack */

#include <iostream>

struct Node
{
    Node* previous = nullptr;
    int information = 0;
};

struct Stack
{
    Node* head;
    Node* tail;
};

void Constructor(Stack& stack) // A function that initializes the fields of the structure when it is created.
{
    stack.head = nullptr;
    stack.tail = nullptr;
}

void destructor(Stack& stack) // A function that will clear the memory that was used for the structure.
{
    while (stack.tail != nullptr)
    {
        Node* used = new Node;
        used = stack.tail;
        stack.tail = stack.tail->previous;
        delete used;
    }
}

unsigned int size(const Stack& stack) // Count the number of elements which are in the structure.
{
    int counter = 0;
    Node* node = stack.tail;
    while (node != stack.head)
    {
        node = node->previous;
        counter++;
    }
    counter++;
    return counter;
}

void push(Stack& stack, Node& node) // Adding element.
{
    if (stack.head == nullptr)
    {
        Node* new_element = new Node;
        new_element->information = node.information;
        stack.head = new_element;
        stack.tail = new_element;
    }
    else
    {
        Node* new_element = new Node;
        new_element->information = node.information;
        new_element->previous = stack.tail;
        stack.tail = new_element;
    }
}

Node& pop(Stack& stack) // Deleting element.
{
    Node* rezulting_value = new Node;
    Node* node = stack.tail;
    rezulting_value->information = node->information;
    stack.tail = stack.tail->previous;
    delete node;
    return *rezulting_value;
}

void print(const Stack& stack)    // Print elements.
{
    for (auto i = stack.tail; i != nullptr; i = i->previous)
        std::cout << i->information << ' ';
}

int main()
{
    Stack stack;

    Constructor(stack);

    for (int i = 10; i > 0; i--)
    {
        Node node;
        node.information = i;
        push(stack, node);
    }

    std::cout << "There are our elements: ";
    print(stack);

    std::cout << std::endl << "The size of stack: " << size(stack);

    Node node = pop(stack);
    std::cout << std::endl << node.information << std::endl;

    destructor(stack);

    std::cout << "There are " << size(stack) << " elements in queue" << std::endl;
    return 0;
}
