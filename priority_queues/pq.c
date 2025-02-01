/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Connor Baldes
 * Email:
 */

#include <stdlib.h>

#include "pq.h"

#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */
struct pq {

  struct dynarray* queue;

  int last_filled;

  int next_open;

};


/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {

  struct pq* pq = malloc(sizeof(struct pq));

  pq->queue = dynarray_create();

  int last_filled = 0;

  int next_open = 0;


  return pq;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {

  dynarray_free(pq->queue);

  free(pq);

  return;
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {

  for(int i = 0; i < dynarray_size(pq->queue); i++) {

    if(dynarray_get(pq->queue,i) != NULL) {

      return 0;
    }
  }

  return 1;
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
  
  void* temp_data;
  int temp_p1;
  int temp_p2;

  int child;
  int parent;

  int priority_val;
  void* temp;


  priority_val = priority;

  if(pq->last_filled == 0 && pq->next_open == 0) {


    dynarray_insert(pq->queue, value, priority);

    pq->next_open += 1;
  }

  else{ 

    dynarray_insert(pq->queue, value, priority);


    child = pq->next_open;
    parent = (((pq->next_open)-1) /2);

    pq->last_filled += 1;

    pq->next_open += 1;

    
    temp_p1 = dynarray_get_priority(pq->queue,child);

    temp_p2 = dynarray_get_priority(pq->queue,parent);
 
    while( (temp_p1 <= temp_p2) ) {



      temp_data = dynarray_get(pq->queue, parent);
      
  

      dynarray_set(pq->queue, parent, dynarray_get_priority(pq->queue, child), dynarray_get(pq->queue, child) );

      dynarray_set(pq->queue, child, temp_p2, temp_data );

      child = parent;

      parent = (((child)-1) /2);

      if(dynarray_get(pq->queue, parent) == dynarray_get(pq->queue, 0) ) {

        break;
      }
     //dynarray_set(pq->priority, child, dynarray_get(temp_pq->priority,child) );
      //dynarray_set(pq->data, child, dynarray_get(temp_pq->data,child) );



    }


  

  }

  return;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {


  return dynarray_get(pq->queue, 0);
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {

  return dynarray_get_priority(pq->queue, 0);
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {

  void* value = dynarray_get(pq->queue,0);

  int position = 0;

  void*temp_data;
  int temp_p1;

  dynarray_set(pq->queue, 0, dynarray_get_priority(pq->queue, pq->last_filled),dynarray_get(pq->queue, pq->last_filled) );

  dynarray_remove(pq->queue, pq->last_filled);

  while(((dynarray_get_priority(pq->queue, position) > (dynarray_get_priority(pq->queue, (2 * position)+1)))  || (dynarray_get_priority(pq->queue, position) > dynarray_get_priority(pq->queue, (2 * position)+2))) && (dynarray_size(pq->queue) < position)) {

      temp_data = dynarray_get(pq->queue, position);

      temp_p1 = dynarray_get_priority(pq->queue, position);

    if((dynarray_get_priority(pq->queue, position) > (dynarray_get_priority(pq->queue, (2 * position)+1) )) && dynarray_get_priority(pq->queue, position) < (dynarray_get_priority(pq->queue, (2 * position)+2) )) {

      dynarray_set(pq->queue, position, (dynarray_get_priority(pq->queue, (2 * position)+1)), (dynarray_get(pq->queue, (2 * position)+1)));

      dynarray_set(pq->queue, ((2 * position)+1), temp_p1, temp_data);

      position = ((2 * position)+1);

    }
    else if((dynarray_get_priority(pq->queue, position) > (dynarray_get_priority(pq->queue, (2 * position)+2) )) && dynarray_get_priority(pq->queue, position) < (dynarray_get_priority(pq->queue, (2 * position)+1) ) ) {

      dynarray_set(pq->queue, position, (dynarray_get_priority(pq->queue, (2 * position)+1)), (dynarray_get(pq->queue, (2 * position)+2)));

      dynarray_set(pq->queue, ((2 * position)+2), temp_p1, temp_data);

      position = ((2 * position)+2);

    }
    else{

      if((dynarray_get_priority(pq->queue, (2 * position)+1) > dynarray_get_priority(pq->queue, (2 * position)+2))) {

        dynarray_set(pq->queue, position, (dynarray_get_priority(pq->queue, (2 * position)+2)), (dynarray_get(pq->queue, (2 * position)+2)));

        dynarray_set(pq->queue, ((2 * position)+2), temp_p1, temp_data);

        position = ((2 * position)+2);
      }
      else {

       dynarray_set(pq->queue, position, (dynarray_get_priority(pq->queue, (2 * position)+1)), (dynarray_get(pq->queue, (2 * position)+1)));

        dynarray_set(pq->queue, ((2 * position)+1), temp_p1, temp_data);

        position = ((2 * position)+1);

      }

    }
  }

  

  pq->next_open = dynarray_size(pq->queue); 
  pq->last_filled = dynarray_size(pq->queue) -1;

  


  
  return value;
}
