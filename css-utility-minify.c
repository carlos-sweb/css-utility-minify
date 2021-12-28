#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char * trim(char * buff);

char *choppy( char *s )
{
    char *n = malloc( strlen( s ? s : "\n" ) );
    if( s )
        strcpy( n, s );
    n[strlen(n)-1]='\0';
    return n;
}

int main( int argc ,char *argv[]  ) {

    if( argc  < 3 ){
      printf("%s\n","We need two argument :( ");
      exit(0);
    }

    FILE * file;
    file =  fopen( argv[1] ,"r");
    if( file == NULL ){
      printf("%s : ",argv[1]);
      printf("%s\n","File no exists");
      exit(0);
    }

    if( file != NULL ){

        FILE * fptr;
        fptr = fopen(argv[2], "w+"); // "w" defines "writing mode"
        char * line = NULL;
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, file)) != -1){
            fputs( trim( choppy( line ) ) ,fptr);
        }
        fclose(file);
        fclose(fptr);
    }

    return (0);
}

// https://stackoverflow.com/questions/1514660/remove-preceding-spaces-and-tabs-from-a-given-string-in-c-language
char * trim(char * buff)
{
    //PRECEDING CHARACTERS
    int x = 0;
    while(1==1)
    {
        if((*buff == ' ') || (*buff == '\t') || (*buff == '\r') || (*buff == '\n'))
            {
                x++;
                ++buff;
            }
        else
            break;
    }
    //printf("PRECEDING spaces : %d\n",x);
    //TRAILING CHARACTERS
    int y = strlen(buff)-1;
    while(1==1)
    {
        if(buff[y] == ' ' || (buff[y] == '\t') || (buff[y] == '\r') || (buff[y] == '\n'))
            {
                y--;
            }
        else
            break;
    }
    y = strlen(buff)-y;
    //printf("TRAILING spaces : %d\n",y);
    buff[strlen(buff)-y+1]='\0';
    return buff;
}
