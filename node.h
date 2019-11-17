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

        int getID();
        Node* getFather();
        Node* getNext();
        bool getTokenPresent();
        bool getRequestingCS();
        virtual ~Node();

    protected:

    private:
        int id;
        Node *father;
        Node *next;
        bool tokenPresent;
        bool requestingCS;
};

#endif // NODE_H
