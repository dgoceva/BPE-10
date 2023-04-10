#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN 31
#define CH_LEN 8

typedef struct {
    char name[LEN];
    char chip[CH_LEN];
    float price;
} TPet;

TPet inputPet(void)
{
    TPet pet;
    FILE *f;

    printf("Name: ");
    fgets(pet.name,LEN,stdin);
    fflush(stdin);
    printf("Chip: ");
    pet.name[strlen(pet.name)-1]='\0';
    fgets(pet.chip,CH_LEN,stdin);
    fflush(stdin);
    printf("Price: ");
    scanf("%f",&pet.price);
    fflush(stdin);

 //   if((f=fopen("animalsText.txt","w"))==NULL) {
    if((f=fopen("animalsText.txt","a"))==NULL) {
        perror("Open error: ");
        exit(2);
    }
    fprintf(f,"%s,%.2f\n",pet.name,pet.price);
    fclose(f);
    return pet;
}

void printPetsByPrice(TPet pets[],unsigned len,float price)
{
    bool isFound=false;

    for(int i=0;i<len;++i){
        if(pets[i].price==price){
            isFound=true;
            printf(" %s - %s\n",pets[i].name,pets[i].chip);
        }
    }
    if(!isFound){
        puts("No such data...\n");
    }
}

void printPets(float price)
{
    FILE *f;
    unsigned len;
    TPet pet;
    bool isFirst=true;

    if((f=fopen("animalsBin.bin","rb"))==NULL){
        perror("Open Bin error: ");
        exit(4);
    }

    while(true){
        if(fread(&len,sizeof(unsigned),1,f)!=1){
            if(!feof(f)){
                perror("Reading bin error: ");
                fclose(f);
                exit(10);
            }else
                break;
        }
        if(fread(&pet.name,sizeof(char),len,f)!=len){
            perror("Reading bin error: ");
            fclose(f);
            exit(11);
        }
        pet.name[len]='\0';
        if(fread(&pet.chip,sizeof(char),CH_LEN-1,f)!=CH_LEN-1){
                perror("Reading bin error: ");
                fclose(f);
                exit(12);
        }
        pet.chip[CH_LEN-1]='\0';
        if(fread(&pet.price,sizeof(float),1,f)!=1){
                perror("Reading bin error: ");
                fclose(f);
                exit(13);
        }
        if(pet.price>=price){
            if(!isFirst){
                puts("----------\n");
            } else
                isFirst=false;
            printf("Bin Owner Name: %s\n",pet.name);
            printf("Bin Chip: %s\n",pet.chip);
            printf("Bin Price: %.2f\n",pet.price);
        }
    }
    fclose(f);
}
int main()
{
    /*
    TPet pets[LEN];
    const unsigned SIZE=5;

    for(int i=0;i<SIZE;++i){
        pets[i] = inputPet();
    }
    printPetsByPrice(pets,SIZE,22.22);
    writeToBin(pets,SIZE);
    */
    printPets(25);
    printf("Hello world!\n");
    return 0;
}

void writeToBin(TPet pets[],unsigned len)
{
    FILE *f = fopen("animalsBin.bin","wb");
    unsigned size;

    if(f==NULL){
        perror("Write error: ");
        exit(3);
    }
    for(int i=0;i<len;++i){
        size = strlen(pets[i].name);
        fwrite(&size,sizeof(unsigned),1,f);
        fwrite(pets[i].name,sizeof(char),size,f);
        fwrite(pets[i].chip,sizeof(char),CH_LEN-1,f);
        fwrite(&pets[i].price,sizeof(float),1,f);
    }
    fclose(f);
}
