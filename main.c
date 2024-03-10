#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct key_value{
    char functionChar;
    int key;
    char *value;
} ThreeValues;


ThreeValues loadNextArgv(char *input){
    ThreeValues values;
    
    values.value = (char*)malloc(100 * sizeof(char));
    
    
    int parseCount = sscanf(input, "%c,%d,%99s", &values.functionChar, &values.key, values.value);
    
    if(parseCount != 3){
        printf("something wrong buddy");
    }
    
    return values;
}



int main(int argc, char** argv) {

    
    if(argc > 1){
       ThreeValues output = loadNextArgv(argv[1]);
       printf("here is the values: %c, %d, %s\n", output.functionChar, output.key, output.value);
       
       free(output.value);
    }
    
    
    
    
    
    
    
    return (EXIT_SUCCESS);
}

