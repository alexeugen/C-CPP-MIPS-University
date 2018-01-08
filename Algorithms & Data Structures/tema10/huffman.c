#include <iostream>

using namespace std;


struct vheap{
	int val;
	int pon;
	vheap *left;
	vheap *right;
};


vheap *v[100];


int n = 5;
vheap w[10];
int cn = n;

/*
void max_heapify(int i)
{
	int l = 2*i;
	int r = 2*i + 1;
	int max;
	int aux;

	if(l<n && v[l].pon > v[i].pon)
		max = l;
	else
		max = i;
	if(r<n && v[r].pon > v[max].pon)
		max = r;
	if(max != i)
	{	
		vheap aux = v[i];
		v[i] = v[max];
		v[max] = aux;
		max_heapify(max);
	}
}
*/
void min_heapify(int i)
{
	int l = 2*i;
	int r = 2*i + 1;
	int min;
	int aux;

	if(l<n && v[l]->pon < v[i]->pon)
		min = l;
	else
		min = i;
	if(r<n && v[r]->pon < v[min]->pon)
		min = r;
	if(min != i)
	{	
		vheap *aux;
		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
		min_heapify(min);
	}
}
/*
void max_heap()
{
	for(int i = (n-1)/2; i>=0; i--)
		max_heapify(i);
}
*/
void min_heap()
{
	for(int i = (n-1)/2; i>=0; i--)
		min_heapify(i);	
}
/*
void heap_sort()
{
	int k = 0;

	while(k<cn)
	{
		w[k++] = v[0];
		v[0] = v[n-1];
		n--;
		max_heapify(0);
	}
}
*/

void insert(int va, int p)
{
	v[n]->val = va;
	v[n]->pon = p;
	int i = n;
	n++;
	while(i/2 != 0 && v[i/2]->pon < v[i]->pon)
	{
		min_heapify(i/2);
		i = i/2;
	}
}

void insert_nod(vheap *nod)
{
	
	v[n] = nod;
	int i = n;
	n++;

	while(i/2 != 0 && v[i/2]->pon < v[i]->pon)
	{
		min_heapify(i/2);
		i = i/2;
	}

}

vheap *extract()
{
	vheap *temp = v[0];
	v[0] = v[n-1];
	n--;
	min_heapify(0);
	return temp;
}

vheap *new_nod(vheap *p1, vheap *p2)
{
	vheap *temp;
	temp = new vheap;
	temp->pon = p1->pon + p2->pon;
	temp->left = p1;
	temp->right = p2;
	return temp;
}

void huffman()
{
	while(n>1)
	{
		for(int i =0; i<n; i++)
			cout<<v[i]->pon<<" ";
		cout<<endl;

		vheap *temp1 = extract();
		vheap *temp2 = extract();
		
		cout<<temp1->pon<<" "<<temp2->pon<<endl;
		vheap *nod = new_nod(temp1, temp2);
		insert_nod(nod);
	}
}


void inorder(vheap *temp)
{
	if(temp)
	{
	
		//if(!temp->left && !temp->right)
			
	//	else
	//	{
			inorder(temp->left);
			cout<<temp->pon<< " ";
			inorder(temp->right);
	//	}
	}
}


int main()
{
	for(int i=0; i<100; i++)
		v[i] = new vheap;
	*v[0] = {8, 3, NULL, NULL};
	*v[1] = {5, 1, NULL, NULL};
	*v[2] = {7, 6, NULL, NULL};
	*v[3] = {13, 18, NULL, NULL};
	*v[4] = {17, 5, NULL, NULL};



/*                      49                        */
/*                   /       \                      */
/*                 18*         31                   */
/*                          /     \            */
/*                        14       17*             */
/*                      /    \                 */
/*                     8      6*               */
/*                    / \                     */
/*                   3*  5*                    */
/*                                           */
/*                                           */
/*                                           */
/*                                           */
/*                                           */

	min_heap();
	for(int i = 0; i<n; i++)
		cout<<v[i]->pon<<" ";
	cout<<'\n';
	insert(5, 17);
	for(int i = 0; i<n; i++)
		cout<<v[i]->pon<<" ";

	cout<<'\n';
	extract();
	for(int i = 0; i<n; i++)
		cout<<v[i]->pon<<" "; 
	cout<<'\n';

	huffman();
	
	cout<<v[0]->pon<<endl;
	inorder(v[0]);
	return 0;
}