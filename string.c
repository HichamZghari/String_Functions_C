#include<stdio.h>
#include<stdlib.h>
#define Max_String 100
#define Max_Lines 10



//Searches the string for a specified value and returns the position of where it was found

int Find(char *s, char *value){

  if(! *value)
    return -1;
  
  int index = 0;

  while(*s && *s != *value)
    s++, index++;

  while(*s && *value && *s == *value)
    s++, value++;

  if(!*value)
    return index;

  return -1;

}


//////////////////////// Auxiliary functions ///////////////////////////

/////////////////////////////////////////////////////

void Concat(char *original, char *add){

  while(*original)
    original++;

  while(*add){
    *original = *add;
    original++, add++;
  }
  
  *original = '\0';  
}


char *ncaracters(char caracter, int value){

  char *result = malloc(value * sizeof(char*));
  
  for(int i = 0; i < value; i++)
    result[i] = caracter;

  result[value] = '\0';
  
  return result;

}




int is_letter(char c){

  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


int is_num(char c){

  return (c >= '0' && c <= '9');

} 

int is_num_or_letter(char c){

  return (is_num(c) || is_letter(c));

}
    
int printable(char c){

  return (c > 31);

}

int is_lower(char c){

  return (c >= 'a' && c <= 'z');

}

int is_upper(char c){

  return (c >= 'A' && c <= 'Z');

}

int is_function(int (*f)(char), char *s){

 while(*s){
    
    if(!f(*s))
      return 0;
    
    s++;
  }

  return 1;

}






void copy(char *or, char *cop){
  
  while(*cop){
    *or = *cop;
    or++, cop++;
  }
  
  *or = '\0';

}


void replace_first(char *or, char *s1, char *s2){

  int index = Find(or, s1);
 
  if(index >= 0){

    int ind = 0;
    int point;
    char *copy_or = or;
    char *new = malloc(sizeof(char*) * Max_String);
    
  
    for(int i = 0; i < index; i++)
      new[ind] = *copy_or, copy_or++, ind++, point++;  

    while(*s2)
      new[ind] = *s2, ind++, s2++;
    
    while(*s1)
      s1++, copy_or++, point++;

    while(*copy_or) 
      new[ind] = *copy_or, ind++, copy_or++, point++;

    new[ind] = '\0';
    
    copy(or, new);
    free(new);
   
  }


}




void strip_left(char *orig){

  if(Len(orig) > 0){

    char *new = malloc(sizeof(char*) * Max_String);
    char *copy_orig = orig;
    
    while(*copy_orig == ' ')
      copy_orig++;

    int i = 0;
    while(*copy_orig)
      new[i] = *copy_orig, copy_orig++, i++;

    new[i] = '\0';

    copy(orig, new);
    free(new);
    
  }
}


void strip_rigth(char *orig){

  int l = Len(orig);
  
  if(l > 0){

    int i = 0;
    char *copy_orig = orig;
    char *copy_orig2 = orig;
    char *new = malloc(sizeof(char*) * Max_String);
    
    while(*(copy_orig + 1))
      copy_orig++;

    while(*copy_orig == ' ')
      copy_orig--, i++;

    for(int j = 0; j < l - i; j++)
      new[j] = *copy_orig2, copy_orig2++;

    new[l - i] = '\0';
    copy(orig, new);
    free(new);

  }
}

int lines(char *orig){

  int i = 0;

  while(*orig){

    if(*orig == '\n')
      i++;

    orig++;

  }

  return i + 1;
}

///////////////////////////////////////////////////////////////


//Calculates string's length

int Len(char *s){

  int i = 0;
  
  while(*s)
    s++, i++;
    
  return i;
  
}


//Compares two strings

int Compare(char *s1, char *s2){

  while(*s1 && *s2 && *s1 == *s2)
    s1++, s2++;

  return (!*s1 && !*s2);
}


//Converts the first character to upper case

void Capitalize(char *s){

  if(*s && *s >= 'a' && *s <= 'z')
    *s -= 32;

}


//Converts string into lower case

void Casefold(char *s){
  
   while(*s){
    if(*s >= 'A' && *s <= 'Z')
      *s += 32;
    
    s++;
  }
}


//Returns a centered string

void Center(char *s, int length, char caracter){

  int lenS = Len(s);

  if(lenS < length){
    
  int n = ((length / 2) - (lenS / 2));
  char *s1 = ncaracters(caracter, length - n - lenS);
  char *s2 = ncaracters(caracter, n);
  
  Concat(s, s2);
  Concat(s1, s);
  copy(s, s1);
  free(s1);
  free(s2);
  
  }
  
}


//Returns the number of times a specified value occurs in a string

int Count(char *s, char *value){
  
 int count  = 0;
 char *news;
 char *newvalue; 

 if(! *value)
   return 0;
 
 while(*s){
  
   news = s;
   newvalue = value;

   while(*news && *newvalue && *news == *newvalue)
     news++, newvalue++;

   if(!*newvalue)
     count++;

   s++;

 }

   return count;
}


//Returns true if the string ends with the specified value

int Endswith(char *s, char *ending){

  if(!*ending)
    return 1;
  
  while(*s && *ending && *s != *ending)
    s++;

  while(*s && *ending && *s == *ending)
    s++, ending++;

  return (!*ending && !*s);

}


//Sets the tab size of the string

void Expandstabs(char *s, int n){

  char news[Max_String * 5];
  char *copys = s;
  
  int i = 0;
  
  while(*copys){
    
    if(*copys != ' '){
      news[i] = *copys;
      i++;
      
      for(int j = 0; j < n; j++)
	news[i + j] = ' ';

      i += n;
   
    }

    copys++;
  }

  news[i] = '\0';
  copy(s, news);
  
  

}



//Searches the string for a specified value and returns the position of where it was found

int Index(char *s, char *value, int a, int b){

  if(! *value)
    return -1;
  
  int index = 0;
  int j = a;
  
  for(int i = 0; i < a; i++)
    *s++;
  
  while(j < b && *s && *s != *value)
    s++, index++, j++;

  while(j < b && *s && *value && *s == *value)
    s++, value++, j++;

  if(!*value)
    return index;

  return -1;

}


//Returns True if all characters in the string are alphanumeric

int Isalnum(char *s){

  if(!*s)
    return 0;
  
  return is_function(is_num_or_letter, s);
  
}


//Returns True if all characters in the string are in the alphabet

int Isalpha(char *s){

  if(!*s)
    return 0;
  
  return is_function(is_letter, s);
  
}


//Returns True if all characters in the string are decimals

int Isdecimal(char *s){

  if(!*s)
    return 0;
  
  return is_function(is_num, s);
  
}
 



//Returns True if all characters in the string are printable

int Isprintable(char *s){

  return is_function(printable, s);

}


//Returns True if all characters in the string are lower case

int Islower(char *s){

  return is_function(is_lower, s);

}


//Returns True if all characters in the string are upper case

int Isupper(char *s){

  return is_function(is_upper, s);

}


//Returns True if the string follows the rules of a title

int Istitle(char *s){

  if(is_upper(*s)){
    s++;
    while(*s && is_lower(*s))
      s++;

    if(! *s)
      return 1;
  }

  return 0;

}


//Returns a string where a specified value is replaced with a specified value

void Replace(char *orig, char *s1, char *s2){

  if(!Compare(s1, s2)){
    
    int index = Find(orig, s1);

    while(index >= 0){

      replace_first(orig, s1, s2);
      index = Find(orig, s1);
    }
  }
}
    

//Returns a right justified version of the string

void Rjust(char *orig, int n, char c){

  int l = Len(orig);
  
  if(n > l){

    char *new = malloc(sizeof(char*) * Max_String);
    
    for(int i = 0; i < (n - l); i++)
      new[i] = c;

    for(int i = (n - l); i < n; i++)
      new[i] = orig[i - (n - l)];
    
    new[n] = '\0';
    
    copy(orig, new);
    free(new);
  }

}


//Fills the string with a specified number of 0 values at the beginning

void Zfill(char *orig, int n){

  return Rjust(orig, n, '0');

}


//Converts the first character of each word to upper case

void Title(char *orig){

  int l = Len(orig);

  if(l > 0){

    if(is_lower(orig[0]))
      orig[0] -= 32;
    
    for(int i = 1; i < l; i++)
      if(is_lower(orig[i]) && orig[i - 1] == ' ')
	orig[i] = orig[i] - 32;
  }

}


//Swaps cases, lower case becomes upper case and vice versa

void Swapcase(char *orig){

  while(*orig){

    if(is_lower(*orig))
      *orig -= 32;

    else if(is_upper(*orig))
      *orig += 32;

    orig++;

  }
}


//Returns true if the string starts with the specified value

int Startswith(char *orig, char *start){

  while(*orig && *start && *orig == *start)
    orig++, start++;

  return (! *start);

}


//Returns a trimmed version of the string

void Strip(char *orig){

  strip_left(orig);
  strip_rigth(orig);

}



//Splits the string at the specified separator, and returns a list

char **Rsplit(char *orig, char sep){

  int nb_lines = lines(orig);
  char **result = malloc(sizeof(char**) * nb_lines);
  int i = 0;

  while(i < nb_lines){
   
    result[i] = malloc(sizeof(char*) * Max_String);
    int j =0;
    
    while(*orig && *orig != sep)
      result[i][j] = *orig, orig++, j++;

    result[i][j] = '\0';
    orig++;
    i++;
   

  }

  return result;
}
      

//Splits the string at line breaks and returns a list

char **Splitlines(char *orig){

  return Rsplit(orig, '\n');

}


//Returns a tuple where the string is parted into three parts

char **Rpartition(char *orig, char *part){

  int n = Find(orig, part);
  int l = Len(orig);
  int l1 = Len(part);
  char **result = malloc(sizeof(char**) * 3);

  for(int i = 0; i < 3; i++)
    result[i] = malloc(sizeof(char*) * Max_String);

  for(int i = 0; i < n; i++)
    result[0][i] = orig[i];

  result[0][n] = '\0';

  copy(result[1], part);

  for(int i = n + l1; i < l; i++)
    result[2][i - n - l1] = orig[i];

  return result;

}


//Searches the string for a specified value and returns the last position of where it was found

int Rfind(char *orig, char *value){

  if(! *value)
    return -1;
  
  int l = Len(orig);
  int lv = Len(value);
  int i = l - 1;
  int j = lv - 1;

  while(i >= 0){
    
  while(orig[i] != value[j])
    i--;

  if(i >= 0)
    while(j >= 0 && i >= 0 && orig[i] == value[j])
      i--, j--;

  if(j < 0)
    return i + 1;

  }

  return -1;

}
  

char *Join(char **string_array, int len){

  char *joined = malloc(sizeof(char*) * Max_String * 10);
  *joined = '\0';
  
  for(int i = 0; i < len; i++)
    Concat(joined, string_array[i]);

  return joined;

}

