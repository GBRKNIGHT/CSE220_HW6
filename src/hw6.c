#include "hw6.h"


// function to divide a string by space. 
char** divide_line(char* input_line)
{
    int length = strlen(input_line);
    char** result = malloc(MAX_SEARCH_LEN * 8); 
    int word_count = 0;
    char* word = strtok(input_line, " ");
    while(word != NULL){
        int word_length = strlen(word);
        result[word_count] = malloc(word_length + 1);
        strcpy(result[word_count], word);
        word_count++;
        word = strtok(NULL, " ");
    }
    result[sizeof(result)] = NULL; // set the last element to be NULL
    return result; 
}


// Function to find -s in an array of strings, return error (-999) if not found. 
// If found, return the position of it. 
int detect_dash_s(char* substrings[])
{
    int result = -999;
    int size = sizeof(substrings);
    int occur_signal = 0;
    for(int i = 0; i < size; i++)
    {
        if(strlen(substrings[i]) != 2)
        {
            // if length != 2, continue
            continue;
        }
        char* substring = substrings[i];
        char* dash_s = "-s";
        char* p_strstr = strstr(substring, dash_s);
        if(p_strstr){
            occur_signal ++;
            result = i;
        }
        if(occur_signal > 1){
            return -888; // return -888 if DUPLICATE_ARGUMENT
        }
    }
    return result;
}


// Function to find -r in an array of strings, return error (-999) if not found. 
// If found, return the position of it. 
int detect_dash_r(char* substrings[])
{
    int result = -999;
    int size = sizeof(substrings);
    int occur_signal = 0;
    for(int i = 0; i < size; i++)
    {
        if(strlen(substrings[i]) != 2)
        {
            // if length != 2, continue
            continue;
        }
        char* substring = substrings[i];
        char* dash_s = "-r";
        char* p_strstr = strstr(substring, dash_s);
        if(p_strstr){
            result = i;
            occur_signal ++;
        }
        if(occur_signal > 1){
            return -888; // return -888 if DUPLICATE_ARGUMENT
        }       
    }
    return result;
}


// Function to find -w in an array of strings, return error (-999) if not found. 
// If found, return the position of it. 
int detect_dash_w(char* substrings[])
{
    int result = -999;
    int size = sizeof(substrings);
    int occur_signal = 0;
    for(int i = 0; i < size; i++)
    {
        if(strlen(substrings[i]) != 2)
        {
            // if length != 2, continue
            continue;
        }
        char* substring = substrings[i];
        char* dash_s = "-w";
        char* p_strstr = strstr(substring, dash_s);
        if(p_strstr){
            result = i;
            occur_signal++;
        }
        if(occur_signal > 1){
            return -888; // return -888 if DUPLICATE_ARGUMENT
        }
    }
    return result;
}


// Function to find -l in an array of strings, return error (-999) if not found. 
// If found, return the position of it. 
int detect_dash_l(char* substrings[])
{
    int result = -999;
    int size = sizeof(substrings);
    int occur_signal = 0;
    for(int i = 0; i < size; i++)
    {
        if(strlen(substrings[i]) != 2)
        {
            // if length != 2, continue
            continue;
        }
        char* substring = substrings[i];
        char* dash_s = "-l";
        char* p_strstr = strstr(substring, dash_s);
        if(p_strstr){
            result = i;
            occur_signal++;
        }
        if(occur_signal > 1){
            return -888; // return -888 if DUPLICATE_ARGUMENT
        }
    }
    return result;
}


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
    }
    else{ // if char0 is *, it is valid search no whether what. 
        return 1;
    }
    return result; 
}



// following code copied from the instruction site, and modified by me. 
/*
	example of command line parsing via getopt
	usage: getopt [-dmp] -f fname [-s sname] name [name ...]

	Paul Krzyzanowski
*/


