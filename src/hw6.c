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
        
        // int one_l = space_positions[1] - space_positions[0];
        // find length
        // int two_l = space_positions[2] - space_positions[1] - 1; 
        // minus one after each iteration 
        // int three_l = space_positions[3] - space_positions[2] - 2;

        // initialize strings with given lengths above. 
        char* substring_0 = NULL;
        substring_0 = (char*) calloc (string_lengths[0]+1, sizeof(char));
        char* substring_1 = NULL;
        substring_1 = (char*) calloc (string_lengths[1]+1, sizeof(char));
        char* substring_2 = NULL;
        substring_2 = (char*) calloc (string_lengths[2]+1, sizeof(char));
        char* substring_3 = NULL;
        substring_3 = (char*) calloc (string_lengths[3]+1, sizeof(char));
        char* substring_4 = NULL;
        substring_4 = (char*) calloc (string_lengths[4]+1, sizeof(char));
        char* substring_5 = NULL;
        substring_5 = (char*) calloc (string_lengths[5]+1, sizeof(char));
        char* substring_6 = NULL;
        substring_6 = (char*) calloc (string_lengths[6]+1, sizeof(char));

        //store strings pters into an array. 
        char* substrings[7] = {substring_0, substring_1, substring_2, substring_3, 
        substring_4, substring_5, substring_6};

        // put original string into different substrings
        // substr 0
        int c = 0;
        int substring_ptr = 0;
        int count_char = 0;
        while(count_char < string_lengths[0]){
            substring_0[count_char] = line[c];
            count_char++;
            c++;
        }
        substring_ptr++;
        //substr 1
        c = space_positions[1] + 1;
        count_char = 0;
        while(count_char < string_lengths[1]){
            substring_1[count_char] = line[c];
            c++;
        }
        substring_ptr++;
        //substr 2
        c = space_positions[2] + 1;
        count_char = 0;
        while(count_char < string_lengths[2]){
            substring_2[count_char] = line[c];
            c++;
        }
        substring_ptr++;
        //substr 3
        c = space_positions[3] + 1;
        count_char = 0;
        while(count_char < string_lengths[3]){
            substring_3[count_char] = line[c];
            c++;
        }
        substring_ptr++;
        //substr 4
        c = space_positions[4] + 1;
        count_char = 0;
        while(count_char < string_lengths[4]){
            substring_4[count_char] = line[c];
            c++;
        }
        substring_ptr++;
        //substr 5
        c = space_positions[5] + 1;
        count_char = 0;
        while(count_char < string_lengths[4]){
            substring_5[count_char] = line[c];
            c++;
        }
        substring_ptr++;
        //substr 6
        c = space_positions[6] + 1;
        count_char = 0;
        while(count_char < string_lengths[4]){
            substring_6[count_char] = line[c];
            c++;
        }
        substring_ptr++;
    }
    return 0;
}
