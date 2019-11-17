#include <bits/stdc++.h>
#include "node.h"

using namespace std;

Node root;
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

void checkInitialization(vector<Node> v){
	for(Node n : v){
		if(n.getID() == 0){
			cout<<root.getID()<<"->"<<root.getFather()<<" "<<root.getNext()<<" "<<root.getTokenPresent()<<" "<<root.getRequestingCS()<<endl;
		}else{	
			cout<<n.getID()<<"->"<<n.getFather()<<" "<<n.getNext()<<" "<<n.getTokenPresent()<<" "<<n.getRequestingCS()<<endl;
		}
	}
	cout<<endl;
}

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
		}
	}
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

	cout<<"*******************"<<endl;
	printRequestingID(requestingNodes);
	cout<<"*******************"<<endl;
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
	initialization(nodeVector);

	//checkInitialization
	cout<<"*******************"<<endl;
	checkInitialization(nodeVector);
	cout<<"*******************"<<endl;

	//RequestCS
	requestCS();
    return 0;
}
