#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct key_value{
    int key;
    char value[100];
} ThreeValues;

void get(int key){
    FILE *pFile = fopen("database.txt", "r");
    
    if(pFile == NULL){
        printf("Database doesn't exist or can't be opened!\n");
        return;
    }
    
    int keyValue;
    char value[100];
    bool isExist = false;

   while(fscanf(pFile, "%d,%99[^\n]", &keyValue, value) == 2){
       if(keyValue == key){
           isExist = true;
            break;
       }
    }
    
    if(isExist){
        printf("%d,%s\n", key, value);
    }
    else {
        printf("%d not found!\n", key);
    }
    fclose(pFile);
}

void put(ThreeValues values){
    FILE *pFile = fopen("database.txt", "a+");
    
    if(pFile == NULL){
        printf("Can't open the file!\n");
        return;
    }
    int temp;
    char value[100];
    	while(fscanf(pFile, "%d,%99[^\n]", &temp, value) == 2){  
	      		if(temp == values.key){ 
		printf("The key is already in the system!\n");
		return;
			}
        }
    fprintf(pFile, "%d,%s\n", values.key, values.value);
   
    fclose(pFile);
}

void delete(int key){
    FILE *pFile = fopen("database.txt", "r");
    FILE *pTemp = fopen("temp.txt", "a+");
    
    if(pFile == NULL || pTemp == NULL){
        return;
    }
    
    
    int tempKey;
    char value[100];
    bool isExist = false;
    
    while(fscanf(pFile, "%d,%99[^\n]", &tempKey, value) == 2){
        if(tempKey != key){
            fprintf(pTemp, "%d,%s\n", tempKey, value);
        }
        else {
            isExist = true;
        }
    }
    fclose(pFile);
    fclose(pTemp);
        
       if(isExist == true){
        remove("database.txt");
        rename("temp.txt", "database.txt");
    }
   
    else{
        printf("%d not found\n", key);
        remove("temp.txt");
    }
        
    
}
    void clear(){
        remove("database.txt");
    }
    
    void all(){
        FILE *pFile = fopen("database.txt", "r");
    if (pFile == NULL) {
        printf("Can't open file\n");
        return;
    }

    int key;
    char value[100];

    while (fscanf(pFile, "%d,%99[^\n]", &key, value) == 2) {
        printf("%d,%s\n", key, value);
    }

    fclose(pFile);
    }
    
   




ThreeValues loadNext(char *input){
    ThreeValues values;    
    
    int parseCount = sscanf(input, "%*c,%d,%99s", &values.key, values.value);
    return values;
}




int main(int argc, char** argv) {
    char ch;
    int value;
    //loadData();
    
    
        for(int i =1; i < argc; i++){
           if (argv[i][0] == 'p') {
          ThreeValues output = loadNext(argv[i]);
               put(output);
        } else if (argv[i][0] == 'g') {
            sscanf(argv[i], "%c,%d", &ch, &value);
            get(value);
        } else if (argv[i][0] == 'd') {
            sscanf(argv[i], "%c,%d", &ch, &value);
            delete(value);
        } else if (argv[i][0] == 'c') {
            clear();
        } else if (argv[i][0] == 'a') {
            all();
        } else {
           printf("bad command"); 
        }
          

    }
            
        return (EXIT_SUCCESS);
    }
    



