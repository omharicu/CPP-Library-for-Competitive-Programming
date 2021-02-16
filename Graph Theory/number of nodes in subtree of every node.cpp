// can calculate weight or number of nodes in subtree of every node by a  little modification
void subtree_weight(int u,int par)
{
	int sum = 1; // or sum = a[u] , if the weight is in array a
	for(int v:g[u])
	{
		if(v==par)
			continue;
		subtree_weight(v,u);
	}
	for(int v:g[u])
	{
		if(v==par)
			continue;
		sum += subtree[v]; 
	}
	subtree[u] = sum;
}
