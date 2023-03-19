#include "hw6.h"

int main(int argc, char *argv[]) {
    unsigned int argv_size = sizeof(argv);
    // if(argv_size < 7) {
    //     return 1;
    // }
    for(int i = 0; i < argv_size;i++){
        char* line = &argv[i];
        if (line == NULL) return 1;
        int length = strlen(line);
        int num_space = 0;
        int space_positions[7] = {-999, -999, -999, -999, -999, -999, -999};
        for(int j = 0; j < length; j++){
            if(line[j] == ' '){
                space_positions[num_space] = j;
                num_space ++;
            }
        }
        if(num_space < 7) {
            return 1;
        }
        // split by found space indexs
        // find the length of each substrings. 
        int string_lengths[7] = {-555, -555, -555, -555, -555, -555, -555};
        for (int j = 0; j < sizeof(space_positions); j++){
            string_lengths[j] = space_positions[j+1] - space_positions[j] - j;
        }
        
        // int one_l = space_positions[1] - space_positions[0];// find length
        // int two_l = space_positions[2] - space_positions[1] - 1; // minus one after each iteration 
        // int three_l = space_positions[3] - space_positions[2] - 2;
    }
    return 0;
}
