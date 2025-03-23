#include "../include/input.h"

char* get_user_input() {
    char* output_buffer = NULL;
    
    char input_buffer[BUFFER_SIZE + 1];
    int buffers_filled = 0;
    int index = 0;
    
    for (char c = getchar(); c != '\n'; c = getchar(), index++) {
        if (index == BUFFER_SIZE) {
            input_buffer[index] = '\0';
            
            buffers_filled++;
            char *_output_buffer = malloc(sizeof(char) * (buffers_filled * BUFFER_SIZE + 1));
            if (output_buffer != NULL) {
                strcpy(_output_buffer, output_buffer);
                free(output_buffer);
            }

            _output_buffer[(buffers_filled - 1) * BUFFER_SIZE] = '\0';
            strcat(_output_buffer, input_buffer);

            output_buffer = _output_buffer;
            index = 0;
        }
        
        input_buffer[index] = c;
    }
    
    input_buffer[index] = '\0';
    if (output_buffer == NULL) {
        char *output = malloc(sizeof(char) * (strlen(input_buffer) + 1)); 
        strcpy(output, input_buffer);

        return output;
    }

    char *output = malloc(sizeof(char) * (strlen(output_buffer) + strlen(input_buffer) + 1));

    strcpy(output, output_buffer);
    strcat(output, input_buffer);

    free(output_buffer);
    return output;
}