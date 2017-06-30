#include "strtonum.h"

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
        if(*detectHex == 'x'){
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
          if(*endptr == 'x')
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
        if(*endptr == 'x')
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


int strcmpInsensitive(char* a, char* b)
{
  int cmp;
  cmp = strcmpi(a, b);
  return cmp;
}
 

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
