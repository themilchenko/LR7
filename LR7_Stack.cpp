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
    unsigned int size;
};

void Constructor(Stack& stack) // A function that initializes the fields of the structure when it is created.
{
    stack.head = nullptr;
    stack.tail = nullptr;
    stack.size = 0;
}

void destructor(Stack& stack) // A function that will clear the memory that was used for the structure.
{
    while (stack.size != 0)
    {
        stack.size--;
        Node* used = stack.head;
        stack.tail = stack.tail->previous;
        delete used;
    }
}

unsigned int size(const Stack& stack) // Count the number of elements which are in the structure.
{
    unsigned int size = stack.size;
    return size;
}

void push(Stack& stack, Node& node) // Adding element.
{
    if (stack.size == 0)
    {
        stack.size++;
        Node *element = new Node;
        element->information = node.information;
        stack.head = element;
        stack.tail = element;
    }
    else
    {
        stack.size++;
        Node *element = new Node;
        element->information = node.information;
        element->previous = stack.tail;
        stack.tail = element;
    }
}

Node& pop(Stack& stack) // Deleting element.
{
    stack.size--;
    Node *node = stack.tail;
    Node *element = new Node;
    element->information = node->information;
    stack.tail = stack.tail->previous;
    delete node;
    return *element;
}

void print_stack(const Stack& stack)    // Print elements.
{
    for (auto i = stack.tail; i != nullptr; i = i->previous)
        std::cout << i->information << ' ';
}

void print_info(const Stack& stack)
{
    if (size(stack) != 0)
    {
        std::cout << "Elements of stack: ";
        print_stack(stack);
        std::cout << std::endl;
        std::cout << "Size of stack: " << size(stack) << std::endl;
    }
    else
        std::cout << "There are no elements in stack.";
}

int main()
{
    Stack stack;

    Constructor(stack);

    for (int i = 0; i < 10; i++)
    {
        Node node;
        node.information = i;
        push(stack, node);
    }
    print_info(stack);

    std::cout << std::endl;

    std::cout << "Popped element: " << pop(stack).information << std::endl;
    std::cout << "Popped element: " << pop(stack).information << std::endl;
    std::cout << "Popped element: " << pop(stack).information << std::endl;

    std::cout << std::endl;

    print_info(stack);

    destructor(stack);

    std::cout << std::endl;

    print_info(stack);

    std::cout << std::endl;

    return 0;
}
