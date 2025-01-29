/*
 * This file is where you should implement your binary search tree.  It already
 * contains skeletons of the functions you need to implement (along with
 * documentation for each function).  Feel free to implement any additional
 * functions you might need.  Also, don't forget to include your name and
 * @oregonstate.edu email address below.
 *
 * Name: Connor Baldes
 * Email:
 */

#include <stdlib.h>

#include "bst.h"
#include "stack.h"

/*
 * This structure represents a single node in a BST.  In addition to containing
 * pointers to its two child nodes (i.e. `left` and `right`), it contains two
 * fields representing the data stored at this node.  The `key` field is an
 * integer value that should be used as an identifier for the data in this
 * node.  Nodes in the BST should be ordered based on this `key` field.  The
 * `value` field stores data associated with the key.
 *
 * You should not modify this structure.
 */
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};


/*
 * This structure represents an entire BST.  It specifically contains a
 * reference to the root node of the tree.
 *
 * You should not modify this structure.
 */
struct bst {
  struct bst_node* root;
};

/*
 * This function should allocate and initialize a new, empty, BST and return
 * a pointer to it.
 */
struct bst* bst_create() {

  struct bst* new_bst = malloc(sizeof(struct bst));

  new_bst->root = NULL;

  return new_bst;
}

/*
 * This function should free the memory associated with a BST.  While this
 * function should up all memory used in the BST itself, it should not free
 * any memory allocated to the pointer values stored in the BST.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   bst - the BST to be destroyed.  May not be NULL.
 */
void bst_free(struct bst* bst) {

  free_nodes(bst->root);

  free(bst);


}

/*
 * This function should return the total number of elements stored in a given
 * BST.
 *
 * Params:
 *   bst - the BST whose elements are to be counted.  May not be NULL.
 */
int bst_size(struct bst* bst) {

  int count = 0;

  if(bst->root != NULL) {

    count = count_nodes(bst->root);

  }

  return count;
}

/*
 * This function should insert a new key/value pair into the BST.  The key
 * should be used to order the key/value pair with respect to the other data
 * stored in the BST.  The value should be stored along with the key, once the
 * right location in the tree is found.
 *
 * Params:
 *   bst - the BST into which a new key/value pair is to be inserted.  May not
 *     be NULL.
 *   key - an integer value that should be used to order the key/value pair
 *     being inserted with respect to the other data in the BST.
 *   value - the value being inserted into the BST.  This should be stored in
 *     the BST alongside the key.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void bst_insert(struct bst* bst, int key, void* value) {

  struct bst_node* new_node = malloc(sizeof(struct bst_node));

  new_node->key = key;
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;

  struct bst_node* parent = NULL;

  struct bst_node* cur_node = bst->root;

  if(bst->root == NULL) {

    bst->root = new_node;

    //printf("Root node created. key: %d should be: %d cur_node key: %d \n", new_node->key, key, bst->root->key);
    return;
  }
 

  while(cur_node != NULL) {
    //printf("enter loop \n");
    parent = cur_node;
    //printf(" %d ",parent->key);

    //printf(" %d \n",key);

    if(key < cur_node->key) {

      cur_node = cur_node->left;
    }
    else {

      cur_node = cur_node->right;
    }

  }
  //printf("\n");

  if(key < parent->key) {

    parent->left = new_node;
    //printf("Key: %d \n", parent->left->key);
  }
  else {

    parent->right = new_node;
    //printf("Key: %d \n", parent->right->key);
  }

  return;
}

/*
 * This function should remove a key/value pair with a specified key from a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should remove the first one it encounters (i.e. the one closest to
 * the root of the tree).
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair to be removed from the BST.
 */
void bst_remove(struct bst* bst, int key) {
  //printf("  %d  ", key);
  struct bst_node* parent = get_parent(bst,key);
  //printf("go beavs");

  struct bst_node* node_rem = get_child(parent, key);
  //printf("go beavs");


  //printf("go beavs");

  if((bst->root == node_rem) && (node_rem->left == NULL) && (node_rem->right == NULL)) {
    
    bst->root = NULL;
  }
  
  else if((node_rem->left == NULL) && (node_rem->right == NULL)) {
    
    if(parent->right == node_rem) {
      parent->right = NULL;
      
    }
    else {
      parent->left = NULL;
      
    }

  }
  
  else if((node_rem->left != NULL) && (node_rem->right == NULL) ) {

    if(parent->right == node_rem) {
      parent->right = node_rem->left;
      
    }
    else {
      parent->left = node_rem->left;
      
    } 

  }
  
  else if((node_rem->left == NULL) && (node_rem->right != NULL) ) {

    if(parent->right == node_rem) {
      parent->right = node_rem->right;
      
    }
    else {
      parent->left = node_rem->right;
      
    }


  }
  
  else {
    //printf("go beavs");
    struct bst_node* successor = node_s(node_rem);
    //printf("go beavs");

    struct bst_node* p_successor = node_s_p(node_rem, successor);
    
    successor->left = node_rem->left;
    

    if(successor != node_rem->right) {
      
      p_successor->left = successor->right;

      successor->right = node_rem-> right;
      

    }

  
    //printf("Parent location: %d Node to be removed location: %d", parent->left, node_rem);
  
    if(bst->root->key == parent->key) {

      bst->root = successor;

    }
    
    else if(parent->left == node_rem) {

      parent->left = successor;
  
    }
    
    else {
      parent->right = successor;

    }
  }

  free(node_rem);
  
  
  return;
}

