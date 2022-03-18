#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "languages.h"

int main(int argc, char** argv) {
    if (argc == 1 || argc > 2) {
        printf("Usage: mkfileinit [c | cpp | java].\n");
        return 1;
    }

    if (strcmp("c", argv[1]) == 0) parseCLang();
    else if (strcmp("cpp", argv[1]) == 0) parseCPPLang();
    else if (strcmp("java", argv[1]) == 0) parseJavaLang();

    else {
        printf("Unknown option: %s\n", argv[1]);
        return 1;
    }

}