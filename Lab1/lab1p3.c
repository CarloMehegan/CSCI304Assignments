#include <stdio.h>
#include <stdlib.h>

//takes the start and end of a word, iterates through the letters, reversing the word
void reverseWord(char *begin, char *end) {
    char temp;
    while (begin < end) { // swap beginning and end, until the pointers meet
        // assign values
        temp = *begin;
        *begin = *end;
        *end = temp;
        // increment pointers
        begin++;
        end--;
    }
}

//takes a string, replaces all the underscores with spaces
void replaceUnderscoresWithSpaces(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '_')
        {
            string[i] = ' '; // Replace underscore with space
        }
    }
}

void decoding(char *string)
{
    char *string_ptr = string;
    char *begin, *end; // iterate through string using two position pointers
    begin = string;
    end = NULL;

    while (1)
    {
        if (isalpha(*string_ptr)) 
        {
            *string_ptr = toupper(*string_ptr); // change to upper case
        }
        else
        {
            if (begin != end) 
            {
                reverseWord(begin, end);
            }
            if (*string_ptr == '\0' || *string_ptr == '\n') 
            {
                break; // end of the string/newline = break the loop
            }
            begin = string_ptr + 1; // increment
        }

        end = string_ptr;
        string_ptr ++;
    }

    //after reversing all of the text, turn underscores into spaces
    replaceUnderscoresWithSpaces(string);
}

int main()
{
    // open input and output files (and make sure they exist)
    FILE *fin, *fout;

    fin = fopen("lab1p3in", "r");
    if (!fin)
    {
        printf("Input file does not exist.\n");
        return 0;
    }

    fout = fopen("lab1p3out", "w");
    if (!fout)
    {
        printf("Output file does not exist.\n");
        return 0;
    }


    char temp[100];

    // fgets = file get string; reads a line of text from a file
        // temp = where the string will be stored
        // 100 = max size
        // fin = the file to be read from
    while (fgets(temp, sizeof(temp), fin) != NULL)
    {
        decoding(temp);
        fprintf(fout, temp); //print to file
    }

    fclose(fin);
    fclose(fout);
    return 1;
}