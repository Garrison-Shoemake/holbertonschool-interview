#include "lists.h"
/**
 * is_palindrome - checks a list for if its a palindrome
 * @head: head of the list to check
 * Return: returns 0 if not and 1 if is
 */
int is_palindrome(listint_t **head)
{
    listint_t *node = *head;
	listint_t *slow, *fast, *prev, *second_ll_start, *head2, *next, *start;     
    
    if (!head)
        return (0);

    slow = fast = prev = node; 
    if ( node -> next == NULL) 
        return 1;          
      while ( slow && fast && fast -> next ) 
    { 
        prev = slow; 
        slow = slow -> next; 
        fast = fast -> next -> next;     
	} 
    if ( fast && fast -> next == NULL) 
        start = prev -> next;     
	else 
        start = prev;     
		start = start -> next; 
	    prev -> next = NULL; 
	    second_ll_start = NULL; 
    while ( start != NULL) 
    { 
       next = start -> next; 
       start -> next = second_ll_start;       	 
		 second_ll_start = start; 
        start = next;     
	} 
		head2 = second_ll_start;     
		while ( head2 && head ) 
    	{ 
        if ( head2 -> n == node -> n ) 
        { 
            head2 = head2 -> next;             
			node = node -> next;         
		} else 
            return 0;    	 
        } 
    if ( head2 == node ) 
        return 1; 

    return(0);
}