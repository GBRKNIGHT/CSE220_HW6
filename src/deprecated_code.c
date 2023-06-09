// #include "hw6.h"


// // function to divide a string by space. 
// char** divide_line(char* input_line)
// {
//     int length = strlen(input_line);
//     char** result = malloc(MAX_SEARCH_LEN * 8); 
//     int word_count = 0;
//     char* word = strtok(input_line, " ");
//     while(word != NULL){
//         int word_length = strlen(word);
//         result[word_count] = malloc(word_length + 1);
//         strcpy(result[word_count], word);
//         word_count++;
//         word = strtok(NULL, " ");
//     }
//     result[sizeof(result)] = NULL; // set the last element to be NULL
//     return result; 
// }


// // Function to find -s in an array of strings, return error (-999) if not found. 
// // If found, return the position of it. 
// int detect_dash_s(char* substrings[])
// {
//     int result = -999;
//     int size = sizeof(substrings);
//     int occur_signal = 0;
//     for(int i = 0; i < size; i++)
//     {
//         if(strlen(substrings[i]) != 2)
//         {
//             // if length != 2, continue
//             continue;
//         }
//         char* substring = substrings[i];
//         char* dash_s = "-s";
//         char* p_strstr = strstr(substring, dash_s);
//         if(p_strstr){
//             occur_signal ++;
//             result = i;
//         }
//         if(occur_signal > 1){
//             return -888; // return -888 if DUPLICATE_ARGUMENT
//         }
//     }
//     return result;
// }


// // Function to find -r in an array of strings, return error (-999) if not found. 
// // If found, return the position of it. 
// int detect_dash_r(char* substrings[])
// {
//     int result = -999;
//     int size = sizeof(substrings);
//     int occur_signal = 0;
//     for(int i = 0; i < size; i++)
//     {
//         if(strlen(substrings[i]) != 2)
//         {
//             // if length != 2, continue
//             continue;
//         }
//         char* substring = substrings[i];
//         char* dash_s = "-r";
//         char* p_strstr = strstr(substring, dash_s);
//         if(p_strstr){
//             result = i;
//             occur_signal ++;
//         }
//         if(occur_signal > 1){
//             return -888; // return -888 if DUPLICATE_ARGUMENT
//         }       
//     }
//     return result;
// }


// // Function to find -w in an array of strings, return error (-999) if not found. 
// // If found, return the position of it. 
// int detect_dash_w(char* substrings[])
// {
//     int result = -999;
//     int size = sizeof(substrings);
//     int occur_signal = 0;
//     for(int i = 0; i < size; i++)
//     {
//         if(strlen(substrings[i]) != 2)
//         {
//             // if length != 2, continue
//             continue;
//         }
//         char* substring = substrings[i];
//         char* dash_s = "-w";
//         char* p_strstr = strstr(substring, dash_s);
//         if(p_strstr){
//             result = i;
//             occur_signal++;
//         }
//         if(occur_signal > 1){
//             return -888; // return -888 if DUPLICATE_ARGUMENT
//         }
//     }
//     return result;
// }


// // Function to find -l in an array of strings, return error (-999) if not found. 
// // If found, return the position of it. 
// int detect_dash_l(char* substrings[])
// {
//     int result = -999;
//     int size = sizeof(substrings);
//     int occur_signal = 0;
//     for(int i = 0; i < size; i++)
//     {
//         if(strlen(substrings[i]) != 2)
//         {
//             // if length != 2, continue
//             continue;
//         }
//         char* substring = substrings[i];
//         char* dash_s = "-l";
//         char* p_strstr = strstr(substring, dash_s);
//         if(p_strstr){
//             result = i;
//             occur_signal++;
//         }
//         if(occur_signal > 1){
//             return -888; // return -888 if DUPLICATE_ARGUMENT
//         }
//     }
//     return result;
// }

