#include <bits/stdc++.h>
#include "node.h"

using namespace std;

int main()
{
    int numberOfNodes;
	// cout<<"Enter number of nodes : ";
	cin>>numberOfNodes;
	vector<Node> nodeVector;

	//setting ID to nodes
	for(int i=0; i<numberOfNodes; ++i){
		Node node;
		node.setID(i);
		nodeVector.push_back(node);
	}
	for(Node n : nodeVector)
		cout<<n.getID()<<" ";
    return 0;
}
