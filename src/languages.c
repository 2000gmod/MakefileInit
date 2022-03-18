#include "languages.h"

void reportError(char* errorString) {
    printf("%s", errorString);
    exit(1);
}

char* removeTrailingNewLine(char string[], const int bufferSize) {
    int maxNonZero = 0;

    for (int i = 0; i < bufferSize; i++) {
        if (string[i] != 0) maxNonZero = i;
    }

    if (string[maxNonZero] == '\n') string[maxNonZero] = 0;

    return string;
}

void parseCLang() {
    char targetName[INPUT_BUFFER_SIZE] = {0};
    char objDir[INPUT_BUFFER_SIZE] = {0};
    char srcDir[INPUT_BUFFER_SIZE] = {0};
    char outDir[INPUT_BUFFER_SIZE] = {0};
    char outFileName[INPUT_BUFFER_SIZE] = {0};

    char *readBuffer;

    printf("Output file name: ");
    if (fgets(outFileName, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Compilation target name: ");
    if (fgets(targetName, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Output generation directory: ");
    if (fgets(outDir, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Object directory: ");
    if (fgets(objDir, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Source directory: ");
    if (fgets(srcDir, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");


    removeTrailingNewLine(targetName, INPUT_BUFFER_SIZE);
    removeTrailingNewLine(objDir, INPUT_BUFFER_SIZE);
    removeTrailingNewLine(srcDir, INPUT_BUFFER_SIZE);
    removeTrailingNewLine(outDir, INPUT_BUFFER_SIZE);
    removeTrailingNewLine(outFileName, INPUT_BUFFER_SIZE);

    FILE *template = fopen(C_PATH, "r");
    FILE *outputFile = fopen(outFileName, "w");

    long templateSize;
    fseek(template, 0L, SEEK_END);
    templateSize = ftell(template);
    rewind(template);

    readBuffer = calloc(1, templateSize + 1);

    if (fread(readBuffer, templateSize, 1, template) != 1) exit(1);

    fprintf(outputFile, readBuffer, targetName, objDir, srcDir, outDir);
    fprintf(outputFile, "\n");

    fclose(outputFile);
    fclose(template);
    free(readBuffer);
}

void parseCPPLang() {
    char targetName[INPUT_BUFFER_SIZE] = {0};
    char objDir[INPUT_BUFFER_SIZE] = {0};
    char srcDir[INPUT_BUFFER_SIZE] = {0};
    char outDir[INPUT_BUFFER_SIZE] = {0};
    char outFileName[INPUT_BUFFER_SIZE] = {0};

    char *readBuffer;

    printf("Output file name: ");
    if (fgets(outFileName, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Compilation target name: ");
    if (fgets(targetName, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Output generation directory: ");
    if (fgets(outDir, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Object directory: ");
    if (fgets(objDir, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Source directory: ");
    if (fgets(srcDir, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");


    removeTrailingNewLine(targetName, INPUT_BUFFER_SIZE);
    removeTrailingNewLine(objDir, INPUT_BUFFER_SIZE);
    removeTrailingNewLine(srcDir, INPUT_BUFFER_SIZE);
    removeTrailingNewLine(outDir, INPUT_BUFFER_SIZE);
    removeTrailingNewLine(outFileName, INPUT_BUFFER_SIZE);

    FILE *template = fopen(CPP_PATH, "r");
    FILE *outputFile = fopen(outFileName, "w");

    long templateSize;
    fseek(template, 0L, SEEK_END);
    templateSize = ftell(template);
    rewind(template);

    readBuffer = calloc(1, templateSize + 1);

    if (fread(readBuffer, templateSize, 1, template) != 1) exit(1);

    fprintf(outputFile, readBuffer, targetName, objDir, srcDir, outDir);
    fprintf(outputFile, "\n");

    fclose(outputFile);
    fclose(template);
    free(readBuffer);
}

void parseJavaLang() {
    char outFileName[INPUT_BUFFER_SIZE] = {0};
    char srcDir[INPUT_BUFFER_SIZE] = {0};
    char outDir[INPUT_BUFFER_SIZE] = {0};
    char classDir[INPUT_BUFFER_SIZE] = {0};
    char mainPackage[INPUT_BUFFER_SIZE] = {0};
    char mainClass[INPUT_BUFFER_SIZE] = {0};
    

    char *readBuffer;

    printf("Output file name: ");
    if (fgets(outFileName, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Source directory: ");
    if (fgets(srcDir, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Output directory: ");
    if (fgets(outDir, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Class directory: ");
    if (fgets(classDir, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Main package name: ");
    if (fgets(mainPackage, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    printf("Main class name: ");
    if (fgets(mainClass, INPUT_BUFFER_SIZE, stdin) == NULL) reportError("Null exception\n");

    removeTrailingNewLine(outFileName, INPUT_BUFFER_SIZE);

    FILE *template = fopen(JAVA_PATH, "r");
    FILE *outputFile = fopen(outFileName, "w");

    long templateSize;
    fseek(template, 0L, SEEK_END);
    templateSize = ftell(template);
    rewind(template);

    readBuffer = calloc(1, templateSize + 1);

    if (fread(readBuffer, templateSize, 1, template) != 1) exit(1);

    fprintf(outputFile, readBuffer, srcDir, outDir, classDir, mainPackage, mainClass);
    fprintf(outputFile, "\n");

    fclose(outputFile);
    fclose(template);
    free(readBuffer);
}