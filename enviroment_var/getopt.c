#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
/*
Linux getopt funcion
prototype:
int getopt(int argc,char *const argv[],const char*optstring);
extern char *optarg;
extern int optind, opteer,optopt;

this function returns every signle option in each iteration,when done return -1,special charactors like -- may stop scanning;
if there is a refrence option in optstring, optarg point at it;
with unrecognised charactor getopt returns a '?'

when optstring start with ':', when come out a refrence option without refrence, getopt returns a ':' instead of '?'

under linux getopt reconstruct the argv, gather all the recognised option and the unrecognised,which start from argv[optind] until the end;
 */
int main(int argc,char *argv[])
{
  int opt;
  /*
    in optstring 
    if ':' after some character, means that character has relationship with something. such as 'f', there must something afer 'f'.
    example(int shell):
    ./getopt -f somefile.c
    while other options like i,l... may use without other things.
  */
  while((opt = getopt(argc, argv,":if:lr")) != -1)
    {
      switch(opt)
	{
	case'i':
	case'l':
	case'r':
	case'f':
	  printf("option %c\n",opt);
	  break;
	case':':
	  printf("option needs a value\n");
	  break;
	case'?':
	  printf("unknown option :%c\n",optopt);
	  break;
	}
     }
  for(;optind < argc;++optind)
    printf("argument:%s\n",argv[optind]);
  exit(0);
}