/*
 * This function should return the value associated with a specified key in a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should return the first one it encounters (i.e. the one closest to
 * the root of the tree).  If the BST does not contain the specified key, this
 * function should return NULL.
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair whose value is to be returned.
 *
 * Return:
 *   Should return the value associated with the key `key` in `bst` or NULL,
 *   if the key `key` was not found in `bst`.
 */
void* bst_get(struct bst* bst, int key) {

  struct bst_node* node = bst->root;



  while(node != NULL) {
    //printf("Node key: %d, Key: %d \n", node->key, key);
    if(node->key == key) {

      return node->value;

    }
    else if(key < node->key) {

      node = node->left;

    }
    else {
      node = node->right;

    }

  }

  return NULL;
}

void free_nodes(struct bst_node* node){

  if(node == NULL) {

    return;
  }

  free_nodes(node->left);
  free_nodes(node->right);

  free(node);

}

int count_nodes(struct bst_node* root) {
  
  unsigned int count = 1;

  if(root->left != NULL) {
    count += count_nodes(root->left);
  }
  if(root->right != NULL) {
    count += count_nodes(root->right);
  }

  return count;

}

struct bst_node* get_parent(struct bst* bst, int key) {

  struct bst_node* parent = bst->root;
  struct bst_node* cur_node = bst->root;

  while(cur_node != NULL) {

    if(key == cur_node->key) {
      return parent;

    }
    else if (key < cur_node->key) {
      parent = cur_node;
      cur_node = cur_node->left;
    
    }
    else {
      parent = cur_node;
      cur_node = cur_node->right;

    }
  }
  return NULL;
}

struct bst_node* get_child(struct bst_node* parent, int key) {

  if(parent == NULL) {
    return NULL;
  }

  if(key == parent->key) {
    return parent;

  }
  else if(key < parent->key) {
    return parent->left;
  }
  else {
    return parent->right;
  }

}

struct bst_node* node_s(struct bst_node* node_rem) {

  struct bst_node* cur_node = node_rem->right;

  while(cur_node->left != NULL) {

    cur_node = cur_node->left;

  }
  return cur_node;
}

struct bst_node* node_s_p(struct bst_node* node_rem, struct bst_node* node_child) {

  struct bst_node* parent = node_rem;

  if(parent->right == node_child) {
    return parent;
  }
  parent = parent->right;

  while(parent->left != node_child) {

    parent = parent->left;
  }
  return parent;
}

/*****************************************************************************
 **
 ** BST iterator definition (extra credit only)
 **
 *****************************************************************************/

/*
 * Structure used to represent a binary search tree iterator.  It contains
 * only a reference to a stack to be used to implement the iterator.
 *
 * You should not modify this structure.
 */
struct bst_iterator {
  struct stack* stack;
};

/*
 * This function should allocate and initialize an iterator over a specified
 * BST and return a pointer to that iterator.
 *
 * Params:
 *   bst - the BST for over which to create an iterator.  May not be NULL.
 */
struct bst_iterator* bst_iterator_create(struct bst* bst) {
  return NULL;
}

/*
 * This function should free all memory allocated to a given BST iterator.
 * It should NOT free any memory associated with the BST itself.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   iter - the BST iterator to be destroyed.  May not be NULL.
 */
void bst_iterator_free(struct bst_iterator* iter) {
  return;
}

/*
 * This function should indicate whether a given BST iterator has more nodes
 * to visit.  It should specifically return 1 (true) if the iterator has at
 * least one more node to visit or 0 (false) if it does not have any more
 * nodes to visit.
 *
 * Param:
 *   iter - the BST iterator to be checked for remaining nodes to visit.  May
 *     not be NULL.
 */
int bst_iterator_has_next(struct bst_iterator* iter) {
  return 0;
}

/*
 * This function should return both the value and key associated with the
 * current node pointed to by the specified BST iterator and advnce the
 * iterator to point to the next node in the BST (in in-order order).
 *
 * Because a function can't return two things, the key associated with the
 * current node should be returned the normal way, while its value should be
 * returned via the argument `value`.  Specifically, the argument `value`
 * is a pointer to a void pointer.  The current BST node's value (a void
 * pointer) should be stored at the address represented by `value` (i.e. by
 * dereferencing `value`).  This will look something like this:
 *
 *   *value = current_node->value;
 *
 * Parameters:
 *   iter - BST iterator.  The key and value associated with this iterator's
 *     current node should be returned, and the iterator should be updated to
 *     point to the next node in the BST (in in-order order).  May not be NULL.
 *   value - pointer at which the current BST node's value should be stored
 *     before this function returns.
 *
 * Return:
 *   This function should return the key associated with the current BST node
 *   pointed to by `iter`.
 */
int bst_iterator_next(struct bst_iterator* iter, void** value) {
  if (value) {
    *value = NULL;
  }
  return 0;
}
