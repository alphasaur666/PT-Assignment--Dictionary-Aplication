/**
*@mainpage
* \brief \b Task \b Advanced \b Application \b 15: A dictionary application.
* \author Rosu Razvan-Virgil
* \date 20.06.2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "dictionary.h"
int main(){

  int def_number;
  char word_to_find[20];
  char definition[20];
///> The main file consists in how the application was organised.
///> The dictionary is using 2 .c files, in one of it we store the functions that we need in order to run the application, and a header file. Those files are made for code arrangement.
///> The user will be asked through a dialog where he needs to press a key in order to execute a function. getch funtcion is used here for getting the character associated with the functions.

  struct Dictionary *head = malloc(sizeof(struct Dictionary));
  head->next = NULL;
  while(1){
  printf("Classic Dictionary.\n");
  printf("Copyright:Rosu Razvan 2017. All rights reserved.\n\n\n\n");
  printf("Please choose one of the following operations:\n\n");
  printf("a.Update definition of a word.\n");
  printf("b.Add a definition and a word.\n");
  printf("c.Search for a word and it's current definition.\n");
  printf("d.Add a new definition to a word.\n");
  printf("e.Exit.\n\n\n\n\n\n");
  printf("Please enter a choice:% \n\n\n\n\n\n");
  char confirm = getch();

  if(confirm == 'a'){
    int ok = 0;
    printf("Enter the new definition:  ");
    fgets(definition, 100, stdin);
    printf("Which word would you like to change definition for?  ");
    fgets(word_to_find, 20, stdin);
    ok = check_word(head, word_to_find);
    if(ok){
        printf("Which definition would you like to change? (1/2/3...) ");
        scanf("%d", &def_number);
        update_definition(head, def_number, word_to_find, definition);
        save_to_file("data.in",head);
    } else {
        printf("The word does not exist in the dictionary.");
    }
  }
  if(confirm == 'b'){
        add_dictionary(head);
        save_to_file("data.in",head);
        printf("Would you like to add another definition? y/n \n");
        char confirm2 = getch();
        if( confirm2 == 'y'){
            add_another_definition(head);
            save_to_file("data.in",head);
      }
  }

    if(confirm == 'c'){
            look_for_definition(head);
   }

    if(confirm == 'd'){
        int ok;
        printf("Enter the new definition:  ");
        fgets(definition, 100, stdin);
        printf("Which word would you like to add definition for?  ");
        fgets(word_to_find, 20, stdin);
        ok = check_word(head, word_to_find);
        if(ok){
            add_definition(head, word_to_find, definition);
            save_to_file("data.in",head);
        }
   }

   if(confirm == 'e'){
            return 0;
   }

}
}
