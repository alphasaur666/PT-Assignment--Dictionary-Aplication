#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__
#include <stdio.h>
#include <stdlib.h>


struct Dictionary{
	/*!
	*  \param word = The word that we would like to introduce/search for.
	*  \param definition = The definition that we would like to introduce/update.
  *  \param *next = The next position in the list.
	*/
	char word[20];
	char definition[100][100];
	struct Dictionary *next;
	};



void add_dictionary(struct Dictionary *head);
int check_word(struct Dictionary *head, char word_to_find[20]);
void show_dictionary(struct Dictionary *head);
void update_definition (struct Dictionary *head, int definition_number,
						char word_to_update[20], char definition[100]);
void add_definition (struct Dictionary *head, char word_to_add[20],
					 char definition[100]);
void look_for_definition (struct Dictionary *head);
void add_another_definition(struct Dictionary *head);
void save_to_file(char file[256], struct Dictionary *head);


#endif
