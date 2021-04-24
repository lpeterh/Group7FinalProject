#include "Node.h"

// Constructor
Node::Node(std::string name)
    : name(name)
{ }

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