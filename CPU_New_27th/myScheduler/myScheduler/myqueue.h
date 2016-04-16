#include <iostream>

using namespace std;

#define max_size 100
#define SUCCESS 1
#define FAILURE 0

/*structure for Pool, Ready, Running and Device Queues*/
template<class elem_type>
struct q_node
{
	elem_type *item;
	q_node *next;									// pointer to next node */
};

template<class elem_type>
class queue
{
	public:
		queue();									// Constructor
		~queue();									// Destructor
		int insert(const elem_type *pcb);			// Insert element
		int remove(elem_type *&x);					// Remove element
		int retrieve(elem_type *&x); 				// Retrieve without remove
		int print();								// Print each element
		int is_queue_empty();						// Check if empty
		int is_queue_full();						// Check if full
		int getnumcount();							// Counter of nodes in queue
private:
		q_node<elem_type> *front;
		q_node<elem_type> *rear;
		q_node<elem_type> *current;
		int num_items;								// Counter of nodes in queue
};

template <class elem_type>
queue<elem_type>::queue()
{
			num_items = 0;
			current=NULL;
			front = NULL;
			rear = NULL;
}

template <class elem_type>
queue<elem_type>::~queue()
{
	cout << "Calling Destructor..." << endl;
	if (num_items == 0)
	{
		cout << "Nothing to delete..." << endl;
	}
	else
	{
		current = front;
		while (current != NULL)
		{
			front = front->next;
			current = NULL;
			delete current;
			current = front;
		}
	}
	cout << "Done." << endl;
}

template <class elem_type>
int queue<elem_type>::insert(const elem_type *pcb)
{
	if ( is_queue_full() == SUCCESS )
	{
		cout << "queue is full!" << endl;
		return FAILURE;
	}
	if (num_items == 0)
	{
		rear = new q_node<elem_type>;
		if (rear == NULL)
			return FAILURE;
		else
		{
			rear->next = NULL;
			front = rear;
		}
	}
	else
	{
		rear->next = new q_node<elem_type>;
		if (rear->next == NULL)
			return FAILURE;
		else
		{
			rear = rear->next;
			rear->next = NULL;
		}
	}
	rear->item = (elem_type*)pcb;
	num_items++;
	return SUCCESS;
}
/* end of insert */

template <class elem_type>
int queue<elem_type>::remove(elem_type *&x)
{
	if ( is_queue_empty() == SUCCESS)
	{
		cout << "queue is empty!" << endl;
		return FAILURE;
	}
	current = front;
	if ( num_items > 1 )
		front = front->next;
	x = current->item;
	current = NULL;
	delete current;
	num_items--;
	return SUCCESS;
} /* end of remove */

template <class elem_type>
int queue<elem_type>::retrieve(elem_type *&x)
{
	if ( is_queue_empty() == SUCCESS)
	{
		cout << "The queue is empty!" << endl;
		return FAILURE;
	}
	x = front->item;
	return SUCCESS;
} /* end of retrieve */

/* Print out elements of queue */
template <class elem_type>
int queue<elem_type>:: print()
{
	if (num_items == 0)
	{
		cout << "No elements in the queue!" << endl;
		return FAILURE;
	}
	cout << "The data element(s) are: ";
	if ( front == rear )
	{
		cout << front->item->process_id << endl;
		return SUCCESS;
	}
	else
	{
		for(current = front ; current != NULL; current = current->next)
		cout << current->item->process_id << " " ;
		cout << endl;
		return SUCCESS;
	}
	return 0;
} /* end of print */

template <class elem_type>
int queue<elem_type>::is_queue_empty()
{
	if ( num_items != 0 )
		return FAILURE;
	else
		return SUCCESS;
}

template <class elem_type>
int queue<elem_type>::is_queue_full()
{
	if ( num_items < max_size )
		return FAILURE;
	else return SUCCESS;
}

template <class elem_type>
int queue<elem_type>:: getnumcount()
{
	return num_items;
}
