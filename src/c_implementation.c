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
    int level, startPos, endPos;
    char *classes;
};

void createNode(Node *parentNode, Node *currentNode, int level, int tabCount) {
    if(tabCount > level) {
        // It is my child
        currentNode->childNode = (Node*) malloc(sizeof(Node));
        printf("Created a child element\n");
    }
}

void printTree(Node *head) {
    if(head->childNode != NULL) {
        return
    }
}

int main() {
    //char* test_string = "div\n\tmain.vmainClass1.vmainClass2\n\t\tdiv#main-container\n\t\t\tdiv#keyboard-shortcut.class2\n\t\t\t\tdiv\n\t\t\t\tdiv\n\t\tdiv.form-container\n\t\t\tform method=post\n\t\tv-icon\n\t\t\tv-con";

    char *test_string = "div1\n\tdiv2\n\tdiv3\n\tdiv4\n\t\tdiv5\ndiv6";
    char tab[] = {'\t'};
    printf("My test string is: %s\n", test_string);
    printf("Address of the pint: %p\n", test_string);

    Node *divNode = (Node*) malloc(sizeof(Node));
    strcpy(divNode->id, "div");
    printf("My div is called: %s\n", divNode->id);
    printf("-------------------------------------\n");


    Node *HEAD = (Node*) malloc(sizeof(Node));
    HEAD->parentNode = NULL;

    Node *currentNode = HEAD;

    int tabCount = 0;
    int currentLevel = 0;
    int prevPos = 0;
    int x = 0;
    int whatAmI = 0;
    // 0 = child
    // 1 = sibling
    // 2 = unknown we need find out by going up the chain
    for(int i = 0; i < strlen(test_string); i++) {
        printf("%c", test_string[i]);
        if(strchr(tab, test_string[i]) != NULL) {
            // We have a tab
            tabCount++;
            if(strchr(tab, test_string[i+1]) == NULL) {
                // Next character is not a tab
                printf("--tab--");
                printf("--count: %i", tabCount);
                if(whatAmI==0) {
                    // This node is a child node
                    currentNode->childNode = (Node*) malloc(sizeof(Node));
                    currentNode->childNode->parentNode = currentNode;
                    currentNode->childNode->level = currentLevel;
                    currentNode = currentNode->childNode;
                    currentNode->startPos = prevPos;
                    currentNode->endPos = i;

                }else if(whatAmI==1) {
                    // This node is a sibling node
                    currentNode->nextSibling = (Node*) malloc(sizeof(Node));
                    currentNode->nextSibling->level = currentLevel;
                    currentNode->nextSibling->prevSibling = currentNode;
                    currentNode = currentNode->nextSibling;
                    currentNode->startPos = prevPos;
                    currentNode->endPos = i;
                }else if(whatAmI==2) {

                    while(x == 0) {
                        printf("ran the while loop");
                        int x = 1;
                    }

                }
                //createNode(currentNode, currentNode, currentLevel, tabCount);

                /*
                 * Determine what the next tag will be.
                 */
                if(tabCount > currentLevel) {
                    // Next tag is a child
                    whatAmI = 0;
                    printf("Created a child element\n");
                    currentLevel++;
                } else if(tabCount==currentLevel) {
                    // Sibling node
                    whatAmI = 1;
                } else if(tabCount < currentLevel) {
                    // It is going back we need to find out what it is
                    currentLevel = tabCount;
                }
                tabCount = 0;
                prevPos = i+1;
            }
        }
    }

    //Node = getChildren(test_string, 0, 0, HEAD, 0);

    free(divNode);
    free(HEAD);
    return 0;
}

    /*
      HEAD-> div#1\t div#2\t div#3 div#4
      previousTabCount == position of the current new Node
     */
/*
Node getChildren(string, startPosition, currentPos, Node parentNode, previousTabCount) {
    int tabCount = 0;
    if(char is tab) {
        tabCount++;
        if(strchr(tab, test_string[i]) != NULL && strchr(tab, test_string[i+1]) == NULL) {
            // Here we split the string
            // we have a \t, so we create the element
            Node newNode = createNode(startPosition, currentPosition);

            if(tabCount==0) {
                // Next node belongs to head

            // is the next element my child?
            } else if(tabCount > previousTabCount){
                // Yes, it is my child.
                Node newNode = getChildren(string, startPosition=currentPosition, parentNode=newNode);
                newNode.childNode = returned Node;
            }else if(tabCount<=previousTabCount){
                // It is a sibling
                getChildren(string, startPosition=currentPosition, parentNode=parentTab);
                newNode.parentNode = parentNode;
                newNode.prevSibling
            }
            return newNode;
        }
    }
}
*/
