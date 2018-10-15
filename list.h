#ifndef List_H
#define List_H

#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class List
{
private:

	// struct for singly-linked List nodes
	struct Node
	{
		T      data;
		Node   *next;

		Node(const T & d = T{}, Node * n = nullptr)
			: data{ d }, next{ n } { }

	};

	// HELPER FUNCTION TO PRINT THE List IN REVERSE ORDER.
	void reverse_print(Node* head, Node* tail) const
	{
		if (head == NULL)
		{
			return;
		}
		else
		{
			//cout << "Enter  ";
			reverse_print( head->next, tail);
			//cout << "Exit  ";
			cout << head->data << " ";
		}

	}
	// HELPER FUNCTION FOR MERGING THE LIST.
	Node *merge_sorted(Node *lis1, Node *lis2)
	{
		if (lis1 == NULL)
		{
			return lis2;
		}

		if (lis2 == NULL)
		{
			return lis1;
		}

		if (lis1->data < lis2->data)
		{
			lis1->next = merge_sorted(lis1->next, lis2);
			return lis1;
		}
		else
		{
			lis2->next = merge_sorted(lis1, lis2->next);
			return lis2;
		}
	}

	// HELPER FUNCTION TO PUSH NODES WITH POINTERS.
	void pushNode_withPointers(Node* add)
	{
		// Adding the nodes in to filter list by assigning pointer to current nodes.
		if (front == NULL)
		{
			front = add;
			back = add;
		}
		else
		{
			back->next = add;
			back = add;
		}
	}

	// Recursive helper function to return the greatest elem.
	int search_greatestNum(Node *curr)
	{
		int current = curr->data;
		int next_elem;

		// Base case for the the comparison. Recursion Process.
		if (curr->next == NULL)
		{
			return current;
		}
		else
		{
			next_elem = search_greatestNum(curr->next);
		}
		// Comparison by back tracking.
		if (next_elem < current)
		{
			return current;
		}
		else
		{
			return next_elem;
		}
	}





public:
	// constructors
	List() {
		init();
	}

	~List() {
		clear();
	}
	/**
	* Disclaimer:  C++ conventions tell us that we should have a couple
	* of additional constructors here (a copy constructor, assignment operator
	* etc.)
	*
	* However, to keep things simple for now we will ignore that convention
	* (since the exposure to C++ is pretty variable it seems -- some students
	* having taken 141 before last semester; some students coming from 107,
	* etc.)
	*/


	/**
	* function: clear
	* desc:  makes the calling List empty (but the List still
	*        exists).
	*/
	void clear() {
		Node * p = front;
		Node *pnext;

		while (p != nullptr) {
			pnext = p->next;
			delete p;
			p = pnext;
		}
		front = back = nullptr;
	}





	/**
	* TODO-----1                                 DONNNEEEEEEEEEEEEEEEE
	*
	* function: length
	* desc:  returns the length of the calling List
	*
	* REQUIREMENTS:  this is a working implementation, but
	*   it takes linear time.
	*
	*   Your job (todo):  make modifications so that this
	*     operation becomes constant time (O(1)).
	*
	*   This task is different from most others in that most of
	*       the "real" work you do to make this work
	*	in O(1) time will be in _other_ functions which affect
	*	the length of Lists.
	*
	*	HINT:  you are free to add data members to the List class...
	*	       maybe for "bookkeeping"??
	*/
	int length() const {
		
		return numElements;
	}


public:

	// Return true if the List is empty, false otherwise.
	bool is_empty() const {
		return front == nullptr;
	}


	void print() const {
		Node *p = front;

		cout << "[ ";
		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << "]\n";
	}

	//Push the values in front of the node.
	void push_front(const T & data) 
	{
		numElements++;
		front = new Node(data, front);

		if (back == nullptr)
			back = front;
	}

	bool pop_front(T &val) {
		Node *tmp;

		if (front == nullptr)
			return false;
		val = front->data;

		tmp = front;
		front = front->next;
		delete tmp;
		if (front == nullptr)
			back = nullptr;
		numElements--;
		return true;
	}
	//Push the values in back of the node.
	void push_back(const T & val) 
	{
		numElements++;
		Node *tmp = new Node(val, nullptr);

		if (front == nullptr) {
			front = back = tmp;
		}
		else {
			back->next = tmp;
			back = tmp;
		}
	}

	bool remove_first(const T &x) 
	{
		Node *p, *tmp;
		T dummy;

		if (front == nullptr) return false;
		if (front->data == x) {
			pop_front(dummy);
			return true;
		}
		p = front;
		while (p->next != nullptr) 
		{
			if (x == p->next->data) 
			{
				tmp = p->next;
				p->next = tmp->next;
				if (tmp == back)
					back = p;
				delete tmp;
				return true;
			}
			p = p->next;
		}
		return false;
	}

	int slow_remove_all(const T &x) {
		int n = 0;

		while (remove_first(x))
			n++;
		return n;
	}

	bool is_sorted() const {
		Node *p = front;

		while (p != nullptr && p->next != nullptr) {
			if (p->data > p->next->data)
				return false;
			p = p->next;
		}
		return true;
	}





	/** TODO------------------------2                   DONEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE..
	*    function:  count
	*     description:  Counts number of occurrences
	*     		of x in the List and returns that count.
	*
	*  REQUIRMENT:  Linear runtime (O(n) where n is the length
	*    of the List.)
	*/
	int count(const T &x) const 
	{
		Node*p = front;
		int count = 0;
		// if list is empty
		if (p == NULL)
		{
			return 0;
		}

		// Traversing the list.
		while (p != NULL)
		{
			// MATCH FOUND.
			if (p->data == x)
			{
				count++;
			}
			p = p->next;

		}
		return count;
	}

	/* TODO---------3.                          DONE!!!!!!!!!!!!!!!!!!!!!!!!
	*
	*  function:  pop_back
	*
	*  if List is empty, we do nothing and return false
	*  otherwise, the last element in the List is removed, its
	*      value (data field) is assigned to the reference parameter
	*      data (so the removed element can be 'passed-back' to the
	*      caller) and true is returned.
	*
	*  REQUIRMENT:  Linear runtime (O(n) where n is the length
	*    of the List.)
	*
	*/
	bool pop_back(T &data) 
	{
		// if list is empty
		if (front == NULL)
		{
			return false;
		}

		// if list has one node.
		if (front->next == NULL)
		{
			delete front;
			front = NULL;
			return true;
		}
		// Declaring two 2 nodes that traverses parallely next to each other in the List.
		Node* previousEnd = front;
		Node* End = front->next;

		while (End->next!= NULL)
		{
		//	cout << "hello";
			previousEnd = End;
			End = End->next;	
		}
		
		data = End->data;
		previousEnd->next = NULL;
		delete End;
		back = previousEnd;
		numElements--;
		return true; 
	}  

	/**
	* TODO:-----------4                                     DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!-- NEED SOME WORK I GUESS
	*   function:  equal_to
	*   description:  returns true if calling List and parameter
	*      List other contain exactly the same sequence of values.
	*      Returns false otherwise.
	*
	*  REQUIRMENT:  Linear runtime (O(n) where n is the length
	*    of the shorter of the two Lists.
	**/
	bool equal_to(const List<T> &other) const 
	{
		//cout << " enter";
		Node*l1 = front;
		Node*l2 = other.front;

		if (numElements != other.numElements)
		{
			return false;
		}

		while (l1!= NULL)
		{
			if (l1->data == l2->data)
			{
				//cout << " match found";
				l1 = l1->next;
				l2 = l2->next;
			}
			else 
			{
				return false;
			}	
		}

		return true;
	}

	/**
	* TODO:  print in reverse order------------5                DONNEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
	*
	* Try to do without looking at notes!
	* Hints:  recursive helper function
	*
	*  REQUIRMENT:  Linear runtime (O(n) where n is the length
	*    of the List.)
	*/
	

	/* TODO -----------6										LEFT                                                  
	*  For full credit, you cannot allocate any new memory!
	*
	*  description:  self-evident
	*
	*  REQUIRMENT:  Linear runtime (O(n) where n is the length
	*    of the List.)
	*/
	// PRINT THE ELEMENT IN REVERSE ORDER.
	void print_rev() const 
	{
		//cout << " Elements in reverse order are: ";
		//cout << back->data << " ";
		// Calling the helper function.
		reverse_print(front, back);
		cout << endl;
	}

	// MAKE THE List ENTIRELY REVERSE.
	void reverse()
	{
		Node*curr = front;
		Node*prev = NULL;
		Node*n;

		// Traversing the list and reversing the pointers.
		while (curr != NULL)
		{
			n = curr->next;
			curr->next = prev;
			prev = curr;
			curr = n;
		}
		back = front;
		front = prev;
	}



	/** TODO-------7                               DONNEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
	*   function:  fast_remove_all
	*   description:  same behavior/semantics as
	*      slow_remove_all.  However, this function
	*      must guarantee linear time worst case
	*      runtime (hence, "fast").
	*
	*   REQUIREMENT:  linear worst-case runtime.
	*
	*   Note:  your solution may be either recursive or
	*   iteratieve.
	**/

	
	int fast_remove_all(const T &x) 
	{
		Node*prev = front;
		Node*current = front;
		int n = 0;
		//cout << x << endl;

		// if list is empty
		if (current == NULL)
		{
			return 0;
		}


		while (current != NULL)
		{
				// Conditional for Match found.
			if(current->data==x)
			{
			//	cout << " MATCH FOUND";
				n++;
				if (current == front)
				{
					front = current->next;
					delete current;
					current = front;
					numElements--;
				}
				else
				{
				//	cout << "Enter" << endl;
					//cout << "Now previ is " << prev->data << endl;
					prev->next = current->next;
				//	cout << "Now previ of next is " << prev->next->data << endl;
					delete current;
					current = prev->next;
					numElements--;
					//cout << "Now current is " << current->data << endl;}
				}

			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		return n;
	}

	/** TODO-------8                        DONE
	* function:  insert_sorted
	*
	* description:  assumes given List is already in sorted order from
	*     smallest to largest and inserts x into the appropriate position
	* 	   retaining sorted-ness.
	* Note 1:  duplicates are allowed.
	*
	* Note 2:  if given List not sorted, behavior is undefined/implementation
	* 		dependent.  We blame the caller.
	* 		So... you don't need to check ahead of time if it is sorted.
	*
	*
	* REQUIREMENTS:
	*
	*   O(n) runtime
	*/


	void insert_sorted(const T &x)
	{

		if (front == NULL)
		{
			"List IS EMPTY";
			return;
		}


		Node*prev = front;
		Node*current = front->next;
		/*	if (current == NULL)
		{
		if (prev->data <= x)
		{
		Node*temp = new Node(x, prev->next);
		prev->next = temp;
		back = temp;
		numElements++;
		}
		}*/

		if (prev->data >= x)
		{
		//	cout << "yessssssssssssssss" << endl;
			Node*temp = new Node(x, prev);
			prev = temp;
			current = prev->next;
			front = prev;
			numElements++;
			return;
		}

		if (back->data < x)
		{
		//	cout << "yessssssssssssssss" << endl;
			Node*temp = new Node(x, back->next);
			back->next = temp;
			back = temp;
			numElements++;
			return;
		}

		while (current != NULL)
		{
			//cout << "Enter" << endl;
			if (current->data >= x && prev->data < x)
			{
				//	cout << "Yes match found" << endl;
				Node*temp = new Node(x, prev->next);
				prev->next = temp;
				prev = temp;
				numElements++;
			}

			else
			{
				prev = current;
				current = current->next;
			}
		}
	}


	
	/** TODO--------------------------------------------9        LEFTTTTTTTTTTTTT
	* function:  merge_with
	*
	* description:  assumes both List a and b are in
	* 	sorted (non-descending) order and merges them
	* 	into a single sorted List with the same
	* 	elements.
	*
	* 	This single sorted List is stored in a while
	* 	b becomes empty.
	*
	* 	if either of given Lists are not sorted,
	* 	we blame the caller and the behavior is
	* 	implementation dependent -- i.e., don't worry
	* 	about it!
	*
	*      Condition in which both parameters are the same
	*      List (not merely "equal"), the function simply
	*      does nothing and returns.  This can be tested
	*      with simple pointer comparison.
	*
	* 	Example:
	*
	* 		a:  [2 3 4 9 10 30]
	* 		b:  [5 8 8 11 20 40]
	*
	* 		after call a.merge_with(b):
	*
	* 		  a:  [2 3 4 5 8 8 9 10 11 20 30 40]
	* 		  b:  []
	*
	*
	* REQUIREMENTS:
	*
	* 	Runtime Must be linear in the length of the
	* 	resulting merged List (or using variables above,
	* 	O(a.length()+b.length()).
	*
	*  should not allocate ANY new List
	* 	nodes -- it should just re-link existing
	* 	nodes.
	*/
	

		
			void merge_with(List &other)
			{
			    // Doing merge by recursion. Hence, sending the fronts of two list and return the new front node for calling list.

				//If two list are same.
				if (front == other.front)
				{
					return;
				}

				// Return if both list are empty.
				if (front == NULL && other.front == NULL)
				{
					return;
				}
				// Return if merge list is empty.
				if (other.front == NULL && front != NULL)
				{
					return;
				}

				// Merge the elements from merge list to orig list and make merge list empty.
				if (other.front !=NULL && front == NULL)
				{
					front = other.front;
					other.front = NULL;
					numElements = other.numElements;
					other.numElements = 0;
					return;
				}


				// Calling the helper function to merge the list.
				front = merge_sorted(front, other.front);
				//front = merge(other.front, front);
				other.front = NULL;

				//Update size of orig list and merge list.
				numElements = numElements + other.numElements;
				other.numElements = 0;
				//print();
			}




	/**
	* TODO---------------------------10          DONEEEEEEEEEEEEEEEE-------
	* function:  clone
	*
	* description:  makes a "deep copy" of the given List a
	*   and returns it (as a List pointer).
	*
	* NOTE:  this functionality would normally be folded into
	*  a "copy constructor"
	*
	*/
	List * clone() const    
	{
		//cout << "Enter in clone";
		List<T>* List_new = new List<T>();

		Node* temp = front;

		// LOOP FOR DEEP COPY.
		while (temp != NULL)
		{
			//cout << "Enter in temp";
			List_new-> push_back(temp->data);
			temp = temp->next;
		}
		return List_new;
	}

	/**
	* TODO-------------------------11
	* function:  prefix--------------------------------------------------------DONEEEEEEEEEEEEEEEEEEEEEEEE
	*
	* description:  removes the first k elements from the
	*               calling List which are used to form a new List
	*		            which is then returned.
	*
	*		if n is the length of the given List, we have the
	*		following boundary conditions:
	*
	*		  if k==0:
	*			    calling List unchanged and an empty List returned
	*		  if k>=n:
	*			    calling becomes empty and a List containing
	*			    all elements previously in lst is returned.
	*
	*		examples:
	*
	*		  EX1:  lst:  [2, 3, 9, 7, 8]
	*			k:    3
	*
	*			call:
	*
	*			  List<int> * pre = lst.prefix(3);
	*
	*			after call:
	*			   lst:  [7, 8]
	*			   returned List (prefix):  [2, 3, 9]
	*
	*		  EX2  lst:  [2, 3, 9, 7, 8]
	*			k:    0
	*
	*		  call:
	*
	*			  List<int> * pre = lst.prefix(3);
	*
	*			after call:
	*			   lst:  [2, 3, 9, 7, 8]  (unchanged)
	*			   returned List:  []
	*
	*		  EX3  lst:  [2, 3, 9, 7, 8]
	*			k:    5
	*
	*		  call:
	*
	*			  List<int> * pre = lst.prefix(5);
	*
	*			after call:
	*			   lst:  []
	*			   returned List:  [2, 3, 9, 7, 8]
	*
	* REQUIREMENTS:
	*
	*	RUNTIME:  THETA(n) worst case where n is the length of the given List
	*
	*       ORDERING:  the ordering of the returned prefix should be the same as
	*                  in the given List
	*
	*       MEMORY:    for full credit, no new nodes should be
	*                  allocated or deallocated; you should just
	*                  "re-use" the existing nodes.  HOWEVER, you will
	*		               need to allocate a List object for the returned
	*		               prefix (but, again, the underlying Nodes should be
	*		               re-used from the calling List).
	*/
	
List<T> * prefix(unsigned int k) 
	{
		List<T> *pre_list = new List<T>();

		Node* prev = NULL;
		Node* curr = front;
		Node* head = front;

		if (k > numElements)
		{
			pre_list->numElements = numElements;
			numElements = 0;
			
		}
		else
		{
			numElements = numElements - k;
			pre_list->numElements = k;

		}   

		if (k == 0)
		{
			return pre_list;
		}

		if (front == NULL)
		{
			return pre_list;
		}

		while (k > 0  && curr!=NULL)
		{
			k--;
			prev = curr;
			curr = curr->next;	
		}

		prev->next = NULL;
		pre_list->front = head;

		front = curr;
		return pre_list;
	}    

	/**
	* TODO---------------------------------12 DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	* function:  filter_leq
	*
	* description:  removes all elements of the given List (lst) which
	*		are less than or equal to a given value (cutoff)
	*
	*		A List containing the removed elements is returned.
	*
	* examples:
	*
	*	EX1: 	lst:  [4, 9, 2, 4, 8, 12, 7, 3]
	*		cutoff:  4
	*
	*		after call:
	*			lst:  [9, 8, 12, 7]
	*			returned List:  [4, 2, 4, 3]
	*
	*       -----------------------------------------
	*	EX2: 	lst:  [6, 5, 2, 1]
	*		cutoff:  6
	*
	*		after call:
	*			lst:  []
	*	 		returned List:  [6, 5, 2, 1]
	*
	* REQUIREMENTS:
	*
	*	RUNTIME:  THETA(n) where n is the length of the given List
	*
	*       ORDERING:  the ordering of the returned List should be the same as
	*                  in the given List
	*
	*       MEMORY:    for full credit, no new nodes should be allocated or deallocated;
	*		   you should just "re-use" the existing nodes.  HOWEVER, you will
	*		   need to allocate a List structure itself (i.e., for the returned
	*		   List).
	*
	*/
	

	List * filter_leq(const T & cutoff) 
	{
		List<T> *filter = new List<T>();             //List TO BE RETURNED.

		Node*prev = front;
		Node*current = front;
		int n = 0;
		//cout << x << endl;

		// LIST IS EMPTY, RETURN
		if (front == NULL)
		{
			return filter;
		}

		// CHECK THE INVARIANTS LATER.
		while (current != NULL)
		{
			// CONDITIONAL STATEMENTS FOR CUTOFF.
			if (current->data <=cutoff)
			{
				//	cout << " MATCH FOUND";
				n++;
				if (current == front)
				{
					front = current->next;
					current->next = NULL;
					filter->pushNode_withPointers(current);
					current = front;
					filter->numElements++;
					numElements--;
					//delete current;
					
				}
				else
				{
					//	cout << "Enter" << endl;
					//cout << "Now previ is " << prev->data << endl;
					prev->next = current->next;
					current->next = NULL;
					filter->pushNode_withPointers(current);
					current = prev->next;
					filter->numElements++;
					numElements--;
					//filter->push_back(current->data);
					
					//	cout << "Now previ of next is " << prev->next->data << endl;
					//delete current;
					
					//cout << "Now current is " << current->data << endl;}	
				}

			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		//return n;
		return filter;
	}   

	/**
	* TODO------------------------------------------13  DONEE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	* function:  concat
	*
	* description:  concatenates the calling List with parameter List (other)
	*    The resulting concatenation is reflected the calling List; the
	*    parameter List (other) becomes empty.
	*
	*    example:
	*
	*	EX1:  a: [2, 9, 1]
	*	      b: [5, 1, 2]
	*
	*	      call:
	*	            a.concat(b);
	*
	*	after call:
	*
	*		a: [2, 9, 1, 5, 1, 2]
	*		b: []
	*
	* REQUIREMENTS:
	*
	*     runtime:  O(1)
	*
	*     sanity:  this operation makes sense when a and b
	*		are distinct Lists.  For example, we don't
	*		want/allow the caller to do something like
	*		this:
	*
	*			List<int> *my_List = new List<int>();;
	*
	*			my_List->push_front(my_lst, 4);
	*			my_List->push_front(my_lst, 2);
	*
	*			my_lst->concat(my_lst);
	*
	*		your implementation must detect if it is being
	*		called this way.  If so the function does nothing
	*		and (optionally) prints an error message to
	*		stderr.
	*
	*/
	void concat(List<T> &other) 
	{
		if (front == NULL && other.front == NULL)
		{
			return;
		}

		if (other.front == NULL  && front!=NULL)
		{
			return;
		}

		if (front == NULL && other.front != NULL)
		{
			front = other.front;
			other.front = NULL;
			numElements = other.numElements;
			other.numElements = 0;
			return;
		}

	

		numElements = numElements + other.length();
		if (this == &other) {
			cerr << "warning:  List::concat():  calling object same as parameter";
			cerr << "\n          List unchanged\n";
			return;
		}
		cout << "List::concat(): no error...\n";

		// Connecting the   calling list's back with the front of parameter list.
		back->next = other.front;
		other.front = NULL;
		other.numElements = 0;
	}   


	/**
	* TODO
	*
	* function:  compare_with
	* description: compares the calling List with parameter List (other)
	*    "LEXICALLY" (essentially a generalization of dictionary
	*    ordering).
	*
	*    link:  https://en.wikipedia.org/wiki/Lexicographical_order
	*
	*    Return Value:
	*
	*       o if the two Lists are identical, 0 is returned.
	*       o if the calling List is lexically BEFORE the other List,
	*             -1 is returned
	*       o otherwise, the other List is lexically before the calling
	*             List and 1 (positive one) is returned.
	*
	*    Properties and examples:
	*
	*        The empty List is lexically before all non-empty Lists
	*          (you can say it is "less than" all non-empty Lists).
	*
	*        Examples (using mathematical notation):
	*
	*          [2 5 1] < [3 1 1 1 1]    (think dictionary ordering!)
	*
	*          [4 1 3] < [4 1 3 0 0 0]  (prefix: just like "car" is before
	*                                            "cartoon" in the dictionary).
	*
	*          [4 5 6 1 2 3 9 9 9] < [4 5 6 1 4 0 0]
	*                   ^                     ^
	*                      (they have a common prefix of length 4; but at
	*                      the fifth position they differ and the left List
	*                      is the winner (smaller) -- no need to look further)
	*
	*
	*        Templates?
	*
	*          Since List is a template class, the elements of a particular
	*          List need not be integers.  For example, we could have
	*          Lists of strings.
	*
	*          Good news:  the exact same principle applies because
	*          strings can be compared just like integers can be compared!
	*
	*          Great news:  you don't need to think about this at all!
	*          The exact same code you would write if you assumed the element
	*          type is integer will work for other types like strings.
	*
	*          Why?  Because, for example, all of these operators:
	*
	*                   <, <=, ==, > and >=
	*
	*          all work on strings.  They are not 'built-in' to C++, but
	*          the class string has "overloaded" these operators (they
	*          result in an appropriate function call).
	*
	*          (In a subsequent exercise, we will do this kind of
	*          overloading ourselves!)
	*
	*        Examples with Lists of strings:
	*
	*          ["egg", "goat"] < ["egg", "globe", "apple"]
	*
	*          ["zebra", "fun"] < ["zebra", "funny"]
	*
	*        [Yes, the components of these Lists are THEMSELVES compared
	*        lexically, but the string class is doing those comparisons)
	*
	*/
	int compare_with(const List<T> &other) const 
	{
		// Here l1 is our calling List and l2 is our parameter List.

		Node *l1 = front;
		Node *l2 = other.front;

		// EMPTY LIST ARE IDENITICAL.
		if (l1 == NULL && l2 == NULL)
		{
			return 0;
		}
		// L1 IS EMPTY. SO LEXICALLY BEFORE.
		if (l1 == NULL && l2 != NULL)
		{
			return -1;
		}
		// L2 IS EMPTY. SO LEXICALLY BEFORE.
		if (l1 != NULL && l2 == NULL)
		{
			return 1;
		}

		// l1 and l2 TRAVERSES UNTIL THE THERE ARE SAME ELEMENTS IN BOTH THE list.
		while (l1!=NULL && l2!=NULL && l1->data == l2->data)
		{
			l1 = l1->next;
			l2 = l2->next;
		}

		// AFTER THE END OF SAME ELEMENTS IN BOTH List, NOW IT WILL COMPARE ELEMENTS REMAINING IN TWO NONEMPTY List.
		if (l1!=NULL && l2!=NULL)
		{
			//CompareStrings characters 
			if (l1->data > l2->data)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		// here l2 becomes empty before l1. HENCE l2 it is lexically before.
		if (l2 == NULL && l1 != NULL)
		{
			return 1;
		}
		//l1 becomes empty before l2.  hence l1 is lexically before.
		if (l1 == NULL && l2 != NULL)
		{
			return -1;
		}
		
		// It will return zero if both the List are identical.
		return 0;
	}

	/*
	* TODO---------------------------------------------------------------15 DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*
	* function:  suffix_maxes
	*
	* desc:  constructs a new List of the same length as the calling object
	*        with the value stored at position i of the new List is the MAXIMUM
	*        value in the suffix (or tail) of the calling List starting from
	*        position i.
	*
	*        This new List is returned and the calling List is unchanged.
	*
	*        Example:
	*
	*          Given List:  [6, -18, 12, 4, 1, 7, 2, 5  4]
	*                                    ^^^^^^^^^^^^^^^^
	*
	*          New List:    [12, 12, 12, 7, 7, 7, 5, 5, 4]
	*                                    ^
	*
	*              (as a sub-example, the marked entry in the new List
	*              (marked with '^') is the max of the marked suffix in the
	*              given List (marked with a bunch of '^'s).
	*
	* REQUIREMENTS:
	*
	*        Total Runtime:   O(n)
	*        Calling List is unchanged.
	*
	*/
	/*List<T> * suffix_maxes() const 
	{
		return nullptr;
	}  */

	

	List<T> * suffix_maxes() const
	{
		int elem = 0;
		List<T>* suffix = new List<T>();

		Node *prev = NULL;
		prev = front;


		//If list is empty. return empty list.
		if (front == NULL)
		{
			return suffix;
		}
	
		while (prev != NULL)
		{
			elem = prev->data;
			// Calling recursive helper function to return the greatest element by traversing the list from location i
			elem = suffix->search_greatestNum(prev);

			// Now the original elem is replace and adding to new list.
			suffix->push_back(elem);
			prev = prev->next;
		}

		// Since the length remains same of orginal list.
		suffix->numElements = numElements;
		return suffix;
	}



	private:
	int numElements=0;
	Node *front;
	Node *back;

	void init() 
	{
		front = nullptr;
		back = nullptr;
	}
};

#endif