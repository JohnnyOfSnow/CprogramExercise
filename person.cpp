// Fig. 11.15: fig11_15.c
// Bank-account program reads a random-access file sequentially, 
// updates data already written to the file, creates new data to 
// be placed in the file, and deletes data previously in the file.
#include <stdio.h>

// clientData structure definition               
struct person { 
   int index; // person number                             
   int age; // age
   char lastName[ 15 ]; // person last name     
   char firstName[ 10 ]; // person first name              
}; // end structure clientData                   

// prototypes
unsigned int enterChoice( void );
void textFile( FILE *readPtr );
void updateRecord( FILE *fPtr );
void newRecord( FILE *fPtr );
void deleteRecord( FILE *fPtr );

int main( void )
{ 
   FILE *cfPtr; // credit.dat file pointer
   unsigned int choice,i; // user's choice

   // fopen opens the file; exits if file cannot be opened
   if ( ( cfPtr = fopen( "nameage.dat", "rb+" ) ) == NULL ) {
      puts( "File could not be opened." );
      // output 100 blank records to file                              
      if ( ( cfPtr = fopen( "nameage.dat", "wb" ) ) == NULL ) {
         puts( "File could not be written." );
      } // end if
      else { 
           struct person blankPerson = { 0, 0, "","" };
           // output 100 blank records to file                              
           for ( i = 1; i <= 100; ++i ) {                                   
           fwrite( &blankPerson, sizeof( struct person ), 1, cfPtr );
           } // end for                                                     
     } // end else                                               
   } // end if
   else { 
      // enable user to specify action
      while ( ( choice = enterChoice() ) != 5 ) { 
         switch ( choice ) { 
            // create text file from record file
            case 1:
               textFile( cfPtr );
               break;
            // update record
            case 2:
               updateRecord( cfPtr );
               break;
            // create record
            case 3:
               newRecord( cfPtr );
               break;
            // delete existing record
            case 4:
               deleteRecord( cfPtr );
               break;
            // display message if user does not select valid choice
            default:
               puts( "Incorrect choice" );
               break;
         } // end switch
      } // end while

      fclose( cfPtr ); // fclose closes the file
   } // end else
} // end main

// create formatted text file for printing 
void textFile( FILE *readPtr )
{ 
   FILE *writePtr; // accounts.txt file pointer
   int result; // used to test whether fread read any bytes

   // create clientData with default information
   struct person Aperson = { 0, 0, "","" };

   // fopen opens the file; exits if file cannot be opened
   if ( ( writePtr = fopen( "nameage.txt", "w" ) ) == NULL ) {
      puts( "File could not be opened." );
   } // end if
   else { 
      rewind( readPtr ); // sets pointer to beginning of file
      fprintf( writePtr, "%-6s%-16s%-11s%8s\n", 
         "index", "Last Name", "First Name","Age" );

      // copy all records from random-access file into text file
      while ( !feof( readPtr ) ) { 
         result = fread(&Aperson, sizeof( struct person ), 1, readPtr);

         // write single record to text file
         if ( result != 0 && Aperson.age != '\0' ) {
            fprintf( writePtr, "%-6d%-16s%-11s%8d\n",
               Aperson.index, Aperson.lastName,         
               Aperson.firstName, Aperson.age );      
         } // end if
      } // end while

      fclose( writePtr ); // fclose closes the file
   } // end else
} // end function textFile

// update balance in record
void updateRecord( FILE *fPtr )

