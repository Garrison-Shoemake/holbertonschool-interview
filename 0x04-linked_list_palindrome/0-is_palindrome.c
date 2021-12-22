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
    
    /* empty lists are palindromes */
    if (!*head)
        return (1);

    /* setting up for traversal */
    slow = fast = prev = node; 

    /* single item lists are palindromes */
    if ( node -> next == NULL) 
        return 1;          
    
    /* while our single iterative and double exist and there is 
    at least one more after, set prev to last one, iterate nodes*/
    while ( slow && fast && fast -> next ) 
    { 
        prev = slow; 
        slow = slow -> next; 
        fast = fast -> next -> next;     
	} 
    /* if the second iterator reaches the end of the list
    we want to start a second list for comparison, starting in 
    the middle of the original list*/
    if ( fast && fast -> next == NULL) 
        start = prev -> next;     
	else 
        start = prev;     
		start = start -> next; 
	    prev -> next = NULL; 
	    second_ll_start = NULL; 
    /* constructs the second list */
    while ( start != NULL) 
    { 
        next = start -> next; 
        start -> next = second_ll_start;       	 
	    second_ll_start = start; 
        start = next;     
	} 
    /* sets head2 to constructed second list
    comaprison is done in the while loop after
    so that if at any point they don't match, return false and zero */
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