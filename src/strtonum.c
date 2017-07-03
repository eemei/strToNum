#include "strtonum.h"


/**
Using the C library routine strtol:
     A command is a word separated by spaces or tab.  A word separated by certain characters (like space or tab) is called a token.
     To get tokens one by one, I use the C lib routing strtol (part of C stdlib.h see below how to include it).
         It's part of C language library <string.h> which you can look up online.  Basically you:
            1) pass it a string (and the delimeters you use, i.e. space and tab) and it will return the first token from the string
            2) on subsequent calls, pass it NULL (instead of the string ptr) and it will continue where it left off with the initial string.
      I've written a couple of basic helper routines:
          getNumber: uses strtol and sscanf (strtol: base 2,8, 10, 16 to long int, again part of C stdlib.h) to return an long integer.
          loop: returns how many valid value

*/

/**
* getNumber with char **str argumnent and return int 
* - return -1 
*   when invalid hex value or end of string 
*     -> example 00x12, 10x12, 01x123  
* 
* - return 2
*   when given char is write or read 
*   case insensitive
*
* - return val
*   valid decimal value or hex value
*/
int getNumber(char  **str)
{
  errno = 0;
  char *endptr;  //end pointer  
  int baseDecimal = 10;
  int baseHex = 16;
  char *ptr;
  char *detectHex;
  long int val;
  char *aWrite = "write";
  char *bRead = "read"; 
  ptr = *str;
  char data[10];
  char *receivestr;
  if(*ptr != '\0')
  {
    if (isdigit((unsigned char)*ptr))
    {
      val = strtol(*str, &endptr, baseDecimal);
      if(*ptr == '0')
      {
        detectHex = ptr;
        (*detectHex++);
        if(*detectHex == 'x' || *detectHex == 'X'){
          val = strtol(*str, &endptr, baseHex);
          if((val == LONG_MAX || val == LONG_MIN) && errno == ERANGE)
          {
            *str = endptr;
            return -1;
          }
          *str = endptr;
          return val;
        }
        else
        {
          if(*endptr == 'x' || *endptr == 'X')
          {
            while(*ptr != '\0')
            {
              if(*ptr == ' ')
              {
                *str = ptr;
                return -1;
              }
              if(*ptr == '\t')
              {
                *str = ptr;
                return -1;
              }
              *ptr++;
            }
            *str = ptr;
            return -1;
          }
        }
      }
      else 
      {
        if(*endptr == 'x'|| *endptr == 'X')
        {
          while(*ptr != '\0')
          {
            if(*ptr == ' ')
            {
              *str = ptr;
              return -1;
            }
            if(*ptr == '\t')
            {
              *str = ptr;
              return -1;
            }
            *ptr++;
          }
          *str = ptr;
          return -1;
        }
      }
      *str = endptr;
      return val;
    }
    if(isalpha((char)*ptr)){
      sscanf(ptr, "%s", data);
      if (strcmpInsensitive(aWrite, data) == 0){
        while(*ptr != '\0')
        {
          if(*ptr == ' ')
          {
            *str = ptr;
            return 2;
          }
          if(*ptr == '\t')
          {
            *str = ptr;
            return 2;
          }
          *ptr++;
        }
        *str = ptr;
        return 2;
      }
      else if (strcmpInsensitive(bRead, data) == 0){
        while(*ptr != '\0')
        {
          if(*ptr == ' ')
          {
            *str = ptr;
            return 2;
          }
          if(*ptr == '\t')
          {
            *str = ptr;
            return 2;
          }
          *ptr++;
        }
        *str = ptr;
        return 2;
      }
      return -1;
    }
    else
    {
      *ptr++;
      *str = ptr;
      getNumber (str); 
    }
  }
  else 
    return -1;
}

/**
* compare two strings which in case insensitive
*/
int strcmpInsensitive(char* a, char* b)
{
  int cmp;
  cmp = strcmpi(a, b);
  return cmp;
}
 
 /**
 this function return how many byte data that is valid value and character  
 */

int loop(char **str){
  char *ptr;
  ptr = *str;
  int i=0;
  int val = 0;
  while(*ptr !='\0')
  {
    val = getNumber(str);
    ptr = *str;
    if(val != -1)
    {
      if(val != 2)
      {
        i+=1;
      }   
    }
  }
  return i;
}
