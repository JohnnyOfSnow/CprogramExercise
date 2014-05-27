#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 120

// self-referential structure                            
struct treeNode {                                           
   struct treeNode *leftPtr; // pointer to left subtree 
   char *data; // node value                               
   struct treeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode                             

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// prototypes
void insertNode( TreeNodePtr *treePtr, char *value );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );

// function main begins program execution
int main( void )
{ 
  
   TreeNodePtr rootPtr = NULL; // tree initially empty

   char *tokenPtr; // create char pointer
   int c; // variable to hold character input by user
   char sentence[ SIZE ]; // create char array
   int i = 0; // initialize counter i
  
   // prompt user to enter line of text
   puts( "Enter a line of text:" ); 

   // use getchar to read each character                
   while ( i < SIZE - 1 && ( c = getchar() ) != '\n' ) {
      sentence[ i++ ] = c;                              
   } // end while 
       
   puts("---------------------------------------------------------------");                                  
   puts("Start to token the line of text you input, and add to the tree.");
   puts("---------------------------------------------------------------"); 
   
   sentence[ i ] = '\0'; // terminate string   
   tokenPtr = strtok( sentence, " " ); // begin tokenizing sentence
   
   // continue tokenizing sentence until tokenPtr becomes NULL
   while ( tokenPtr != NULL ) {
      insertNode( &rootPtr, tokenPtr);
      tokenPtr = strtok( NULL, " " ); // get next token
   } // end while
   
   puts("\n*******************************************************************");  
   puts("Tokenizing the line of text is done, and the tree is established.");
   puts("*******************************************************************\n");
   
   // traverse the tree preOrder
   puts( "The preOrder traversal is:" );
   preOrder( rootPtr );
   
   puts("");
   
   // traverse the tree inOrder
   puts( "\nThe inOrder traversal is:" );
   inOrder( rootPtr );
   
   puts("");
   
   // traverse the tree postOrder
   puts( "\nThe postOrder traversal is:" );
   postOrder( rootPtr );
   
   puts("\n--------------------------------");
   system("pause");
   return 0;
} // end main

// insert node into tree
void insertNode( TreeNodePtr *treePtr, char *value )
{ 
   // if tree is empty
   if ( *treePtr == NULL ) {   
      *treePtr = (TreeNodePtr)malloc( sizeof( TreeNode ) );

      // if memory was allocated, then assign data
      if ( *treePtr != NULL ) { 
         ( *treePtr )->data = value;
         ( *treePtr )->leftPtr = NULL;
         ( *treePtr )->rightPtr = NULL;
      } // end if
      else {
         printf( "%s not inserted. No memory available.\n", value );
      } // end else
   } // end if
   else { // tree is not empty
      // data to insert is greaterless than data in current node
      if(strcmp(value ,( *treePtr )->data) == 1){
         insertNode( &( ( *treePtr )->rightPtr ), value );               
      }                               
      // data to insert is less than data in current node
      else if(strcmp(value ,( *treePtr )->data) == -1){
         insertNode( &( ( *treePtr )->leftPtr ), value );               
      } // end else if                                      
      else { // duplicate data value ignored
         printf( "The String %s is repeat\n", value);
      } // end else
   } // end else
} // end function insertNode

// begin inorder traversal of tree
void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {                
      inOrder( treePtr->leftPtr );         
      printf( "%s ", treePtr->data );      
      inOrder( treePtr->rightPtr );        
   } // end if                          
} // end function inOrder

// begin preorder traversal of tree
void preOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {                
      printf( "%s ", treePtr->data );      
      preOrder( treePtr->leftPtr );        
      preOrder( treePtr->rightPtr );       
   } // end if                          
} // end function preOrder

// begin postorder traversal of tree
void postOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {                
      postOrder( treePtr->leftPtr );       
      postOrder( treePtr->rightPtr );      
      printf( "%s ", treePtr->data );      
   } // end if                          
} // end function postOrder
