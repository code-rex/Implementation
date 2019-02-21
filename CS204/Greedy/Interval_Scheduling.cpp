#include<bits/stdc++.h>
using namespace std;
struct node{
	int digit;
	struct node* link;
};
struct node* getnode();
void push_to_front(int b,struct node** a);
struct node* convert_string_to_linked_list(string a);
void print(struct node* a);
struct node* add(struct node *a,struct node *b);
struct node* subtract(struct node *a,struct node *b);
struct node* multiply(struct node *a,struct node *b);
struct node* multiply_one_digit_b(struct node *first,int b_digit,int flag);
struct node* power(struct node *a,int b);


int main(){
string a,b;
cout<<"Enter first no."<<endl;
cin>>a;
cout<<"Enter second no."<<endl;
cin>>b;
struct node* first,*second;
first = convert_string_to_linked_list(a);
second = convert_string_to_linked_list(b);
cout<<"Operation : - "<<endl;
cout<<"1. Addition"<<endl;
cout<<"2. Subtraction"<<endl;
cout<<"3. Multiplication"<<endl;
cout<<"4. Exponentiation"<<endl;
int res;
cin>>res;
if(res == 1){
struct node* sum = add(first,second);
cout<<"Answer : "<<endl;
print(sum);
}
else if(res == 2){
struct node* diff = subtract(first,second);
cout<<"Answer : "<<endl;
print(diff);
}
else if(res == 3){
struct node* prod = multiply(first,second);
cout<<"Answer : "<<endl;
print(prod);
}
else if(res == 4){
string a1;
int a2;
cout<<"Enter base"<<endl;
cin>>a1;
cout<<"Enter exponent "<<endl;
cin>>a2;
struct node* b1;
struct node* b3;
b1 = convert_string_to_linked_list(a1);
struct node* exp = power(b1,a2);
cout<<"Answer : ";
print(exp);
}
}

struct node* power(struct node *base,int exp){
	struct node* ans = NULL;
	push_to_front(1,&ans);
	for(int i=1;i<=exp;i++)
	{
		ans = multiply(base,ans);
	}
	return ans;
}
struct node* multiply_one_digit_b(struct node *first,int b_digit,int flag){
	stack<int> s1;
	struct node* temp;
	//push first number in stack1
	temp = first;
	while(temp!=NULL)
		{
			s1.push(temp->digit);
			temp = temp->link;
		}	
		
	for(int i=0;i<flag;i++)
			push_to_front(0,&temp);

	int dig,carry=0;
	while(!s1.empty()){
		dig = carry + s1.top()*b_digit;
		push_to_front(dig%10,&temp);
		carry = dig/10;
		s1.pop();
	}
	
	if(carry!=0)
		push_to_front(carry,&temp);		

	return temp;		
}
struct node* multiply(struct node* a, struct node* b){
	stack<int> s2;
	struct node* temp;
	//push second number in stack1
		temp = b;
		while(temp!=NULL)
		{
			s2.push(temp->digit);
			temp = temp->link;
		}
	struct node* ans=NULL;
	push_to_front(0,&ans);
	int flag=0;
	while(!s2.empty())
	{
		temp = multiply_one_digit_b( a , s2.top(),flag );
		s2.pop();
		ans = add(ans,temp);
		flag++;
		temp = NULL;
	}
	return ans;
}
struct node* subtract(struct node *a,struct node *b){
	//assuming a>b
	stack<int> s1,s2;
	struct node* temp;
	//push first number in stack1
		temp = a;
		while(temp!=NULL)
		{
			s1.push(temp->digit);
			temp = temp->link;
		}
		//push second number in stack2
		temp = b;
		while(temp!=NULL)
		{
			s2.push(temp->digit);
			temp = temp->link;
		}
	temp = NULL;	
	int x,y;
	stack<int> s3;
	
	while(!s2.empty())
	{
		x = s1.top();
		y = s2.top();
		s1.pop();s2.pop();
		if(x>=y)
		{
			push_to_front(x-y,&temp);
		}
		else
		{
			// subtract one from the digit from which we are borrowing
			//write 9-x for other digits
			if(s1.top()==0)
			{
				while(s1.top()==0)
				{
					s3.push( s1.top());
					s1.pop();
				}
				int w = s1.top();
				s1.pop();
				s1.push(w-1);
			// empty the third stack back to first
				while(!s3.empty())
				{
					s1.push(9 - s3.top() );
					s3.pop();
				}
			}
			else
			{
				//subtract one from the next digit
				int w = s1.top();
				s1.pop();
				s1.push(w-1);
			}
		push_to_front(10+(x-y), &temp);
		}
	}
	while(!s1.empty())
	{
		push_to_front(s1.top(),&temp);
		s1.pop();
	}
	//remove 0 from the front;
	if(temp->digit==0)
	{
		while(temp!=NULL && temp->digit==0)
		{
			temp=temp->link;
		}
	}
	if(temp==NULL)
	{
		push_to_front(0,&temp);
	}
	return temp;
}
struct node* add(struct node *a,struct node *b){
	stack<int> s1,s2;
	struct node* temp;
	//push first number in stack1
		temp = a;
		while(temp!=NULL)
		{
			s1.push(temp->digit);
			temp = temp->link;
		}
		//push second number in stack2
		temp = b;
		while(temp!=NULL)
		{
			s2.push(temp->digit);
			temp = temp->link;
		}	//redundant but written for clarity
	temp = NULL;
	int carry = 0;
	int digsum;
	
	while(!s1.empty() && !s2.empty())
	{
		digsum = carry + s1.top() + s2.top();
		push_to_front(digsum%10,&temp);
		carry = digsum/10;
		s1.pop();s2.pop();
	}
	if(!s1.empty()){
		while(!s1.empty())
		{
		digsum = carry + s1.top();
		push_to_front(digsum%10,&temp);
		carry = digsum/10;
		s1.pop();		
		}
	}
	if(!s2.empty()){
		while(!s2.empty())
		{
		digsum = carry + s2.top();
		push_to_front(digsum%10,&temp);
		carry = digsum/10;
		s2.pop();		
		}
	}	
	
	if(carry!=0)
		push_to_front(carry,&temp);	
	return temp;
}
void print(struct node* a){
	while(a!=NULL)
	{
		cout<<a->digit;
		a = a->link;
	}
}
struct node* getnode(){
	return (new struct node);
}
struct node * convert_string_to_linked_list(string a){
	struct node	*p = NULL;
	int l = a.length();
	int digit;
	while(l--)
	{
		digit = int(a[l]) - 48;
		push_to_front(digit,&p);
	}
	return p;
}
void push_to_front(int digit,struct node **p){
	struct node* temp = getnode();
	temp->digit = digit;
	temp->link = *p;
	*p = temp;
}
