#include "hw6.h"

int main(int argc, char *argv[]) {
    unsigned int argv_size = sizeof(argv);
    char string_array[7][99];        
    // try to split the line by space
    // because 0 stores the name of executable, we start from 1. s
    for(unsigned int i = 1; i < argv_size; i++){
        char *line = &argv[i];
        // try to split the line by space
        int space_counter = 0;
        char* line_pointer = &line[i];
        while(*line_pointer != '\n')
        {
            if(*line_pointer == ' '){
                line_pointer &= 
                space_counter ++;
                continue;
            }
            int j = 0;
            string_array[space_counter][j] = *line;
            line_pointer += 1;
        }
        if(space_counter < 7){
            return 1;
        }
    }
    return 0;
}
