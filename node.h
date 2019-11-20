#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        void setID(int);
        void setFather(Node*);
        void setNext(Node*);
        void setTokenPresent(bool t);
        void setRequestingCS(bool b);
        void setRequestCollectionBox(int r);

        int getID();
        int getRequestCollectionBox();
        Node* getFather();
        Node* getNext();
        bool getTokenPresent();
        bool getRequestingCS();
        virtual ~Node();

    protected:

    private:
        int id;
        int requestCollectionBox;
        Node *father;
        Node *next;
        bool tokenPresent;
        bool requestingCS;
};

#endif // NODE_H
