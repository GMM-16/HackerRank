/*
A document is represented as a collection paragraphs, a paragraph is represented as a collection of sentences, a sentence is represented as a collection of words and a word is represented as a collection of lower-case ([a-z]) and upper-case ([A-Z]) English characters. You will convert a raw text document into its component paragraphs, sentences and words. To test your results, queries will ask you to return a specific paragraph, sentence or word as described below.
Alicia is studying the C programming language at the University of Dunkirk and she represents the words, sentences, paragraphs, and documents using pointers:
A word is described by:

struct word 
{
    char* data;
};

A sentence is described by:

struct sentence 
{
    struct word* data;
    int word_count;//the number of words in a sentence
};

The words in the sentence are separated by one space (" "). The last word does not end with a space.
A paragraph is described by:

struct paragraph 
{
    struct sentence* data  ;
    int sentence_count;//the number of sentences in a paragraph
};

The sentences in the paragraph are separated by one period (".").
A document is described by:

struct document 
{
    struct paragraph* data;
    int paragraph_count;//the number of paragraphs in a document
};

The paragraphs in the document are separated by one newline("\n"). The last paragraph does not end with a newline.

Alicia has sent a document to her friend Teodora as a string of characters, i.e. represented by char* not struct document. Help her convert the document to struct document form by completing the following functions:
void initialise_document(char* text) to intialise the document. You have to intialise the global variable Doc of type struct document.
struct paragraph kth_paragraph(int k) to return the kth paragraph in the document.
struct sentence kth_sentence_in_mth_paragraph(int k, int m) to return the kth sentence in the mth paragraph.
struct word kth_word_in_mth_sentence_of_nth_paragraph(int k, int m, int n) to return the kth word in the mth sentence of the nth paragraph.

Input Format
The first line contains the integer paragraph_count.
Each of the next paragraph_count lines contains a paragraph as a single string.
The next line contains the integer q, the number of queries.
Each of the next q lines contains a query in one of the following formats:
1 k: This corresponds to calling the function kth_paragraph.
2 k m: This corresponds to calling the function kth_sentence_in_mth_paragraph.
3 k m n: This corresponds to calling the function kth_word_in_mth_sentence_of_nth_paragraph.

Constraints
The text which is passed to get_document has words separated by a spaces(" "), sentences separated by a period(".") and paragraphs separated by a newline("\n").
The last word in a sentence does not end with a space.
The last paragraph does not end with a newline.
The words contain only upper-case and lower-case English letters.
1 <= number of characters in the entire document <= 1000.
1 <= number of paragraphs in the entire document <= 5.

Output Format
Print the paragraph, sentence or the word corresponding to the query to check the logic of your code.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

typedef struct word word;
typedef struct sentence sentence;
typedef struct paragraph paragraph;

struct document get_document(char* text) 
{
    int text_len = strlen(text), i = 1, k = 0;
    struct document *d =  malloc(sizeof(struct document));
    paragraph *p =  malloc(sizeof(paragraph));
    sentence *s =  malloc(sizeof(sentence));
    word *w =  malloc(sizeof(word));
    char *string = malloc(sizeof(char));
    d->paragraph_count = 1;
    p->sentence_count = 1;
    s->word_count = 1;
    while (text_len--) {
        switch (text[k]) {
            case ' ':
                w = realloc(
                    w, 
                    sizeof(word) * (s[p[d->paragraph_count-1].sentence_count-1].word_count)
                );
                w[s[p[d->paragraph_count-1].sentence_count-1].word_count-1].data = string;
                string = malloc(sizeof(char));
                s[p[d->paragraph_count-1].sentence_count-1].word_count++;
                i = 1;
                break;
            case '.':
                w = realloc(
                    w, 
                    sizeof(word) * (s[p[d->paragraph_count-1].sentence_count-1].word_count)
                );
                w[s[p[d->paragraph_count-1].sentence_count-1].word_count-1].data = string;
                s[p[d->paragraph_count-1].sentence_count - 1].data = w;
                p[d->paragraph_count-1].sentence_count++;
                s = realloc(s, sizeof(sentence) * p[d->paragraph_count-1].sentence_count);
                
                
                if (text_len != 0 ) {
                    string = malloc(sizeof(char));
                    w = malloc(sizeof(word));
                    
                    s[p[d->paragraph_count-1].sentence_count - 1].word_count++;
                    i = 1;
                }else{
                    p[d->paragraph_count - 1].sentence_count--;
                    p[d->paragraph_count - 1].data = s;
                    d->data = p;
                }
                break;
            case '\n':
                p[d->paragraph_count - 1].sentence_count--;
                p[d->paragraph_count - 1].data = s;
                d->paragraph_count++;
                p = realloc(p, sizeof(paragraph) * d->paragraph_count);
                s = malloc(sizeof(sentence));
                p[d->paragraph_count-1].sentence_count++;
                s->word_count++;
                
                break;
            default:
                
                string = realloc(string, sizeof(char) * (i + 1));
                string[i-1] = text[k];
                string[i] = '\0';
                i++;
                break;
        }
        k++;
    };
    return *d;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) 
{
    typedef struct word word;
   word w;
   w = Doc.data[n-1].data[m-1].data[k-1];
   return w;
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) 
{ 
    sentence s;
    s = Doc.data[m-1].data[k-1];
    return s;
}

struct paragraph kth_paragraph(struct document Doc, int k) 
{
    paragraph p;
    p = Doc.data[k-1];
    return p;
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
