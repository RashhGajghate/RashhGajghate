#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* filter(const char* data, char filter) {
    int length = strlen(data);
    char* filtered = (char*)malloc((length + 1) * sizeof(char));  // Allocate memory for filtered string
    
    if (filtered == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    int j = 0;
    for (int i = 0; i < length; i++) {
        char current = data[i];
        
        if (tolower(current) != tolower(filter)) {  // Case-insensitive comparison
            filtered[j++] = current;  // Add non-filtered characters to the filtered string
        }
    }
    
    filtered[j] = '\0';  // Null-terminate the filtered string
    return filtered;
}

int main() {
    const char* data = "Welcome to CDAC";
    char ele = 'c';
    
    char* filteredString = filter(data, ele);
    
    printf("Filtered String: %s\n", filteredString);
    
    free(filteredString);  // Free the dynamically allocated memory
    
    return 0;
}
