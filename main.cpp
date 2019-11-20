#include <bits/stdc++.h>
#include <pthread.h>
#include "node.h"

using namespace std;

<<<<<<< HEAD
=======
Node root;
>>>>>>> 271ee151e52a018c578e91bfc07da48218e0dab8
vector<Node> nodeVector;

void printID(vector<Node> v){
	for(Node n : v)
		cout<<n.getID()<<" ";
	cout<<endl;
}

void printRequestingID(vector<int> v){
	for(int n : v)
		cout<<n<<" ";
	cout<<endl;
}

<<<<<<< HEAD
void checkInitialization(){
	for(Node n : nodeVector){
		if(n.getID() == 0){
			cout<<n.getID()<<"->"<<"[ father : "<<n.getFather()<<" ][ "<<" next : "<<n.getNext()<<" ][ "<<" token : "<<n.getTokenPresent()<<" ][ "<<" requestingCS : "<<n.getRequestingCS()<<" ]"<<endl;
		}else{	
			cout<<n.getID()<<"->"<<"[ father : "<<n.getFather()<<" ][ "<<" next : "<<n.getNext()<<" ][ "<<" token : "<<n.getTokenPresent()<<" ][ "<<"requestingCS :"<<n.getRequestingCS()<<" ]"<<endl;
=======
void checkInitialization(vector<Node> v){
	for(Node n : v){
		if(n.getID() == 0){
			cout<<root.getID()<<"->"<<root.getFather()<<" "<<root.getNext()<<" "<<root.getTokenPresent()<<" "<<root.getRequestingCS()<<endl;
		}else{	
			cout<<n.getID()<<"->"<<n.getFather()<<" "<<n.getNext()<<" "<<n.getTokenPresent()<<" "<<n.getRequestingCS()<<endl;
>>>>>>> 271ee151e52a018c578e91bfc07da48218e0dab8
		}
	}
	cout<<endl;
}

<<<<<<< HEAD

void initialization(){
	for(int i=0; i<nodeVector.size(); ++i){
		if(i == 0){
			nodeVector[0].setNext(NULL);
			nodeVector[0].setFather(NULL);
			nodeVector[0].setTokenPresent(true);
			nodeVector[0].setRequestingCS(false);
		}
		else{
			nodeVector[i].setFather(&nodeVector[0]);
			nodeVector[i].setNext(NULL);
			nodeVector[i].setTokenPresent(false);
			nodeVector[i].setRequestingCS(false);
=======
void setRoot(Node n){
	root = n;
	root.setNext(NULL);
	root.setFather(NULL);
	root.setTokenPresent(true);
	root.setRequestingCS(false);
}

void initialization(vector<Node> v){
	for(Node n : v){
		if(n.getID() == 0){
			setRoot(n);
		}
		else{
			n.setFather(&root);
			n.setNext(NULL);
			n.setTokenPresent(false);
			n.setRequestingCS(false);
>>>>>>> 271ee151e52a018c578e91bfc07da48218e0dab8
		}
	}
}

<<<<<<< HEAD
void* initializeRequest(void *i){
	Node *n = (Node*) i;
	n->setRequestingCS(true);
	if(n->getFather() != NULL){
		//sending req to its father
		(n->getFather())->setRequestCollectionBox(n->getID());
		n->setFather(NULL);
	}

	checkInitialization();
}

=======
>>>>>>> 271ee151e52a018c578e91bfc07da48218e0dab8
void requestCS(){
	cout<<"Enter node ID who want to request Critical Section.\nEnter -999 to stop\n";
	vector<int> requestingNodes;
	while(1){
		int id;
		cin>>id;
		if(id==-999)
			break;
		requestingNodes.push_back(id);
	}

<<<<<<< HEAD
	pthread_t threads[requestingNodes.size()];
	cout<<"*******************"<<endl;
	printRequestingID(requestingNodes);
	cout<<"*******************"<<endl;

	for(int i=0; i<requestingNodes.size(); ++i){
		pthread_create(&threads[i], NULL, initializeRequest, (void*)&nodeVector[requestingNodes[i]]);
	}
	
	for(int i=0; i<requestingNodes.size(); ++i){
		pthread_join(threads[i],NULL);
	}

=======
	cout<<"*******************"<<endl;
	printRequestingID(requestingNodes);
	cout<<"*******************"<<endl;
>>>>>>> 271ee151e52a018c578e91bfc07da48218e0dab8
}

int main(){
    int numberOfNodes;
	// cout<<"Enter number of nodes : ";
	cin>>numberOfNodes;

	//setting ID to nodes
	for(int i=0; i<numberOfNodes; ++i){
		Node node;
		node.setID(i);
		nodeVector.push_back(node);
	}

	//printing Node ID
	cout<<"*******************"<<endl;
	printID(nodeVector);
	cout<<"*******************"<<endl;

	//Initialization
<<<<<<< HEAD
	initialization();

	//checkInitialization
	cout<<"*******************"<<endl;
	checkInitialization();
=======
	initialization(nodeVector);

	//checkInitialization
	cout<<"*******************"<<endl;
	checkInitialization(nodeVector);
>>>>>>> 271ee151e52a018c578e91bfc07da48218e0dab8
	cout<<"*******************"<<endl;

	//RequestCS
	requestCS();
    return 0;
}
