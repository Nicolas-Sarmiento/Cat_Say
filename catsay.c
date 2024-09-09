#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<wchar.h>
FILE *pet;
int LENGHT = 30;
char* DEFAULT_MESSAGE[] = {"","C","is","the","best","language!!","C >> JS"};
void openPet(char* url){
    pet = fopen(url, "r");
}
void printPet(){
    char buffer [256];
    while (fgets(buffer, sizeof(buffer), pet)){
        printf("%s", buffer);
    }
    fclose(pet);
}
void printMsg(int argc, char* args[]){
    int arg = 1;
    int ln = 0;
    int lastln = 0;
    while (arg < argc){
        ln += strlen(args[arg]) + 1;
        if( ln > LENGHT){
            for(int i = 0; i <= (LENGHT-lastln-2);i++){
                printf(" ");
            }
            ln = strlen(args[arg]) + 1;
            lastln = 0;
            printf("|\n|%s ", args[arg]);

        }else{
            printf("%s ", args[arg]);
        }
        lastln += strlen(args[arg]) + 1;
        arg++;
    }
    for(int i = 0; i <= (LENGHT-lastln-2);i++){
        printf(" ");
    }
    printf("|\n\\");
}

int main(int argc, char* args[]){
    setlocale(LC_ALL, "");
    openPet("cat.txt");
    if(pet == NULL){
        perror("cannot find pet");
        return -1;
    }
    if(argc < 2){
        args = DEFAULT_MESSAGE;
        argc = sizeof(DEFAULT_MESSAGE)/sizeof(DEFAULT_MESSAGE[0]);
    }
    int len;
    for(int i = 1; i < argc; i++){
        len = strlen(args[i]); 
        if( len > LENGHT){
            LENGHT = len + 6;
        }
    }
    printf("/");
    for(int i = 1; i < LENGHT; i++){
        printf("-");
    }
    printf("\\\n|");
    printMsg(argc, args);
    for(int i = 1; i < LENGHT; i++){
        printf("-");
    }
    printf("/\n");
    printPet();
    return 0;
}