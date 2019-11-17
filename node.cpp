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
Node* Node::getFather(){
	return father;
}
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
