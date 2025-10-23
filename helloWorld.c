#include <stdio.h>
#include <string.h>

void createTree(size_t treeSize);

void setLine(size_t lineNum, size_t treeSize, char* dest) {
    size_t stars = (2 * lineNum) - 1;
    size_t spaces = treeSize - lineNum;

    for (size_t i = 0; i < spaces; i++) {
        dest[i] = ' ';
    }

    for (size_t j = 0; j < stars; j++) {
        dest[spaces + j] = '*';
    }

    dest[spaces + stars] = '\n';
    dest[spaces + stars + 1] = '\0';
}

int main(void) {
   size_t treeSize = 10;
   createTree(treeSize);
   return 0;
}

void createTree(size_t treeSize) {
   char asciiTree[2056] = "";
   for (size_t treePart = 1; treePart <= treeSize; treePart++)
   {
      for (size_t i = 1; i <= treePart; i++)
      {
         char asciiTreeLine[2056];

         setLine(i, treeSize, asciiTreeLine);
         strcat(asciiTree, asciiTreeLine);
      }
   }
      
      
   printf("%s", asciiTree);
}