// //deprecated main function 
// // main function 
// int main(int argc, char *argv[]) {
//     // unsigned int argv_size = sizeof(argv);
//     for(int i = 0; i < argc;i++){
//         char* line = argv[i];
//         if (line == NULL) 
//         {
//             return 1;
//         }
//         int length = strlen(line);
//         int num_space = 0;
//         // char** divided_line = divide_line(line);
//         // int spilit_len = sizeof(divided_line);
//         // free(spilit_len);
//         for(int j = 0; j < strlen(line); j++){
//             if(line[j] == ' '){
//                 num_space ++;
//             }
//         }
//         // if less than 7 substrings, return error code 1
//         if(num_space < 6) {
//             return(1);
//         }
//         // if equal to 7, it will probably correct. 
//         if (num_space == 7)
//         {
//             int space_positions[7] = {-999, -999, -999, -999, -999, -999, -999};
//             for(int j = 0; j < length; j++){
//                 if(line[j] == ' '){
//                     space_positions[num_space] = j;
//                     num_space ++;
//                 }
//             }
//             // split by found space indexs
//             // find the length of each substrings. 
//             int string_lengths[7] = {-555, -555, -555, -555, -555, -555, -555};
//             for (int j = 0; j < sizeof(space_positions); j++){
//                 string_lengths[j] = space_positions[j+1] - space_positions[j] - j;
//             }
            
//             // int one_l = space_positions[1] - space_positions[0];
//             // find length
//             // int two_l = space_positions[2] - space_positions[1] - 1; 
//             // minus one after each iteration 
//             // int three_l = space_positions[3] - space_positions[2] - 2;

//             // initialize strings with given lengths above. 
//             char* substring_0 = NULL;
//             substring_0 = (char*) calloc (string_lengths[0]+1, sizeof(char));
//             char* substring_1 = NULL;
//             substring_1 = (char*) calloc (string_lengths[1]+1, sizeof(char));
//             char* substring_2 = NULL;
//             substring_2 = (char*) calloc (string_lengths[2]+1, sizeof(char));
//             char* substring_3 = NULL;
//             substring_3 = (char*) calloc (string_lengths[3]+1, sizeof(char));
//             char* substring_4 = NULL;
//             substring_4 = (char*) calloc (string_lengths[4]+1, sizeof(char));
//             char* substring_5 = NULL;
//             substring_5 = (char*) calloc (string_lengths[5]+1, sizeof(char));
//             char* substring_6 = NULL;
//             substring_6 = (char*) calloc (string_lengths[6]+1, sizeof(char));

//             //store strings pters into an array. 
//             char* substrings[7] = {substring_0, substring_1, substring_2, substring_3, 
//             substring_4, substring_5, substring_6};

//             // put original string into different substrings
//             // substr 0
//             int c = 0;
//             int substring_ptr = 0;
//             int count_char = 0;
//             while(count_char < string_lengths[0]){
//                 substring_0[count_char] = line[c];
//                 count_char++;
//                 c++;
//             }
//             substring_ptr++;
//             //substr 1
//             c = space_positions[1] + 1;
//             count_char = 0;
//             while(count_char < string_lengths[1]){
//                 substring_1[count_char] = line[c];
//                 c++;
//             }
//             substring_ptr++;
//             //substr 2
//             c = space_positions[2] + 1;
//             count_char = 0;
//             while(count_char < string_lengths[2]){
//                 substring_2[count_char] = line[c];
//                 c++;
//             }
//             substring_ptr++;
//             //substr 3
//             c = space_positions[3] + 1;
//             count_char = 0;
//             while(count_char < string_lengths[3]){
//                 substring_3[count_char] = line[c];
//                 c++;
//             }
//             substring_ptr++;
//             //substr 4
//             c = space_positions[4] + 1;
//             count_char = 0;
//             while(count_char < string_lengths[4]){
//                 substring_4[count_char] = line[c];
//                 c++;
//             }
//             substring_ptr++;
//             //substr 5
//             c = space_positions[5] + 1;
//             count_char = 0;
//             while(count_char < string_lengths[4]){
//                 substring_5[count_char] = line[c];
//                 c++;
//             }
//             substring_ptr++;
//             //substr 6
//             c = space_positions[6] + 1;
//             count_char = 0;
//             while(count_char < string_lengths[4]){
//                 substring_6[count_char] = line[c];
//                 c++;
//             }
//             substring_ptr++;

