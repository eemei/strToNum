#include "strtonum.h"


int getNumber (char  **str)
{
  char *endptr;  //end pointer  
  int baseDecimal = 10;
  int baseHex = 16;
  char *ptr;
  char *detectHex;
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
        if (*endptr == 'x')  //example 0x,...
        {
          val = strtol(ptr, &endptr, baseHex);
          return val;
        }
      }
      *str = endptr;
      getNumber(str);
    }
    else 
    {
      detectHex = ptr;
      /* Non-digit: suffix not found yet */ 
      val = strtol(ptr, &endptr, 0);
      if(*detectHex == ' ' || *detectHex == '\t')
      {
        (*detectHex++);
        if(*detectHex == '0')
        {
          (*detectHex++);
          if(*detectHex == 'x'){
            val = strtol(ptr, &endptr, baseHex);
            printf ("getNumber val 16 = '%x'\n\n", val);
            printf("endptr 16= %s\n", endptr);
          }
        }
      }

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
