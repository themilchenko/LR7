/* LR_7 // Stack */

#include <iostream>

struct Node
{
	Node* previous = nullptr;
	int information;
};

struct Stack
{
	Node* head;
	Node* tail;
};

void Constructor(Stack& stack)
{
	stack.head = nullptr;
	stack.tail = nullptr;
}

void push(Stack& stack, Node& node)
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

Node& pop(Stack& stack)
{
	Node* rezulting_value = new Node;
	Node* node = stack.tail;
	rezulting_value->information = node->information;
	stack.tail = stack.tail->previous;
	delete node;
	return*rezulting_value;
}

unsigned int size(const Stack& stack)
{
	int counter = 0;
	Node* node = stack.tail;
	while (node != stack.tail)
	{
		node = node->previous;
		counter++;
	}
	return counter;
}

void destructor(Stack& stack)
{
	while (stack.tail != nullptr)
	{
		Node* used = new Node;
		used = stack.tail;
		stack.tail = stack.tail->previous;
		delete used;
	}
}

int main()
{
	Stack stack;
	Constructor(stack);
	for (int i = 0; i < 7; i++)
	{
		Node node;
		node.information = i;
		push(stack, node);
	}
	std::cout << "There are " << size(stack) << " elements in queue" << std::endl;
	Node node = pop(stack);
	std::cout << "There are " << node.information << " popped elements in queue" << std::endl;
	destructor(stack);
	std::cout << "There are " << size(stack) << " elements in queue" << std::endl;
	return 0;
}