#include "node.h"

Node::Node()
{
    //ctor
}

Node::~Node()
{
    //dtor
}

//getter methods
int Node::getID(){
	return id;
}
<<<<<<< HEAD
int Node::getRequestCollectionBox(){
	return requestCollectionBox;
}
Node* Node::getFather(){
	return father;
}
=======
Node* Node::getFather(){
	return father;
}
>>>>>>> 271ee151e52a018c578e91bfc07da48218e0dab8
Node* Node::getNext(){
	return next;
}
bool Node::getTokenPresent(){
	return tokenPresent;
}
bool Node::getRequestingCS(){
	return requestingCS;
}
// setter methods
void Node::setID(int id){
	this->id = id;
}
void Node::setFather(Node *f){
	this->father = f;
}
void Node::setNext(Node *n){
	this->next = n;
}
void Node::setTokenPresent(bool t){
	this->tokenPresent = t;
}
void Node::setRequestingCS(bool b){
	this->requestingCS = b;
}
<<<<<<< HEAD
void Node::setRequestCollectionBox(int r){
	this->requestCollectionBox = r;
}
=======
>>>>>>> 271ee151e52a018c578e91bfc07da48218e0dab8
