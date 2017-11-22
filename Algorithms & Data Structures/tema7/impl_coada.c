#include <iostream>

using namespace std;

struct nod{
	int data;
	nod *next;
}*head, *tail;

nod *new_nod(int data)
{
	nod *temp;
	temp = new nod;
	temp->data = data;
	temp->next = NULL;

	return temp;
}

void af()
{
	nod *temp = head;

	if(head)
	{
	cout<<"out  ";
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"in"<<endl;
}
	else
		cout<<"coada vida\n";
}

void push(int data)
{	
	if(head == NULL)
	{
		head = new_nod(data);
		tail = head;
	}
	else
	{
		tail->next = new_nod(data);
		tail = tail->next;
	}
}

int pop()
{
	if(head)
	{
		int c = head->data;
		nod *temp = head;
		head = head->next;
		delete temp;
		return c;
	}
	else
		return -1;
}

int peek()
{
	if(head)
		return head->data;
	else
		return -1;
}

int empty()
{
	if(head)
		return 0;
	else
		return 1;
}

int search(int arg)
{
	nod *temp=head;

	int i = 1;
	while(temp)
	{
		if(temp->data == arg)
			return i;
		i++;
		temp = temp->next;
	}
	return -1;
}

int main()
{
	af();
	push(1);
	push(2);
	push(3);
	af();
	cout<<search(2)<<endl;
	cout<<search(4)<<endl;
	cout<<empty()<<endl;
	cout<<pop()<<endl;
	af();
	cout<<peek()<<endl;
	af();
	pop();
	pop();
	af();
	cout<<pop()<<endl;
	cout<<empty()<<endl;

	return 0;
}