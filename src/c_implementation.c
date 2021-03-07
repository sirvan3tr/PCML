#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeType Node;
struct nodeType {
    Node *parentNode;
    Node *childNode;
    Node *nextSibling;
    Node *prevSibling;
    char id[4];
    char *classes;
};

int main() {
    char* test_string = "div\n\tmain.vmainClass1.vmainClass2\n\t\tdiv#main-container\n\t\t\tdiv#keyboard-shortcut.class2\n\t\t\t\tdiv\n\t\t\t\tdiv\n\t\tdiv.form-container\n\t\t\tform method=post\n\t\tv-icon\n\t\t\tv-con";

    char tab[] = {'\t'};
    printf("My test string is: %s\n", test_string);
    printf("Address of the pint: %p\n", test_string);

    Node *divNode = (Node*) malloc(sizeof(Node));
    strcpy(divNode->id, "div");
    printf("My div is called: %s\n", divNode->id);

    for(int i = 0; i < strlen(test_string); i++) {
        printf("%c", test_string[i]);
        if(strchr(tab, test_string[i]) != NULL && strchr(tab, test_string[i+1]) == NULL) {
            printf("Same string \n");
        }
    }

    free(divNode);
    return 0;
}
