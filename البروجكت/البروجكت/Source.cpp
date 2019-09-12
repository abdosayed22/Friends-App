#include<iostream>
#include<string>
#include<assert.h>
using namespace std ;
template<class T>
class Node
{
public :

	T data ;

	Node * next ;

	Node()
	{
		data = 0 ;
		next = NULL ;
	}
	Node(T value)
	{
		data = value ;
		next = NULL;
	}
	
};

template<class T>
class LinkedList
{
	Node<T> *head ;
	Node<T> *tail ;
public:
	int size ;

	LinkedList()
	{
		head = tail = NULL ;
		size = 0 ;
	}
	void Append(T value)
	{
		Node<T> * temp = new Node<T>(value);
		if(head == NULL)
			head = tail = temp ;
		else
		{
			tail->next = temp ;
			tail = tail-> next ;
			
		}
		size ++ ;
	}
	void insertAt(T value , int pos)
	{
		assert(pos >= 0 && pos < size);
		Node *temp = head ;
		Node * newNode = new Node(value);
		if(pos == 0 )
		{
			newNode->next = head ;
			head = newNode ;
		}
		else
		{
			for(int i = 0 ; i < pos-1 ; i++)
			{
				temp = temp->next ;
			}

				newNode->next = temp->next ;
				temp->next = newNode ;
			

		}
		size ++ ;

	}

	void deleteAt(int pos)
	{
		assert(pos >= 0 && pos < size);
		Node<T> * temp = head ;
		if(pos == 0 )
		{
			head = head->next ;
			delete temp ;
		}
		else
		{
			for(int i = 0 ; i < pos-1 ; i++)
			{
				temp = temp->next ;
			}
			Node<T> *del = temp->next ;
			temp->next = del->next ;
			delete del ;
			if(pos == (size-1))
				tail = temp ;
			size -- ;
		}
	}

	bool deleteID (int id )
	{
		Node<user> * temp = head ;
		int pos = 0 ;
		while(temp != NULL)
		{
			if(temp->data.id == id)
			{
				deleteAt(pos);
				return true ;
			}
			temp = temp->next ;
			pos ++ ;
		}
		return false ;
		
	}

	void display ()
	{
		Node<T> * temp = head ;
		while(temp != NULL)
		{
			
				cout << temp->data.id << "\t"; 
				cout << temp->data.name << endl;
			temp = temp->next ;
		}
	}
	void displayString ()
	{
		Node<T> * temp = head ;
		while(temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next ;
		}
	}
	T login (int id , string password)
	{
		Node<T> * temp = head ;
		while(temp != NULL)
		{
			if(temp->data.id == id && temp->data.password == password)
			{
				return temp->data ;
			}
			temp = temp->next ;
		}
		temp->data.id  = -1;
		return temp->data ;
	}
	T search (int id )
	{
		Node<T> * temp = head ;
		while(temp != NULL)
		{
			if(temp->data.id == id)
			{
				return temp->data ;
			}
			temp = temp->next ;
		}
		temp->data.id  = -1;
		return temp->data ;
	}
};


class user
{
public :


	// attri
	int id ;
	string name;
	string password;
	LinkedList<user> friends;
	LinkedList<string> intrests ;

	// fun
	void addFriend(user u)
	{
		friends.Append(u);
	}
	void addIntrest(string i)
	{
		intrests.Append(i);
	}
	void displayFriends()
	{
		friends.display();
	}
	void displayIntrests()
	{
		intrests.displayString();
	}

	
	void displayCI()
	{}
	void searchName (string name)
	{}
	void searchIntrest()
	{}
	void searchCommon()
	{}
	void searchFriend()
	{}
};


LinkedList<user> users ;

user addUser(LinkedList<user> l)
{
	user u ;
	cout << "enter id \t"  ;
	cin >> u.id ;
	cout << "enter name \t";
	cin >> u.name ;
	cout << "enter password \t";
	cin >> u.password ;
	cout << "enter id for friend you want to add \n enter -1 skip"<<endl;
	int id ;
	id = 10 ;
	while (id != -1 )
	{
		cin >> id ;
		if(id != -1)
		u.friends.Append(l.search(id));
	}
	cout << "enter intrest you want to add \n enter -1 skip"<<endl;
	string intrest ;
	intrest = "test";
	while (intrest != "-1" )
	{
		cin >> intrest ;
		if(intrest != "-1")
		u.intrests.Append(intrest);
	}
	int i ;
	do
	{
	cout << "select 1 to display your friends"<<endl;
	cout << "select 2 to display your intrests"<<endl;
	cout << "select -1 to logout " <<endl;
	 
	
	cin >> i ;
	if(i == 1 )
		u.displayFriends();
	else if(i == 2 )
		u.displayIntrests();
	}
	while(i != -1);
	return u ;
}

void signup()
{
	users.Append(addUser(users));
}


void login()
{
			string  check ="" ;
			cout << "enter your id"<<endl;
			int id;
			cin >> id ;
			user user1 =users.search(id);
			if(user1.id != id)
			{
				check = "error id" ;
			}
			cout << "enter your password"<<endl;
			string pass ;
			cin >> pass ;
			user1 =users.login(id, pass);
			if(user1.password != pass)
			{
				check = "error password" ;
			}
			if(check == "")
			{
				cout << "hello "<<user1.name << endl;
				cout << "select 1 for adding new friend"<<endl;
				cout << "select 2 to delete friend "<<endl;
				cout << "select 3 to display certain friend's inrests " <<endl;
				cout << "select 4 to search user"<<endl;
				cout << "select -1 to close the program"<<endl;
				bool b = true;
				int choice1 ;
				cin >> choice1 ;
				if(choice1 ==1 )
				{
					cout << "enter id belong's friend you want to add " <<endl;
					cin >> id ;
					user u1 =  users.search(id);
					if(u1.id != -1)
					{
						user1.friends.Append(u1);
						cout << "adding success"<<endl;
					}
					else
					{
						cout << "there is no user has this id"<<endl;
					}
				}
				else if(choice1 ==2 )
				{
					cout << "enter id of friend you want delete " <<endl;
					cin >> id ;
					user1.friends.deleteID(id);
				}
				else if(choice1 ==3 )
				{
					cout << "enter id of friend you want show intrests " <<endl;
					cin >> id ;
					user1.friends.search(id).intrests.displayString();

				}
				else if(choice1 ==4 )
				{
					users.display();
				}
				else if(choice1 == -1 )
				{
					return ;
				}
				else 
				{
					cout << "try again"; 
				}
			}
}

void main()
{
	while (true)
	{
		cout << "select 1 to sign up "<<endl;
		cout << "select 2 to login  "<<endl;
		int choice ;
		cin >> choice ;
		if(choice == 1)
		{
			signup();
		}
		else if(choice == 2)
		{
			login();
		}
	}

	while(true)
	{
		
		cout << "select 1 for adding user"<<endl;
		cout << "select 2 to search for user "<<endl;
		cout << "select 3 to display all users " <<endl;
		cout << "select 4 to delete user"<<endl;

		int select ;
		cin >> select ;
		switch (select)
		{
		case 1 : 
			{
				users.Append(addUser(users));
				break;
			}
		case 3 :
			{
				users.display();
				break;
			}
		}
	
	}

}