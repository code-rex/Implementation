#include<bits/stdc++.h>
using namespace std;
struct Trie
{
	bool isendofword;
	unordered_map<char,Trie*>map; //for only alphabet vector can be used of size 26 
};
Trie* getnewtrie()
{
	Trie* trie=new Trie;
	trie->isendofword=false;
	return trie;
}
void insert(Trie*& root,const string &str)
{
	if(root==nullptr)
		root=getnewtrie();

	Trie* temp=root;
	for(int i=0;i<str.length();i++)
	{
		if(temp->map.find(str[i])==temp->map.end())
			temp->map[str[i]]=getnewtrie();
		temp=temp->map[str[i]];
	}
	temp->isendofword=true;
}
bool search(Trie* root,const string &str)
{
	if(root==nullptr)
		return false;

	Trie* temp=root;
	for(int i=0;i<str.length();i++)
	{
		temp=temp->map[str[i]];
		if(temp==nullptr)
			return false;
	}
	return temp->isendofword;
}
void printTrie(Trie *root,char st[],int level)
{
	if(root->isendofword)
	{
		st[level]='\0';
		cout<< st<< endl;
	}

	unordered_map<char,Trie*>:: iterator itr;
	char next;
	for(itr = root->map.begin();itr!=root->map.end();itr++)
	{
		next=itr->first;
		st[level]=itr->first;
		printTrie(root->map[next],st,level+1);
	}
}
bool Prefixsearch(Trie* root,string pre)
{
	if(root==nullptr)
		return false;

	Trie* temp=root;
	for(int i=0;i<pre.length();i++)
	{
		temp=temp->map[pre[i]];
		if(temp==nullptr)
			return false;
	}
	//Finding/Printing all word starting from that prefix
	//TODO
	return true;
}
// returns true if given node has any children
bool haveChildren(Trie const* curr)
{
	// don't use (curr->map).size() to check for children

	for (auto it : curr->map)
		if (it.second != nullptr)
			return true;

	return false;
}
// Recursive function to delete a string in Trie.
bool deletion(Trie*& curr, char* str)
{
	// return if Trie is empty
	if (curr == nullptr)
		return false;

	// if we have not reached the end of the string
	if (*str)
	{
		// recur for the node corresponding to next character in
		// the string and if it returns true, delete current node
		// (if it is non-leaf)
		if (curr != nullptr &&  curr->map.find(*str) != curr->map.end() &&
			deletion(curr->map[*str], str + 1) && curr->isendofword == false)
		{
			if (!haveChildren(curr))
			{
				delete curr;;
				curr = nullptr;
				return true;
			}
			else {
				return false;
			}
		}
	}

	// if we have reached the end of the string
	if (*str == '\0' && curr->isendofword)
	{
		// if current node is a leaf node and don't have any children
		if (!haveChildren(curr))
		{
			delete curr;; // delete current node
			curr = nullptr;
			return true; // delete non-leaf parent nodes
		}

		// if current node is a leaf node and have children
		else
		{
			// mark current node as non-leaf node (DON'T DELETE IT)
			curr->isendofword = false;
			return false;	   // don't delete its parent nodes
		}
	}

	return false;
}
int main()
{
	Trie* root=nullptr;
	while(1)
	{
		cout<<"1.Insert"<<endl;
		cout<<"2.Search"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Prefix Search"<<endl;
		cout<<"5.Delete String"<<endl;
		cout<<"6.Exit"<<endl;
		int n;
		cin>>n;
		if(n==1)
		{
			string s;
			cin>>s;
			insert(root,s);
		}
		else if(n==2)
		{
			string s;
			cin>>s;
			cout<<search(root,s)<<endl;;
		}
		else if(n==3)
		{
			int level=0;
			char s[26]={0};
			printTrie(root,s,level);
		}
		else if(n==4)
		{
			string s;
			cin>>s;
			cout<<Prefixsearch(root,s)<<endl;;
		}
		else if(n==5)
		{
			char* s;
			cin>>s;
			deletion(root,s);
		}
		else if(n==6)
			exit(0);
	}
	return 0;
}
