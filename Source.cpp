#include "List.h"
//#define nullptr NULL
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

List<int> * slow_list(int n) {

	// placeholder
	return nullptr;
}

int main(int argc, char *argv[]) {
	List<int> *list = new List<int>();      // list is object of integers.
	List<string> *list2 = new List<string>();// list is object of strings.
	List<string> *list3 = new List<string>();
	List<int> *list_copy = new List<int>();

	List<int> *list_equal = new List<int>();

	List<int> *merge = new List<int>();

	List<int> *filter = new List<int>();

	List<int> *conCat = new List<int>();

	List<int> *prefix = new List<int>();

	List<int> *suffix = new List<int>();

	List<int> *lexical = new List<int>();

	int x;
	int n, ndel;

	n = 1000;

	if (argc == 2) {
		n = atoi(argv[1]);
	}

	// Pushing 4 values in list
	/*for (x = 1; x <= 4; x++)
	{
	list->push_front(x);
	} */

/*lst:  [4, 9, 2, 4, 8, 12, 7, 3]
	* cutoff : 4
	*
	*		after call :
	  *lst : [9, 8, 12, 7]
		  * returned List : [4, 2, 4, 3]   */

	//--------------FILTER  1----------------------------------------------------------------

	

	  //lst:  [4, 9, 2, 4, 8, 12, 7, 3]
	/*list->push_front(4);
	list->push_front(9);
	list->push_front(2);
	list->push_front(4);
	list->push_front(8);
	list->push_front(12);
	list->push_front(7);
	list->push_front(3);  
	//list->push_front(x);    
	list->print();

	filter = list->filter_leq(15);

	list->print();
	//filter->print();    

	cout << "LENGTH OF THE LIST IS  " << list->length() << endl;

	filter->print();
	cout << "LENGTH OF THE Filter IS  " << filter->length() << endl;    */



	//--------------------------------------------------------------------------------------------------



	//-----------------------------------CONCAT 2---------------------------------------------------------


	for (x = 1; x <= 4; x++)
	{
	list->push_front(x);
	}       

	//list->print();

	for (x = 5; x <= 10; x++)
	{
	conCat->push_front(x);
	}    

	//list->push_front(2);
	//conCat->push_front(2);
//	conCat->print();

	list->print();
	conCat->print();

	list->concat(*conCat);

	list->print();
	cout << "LENGTH OF THE LIST IS  " << list->length() << endl;

	conCat->print();     
	cout << "LENGTH OF THE CONCAT LIST IS  " << conCat->length() << endl;  



	//.........................................................................................................


	//----------------------------------------COMPARE TWO LIST..EQUAL LIST  3..........................................


/*	list->push_front(8);
	list->push_front(7);
	list->push_front(9);
	list->push_front(3);
	list->push_front(2);  

	//list->push_front(8);
	//list_equal->push_front(8);
	

	bool result = false;

	for (x = 0; x <= 10000; x++)
	{
	list->push_front(x);
	}  

	list->print();

	for (x = 0; x <= 10000; x++)
	{
	list_equal->push_front(x);
	}
	list_equal->print();  

//	list->print();
	//list_equal->print();


	result= list->equal_to(*list_equal);

	cout << result;
	if (result == true)
	{
	cout << "Both list are equal" << endl;
	} 
	else
	{
		cout << "Not euqal result" << endl;   
	}     */







	//..................................................................................................





	//----------------------------------PREFIX 4--------------------------------------------------------------------
	// lst:  [2, 3, 9, 7, 8]  and K=3


	/*list->push_front(8);
	list->push_front(7);
	list->push_front(9);
	list->push_front(3);  
	//list->push_front(2);    

	for (x = 1; x <= 100; x++)
	{
	list->push_front(x);
	}    
	list->print();


	prefix = list->prefix(50);

	cout << " Original list after removing K elements: ";
	list->print();
	cout << "LENGTH OF THE LIST IS  " << list->length() << endl;

	cout << " NEW LIST with K elements removed are: ";
	prefix->print();   
	cout << "LENGTH OF THE LIST IS  " << prefix->length() << endl;   */


	//---------------------------------------------------------------------------------------------------------------



	//--------------------------POP_BACK  5------------------------------------------------------------------------------

	/*for (x = 1; x <= 8; x++)
	{
	list->push_front(x);
	}   

	list->push_front(4);
	list->push_front(9);
	/*list->push_front(4);
	list->push_front(4);
	list->push_front(8);
	list->push_front(12);  

	//list->push_front(9);

	for (x = 1; x <= 10000; x++)
	{
		list->push_front(x);
	}  


	cout << " Original List is: ";
	list->print();
	cout << "Popping the back element from the list: " << endl;

	x = 2;
	list->pop_back(x); 

	list->print();     */

	//-------------------------------------------------------------------------------------------------------------------



	//---------------------------------PRINT REVERSE  6---------------------------------------------------------

	/*for (x = 1; x <= 1000; x++)
	{
	list->push_front(x);
	}   

	/*list->push_front(4);
	list->push_front(9);
	list->push_front(4);
	list->push_front(4);
	list->push_front(8);
	list->push_front(12);
	list->push_front(4);
	list->push_front(3);
	//list->push_front(4);  

	cout << " Original List is: " << endl;
	list->print();

	cout << "Print reverse list is: " << endl;;
	list->print_rev();      */


	//---------------------------------------------------------------------------------------------------------------



	//-----------------------------------------REVERSE THE LIST 7--------------------------------------------------------

	/*for (x = 1; x <= 100; x++)
	{
	list->push_front(x);
	}   

	//list->push_front(2);

	cout << " Original List is: " << endl;
	list->print();

	cout << "Print reverse list is: " << endl;
	list->reverse(); 
	list->print();  */



	//---------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------FAST-REMOVE ALL  8------------------------------------------------

	
	/*list->push_front(4);
	list->push_front(9);
	list->push_front(4);
	list->push_front(4);
	list->push_front(8);
	list->push_front(12);
	list->push_front(4);
	list->push_front(3);
	list->push_front(4);  

	list->print();

	int remove = 0;

	remove = list->fast_remove_all(4);
	cout << " REMOVE FAST in the list is " << remove << endl;                */



	//-------------------------------------------------------------------------------------------------

	//---------------------------------INSERT---SORT  9-------------------------------------------------------

	/*for (x = 1; x <= 100; x++)
	{
	list->push_front(x);
	}  


	/*list->push_front(1);
	/*list->push_front(3);
	list->push_front(5);
	list->push_front(10);
	list->push_front(12);
	list->push_front(20);
	list->push_front(25);
	list->push_front(30);    
	list->reverse();
	cout << "THE LIST IS: " << endl;
	list->print(); 
	cout << "LENGTH OF THE LIST IS  " << list->length() << endl;

	cout << " INSERT THE ELEMENT INTO LIST: " << endl;
	list->insert_sorted(0);
	list->print();  
	cout << "LENGTH OF THE LIST IS  " << list->length() << endl;             */
	


	//------------------------------------------------------------------------------------------------------------



	//-------------------------------------CLONE_LIST-10-----------------------------------------------------------------------


	/*list->push_front(1);
	list->push_front(3);
	list->push_front(5);
	list->push_front(10);
	list->push_front(15);
	list->push_front(20);
	list->push_front(25);
	list->push_front(30);

	cout << "THE LIST IS: " << endl;
	list->print();

	cout << " CLONE LIST IS: " << endl;


	list_copy = list->clone();
	list_copy->print();  */


	//------------------------------------------------------------------------------------------------------------


	//-----------------------------------LENGTH_11-------------------------------------------------------------------------

/*	for (x = 1; x <= 8; x++)
	{
		list->push_front(x);
	}

	cout << " Original List is: " << endl;
	list->print();
	  
	cout << "LENGTH OF THE LIST IS  " << list->length() << endl;       */

	//----------------------------------------COUNT-_12--------------------------------------------------------------------
	/*int count = 0;
	/*list->push_front(4);
	list->push_front(9);
	list->push_front(4);
	list->push_front(4);
	list->push_front(8);
	list->push_front(12);
	list->push_front(4);
	list->push_front(3);
	//list->push_front(x);  

	/*for (x = 1; x <= 10000; x++)
	{
		list->push_front(x);
	}  

	//list->push_front(4);
	list->push_front(4);

	cout << " Original List is: " << endl;
	list->print();

	count = list->count(4);

	cout << " Count the Number of occurences in the list: " << count << endl;     */          


	//-----------------------------------------------------------------------------------------------------------------------





	//----------------------------------------LEXICAL COMPARISON 13--------------------------------------------------------------------



	/**[2 5 1] <[3 1 1 1 1](think dictionary ordering!)
	*
	*[4 1 3] <[4 1 3 0 0 0](prefix: just like "car" is before
	*                                            "cartoon" in the dictionary).
	*
	*[4 5 6 1 2 3 9 9 9] <[4 5 6 1 4 0 0]  */

	/*int comp = 0;
	list->push_front(4);
	/*list->push_front(3);
	list->push_front(2);
	list->push_front(1);    */

////	cout << "THE ORIGINAL List IS: " << endl;
	//list->print();
	//List->push_front(4);


	//lexical->push_front(0);
//	lexical->push_front(7);
	//lexical->push_front(0);
	/*lexical->push_front(4);
	lexical->push_front(3);
	lexical->push_front(2);
	lexical->push_front(1);  


	cout << "THE LEXICAL List IS: "<< endl;
	lexical->print();

	comp=list->compare_with(*lexical);

	/*if the two Lists are identical, 0 is returned.
	*       o if the calling List is lexically BEFORE the other List,
	*-1 is returned
	*       o otherwise, the other List is lexically before the calling
	*             List and 1 (positive one) is returned. 
	*  
	cout << " The comp is" << comp << endl;
	if (comp ==0)
	{
	cout << " The two Lists are identical "<< endl;
	}

	if (comp ==1)
	{
	cout << "the other List is lexically before the calling List " << endl;
	}
	if (comp == -1)
	{
	cout <<" the calling List is lexically BEFORE the other List "<< endl;
	}   */
	   



	//---------------------------------------------------------------------------------------------------------------------------


	//------------------------------------------------MERGE WITH---------------------------------------------------------------------------

    /*a:  [2 3 4 9 10 30]
	* b : [5 8 8 11 20 40]
	*
	* 		after call a.merge_with(b) :
	*
	* 		  a : [2 3 4 5 8 8 9 10 11 20 30 40]
	* b : []
	*
	*     */

	/*list->push_front(9);
	list->push_front(7);
	list->push_front(5);
	list->push_front(3);
	list->push_front(1);
	//list->push_front(2);
	//list->push_front(4);
	//list->push_front(3);  

	merge->push_front(7);
	merge->push_front(5);
	merge->push_front(3);
	merge->push_front(1);
	//merge->push_front(8);
	//merge->push_front(5);
	//merge->push_front(30);  

	cout << "THE ORIGINAL List IS: " << endl;
	list->print();

	cout << "THE MERGE List IS: " << endl;
	merge->print();



	list->merge_with(*merge);

	cout << "THE ORIGINAL List  after merge IS: " << endl;
	list->print(); 

	cout << "LENGTH OF THE LIST IS  " << list->length() << endl;

	merge->print();  
	cout << "LENGTH OF THE LIST IS  " << merge->length() << endl;     */




	//------------------------------------------------SUFFIX_MAX---------------------------------------------------------------------------


/**          Given List : [6, -18, 12, 4, 1, 7, 2, 5  4]
* ^^^^^^^^^^^^^^^^
*
*          New List : [12, 12, 12, 7, 7, 7, 5, 5, 4]   */

	
	//list->push_front(4);
/*	list->push_front(5);
	list->push_front(2);
	list->push_front(7);
	list->push_front(1);
	list->push_front(4);
	list->push_front(12);
	list->push_front(-18);
	list->push_front(6);    


	list->push_front(5);
	list->push_front(4);
	list->push_front(3);
	list->push_front(2);
	list->push_front(1);  
	//list->push_front(4);
	//list->push_front(12);
	//list->push_front(-18);
	//list->push_front(6);

	list->print();

	cout << "LENGTH OF THE LIST IS  " << list->length() << endl;

	suffix = list->suffix_maxes();

	cout << "LENGTH OF THE SUFFIX  LIST IS  " << suffix->length() << endl;
	suffix->print();    */





	




//------------------------------------------------------------------------------------------------------------------------





	/*for (x = 5; x <= 7; x++)
	{
	list_merge->push_front(x);
	}  


	//list->merge_with  (list_merge);

	//list->print_rev();

	//list->reverse();
	//list->print();

	//list->push_front(9);
	list->push_front(8);
	for (x = 4; x >= 1; x--)
	{
	list->push_front(x);
	}  

	list->insert_sorted(12);
	list->print();



	//list->push_front(4);
	//list->push_front(4);

	list->print();
	list->print_rev();
	cout << " Number of elements in this list is " << list->length() << endl;


	x = 1;
	list->pop_back(x);

	for (x = 1; x <= 4; x++)
	{
		list->push_back(x);
	}

	list->print();
	cout << " Number of elements in this list is " << list->length() << endl;

	cout << " Number of occurences in this list is " << list->count(2) << endl;



	list->pop_front(x);
	cout << "popped " << x << endl;
	list->print();

	list->slow_remove_all(2);
	cout << "after remove-all(2):\n";
	list->print();

	// string words[] = {"hello", "goodbye", "sunrise", "sunset"};
	string words[] = { "alice", "bob", "cathy", "donald" };


	for (int i = 0; i<4; i++) 
	{
		list2->push_front(words[i]);
		list3->push_back(words[i]);
	}

	list2->print();
	list3->print();

	cout << "list  sorted?  " << list->is_sorted() << endl;
	cout << "list2 sorted?  " << list2->is_sorted() << endl;
	cout << "list3 sorted?  " << list3->is_sorted() << endl;  


	// list2->front = NULL;


	delete list;
	delete list2;
	delete list3;

	/***  UNCOMMENT THIS CODE ONCE YOU HAVE WRITTEN YOUR
	*     slow_list FUNCTION

	list = slow_list(n);

	cout << "starting slow_remove_all (n=" << n << ")" << endl;
	ndel = list->slow_remove_all(0);
	cout << "slow_remove_all done!" << endl;
	cout << "    num-deleted:    " << ndel << endl;
	cout << "    list-len after: " << list->length()   << endl;

	delete list;  */

	
	system("pause");
	return 0;
}