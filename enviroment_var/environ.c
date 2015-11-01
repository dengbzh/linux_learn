#include<stdlib.h>
#include<stdio.h>
#include<string.h>
/*
This settings only effect this program, and the enviroment values cannot affer the father program

show env in shell:
  echo $HOME

function prototype:
char *getenv(const char*name);
   the format of env is "name=value";
   this function search a string and return teh value corrspond to the name.
       if the name is invalid,return null.
       if the name is exist but without value, returns a string begin with null.
       otherwise returns the value.

int putenv(const char*string);
   the format of parameter is "name=value"
   when space is not enough returns -1
*/

int main(int argc,char *argv[])
{
  char *var,*value;
  if(argc == 1 || argc > 3)
    {
      fprintf(stderr,"usage: environ var [value]\n");
      exit(1);
    }
  var = argv[1];
  value = getenv(var);
  if(value)
    printf("Varible %s has value %s\n",var,value);
  else
    printf("Varible %s has no value\n",var);

  if(argc == 3)
    {
      char *string;
      value = argv[2];
      string =(char*) malloc(strlen(var)+strlen(value)+2);
      if(!string)
	{
	  fprintf(stderr,"out of memory!\n");
	  exit(1);
	}
      strcpy(string,var);
      strcat(string,"=");
      strcat(string,value);
      printf("Calling putenv with: %s\n",string);
      if(putenv(string) != 0)
	{
	  fprintf(stderr,"putenv failed!\n");
	  free(string);
	  exit(1);
	}
      value = getenv(var);
      if(value)
	{
	  printf("New value of %s is %s\n",var,value);
	}
      else
	{
	  printf("New value of %s is null??\n",var);
	}
    }
  exit(0);
}