int main(int argc, char **argv)
{
    for(int i = 0; i < argc;i++)
    {
    char* line = argv[i];
    if (line == NULL) 
    {
        
        return MISSING_ARGUMENT;
    }
    
    // int length = strlen(line);
    // int num_space = 0;
    }
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
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
                char* s[1] = {','};
                char* token = strtok(lname, s);
                
                char** nums[2];
                while(token != NULL){
                    nums[l_num_count] = token;
                    l_num_count ++;
                    if(l_num_count > 1){
                        return L_ARGUMENT_INVALID;
                    }
                }


                char* str_zero = nums[0];
                char* str_one = nums[1];
                long long_zero = strtol(str_zero, strlen(str_zero), 10);
                long long_one = strtol(str_one, strlen(str_one), 10);
                // this part should work 
                if((unsigned int)long_zero > MAX_LINE){
                    return L_ARGUMENT_INVALID;
                }
                if ((unsigned int) long_one > MAX_LINE){
                    return L_ARGUMENT_INVALID;
                }
                if(long_zero > long_one){
                    return L_ARGUMENT_INVALID;
                }
                if((long_one - long_zero) > 20){
                    return L_ARGUMENT_INVALID;
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
            case ':':{
                //error part
                err = 1;
                exit(err);
                break;
            }
            default: 
                err = 1;
                exit(err);
                break;
		}

    }
    
    if(argc < 7){
        return MISSING_ARGUMENT;
    }
    
    if(s_check > 1){
        return DUPLICATE_ARGUMENT;
    }
    if(r_check > 1){
        return DUPLICATE_ARGUMENT;
    }
    if(l_check > 1){
        return DUPLICATE_ARGUMENT;
    }
    if(w_check > 1){
        return DUPLICATE_ARGUMENT;
    }
    
    

    // goes here 
    // input and output files are in the end of the command, so we can retrieve it. 
    char* input_file = argv[optind];
    char* output_file = argv[optind + 1]; 

    if(input_file[0] == '-' || input_file[0] == '/'){
        return INPUT_FILE_MISSING;
    }
    if(output_file[0] == '-' || output_file[0] == '/'){
        return OUTPUT_FILE_UNWRITABLE;
    }
                

    //detect writeability
    char* input_strstr = strstr(input_file, ".txt");
    if(input_strstr == 0){
        return INPUT_FILE_MISSING;
    }
    char* output_strstr = strstr(output_file, ".txt");
    if(output_strstr == 0){
        return OUTPUT_FILE_UNWRITABLE;
    }
    

    if(sname[0] == '-'){
        return S_ARGUMENT_MISSING;
    }
    if(rname[0] == '-'){
        return R_ARGUMENT_MISSING;
    }
    if(lname[0] == '-'){
        return L_ARGUMENT_INVALID;
    }
    

    // free(divide_line);
    // detect for 's
    if (s_flag == 0){
        fprintf(stderr, "%s: missing -s option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		return S_ARGUMENT_MISSING;
    }
	//detect for -r
    else if (r_flag == 0){ // check -r
        fprintf(stderr, "%s: missing -r option\n", argv[0]);
		fprintf(stderr, usage, argv[1]);
		return R_ARGUMENT_MISSING;
    }
    //detect for -l
    else if (l_flag == 0) {	// check -l
		fprintf(stderr, "%s: missing -l option\n", argv[0]);
		fprintf(stderr, usage, argv[2]);
		return L_ARGUMENT_INVALID;
	} 

    else if (err) {
    	exit(1);
    }
	/* see what we have */
	// printf("debug = %d\n", debug);
	// printf("sflag = %d\n", s_flag);
	// printf("lflag = %d\n", l_flag);
    // printf("rflag = %d\n", r_flag);
	// printf("lname = \"%s\"\n", lname);

    
    if(valid_wolf == -999){
        return WILDCARD_INVALID;
    }
	
	if (optind < argc)	{
        for (; optind < argc; optind++){
            printf("argument: \"%s\"\n", argv[optind]);
        }
    }	
	else {
		printf("no arguments left to process\n");
	}
    

    // part2 codes.

    char *search_text = sname;
    char *replacement_text = rname;
    // if(strlen(replacement_text - 1) > MAX_SEARCH_LEN){
    //     return L_ARGUMENT_INVALID;
    // }
    
    FILE* input = fopen(input_file, "r+");
    if(input == NULL){
        return INPUT_FILE_MISSING;
    }
    
    FILE* output = fopen(output_file, "r+");
    // if(output == NULL){
    //     return OUTPUT_FILE_UNWRITABLE;
    // }

    // detect how many lines do the inout and output have, by detecting NULL and EOF
    int in_file_len = 0;
    for(char c = getc(input); (c!= NULL)&&(c!=EOF); c++){
        if(c == '\n') in_file_len++;
    }

    int out_file_len = 0;
    for(char c = getc(output); (c!= NULL)&&(c!=EOF); c++){
        if (c == '\n')
        {
            out_file_len++;
        }
        
    }
    if((in_file_len > MAX_LINE)&&(out_file_len > MAX_LINE)){
        return OUTPUT_FILE_UNWRITABLE;
    }

    
	exit(0);
}