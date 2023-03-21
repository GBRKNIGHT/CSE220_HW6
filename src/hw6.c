#include "hw6.h"


// function to divide a string by space. 
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


// Function to find -s in an array of strings, return error (-999) if not found. 
// If found, return the position of it. 
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


// Function to find -r in an array of strings, return error (-999) if not found. 
// If found, return the position of it. 
//int detect_dash_r(char* substrings[])
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


// Function to find -w in an array of strings, return error (-999) if not found. 
// If found, return the position of it. 
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


// Function to find -l in an array of strings, return error (-999) if not found. 
// If found, return the position of it. 
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

int num[2] = {0, 0};

unsigned int is_wolf_invalid(char* wolf){
    unsigned int result = 1;
    int length = strlen(wolf);
    int char_zero = (wolf[0] == '*'); // if char0 is *
    if(char_zero == 0){
        for(int i = 1; i < length - 1; i++){
            if(wolf[i] == '*'){
                return -999; // not valid if * appears in the mid of string. 
            }
        }
        if(wolf[length] != '*'){
            // if no * in the string
            return -999;
        }
    }
    else{ // if char0 is *, it is valid search no whether what. 
        if(wolf[strlen(wolf)] == '*'){
            // if the last char is also '*', then it is an error. 
            return -999;
        }
        return 1;
    }
    return result; 
}


int find_comma(char* string){
    int result = -999; // if not found, return -999 as result. 
    int comma_count = 0;
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == ','){
            result = i;
            comma_count ++;
        }
    }
    if(comma_count > 1){
        result = -999;
    }
    return result;
}



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



// return 1 if same,
// return 0 if not same. 
int compare_str(char* str1, char* str2){
    if(strlen(str1) != strlen(str2)){
        return 0;
    }
    else{
        for(int i = 0; i < strlen(str1); i++){
            if(str1[i] != str2[i]){
                return 0;
            }
        }
    }
    return 1;
}



// following code copied from the instruction site, and modified by me. 
/*
	example of command line parsing via getopt
	usage: getopt [-dmp] -f fname [-s sname] name [name ...]

	Paul Krzyzanowski
*/


