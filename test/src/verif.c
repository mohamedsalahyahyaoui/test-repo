#include <stdio.h>
#define taille 100
#include "verif.h"
#include <string.h>
int verifier (char login[taille],char password[taille])
 {
    FILE *h;

    char tmp[taille]; 
    char tmp1[taille]; 

    int test,tmp2;

    tmp2=0;
    test=0;

    h=fopen("users.txt","r");

    if (h!=NULL)
        {
            while(fscanf(h,"%s %s %d \n",tmp,tmp1,&tmp2)!= EOF)   
            {
                if ((strcmp(login,tmp)==0)&&(strcmp(password,tmp1)==0))
                    {
                        test=1;
                        return tmp2;
                    }
            }
        }   
    fclose(h);    
    if (test==0) return -1;
     
 }



    
     

     
       

