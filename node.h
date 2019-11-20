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
<<<<<<< HEAD
        void setRequestCollectionBox(int r);

        int getID();
        int getRequestCollectionBox();
=======

        int getID();
>>>>>>> 271ee151e52a018c578e91bfc07da48218e0dab8
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
