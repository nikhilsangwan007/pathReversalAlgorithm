#include <bits/stdc++.h>
#include <pthread.h>
#include "node.h"

using namespace std;

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

void checkInitialization(){
	for(Node n : nodeVector){
		if(n.getID() == 0){
			cout<<n.getID()<<"->"<<"[ father : "<<n.getFather()<<" ][ "<<" next : "<<n.getNext()<<" ][ "<<" token : "<<n.getTokenPresent()<<" ][ "<<" requestingCS : "<<n.getRequestingCS()<<" ]"<<endl;
		}else{	
			cout<<n.getID()<<"->"<<"[ father : "<<n.getFather()<<" ][ "<<" next : "<<n.getNext()<<" ][ "<<" token : "<<n.getTokenPresent()<<" ][ "<<"requestingCS :"<<n.getRequestingCS()<<" ]"<<endl;
		}
	}
	cout<<endl;
}


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
		}
	}
}

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
	initialization();

	//checkInitialization
	cout<<"*******************"<<endl;
	checkInitialization();
	cout<<"*******************"<<endl;

	//RequestCS
	requestCS();
    return 0;
}
