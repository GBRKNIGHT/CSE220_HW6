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
    char* line = argv[0];
    if (line == NULL) 
    {
        return MISSING_ARGUMENT;
    }
    
    int length = strlen(line);
    int num_space = 0;
    }
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int s_flag=0, l_flag = 0, r_flag=0, w_flag=0, debug = 0;
	char *sname = "default_sname", *lname;
	static char usage[] = "usage: %s [-srl] -s sname -r rname -l lname [-s sname] name [name ...]\n";
    int s_check = 0;
    int r_check = 0;
    int l_check = 0;
	while ((c = getopt(argc, argv, "srl:d")) != -1){
		switch (c) {
			case 's':
            {
                s_check ++;
				s_flag = 1;
				break;
            }
			case 'r':
            {
                r_check ++;
                r_flag = 1;
				break;
            }	
			case 'l':
            {
                l_check++;
                l_flag = 1;
				lname = optarg;
				break;
            }
			case 'd':
				debug = 1;
				break;
			case '?':
				err = 1;
				break;
		}
    }
    if ((optind+7) > argc) {	
        // change here will cause valgrind errors. and then go to line 222. 

        // ALWAYS GOES HERE, WHY???
        /* need at least seven argument,  */
        return MISSING_ARGUMENT; // MISSING_ARGUMENT if less than 7. 
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
    char* line = argv;
    char** divided_line = divide_line(line);

    // goes here 
    // input and output files are in the end of the command, so we can retrieve it. 
    char* input_file = divided_line[sizeof(divide_line) - 1];
    char* output_file = divided_line[sizeof(divide_line)];
    char* input_strstr = strstr(input_file, ".txt");
    if(input_strstr == 0){
        return INPUT_FILE_MISSING;
    }
    char* output_strstr = strstr(output_file, ".txt");
    if(output_strstr == 0){
        return OUTPUT_FILE_UNWRITABLE;
    }
    free(divide_line);
    // detect for 's
    if (s_flag == 0){
        fprintf(stderr, "%s: missing -s option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		return S_ARGUMENT_MISSING;
    }
	//detect for -r
    else if (r_flag == 0){ // check -r
        fprintf(stderr, "%s: missing -r option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		return R_ARGUMENT_MISSING;
    }
    //detect for -l
    else if (l_flag == 0) {	// check -l
		fprintf(stderr, "%s: missing -l option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		return L_ARGUMENT_INVALID;
	} 

    else if (err) {
    	fprintf(stderr, usage, argv[0]);
    	exit(1);
    }
	/* see what we have */
	// printf("debug = %d\n", debug);
	// printf("sflag = %d\n", s_flag);
	// printf("lflag = %d\n", l_flag);
    // printf("rflag = %d\n", r_flag);
	// printf("lname = \"%s\"\n", lname);

	
	if (optind < argc)	{

        for (; optind < argc; optind++){
            printf("argument: \"%s\"\n", argv[optind]);
        }
    }	
	else {
		printf("no arguments left to process\n");
	}
    
	// exit(0);
}