#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

void add_dictionary(struct Dictionary *head){ ///> Function for adding the word into the list.
  /*!
	*  \param head = The head of the list, the beginning of it.
	*/


    struct Dictionary *iterator = head;
    struct Dictionary *new_word = malloc(sizeof(struct Dictionary));

    while(iterator->next != NULL){
        iterator = iterator->next;
    }

    new_word->next = NULL;
    iterator->next = new_word; ///> We search for a place where the word can be added in the list. The definition will be added right after the word. Same goes for the other functions, searching is present in mostly of them.

    printf("\nPlease enter your word:");
    fgets(new_word->word,20,stdin);

    printf("\nPlease enter your definition:");
    fgets(new_word->definition[0],100,stdin);

}

int check_word(struct Dictionary *head, char word_to_find[20]){ ///> Function for checking if a word exists in our list.
  /*!
  *
  * 	\param word_to_find = the target word.
  *   \param head = The head of the list, the beginning of it.
  */
    struct Dictionary *iterator = head;

    while(iterator->next != NULL){
        if(strlen(iterator->next->word) != 0)
            if(strcmp(iterator->next->word, word_to_find) == 0)
                return 1;
        iterator = iterator->next;
    }

    return 0;

}

void show_dictionary(struct Dictionary *head){ ///>  Function for showing the word and its multiple/single definitions. We are searching for the word, and we are printing it alongside its definition.
  /*!
  *  \param head = The head of the list, the beginning of it.
  */
    struct Dictionary *iterator = head;
    int i;

    while(iterator->next != NULL){
        printf("\nWord: %s", iterator->next->word);
        for(i = 0; iterator->next->definition[i] != '\0'; i++)
            printf("\nDefinition: %s\n", iterator->next->definition[i]);
    iterator = iterator->next;
    }
}

void update_definition (struct Dictionary *head, int definition_number, char word_to_update[20], char definition[100]){ ///> Function for updating a definition of a word. Any definition can be updated. The function will search the definition based on its definition number and it will replace the current definition with the one you desire.
  /*!
	*  \param definition_number = The number of the definition that we want to update.
	*  \param word_to_update = The target word that needs its definition updated.
  *  \param definition = The updated definition.
  *  \param head = The head of the list, the beginning of it.
	*/


    struct Dictionary *iterator = head;

    while(iterator->next != NULL && strcmp(iterator->next->word, word_to_update) == 0){
        if(strlen(iterator->next->word) != 0)
            if(strcmp(iterator->next->word, word_to_update) == 0){
                printf("\nDefinition of word was successfully updated, press any key to continue.");
                strcpy(iterator->next->definition[definition_number - 1], definition);
                getch();
                return;
            }
        iterator = iterator->next;
    }

    if(iterator->next == NULL){
        printf("\nCannot find the word %s in the dictionary", word_to_update);
        return;
    }


}


void add_definition (struct Dictionary *head, char word_to_add[20], char definition[100]){  ///> Function for adding a definition to a word. The definition will be inserted based on the position where we find place in the list.
  /*!
	*   \param word_to_add = The target word that needs its definition added.
  *   \param definition = The added definition.
  *   \param  head = The head of the list, the beginning of it.
	*/
    int i = 0;
    struct Dictionary *iterator = head;
    int ok = 0;
    while(iterator->next != NULL){
        if(strlen(iterator->next->word) != 0)
            if(strcmp(iterator->next->word, word_to_add) == 0){
                    ok = 1;
                break;
            }
    }

    if(ok){
        for(i = 0; strlen(iterator->next->definition[i]) != 0; i++);
            strcat(iterator->next->definition[i], definition);
        printf("\nDefinition of word was successfully inserted.");
    }

}


void look_for_definition (struct Dictionary *head){  ///> Function for searching for the definitions of a word. The word must exist, although the function will return a negative approach. Based on the search for the word who has a defintion allocated to it.
  /*!
  *  \param  head = The head of the list, the beginning of it.
  */
    struct Dictionary *iterator = head;
    char word[20];
    int i;
    printf("\nPlease enter the word that you would like to search for:\n");
    fgets(word,20,stdin);

    while(iterator->next != NULL && strcmp(iterator->next->word, word) != 0){

        iterator = iterator->next;
    }

    if(iterator->next == NULL){
        printf("The word you entered does not appear in the dictionary.\n");
        return;
    }

    for(i = 0; strlen(iterator->next->definition[i]) != 0; i++)
        printf("\nWord Definition %d: %s\n", i + 1, iterator->next->definition[i]); ///> Because the word may have multiple definitions, we need to print them in order.

}
void add_another_definition(struct Dictionary *head){ ///> Function for adding another definition to the list for a certain word. The function asks for the word, in order to not change the definition of a undesired word.
  /*!
  *  \param  head = The head of the list, the beginning of it.
  */
    struct Dictionary *iterator = head;
    char word[20];
    int i;
    printf("\nPlease enter the word that you would like to search for:");
    fgets(word,20,stdin);

    while(iterator->next != NULL && strcmp(word,iterator->next->word)){
        iterator = iterator->next;
    }

    if(iterator->next == NULL){
        printf("The word you entered does not appear in the dictionary.\n");
        return;
    }


    printf("Enter the new definition for the word \"%s\" :", iterator->next->word);

    for(i = 0; strlen(iterator->next->definition[i]) != 0; i++);

    fgets(iterator->next->definition[i],100,stdin);


}


void save_to_file(char file[256], struct Dictionary *head){ ///> Function for saving the content of the dictionary into a file.

  /*!
	*   \param file = The file where we are going to save the data.
  *   \param head = The head of the list, the beginning of it.
	*/

    struct Dictionary *iterator = head;
    unsigned int counter = 0;
    FILE *f = fopen(file, "w+");
    int i;

    if (f == NULL){
        printf("\nError saving into file!");
        return;
    }

    do{
        counter++;
        for(i = 0; strlen(iterator->next->definition[i]) != 0; i++)
            fprintf(f, "\n%d. Word: %s Definition: %s", counter, iterator->next->word, iterator->next->definition[i]);
        iterator = iterator->next;

    }while(iterator->next != NULL);


    fclose(f);

    printf("\nYour content has been saved to file \"%s\".\n", file);

}
