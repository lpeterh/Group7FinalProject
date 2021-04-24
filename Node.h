#ifndef NODE_H
#define NODE_H

#include <string>


class Node
{
public:
    // Constructor
    Node(std::string name);


    std::string getName(); // Getter
    void setName(std::string newName); // Setter

private:
    std::string name;
};


#endif
