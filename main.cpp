#include <bits/stdc++.h>
#include "node.h"

using namespace std;

void IDAssigningMethod(int numberOfNodes){
	vector<Node> nodeVector;

	for(int i=0; i<numberOfNodes; ++i){
		Node node;
		node.setID(i);
		nodeVector.push_back(node);
	}

	for(Node n : nodeVector)
		cout<<n.getID()<<" ";
	cout<<endl;
}

int main()
{
    int numberOfNodes;
	cout<<"Enter number of nodes : ";
	cin>>numberOfNodes;

	//setting ID to nodes
	IDAssigningMethod(numberOfNodes);
	
    return 0;
}
