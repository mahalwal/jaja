#include<bits/stdc++.h>

using namespace std;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
      cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
      const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

struct node
{
	int data;
	struct node* next;
}*head;


void insert(int val)
{
	if(head==NULL)
	{
		head->data = val;
		head->next = NULL;
		return;
	}
	struct node* temp = head;

	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = new node;
	temp->next->data = val;
	temp->next->next = NULL;
}

void print()
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		cout << temp->data << '\n';
		temp = temp->next;
	}
}

int main()
{
	head = new node;
	head->data = 1;
	head->next = NULL;
	insert(20);
	print();
}