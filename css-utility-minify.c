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


int main()
{

    char nameFile[] = "prueba.min.css";
    FILE * fptr;
    fptr = fopen(nameFile, "w+"); // "w" defines "writing mode"        

    FILE * file;
    file =  fopen("/home/carlos-sweb/Escritorio/css/pp-drawer/dist/alignment/align-content.css","r");

    if( file != NULL ){

        char * line = NULL;
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, file)) != -1){            
            fputs( trim( choppy( line ) ) ,fptr);
        }

    }else{
         printf("File not exists\n");
    }

    fclose(file);
    fclose(fptr);
    

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
