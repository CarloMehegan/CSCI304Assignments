#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

void decoding(char *word)
{
    char *word_ptr = word;
    char *begin, *end; // iterate through string using two position pointers
    begin = word;
    end = NULL;

    while (1)
    {
        if (isalpha(*word_ptr))
        {
            *word_ptr = toupper(*word_ptr); // change letter to upper case
        }
        else
        {
            if (begin != end) 
            {
                reverseWord(begin, end);
            }
            if (*word_ptr == '\0' || *word_ptr == '\n')
            {
                // end of the string/newline => break the loop
                break; 
            }
            begin = word_ptr + 1; // move through the word
        }

        end = word_ptr;
        word_ptr++;
    }

    //after reversing all of the text, turn underscores into spaces
    replaceUnderscoresWithSpaces(word);
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

    char word[100];

    // fgets = "file get string"; reads a word from the file
        // word = where the string will be stored
        // sizeof(word) = max size
        // fin = the file to be read from
    while (fgets(word, sizeof(word), fin) != NULL)
    {
        decoding(word);
        fprintf(fout, word); //print word to output file
    }

    fclose(fin);
    fclose(fout);
    return 1;
}