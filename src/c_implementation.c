#include <stdio.h>
#include <string.h>

int main() {
    char* test_string = "div\n\tmain.vmainClass1.vmainClass2\n\t\tdiv#main-container\n\t\t\tdiv#keyboard-shortcut.class2\n\t\t\t\tdiv\n\t\t\t\tdiv\n\t\tdiv.form-container\n\t\t\tform method=post\n\t\tv-icon\n\t\t\tv-con";

    for(int i = 0; i < strlen(test_string); i++) {
        printf("%c", test_string[i]);
        if(strcmp(test_string[i], "\t")==0) {
            printf("Same string \n");
        }
    }

    return 0;
}
