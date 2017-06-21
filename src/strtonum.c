#include "strtonum.h"


int getNumber (char  **str)
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
        // getAdress(val);
        return val;
      }
      else
      {
        if(*endptr == 'x')
        {
          while(*ptr != ' ')
          {
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
        while(*ptr != ' '){
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
    // if(strcmpInsensitive(aWrite, str) ==  0){
      // return (char)ptr;
      
    // }
    *ptr++;
    *str = ptr;
    getNumber (str); 
  }
  else
  {
    *ptr++;
    *str = ptr;
    getNumber (str); 
  }
}

int strcmpInsensitive(char* a, char* b)
{
  int cmp;
  cmp = strcmpi(a, b);
  return cmp;
}

// int getAdress(long int val){
  // return val;
// }  

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
    i++;
    }
  }
  return i;
}

// int getCharacter(char **str){
  // int len = strlen (*str) + 1;
  // char *buffer = malloc (len);
  // char *write = "write";
  // char *read = "read";
  // char *ptr;
  // int  n;
  
  // ptr = *str;
  // if(*ptr == '\t'){
    // n = sscanf(*str, "%*[\t]%s", buffer);
    // printf("data = '%s'\n",buffer);
    // if(n == 1)
    // {
      // for (i = 0; i > len; i++){
        // if(buffer[i] == write[i])
      // }
      
    // }
  // return -1;
  // }
// }