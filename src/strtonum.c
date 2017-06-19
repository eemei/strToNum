#include "strtonum.h"


int getNumber (char  **str)
{
  char *endptr;  //end pointer  
  int baseDecimal = 10;
  int baseHex = 16;
  char *ptr;
  long int val;

  ptr = *str;
  if(*ptr != '\0')
  {
    if (isdigit((unsigned char)*ptr)) 
    {
      val = strtol(ptr, &endptr, baseDecimal);
      printf ("getNumber val = '%x'\n\n", val);
      printf("endptr = %s\n", endptr);
      if(*ptr == '0')
      {
        if(*endptr == 'x')
        {
          val = strtol(ptr, &endptr, baseHex);
          printf ("getNumber val 16 = '%x'\n\n", val);
          printf("endptr 16= %s\n", endptr);
        }
      }
      *str = endptr;
        getNumber(str);
    }
    else 
    {
    /* Non-digit: suffix not found yet */ 
    val = strtol(ptr, &endptr, 0);
    if(ptr == endptr)
    {
      printf("ERR: cannot be covert %s to long int\r\n\n", endptr);
      return -1;
    }
     (*ptr++);
     *str = ptr;
     getNumber(str);
    }
  }
  else{
    printf ("getNumber val return = '%x'\n\n", val);
    return val;
  }
      

 
}  




// int getNumber (char  **str)
// {
  // char *endptr;  //end pointer  
  // int baseDecimal = 10;
  // int baseHex = 16;
  // char *ptr;
  // long int val;
  // int i = 0;
  // int j = 0;
  // int dseen = 0;

  // if(endptr == *str)
  // {
    // printf("ERR: cannot be covert %s to long int\r\n\n", endptr);
    // return -1;
  // }
 
  // for ( ptr = *str; *ptr != '\0'; ++ptr) 
  // {
    // if (isdigit((unsigned char)*ptr)) 
    // {
       // val = strtol(ptr, &endptr, baseHex);
      
      // if (dseen == 0) 
      // {
        // *str = endptr;
      // /* Digit string starts here */
        // dseen = 1;
        
        // i = i + 1;
        // printf("i =%d\n",i);
        // return getNumber(str);
            // printf ("getNumber val = %x\n\n", val);
    // return val;
      // }
    // }
    // else 
    // {
    // /* Non-digit: suffix not found yet */
    // i = i;
    // dseen = 0;

    // }
  // }
  
  // if (dseen == 0)
  // return -1;

    // printf("a");

// }

// int getnum(const char *str) {
// const char *ptr;
// char *end;
// int dseen;
// long value;

// Advance `str' to start of all-digits suffix.
// * (Alternating strspn() and strcspn() calls might
// * be slicker, but this loop has the virtue of
// * simplicity.)

// dseen = 0;
// for (ptr = str; *ptr != '\0'; ++ptr) {
// if (isdigit((unsigned char)*ptr)) {
// if (dseen == 0) {
////Digit string starts here
// str = ptr;
// dseen = 1;
// }
// }
// else {
////Non-digit: suffix not found yet
// dseen = 0;
// }
// }

////Can't proceed if no such suffix found
// if (dseen == 0)
// return -1;

////Try to convert the suffix
// errno = 0;
// value = strtol(str, &end, 10);
// printf("value =%x\n\n", value);
// printf("endptr = %s\n", end);

// //Fail if unable to convert or if result is
////* too large for an `int'

// if (errno == ERANGE || end == str || value > INT_MAX)
// return -1;

// return value;
// }

// https://codereview.stackexchange.com/questions/28694/algorithm-and-tests-to-parse-lists-of-unsigned-32-bit-ints-from-strings-in-c