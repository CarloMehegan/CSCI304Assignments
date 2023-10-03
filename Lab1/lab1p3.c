#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// takes the start and end of a word, iterates through the letters, reversing the word
void reverseWord(char *begin, char *end) {
    char temp;
    while (begin < end) { // swap beginning and end, until the pointers meet
        // swap values
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
            string[i] = ' '; // replace underscore with space
        }
    }
}

// takes a string and reverses it according to the cypher rubric
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
        else //if not alphanumeric, then we have found the end of a word
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

    char finName[] = "lab1p3in";
    char foutName[] = "lab1p3out";

    fin = fopen(finName, "r");
    if (!fin)
    {
        printf("Input file %s does not exist.\n", finName);
        return 0;
    }

    fout = fopen(foutName, "w");
    if (!fout)
    {
        printf("Output file %s does not exist.\n", foutName);
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
        // print word to output file
        // "%s" clarifies the word should be printed as a string, so things like % signs stay intact
        fprintf(fout, "%s", word);
    }

    fclose(fin);
    fclose(fout);
    return 1;
}