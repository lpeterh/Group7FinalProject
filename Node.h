#ifndef NODE_H
#define NODE_H

#include <string>


class Node
{
public:
    // Operator Overloading
    const Node& operator=(const Node& B);

    // Constructor
    Node(std::string name);

    // Copy Constructor
    Node(const Node& B);


    std::string getName(); // Getter
    void setName(std::string newName); // Setter

private:
    std::string name;
};


#endif
