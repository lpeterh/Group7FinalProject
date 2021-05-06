#include "Node.h"

// Operator Overlaoding
const Node& Node::operator=(const Node& B)
{
    this->name = B.name;
    return *this;
}

// Constructor
Node::Node(std::string name)
    : name(name)
{ }

// Copy Constructor
Node::Node(const Node& B)
{
    this->name = B.name;
}

// Getter
std::string Node::getName()
{
    return name;
}

// Setter
void Node::setName(std::string newName)
{
    (this->name) = newName;
}