//             // detect the DUPLICATE_ARGUMENT
//             if(detect_dash_s(substrings) == -888) return 2;
//             if(detect_dash_l(substrings) == -888) return 2;
//             if(detect_dash_r(substrings) == -888) return 2;
//             if(detect_dash_w(substrings) == -888) return 2;

//             // find the location of -s, -r and -l. 
//             int loc_dashS = detect_dash_s(substrings);
//             int loc_dashR = detect_dash_r(substrings);
//             int loc_dashL = detect_dash_l(substrings);
//             int loc_dashW = detect_dash_w(substrings);


//         }
        
//         // if greater than 7, we need to ignore irrelevant substirngs. 
//         if(num_space > 7)
//         {
//             char** divided_line = divide_line(line);
//             for(long unsigned int j = 0; j < sizeof(divided_line); j++)
//             {
//                 // insert other codes here. Use the algorithm wrote above. s
//                 free(divided_line[j]);
//             }
//             free(divide_line);
//         }
//     }
//     return 0;
// }



    // int out_file_len = 0;
    // for(char c = getc(output); (c!= NULL)&&(c!=EOF); c++){
    //     if (c == '\n')
    //     {
    //         out_file_len++;
    //     }
        
    // }

    // printf("%s %s\n", sname, rname);


// The following function is inspired by this website: 
// https://codeforwin.org/c-programming/c-program-find-and-replace-a-word-in-file


// void replace(char* input_file, char* old_word, char* new_word){
//     char* pos, temp[MAX_SEARCH_LEN];
//     int old_length = strlen(old_word);
//     // int new_length = strlen(new_word);
//     int index = 0;
//     while ((pos = strstr(input_file, old_word)) != NULL)
//     {
//         // Backup current line
//         strcpy(temp, input_file);

//         // Index of current found word
//         index = pos - input_file;

//         // // Terminate str after word found index
//         input_file[index] = '\0';

//         // Concatenate str with new word 
//         strcat(input_file, new_word);
        
//         // Concatenate str with remaining words after 
//         // oldword found index.
//         strcat(input_file, temp + index + old_length);

//        // printf("214");
//     }
//     //return 0; 
// }



                // if(optarg[0] == '\"'){
                //     // how to merge double quoted string, 
                //     // 1. find where is -r located in the argv[]
                //     int loc_da_r = detect_dash_r(argv);
                //     // 2. find and replace until find next double quote. 
                //     int k = 2;
                //     // 2.1 add everything before a double quote
                //     while(detect_double_quote(argv[loc_da_r + k]) == 0){
                //         strcat(optarg, argv[loc_da_r + k]);
                //         k++;
                //     }
                //     // 2.2 add double quote
                //     strcat(optarg, argv[loc_da_r + k + 1]);
                // }
                // // 3. delete the double quote
                // char* temp_optarg[strlen(optarg) - 2];
                // // for(int l = 0; l < strlen(temp_optarg); l++){
                // //     temp_optarg[l] = optarg[l+1];
                // // }
                // // 4. add to rname






                // end = pos + strlen(real_sname) - string;
                //     int fr_ptr = 0;
                //     int entered_here = 0;
                //     while((((isspace(pos[fr_ptr]) == 0)|| (pos[fr_ptr]) == '\n' ))
                //             && ((isspace(pos[fr_ptr + 1])) || (pos[fr_ptr + 1]) == '\n' ))
                //     // while((isspace(*(pos+fr_ptr)) == 0 ) && (ispunct(*(pos+fr_ptr)) == 0)) 
                //     {
                //         printf("gfds\n");
                //         entered_here = 1;
                //         // if(ispunct(pos + fr_ptr + 1)){

                //         // }
                //         fr_ptr--;
                //         /* code */
                //     }
                //     begin = fr_ptr + end - 1;