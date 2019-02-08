#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
#define ll long long int
#define mod 1000000007
#define printa(arr,n) for(int ia=0;ia<n;ia++)cout<<arr[ia]<<" "
#define inputa(arr,n) for(int ia=0;ia<n;ia++)cin>>arr[ia]

template<typename T>
class queue{
	T data;
	queue* head;
	queue* tail;
	queue* next;
	int queue_size;
	queue(T data){
		this->data=data;
		next=NULL;
		head=NULL;
		tail=NULL;
	}

	//Linked List implementatio of queue 
	void Linked_List_Update(T data,int operationType){
		if(operationType==0){
			queue* nextElement=head->next;
			head=nextElement;
		}
		else if(operationType==1){
			if(head==NULL){
				queue* newNode=new queue<T>(data);
				head=newNode;
				tail=newNode;
			}
			else{
				queue* newNode=new queue<T>(data);
				tail->next=newNode;
				tail=newNode;
			}
		}	
	}
public:
	queue(){
		queue_size=0;
		next=NULL;
		head=NULL;
		tail=NULL;
	}

	//Size of the queue.
	int size(){
		return queue_size;
	}

	//Push an element into the queue.
	void push(T data){
		Linked_List_Update(data,1);
		queue_size++;
	}

	//Pop an element from the queue.
	void pop(){
		if(queue_size==0){
			cout<<"No element present in the queue";
			throw -1;
		}
		else{
			Linked_List_Update(data,0);
			queue_size--;
		}
	}

	//Get the front element of queue.
	T front(){
		if(head==NULL) {
			cout<<"No element is there in the queue \n";
			throw -1;
		}
		else{
			return head->data;
		}
	}

	//Get the back element of the queue.
	T back(){
		if(tail==NULL) {
			cout<<"No element is there in the queue \n";
			throw -1;
		}
		else{
			return tail->data;
		}	
	}

	//Check for empty queue
	bool empty(){
		if(queue_size==0)return true;
		return false;
	}
};


int main(){
	queue<string> prab;
	prab.push("abc");
	prab.push("bcd");
	cout<<prab.front()<<" ";
	cout<<prab.back()<<" ";
	cout<<prab.size()<<" ";
	prab.pop();
	prab.pop();
	cout<<prab.size()<<endl;
	prab.push("abc");
	prab.push("bcd");
	prab.push("abc");
	prab.push("bcd");

	cout<<prab.front()<<" ";
	cout<<prab.back()<<" ";
	cout<<prab.size()<<" ";
}