int main(int argc, char **argv)
{
    // plan to return error value after deal with things. 
        int missing_argument = 0;
        int duplicate_argument = 0;
        int input_file_missing = 0;
        int output_file_unwritable = 0;
        int s_argument_missing = 0; 
        int r_argument_missing = 0;
        int l_arguments_invalid = 0;
        int wildcard_invalid = 0;
    
    for(int i = 0; i < argc;i++)
    {
    char* line = argv[i];
    if (line == NULL) 
    {
        missing_argument = 1;
    }
    
    // int length = strlen(line);
    // int num_space = 0;
    }
	extern char *optarg;
	extern int optind;
	int err = 0; 
    int c;

	int s_flag=0, l_flag = 0, r_flag=0, w_flag=0, debug = 0;

	char *sname = "default_sname";
    char *rname = "default_rname";
    char *lname = "default_lname";
	static char usage[] = "usage: %s [-srl] [-s]sname [-r] rname [-l] lname [-w] lname [input_file] [output_file]\n";
    int s_check = 0;
    int r_check = 0;
    int l_check = 0;
    int i_check = 0;
    int o_check = 0;
    int w_check = 0;
    int valid_wolf = 0;
    int l_num_count = 0;
	while ((c = getopt(argc, argv, "s:r:wl:io")) != -1){
        // s: -s, r:-r, l:-l, i: input file, o:output file
        //printf("111");

		switch (c) {
			case 's':
            {
                // sname
                s_check ++;
				s_flag = 1;
                sname = optarg;
				break;
            }
			case 'r':
            {
                //rname
                r_check ++;
                r_flag = 1;
                rname = optarg;
				break;
            }	

            case 'w':{
                w_check ++;
                valid_wolf = is_wolf_invalid(sname);
                w_flag = 1;
                break;
            }
			case 'l':
            {
                l_check++;
                lname = optarg;
                // need to split the 10,13 by comma here

                int comma_loc = find_comma(lname);
                if(comma_loc == -999){
                    l_arguments_invalid = 1;
                }
            //     printf("%d\n", l_arguments_invalid);
                if(comma_loc == strlen(lname)){
                    l_arguments_invalid = 1;
                }
            //     printf("%d\n", l_arguments_invalid);


                //int num[2] = {0, 0};
                char *pt;
                pt = strtok (lname,",");
                int which_num = 0;
                while (pt != NULL) {
                    
                    num[which_num] = atoi(pt);
                    pt = strtok (NULL, ",");
                    which_num ++;
                }
              //  printf("%d\n", l_arguments_invalid);
                //printf("%d %d \n", num[0], num[1]);




                
                // long long_zero = strtol(str_zero, strlen(str_zero), 10);
                // long long_one = strtol(str_one, strlen(str_one), 10);
                long long_zero = (long) num[0];
                long long_one = (long) num[1];
                if((long_zero < 0) || (long_one < 0)){
                    l_arguments_invalid = 1;
                }
               //  printf("%d\n", l_arguments_invalid);
                if(long_zero > long_one){
                    l_arguments_invalid = 1;
                }
               //  printf("%d\n", l_arguments_invalid);
                // this part should work 
                if((unsigned int)long_zero > MAX_LINE)
                {
                    l_arguments_invalid = 1;
                }
               //  printf("%d\n", l_arguments_invalid);
                if ((unsigned int) long_one > MAX_LINE){
                    l_arguments_invalid = 1;
                }
                if(long_zero > long_one){
                    l_arguments_invalid = 1;
                }
                if((long_one - long_zero) > 20){
                    l_arguments_invalid = 1;
                }
                l_flag = 1;
				break;
            }
			case 'd':{
				debug = 1;
				break;
            }
            // case 'i':{
            //     *iname = argv[optind];
            //     // second last argument
            //     i_check++;
            //     break;
            // }
            // case 'o':{
            //     *oname = argv [optind + 1];
            //     // last argument
            //     // argv[argc] will be NULL. 
            //     o_check++;
            //     break;
            // }
            default: 
                break;
		}

    }
    
    if(argc < 7){
        missing_argument = 1;
    }
    
    if(s_check > 1){
        duplicate_argument = 1;
    }
    if(r_check > 1){
        duplicate_argument = 1;
    }
    if(l_check > 1){
        duplicate_argument = 1;
    }
    if(w_check > 1){
        duplicate_argument = 1;
    }
    
    

    // goes here 
    // input and output files are in the end of the command, so we can retrieve it. 
    char* input_file = argv[optind];
    char* output_file = argv[optind + 1]; 

    if(input_file[0] == '-' || input_file[0] == '/'){
        input_file_missing = 1;
    }
    if(output_file[0] == '-' || output_file[0] == '/'){
        output_file_unwritable = 1;
    }
                
    if(compare_str(sname, rname)){
        l_arguments_invalid = 1;
    }

    if(sname[0] == '-'){
        s_argument_missing = 1;
    }
    if(rname[0] == '-'){
        r_argument_missing = 1;
    }
    if(lname[0] == '-'){
        l_arguments_invalid = 1;
    }
    

    // free(divide_line);
    // detect for 's
    if (s_flag == 0){
        fprintf(stderr, "%s: missing -s option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		s_argument_missing = 1;
    }
	//detect for -r
    else if (r_flag == 0){ // check -r
        fprintf(stderr, "%s: missing -r option\n", argv[0]);
		fprintf(stderr, usage, argv[1]);
		r_argument_missing = 1;
    }
    //detect for -l
    else if (l_flag == 0) {	// check -l
		fprintf(stderr, "%s: missing -l option\n", argv[0]);
		fprintf(stderr, usage, argv[2]);
		l_arguments_invalid = 1;
	} 

    else if (err) {
    	exit(1);
    }
    
    if(valid_wolf == -999){
        wildcard_invalid = 1;
    }
	
	if (optind < argc)	{
        for (; optind < argc; optind++){
            printf("argument: \"%s\"\n", argv[optind]);
        }
    }	
	else {
		printf("no arguments left to process\n");
	}
    if(missing_argument){
        return MISSING_ARGUMENT;
    }
    if(duplicate_argument){
        return DUPLICATE_ARGUMENT;
    }
    if(input_file_missing){
        return INPUT_FILE_MISSING;
    }
    if(output_file_unwritable){
        return OUTPUT_FILE_UNWRITABLE;
    }
    if(s_argument_missing){
        return S_ARGUMENT_MISSING;
    }
    if(r_argument_missing){
        return R_ARGUMENT_MISSING;
    }
    if(l_arguments_invalid){
        return L_ARGUMENT_INVALID;
    }
    if(wildcard_invalid){
        return WILDCARD_INVALID;
    }
    // part2 codes.

    char *search_text = sname;
    char *replacement_text = rname;
    // if(strlen(replacement_text - 1) > MAX_SEARCH_LEN){
    //     return L_ARGUMENT_INVALID;
    // }
    
    FILE* input = fopen(input_file, "r");// read only
    if(input == NULL){
        return INPUT_FILE_MISSING;
    }
    
    FILE* output = fopen(output_file, "w"); // write only 
    if (input == NULL){
        return OUTPUT_FILE_UNWRITABLE;
    }
    //printf("file created.");
    // if(output == NULL){
    //     return OUTPUT_FILE_UNWRITABLE;
    // }

    // detect how many lines do the inout and output have, by detecting NULL and EOF
    // int in_file_len = 0;
    // for(c = getc(input); (c!= NULL)&&(c!=EOF); c++){
    //     if(c == '\n') in_file_len++;
    // }

    // int out_file_len = 0;
    // for(char c = getc(output); (c!= NULL)&&(c!=EOF); c++){
    //     if (c == '\n')
    //     {
    //         out_file_len++;
    //     }
        
    // }

    // printf("%s %s\n", sname, rname);

    
    FILE* input_temp = input;
    //printf(". %d. \n", in_file_len);
    int j = 0;
   // printf("%d\n", num[1] - num[0]+1);
    while(j < num[1] - num[0]+1){
        // replace(input_temp, sname, rname);
        // fputs(input_temp, output);
        int bytes_read;
        size_t size = 15;
        char *string;
        //printf ("Please enter a string: ");
        /* These 2 lines are very important. */
        string = (char *) malloc (size);
        bytes_read = getline (&string, &size, input_temp);
       printf("563 %d\n", bytes_read);
        if (bytes_read == EOF){
            break;
        }
       // printf(bytes_read);
        //replace(string, sname, rname);




           char* pos, temp[MAX_SEARCH_LEN];
    int old_length = strlen(sname);
    // int new_length = strlen(new_word);
    int index = 0;


 

    while ((pos = strstr(string, sname)) != NULL)
    {
        // Backup current line
        strcpy(temp, string);

        // Index of current found word
        index = pos - string;

        // // Terminate str after word found index
        string[index] = '\0';

        // Concatenate str with new word 
        strcat(string, rname);
        
        // Concatenate str with remaining words after 
        // oldword found index.
        strcat(string, temp + index + old_length);

       // printf("214");
    }
       // printf(bytes_read);
        fputs(string, output);
        //free(bytes_read);
        free(string);
    }
    //fputs("---END---", output);
    fclose(input);
    fclose(output);


    // if((in_file_len > MAX_LINE)&&(out_file_len > MAX_LINE)){
    //     return OUTPUT_FILE_UNWRITABLE;
    // }


    
	exit(0);
}