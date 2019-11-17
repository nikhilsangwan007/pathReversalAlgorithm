#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        void setID(int);
        void setFather(Node*);
        void setNext(Node*);

        int getID();
        Node getFather();
        Node getNext();
        virtual ~Node();

    protected:

    private:
        int id;
        Node *father;
        Node *next;
};

#endif // NODE_H
