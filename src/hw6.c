#include "hw6.h"

int main(int argc, char *argv[]) {
    unsigned int argv_size = sizeof(argv);
    // because 0 stores the name of executable, we start from 1. s
    for(unsigned int i = 1; i < argv_size; i++){
        char *line = argv[i];

        // try to split the line by space
        char string_array[7][99];
        int space_counter = 0;
        while(*line != '\n')
        {
            if(*line == ' '){
                *line += 1;
                space_counter ++;
                continue;
            }
            int j = 0;
            string_array[space_counter][j] = *line;
            *line += 1;
        }
        
    }
    return 0;
}
