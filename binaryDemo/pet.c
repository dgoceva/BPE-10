#include "pet.h"

unsigned readCsv(char* fname,TPet *pets)
{
    FILE *f;
    int index=0;
    char buff[MAX_SIZE];

    f=fopen(fname,"r");
    if(f==NULL){
            perror("Open txt error: ");
        exit(2);
    }

    while(true){
        if(fgets(buff,MAX_SIZE,f)==NULL){
            if(!feof(f)){
                perror("Reading error: ");
                fclose(f);
                exit(3);
            }else {
                fclose(f);
                return index;
            }
        }
        if(!parsePet(buff,pets+index)){
            fclose(f);
            exit(4);
        }
        index++;
    }
}

bool parsePet(char *buff, TPet *pet)
{
    char *token;
    const char* DELIM=",";

    token = strtok(buff,DELIM);
    if(token==NULL){
        return false;
    }
    strcpy(pet->name,token);
    token = strtok(NULL,DELIM);
    if(token==NULL){
        return false;
    }
    strcpy(pet->chip,token);
    token = strtok(NULL,DELIM);
    if(token==NULL){
        return false;
    }
    pet->price = atof(token);
    return true;
}

void printPets(TPet *pets, unsigned len)
{
    for(int i=0;i<len;++i){
        printf("%s - %s - %g\n",pets[i].name,pets[i].chip,pets[i].price);
    }
}

void writeBin(char *fname, TPet *pets, unsigned len)
{
    FILE *f = fopen(fname,"wb");

    if(f==NULL){
            perror("Open bin error: ");
        exit(22);
    }
    fwrite(pets,sizeof(TPet),len,f);
    fclose(f);
}
