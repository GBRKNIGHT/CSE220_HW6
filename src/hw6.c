#include "hw6.h"



long num[2] = {0, 0};
long start = 0;

unsigned int is_wolf_invalid(char* wolf){
    unsigned int result = 1;
    int length = strlen(wolf);
    int check_asterisk = 0;
    for(int i = 0; i < length; i++){
        if(wolf[i] == '*'){
            check_asterisk = 1;
        }
    }
    int char_zero = (wolf[0] == '*'); // if char0 is *
    if(char_zero == 0){
        for(int i = 1; i < length - 1; i++){
            if(wolf[i] == '*'){
                return -999; // not valid if * appears in the mid of string. 
            }
        }
    }
    else{ // if char0 is *, it is valid search no whether what.
        printf("HEREHERE\n");
        if(wolf[strlen(wolf) - 1] == '*'){
            // if the last char is also '*', then it is an error. 
            return -999;
        } 
        for(int i = 2; i < length - 1; i++){
            if(wolf[i] == '*'){
                return -999; // not valid if * appears in the mid of string. 
            }
        }

        return 1;
    }
    // if no asterisks appears, return error 7. 
    if(check_asterisk == 0){
        return -999;
    }
    return result; 
}


int find_comma(char* string){
    int result = -999; // if not found, return -999 as result. 
    int comma_count = 0;
    for(long unsigned int i = 0; i < strlen(string); i++){
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





// return 1 if same,
// return 0 if not same. 
int compare_str(char* str1, char* str2){
    if(strlen(str1) != strlen(str2)){
        return 0;
    }
    else{
        for(long unsigned int i = 0; i < strlen(str1); i++){
            if(str1[i] != str2[i]){
                return 0;
            }
        }
    }
    return 1;
}


// function to detect if a paraphrase contains a double quote
int detect_double_quote(char* original){
    if(original[strlen(original) == '\"']){
        return 1;
    }
    else{
        return 0;
    }
}


// Function to find -r in an array of strings, return error (-999) if not found. 
// If found, return the position of it. 
int detect_dash_r(char* substrings[])
{
    int result = -999;
    int size = sizeof(substrings);
    for(int i = 0; i < size; i++)
    {
        if(strlen(substrings[i]) != 2)
        {
            continue;
        }
        char* substring = substrings[i];
        char* dash_s = "-r";
        char* p_strstr = strstr(substring, dash_s);
        if(p_strstr){
            result = i;
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



// 这个function是想对比两个string，s_str 是sname
// 
int is_match(char* str1, char* s_str, int start_at){
    for(int i = 0; i < strlen(s_str) - 1; i++){
        if(str1[start_at + i] != s_str[i]) return 0;
    }
    return 1;
}


// substring function 
// 找substrng的
char* substring(char* str, int start, int end){
    char* result = (char*)malloc(sizeof(char)*(end - start + 1));
    for(int i = 0; i < end - start + 1; i++){
        result[i] = str[i + start];
    }
    result[strlen(result)] = '\0';
    return result; 
}


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
    // int i_check = 0;
    // int o_check = 0;
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
                if((long unsigned int)comma_loc == strlen(lname)){
                    l_arguments_invalid = 1;
                }
                //     printf("%d\n", l_arguments_invalid);


                //int num[2] = {0, 0};
                char *pt;
                pt = strtok (lname,",");
                int which_num = 0;
                while (pt != NULL) {
                    char *ptr;
                    num[which_num] = strtol(pt, &ptr, 10);
                    pt = strtok (NULL, ",");
                    which_num ++;
                }
                //printf("%d\n", l_arguments_invalid);
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
                if((unsigned int)long_zero > MAX_LINE)
                {
                    l_arguments_invalid = 1;
                }
               //  printf("%d\n", l_arguments_invalid);
                if(long_zero > long_one){
                    l_arguments_invalid = 1;
                }
                l_flag = 1;
				break;
            }
			case 'd':{
				debug = 1;
				break;
            }
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
                
    // if(compare_str(sname, rname)){
    //     l_arguments_invalid = 1;
    // }

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
    // else if (l_flag == 0) {	// check -l
	// 	fprintf(stderr, "%s: missing -l option\n", argv[0]);
	// 	fprintf(stderr, usage, argv[2]);
	// 	l_arguments_invalid = 1;
	// } 

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
        // printf("HEREHERE\n");
        return MISSING_ARGUMENT;
    }
    if(duplicate_argument){
        // printf("HEREHERE\n");
        return DUPLICATE_ARGUMENT;
    }
    if(input_file_missing){
        printf("HEREHERE 2\n");
        return INPUT_FILE_MISSING;
    }
    if(output_file_unwritable){
        printf("HEREHERE 3\n");
        return OUTPUT_FILE_UNWRITABLE;
    }
    if(s_argument_missing){
        printf("HEREHERE 4\n");
        return S_ARGUMENT_MISSING;
    }
    if(r_argument_missing){
        printf("HEREHERE 5\n");
        return R_ARGUMENT_MISSING;
    }
    if(l_arguments_invalid){
        printf("HEREHERE 6\n");
        return L_ARGUMENT_INVALID;
    }
    if(wildcard_invalid){
        printf("HEREHERE 7\n");
        return WILDCARD_INVALID;
    }



    // part2 codes.
    
    // char *search_text = sname;
    // char *replacement_text = rname;
    FILE* input = fopen(input_file, "r");// read only
    if(input == NULL){ 
        return INPUT_FILE_MISSING;
    }

    FILE* output = fopen(output_file, "w"); // write only 
    if (output == NULL){
        return OUTPUT_FILE_UNWRITABLE;
    }
    
    FILE* input_temp = input;
    // if never detected l, then replace all words in the input passage. 
    if(l_check == 0 && w_check == 0){
        while (1)
        {
            int j = 0;
            // replace(input_temp, sname, rname);
            // fputs(input_temp, output);
            int bytes_read;
            size_t size = 200;
            char *string;

            string = (char *) malloc (size);
            bytes_read = getline (&string, &size, input_temp);
            // bytes_read = getline (&string, &size, input_temp);
            printf("563 %d\n", bytes_read);
            if (bytes_read == EOF){
                free(string);
                break;
            }
            j++;
            // printf(bytes_read);
            //replace(string, sname, rname);
            // Following code inspired by: 
            // https://codeforwin.org/c-programming/c-program-find-and-replace-a-word-in-file

            char* pos, temp[1000];
            int old_length = strlen(sname);
            // int new_length = strlen(new_word);
            int index = 0;

            while ((pos = strstr(string+index, sname)) != NULL)
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

                index += old_length;

            // printf("214");
            }
            fputs(string, output);
            free(string);
        }
        return 0;
    }


    // simple search with -l range. 
    else if (l_check == 1 && w_check == 0){
        int j = 0;
        while (j < num[0] - 1){
            int bytes_read;
            size_t size = 200;
            char *string;
            string = (char *) malloc (size);
            bytes_read = getline (&string, &size, input_temp);   
            if (bytes_read == EOF){
                free(string);
                break;
            }     
            j++;
            fputs(string, output);
            free(string);
        }
        while(j <= (num[1])){
            printf(" STUPID %d\n", (int)(num[1] - num[0]+1));
            // replace(input_temp, sname, rname);
            // fputs(input_temp, output);
            int bytes_read;
            size_t size = 200;
            char *string;

            string = (char *) malloc (size);
            bytes_read = getline (&string, &size, input_temp);
            if (bytes_read == EOF){
                free(string);
                break;
            }
            j++;
            // printf(bytes_read);
            //replace(string, sname, rname);

            // The following codes is inspired by this website: 
            // https://codeforwin.org/c-programming/c-program-find-and-replace-a-word-in-file

            char* pos, temp[1000];
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

            }
            fputs(string, output);
            free(string);
        }
        while (1){
            int bytes_read;
            size_t size = 200;
            char *string;
            string = (char *) malloc (size);
            bytes_read = getline (&string, &size, input_temp);   
            if (bytes_read == EOF){
                free(string);
                break;
            }    

            if(bytes_read == 0){
                break;
            } 
            j++;
            fputs(string, output);
            free(string);
        }
        fclose(input);
        fclose(output);
        return 0;
    }

    // if wildcard applies to the whole passage. 
    else if (l_check == 0 && w_check == 1){
        int front_flag = 0, back_flag = 0;
        char* real_sname = (char*) malloc(strlen(sname) + 1);
        if(sname[0] == '*') {
            front_flag = 1;
            real_sname = substring(sname, 1 , strlen(sname) - 1);
        }
        if(sname[strlen(sname)-1] == '*') {
            back_flag = 1;
            int substr_start = 0;
            int substr_end = strlen(sname) - 2;
            
            real_sname = (char*)malloc((substr_end - substr_start + 1));
            int i = 0;
            sname[strlen(sname)-1] = '\0';
            
            real_sname = sname;
            // printf("%s \n",real_sname);
        }

        int j = 0;
        while (1)
        {
            int bytes_read;
            size_t size = 200;
            char *string;

            string = NULL;
            string = (char *) malloc (size);
            bytes_read = getline (&string, &size, input_temp);
            // printf("563 %d\n", bytes_read);

            if (bytes_read == EOF){
                free(string);
                break;
            }
            j++;
            // printf(bytes_read);
            //replace(string, sname, rname);
            // Following code inspired by: 
            // https://codeforwin.org/c-programming/c-program-find-and-replace-a-word-in-file

            char* pos, temp[10000];
            char* temp_str = NULL;
            int index = 0;
            printf("%d: ", j);
            while ((pos = strstr(string+index, real_sname)) != NULL)
            {
                temp_str = (char*)malloc(strlen(real_sname)+1);
                printf("%s \n",sname);
                // Check if the word is valid to replace
                strcpy(temp_str, real_sname);
                printf("%s \n",sname);
                int is_space_pos_one  = isspace(*(pos-1));

                int is_punc_pos_one = ispunct(*(pos-1));
                int front_flag_cond = (is_space_pos_one && is_punc_pos_one);
                
                if (front_flag && (is_space_pos_one && is_punc_pos_one))
                {
                    
                    index = pos - string + 1; 
                    free(temp_str);
                    continue;
                }

                // int back_flag_cond = ((is_space_pos_one == 0) && (is_punc_pos_one == 0));
                
                if (back_flag && ((is_space_pos_one == 0) && (is_punc_pos_one == 0)))
                {
                    index = pos - string + strlen(real_sname);  
                    free(temp_str);
                    continue;
                }
                int begin = 0, end = 0;
                
                
                if (front_flag)
                {
                    end = pos - string + strlen(real_sname) ;
                    
                    int fr_ptr = 0;
                    while((isspace(*(pos+fr_ptr)) == 0 )&& (ispunct(*(pos+fr_ptr)) == 0)) 
                    {
                        fr_ptr--;
                    }
                    begin = fr_ptr + end - 1;
                }

                if (back_flag)
                {
                    begin = pos - string;
                    int fr_ptr = 0;
                    while((isspace(pos[fr_ptr]) == 0 )&& ispunct(pos[fr_ptr]) == 0) 
                    {
                        fr_ptr++;
                        /* code */
                    }
                    end = fr_ptr + begin;
                }

                int old_length = end - begin;
                // Backup current line
                strcpy(temp, string);

                // Index of current found word
                index = begin;

                // // Terminate str after word found index
                string[index] = '\0';

                // Concatenate str with new word 
                strcat(string, rname);
                
                // Concatenate str with remaining words after 
                // oldword found index.
                strcat(string, temp + index + old_length);

                index = end + 1;

            // printf("214");
            }
            printf("\n");
            fputs(string, output);
            free(string);
        }
        free(real_sname);
        
    }
    
    // if wildcard applies to given -l range
    else if (l_check && w_check){
        int front_flag = 0, back_flag = 0;
        char* real_sname = (char*) malloc(strlen(sname) + 1);
        if(sname[0] == '*') {
            front_flag = 1;
            // real_sname = substring(sname, 1 , strlen(sname) - 1);
            int substr_start = 1;
            int substr_end = strlen(sname) - 1;
            int i = 0;
            for(i = 0; i < substr_end - substr_start + 1; i++){
                real_sname[i] = sname[i + start];
            }
            real_sname[i] = '\0';
        }
        if(sname[strlen(sname)-1] == '*') {
            back_flag = 1;
            int substr_start = 0;
            int substr_end = strlen(sname) - 2;
            // real_sname = (char*)malloc((substr_end - substr_start + 1));
            int i = 0;
            for(i = 0; i < substr_end - substr_start + 1; i++){
                real_sname[i] = sname[i + start];
            }
            real_sname[i] = '\0';
        }
        int j = 0;
        // before replacement
        while (j < num[0] - 1){
            int bytes_read;
            size_t size = 200;
            char *string;
            string = (char *) malloc (size);
            bytes_read = getline (&string, &size, input_temp);   
            if (bytes_read == EOF){
                free(string);
                break;
            }     
            j++;
            fputs(string, output);
            free(string);
        }

        int m = 0;
        // replacement part. 
        while(j <= (num[1])){
            int bytes_read;
            size_t size = 200;
            char *string;

            string = (char *) malloc (size);
            bytes_read = getline (&string, &size, input_temp);
            if (bytes_read == EOF){
                free(string);
                break;
            }
            m ++;
            // printf(bytes_read);
            //replace(string, sname, rname);

            // The following codes is inspired by this website: 
            // https://codeforwin.org/c-programming/c-program-find-and-replace-a-word-in-file

            char* pos, temp[10000];


            int old_length = strlen(sname);
            // int new_length = strlen(new_word);
            int index = 0;
            while ((pos = strstr(string+index, real_sname)) != NULL)
            {
                // Check if the word is valid to replace
                printf("%d ", pos-string);
                char* temp_str[10000];
                int is_space_pos_one  = isspace((pos-1));
                int is_punc_pos_one = ispunct((pos-1));

                // int front_flag_cond = (is_space_pos_one && is_punc_pos_one);
                if (front_flag && (is_space_pos_one && is_punc_pos_one))
                {
                    index = pos - string + 1; 
                    continue;
                }

                // int back_flag_cond = ((is_space_pos_one == 0) && (is_punc_pos_one == 0));
                if (back_flag && ((is_space_pos_one == 0) && (is_punc_pos_one == 0)))
                {
                    index = pos - string + strlen(real_sname);  
                    continue;
                }
                int begin = 0, end = 0;
                
                if (front_flag)
                {
                    end = pos + strlen(real_sname) - string;
                    int fr_ptr = 0;
                    while((isspace(*(pos+fr_ptr)) == 0 )&& (ispunct(*(pos+fr_ptr)) == 0)) 
                    {
                        fr_ptr--;
                        /* code */
                    }
                    begin = fr_ptr + end - 1;
                }

                if (back_flag)
                {
                    begin = pos - string;
                    int fr_ptr = 0;
                    while((isspace(pos[fr_ptr]) == 0 )&& ispunct(pos[fr_ptr]) == 0) 
                    {
                        fr_ptr++;
                        /* code */
                    }
                    end = fr_ptr + begin;
                }

                int old_length = end - begin;
                // Backup current line
                strcpy(temp, string);

                // Index of current found word
                index = begin;

                // // Terminate str after word found index
                string[index] = '\0';

                // Concatenate str with new word 
                strcat(string, rname);
                
                // Concatenate str with remaining words after 
                // oldword found index.
                strcat(string, temp + index + old_length);

                index = end + 1;
            }
            fputs(string, output);
            free(string);
        }
        
        // after replacement
        while (1){
            int bytes_read;
            size_t size = 200;
            char *string;
            string = (char *) malloc (size);
            bytes_read = getline (&string, &size, input_temp);   
            if (bytes_read == EOF){
                free(string);
                break;
            }    

            if(bytes_read == 0){
                break;
            } 
            j++;
            fputs(string, output);
            free(string);
        }
        free(real_sname);
    }
    else{

    }

    //after replacement. 
    

    // fputs("---END---", output);
    fclose(input);
    fclose(output);
    
	exit(0);
}