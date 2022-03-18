#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <stdlib.h>
#include <stdio.h>

#define C_PATH "/usr/local/etc/MakefileInit/templates/c_lang"
#define CPP_PATH "/usr/local/etc/MakefileInit/templates/cpp_lang"
#define JAVA_PATH "/usr/local/etc/MakefileInit/templates/java_lang"

#define INPUT_BUFFER_SIZE 256

void parseCLang();
void parseCPPLang();
void parseJavaLang();

void reportError(char* errorString);
char* removeTrailingNewLine(char string[], const int bufferSize);

#endif