{ 
   unsigned int index; // account number
   int transaction; // transaction amount

   // create clientData with no information
   struct person Aperson = { 0, 0, "","" };

   // obtain number of account to update
   printf( "%s", "Enter index to update ( 1 - 100 ): " );
   scanf( "%d", &index );
   
  
   // move file pointer to correct record in file              
   fseek( fPtr, ( index - 1 ) * sizeof( struct person ), 
      SEEK_SET );                                              

   // read record from file
   fread( &Aperson, sizeof( struct person ), 1, fPtr );

   // display error if account does not exist
   if ( Aperson.age == '\0' ) {
      printf( "Index %d has no information.\n", index );
   } // end if
   else { // update record
      printf( "%-6d%-16s%-11s%8d\n\n", 
         Aperson.index, Aperson.lastName, 
         Aperson.firstName, Aperson.age );
      
      // request transaction amount from user 
      printf( "%s", "Enter charge number of age: " );
      scanf( "%d", &transaction );
      
      Aperson.age = transaction; // update age
      
      printf( "%-6d%-16s%-11s%8d\n", 
         Aperson.index, Aperson.lastName, 
         Aperson.firstName, Aperson.age );
      
      // move file pointer to correct record in file              
      fseek( fPtr, ( index - 1 ) * sizeof( struct person ), 
         SEEK_SET );                                              

      // write updated record over old record in file         
      fwrite( &Aperson, sizeof( struct person ), 1, fPtr );
   } // end else
} // end function updateRecord

// delete an existing record
void deleteRecord( FILE *fPtr )
{ 
   struct person Aperson; // stores record read from file
   struct person blankPerson = { 0, 0, "","" }; // blank client
   
   unsigned int index; // account number

   // obtain number of account to delete
   printf( "%s", "Enter index number to delete ( 1 - 100 ): " );
   scanf( "%d", &index );

   // move file pointer to correct record in file                 
   fseek( fPtr, ( index - 1 ) * sizeof( struct person ), 
      SEEK_SET );                                                 

   // read record from file                               
   fread( &Aperson, sizeof( struct person ), 1, fPtr );

   // display error if record does not exist
   if ( Aperson.index == 0 ) {
      printf( "Index %d does not exist.\n", index );
   } // end if
   else { // delete record
      // move file pointer to correct record in file                 
      fseek( fPtr, ( index - 1 ) * sizeof( struct person ), 
         SEEK_SET );                                                 

      // replace existing record with blank record   
      fwrite( &blankPerson,                          
         sizeof( struct person ), 1, fPtr );     
   } // end else
} // end function deleteRecord

// create and insert record
void newRecord( FILE *fPtr )
{ 
   // create clientData with default information
   struct person Aperson = { 0, 0, "","" };

   unsigned int index; // account number

   // obtain number of account to create
   printf( "%s", "Enter new index number ( 1 - 100 ): " );
   scanf( "%d", &index );

   // move file pointer to correct record in file                 
   fseek( fPtr, ( index - 1 ) * sizeof( struct person ), 
      SEEK_SET );                                                 

   // read record from file                               
   fread( &Aperson, sizeof( struct person ), 1, fPtr );

   // display error if account already exists
   if ( Aperson.index != 0 ) {
      printf( "Index #%d already contains information.\n",
         Aperson.index );
   } // end if
   else { // create record
      // user enters last name, first name and balance
      printf( "%s", "Enter lastname, firstname, age\n? " );
      scanf( "%14s%9s%d", &Aperson.lastName, &Aperson.firstName, 
         &Aperson.age );

      Aperson.index = index;
      
      // move file pointer to correct record in file   
      fseek( fPtr, ( Aperson.index - 1 ) *            
         sizeof( struct person ), SEEK_SET );      

      // insert record in file                       
      fwrite( &Aperson,                               
         sizeof( struct person ), 1, fPtr );     
   } // end else
} // end function newRecord

// enable user to input menu choice
unsigned int enterChoice( void )
{ 
   unsigned int menuChoice; // variable to store user's choice

   // display available options
   printf( "%s", "\nEnter your choice\n"
      "1 - store a formatted text file of accounts called\n"
      "    \"nameage.txt\" for printing\n"
      "2 - update an age\n"
      "3 - add a new person information\n"
      "4 - delete a person information\n"
      "5 - end program\n? " );

   scanf( "%u", &menuChoice ); // receive choice from user
   return menuChoice;
} // end function enterChoice
