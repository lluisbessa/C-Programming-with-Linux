#include "headers.h"

void doFormSearch(void){
    FIELD *field[4];
	FORM  *my_form;
	int ch, found;
	
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* Initialize the fields */
	field[0] = new_field(1, 20, 4, 18, 0, 0);
	field[1] = new_field(1, 20, 6, 18, 0, 0);
	field[2] = new_field(1, 20, 8, 18, 0, 0);
	field[3] = NULL;

	/* Set field options */
	set_field_back(field[0], A_UNDERLINE); 	/* Print a line for the option 	*/
	field_opts_off(field[0], O_AUTOSKIP);  	/* Don't go to next field when this */
						/* Field is filled up 		*/
	set_field_back(field[1], A_UNDERLINE); 
	field_opts_off(field[1], O_AUTOSKIP);

	set_field_back(field[2], A_UNDERLINE); 
	field_opts_off(field[2], O_AUTOSKIP);
	/* Create the form and post it */
	my_form = new_form(field);
	post_form(my_form);
	refresh();
	mvprintw(4, 5, "First name:");
	mvprintw(6, 5, "Last name:");
    mvprintw(8, 5, "Subject:");
    mvprintw(LINES - 2, 0, "F1 to Exit - Enter to perform operation");
	refresh();
    pos_form_cursor(my_form);
	/* Loop through to get user requests */
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_DOWN:
				/* Go to next field */
				form_driver(my_form, REQ_NEXT_FIELD);
				/* Go to the end of the present buffer */
				/* Leaves nicely at the last character */
				form_driver(my_form, REQ_END_LINE);
				break;
			case KEY_UP:
				/* Go to previous field */
				form_driver(my_form, REQ_PREV_FIELD);
				form_driver(my_form, REQ_END_LINE);
				break;
		    case 10:
			    form_driver(my_form, REQ_NEXT_FIELD);
			    form_driver(my_form, REQ_PREV_FIELD);
			    move(LINES-10, 0);
                found = searchStudent(field_buffer(field[0],0),field_buffer(field[1],0),field_buffer(field[2],0));
			    if (!found) {
                    printw("No records for these student");
                }
			    break;

			default:
				/* If this is a normal character, it gets */
				/* Printed				  */	
				form_driver(my_form, ch);
				break;
		}
	}

	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]); 
	free_field(field[2]); 
	endwin();
}

void doFormSearchNoGrade(void){
    FIELD *field[3];
	FORM  *my_form;
	int ch, found;
	
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* Initialize the fields */
	field[0] = new_field(1, 20, 4, 18, 0, 0);
	field[1] = new_field(1, 20, 6, 18, 0, 0);
	field[2] = NULL;

	/* Set field options */
	set_field_back(field[0], A_UNDERLINE); 	/* Print a line for the option 	*/
	field_opts_off(field[0], O_AUTOSKIP);  	/* Don't go to next field when this */
						/* Field is filled up 		*/
	set_field_back(field[1], A_UNDERLINE); 
	field_opts_off(field[1], O_AUTOSKIP);

	/* Create the form and post it */
	my_form = new_form(field);
	post_form(my_form);
	refresh();
	mvprintw(4, 5, "First name:");
	mvprintw(6, 5, "Last name:");
    mvprintw(LINES - 2, 0, "F1 to Exit - Enter to perform operation");
	refresh();
    pos_form_cursor(my_form);
	/* Loop through to get user requests */
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_DOWN:
				/* Go to next field */
				form_driver(my_form, REQ_NEXT_FIELD);
				/* Go to the end of the present buffer */
				/* Leaves nicely at the last character */
				form_driver(my_form, REQ_END_LINE);
				break;
			case KEY_UP:
				/* Go to previous field */
				form_driver(my_form, REQ_PREV_FIELD);
				form_driver(my_form, REQ_END_LINE);
				break;
		    case 10:
			    form_driver(my_form, REQ_NEXT_FIELD);
			    form_driver(my_form, REQ_PREV_FIELD);
			    move(LINES-10, 0);
                found = searchStudentNoSubject(field_buffer(field[0],0),field_buffer(field[1],0));
                if (!found) {
                    printw("No records for these student");
                }
			    break;

			default:
				/* If this is a normal character, it gets */
				/* Printed				  */	
				form_driver(my_form, ch);
				break;
		}
	}

	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]); 

	endwin();
}


void doFormAdd(void){
    FIELD *field[3];
	FORM  *my_form;
	int ch;
	
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* Initialize the fields */
	field[0] = new_field(1, 20, 4, 18, 0, 0);
	field[1] = new_field(1, 20, 6, 18, 0, 0);
	field[2] = NULL;
	/* Set field options */
	set_field_back(field[0], A_UNDERLINE); 	/* Print a line for the option 	*/
	field_opts_off(field[0], O_AUTOSKIP);  	/* Don't go to next field when this */
						/* Field is filled up 		*/
	set_field_back(field[1], A_UNDERLINE); 
	field_opts_off(field[1], O_AUTOSKIP);

	/* Create the form and post it */
	my_form = new_form(field);
	post_form(my_form);
	refresh();
	mvprintw(4, 5, "First name:");
	mvprintw(6, 5, "Last name:");
    mvprintw(LINES - 2, 0, "F1 to Exit - Enter to perform operation");
	refresh();
    pos_form_cursor(my_form);
	/* Loop through to get user requests */
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_DOWN:
				/* Go to next field */
				form_driver(my_form, REQ_NEXT_FIELD);
				/* Go to the end of the present buffer */
				/* Leaves nicely at the last character */
				form_driver(my_form, REQ_END_LINE);
				break;
			case KEY_UP:
				/* Go to previous field */
				form_driver(my_form, REQ_PREV_FIELD);
				form_driver(my_form, REQ_END_LINE);
				break;
		    case 10:
			    form_driver(my_form, REQ_NEXT_FIELD);
			    form_driver(my_form, REQ_PREV_FIELD);
			    move(LINES-10, 0);
                addStudent(field_buffer(field[0],0),field_buffer(field[1],0));
			    break;
			default:
				/* If this is a normal character, it gets */
				/* Printed				  */	
				form_driver(my_form, ch);
				break;
		}
	}

	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]); 
	endwin();
}

void changeStudent(void){
    FIELD *field[6];
	FORM  *my_form;
	int ch;
	
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* Initialize the fields */
	field[0] = new_field(1, 20, 4, 35, 0, 0);
	field[1] = new_field(1, 20, 6, 35, 0, 0);
	field[2] = new_field(1, 20, 8, 35, 0, 0);
    field[3] = new_field(1, 20, 10, 35, 0, 0);
	field[4] = new_field(1, 20, 12, 35, 0, 0);
    field[5] = new_field(1, 20, 14, 35, 0, 0);
	field[6] = NULL;
	/* Set field options */
	set_field_back(field[0], A_UNDERLINE); 	/* Print a line for the option 	*/
	field_opts_off(field[0], O_AUTOSKIP);  	/* Don't go to next field when this */
						/* Field is filled up 		*/
	set_field_back(field[1], A_UNDERLINE); 
	field_opts_off(field[1], O_AUTOSKIP);
	
	set_field_back(field[2], A_UNDERLINE); 
	field_opts_off(field[2], O_AUTOSKIP);
	
    set_field_back(field[3], A_UNDERLINE); 
	field_opts_off(field[3], O_AUTOSKIP);

	
	set_field_back(field[4], A_UNDERLINE); 
	field_opts_off(field[4], O_AUTOSKIP);
	
    set_field_back(field[5], A_UNDERLINE); 
	field_opts_off(field[5], O_AUTOSKIP);
	
	/* Create the form and post it */
	my_form = new_form(field);
	post_form(my_form);
	refresh();
	mvprintw(4, 5, "First name before replace:");
	mvprintw(6, 5, "Last name before replace:");
	mvprintw(8, 5, "New firstname:");
    mvprintw(10, 5, "New last name:");
    mvprintw(12, 5, "New or old Subject:");
    mvprintw(14, 5, "Grade:");
    mvprintw(LINES - 2, 0, "F1 to Exit - Enter to perform operation");
	refresh();
    pos_form_cursor(my_form);
	/* Loop through to get user requests */
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_DOWN:
				/* Go to next field */
				form_driver(my_form, REQ_NEXT_FIELD);
				/* Go to the end of the present buffer */
				/* Leaves nicely at the last character */
				form_driver(my_form, REQ_END_LINE);
				break;
			case KEY_UP:
				/* Go to previous field */
				form_driver(my_form, REQ_PREV_FIELD);
				form_driver(my_form, REQ_END_LINE);
				break;
		    case 10:
			    form_driver(my_form, REQ_NEXT_FIELD);
			    form_driver(my_form, REQ_PREV_FIELD);
			    move(LINES-5, 0);
                updateStudent(field_buffer(field[0],0),field_buffer(field[1],0),field_buffer(field[2],0),field_buffer(field[3],0),field_buffer(field[4],0),field_buffer(field[5],0));
			    break;
			default:
				/* If this is a normal character, it gets */
				/* Printed				  */	
				form_driver(my_form, ch);
				break;
		}
	}

	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]);
	free_field(field[2]);
	free_field(field[3]);
	free_field(field[4]);
	free_field(field[5]); 

	endwin();
}

void doFormRemove(void){
    FIELD *field[4];
	FORM  *my_form;
	int ch;
	
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* Initialize the fields */
	field[0] = new_field(1, 20, 4, 18, 0, 0);
	field[1] = new_field(1, 20, 6, 18, 0, 0);
	field[2] = new_field(1, 20, 8, 40, 0, 0);;
	field[3] = NULL;
	/* Set field options */
	set_field_back(field[0], A_UNDERLINE); 	/* Print a line for the option 	*/
	field_opts_off(field[0], O_AUTOSKIP);  	/* Don't go to next field when this */
						/* Field is filled up 		*/
	set_field_back(field[1], A_UNDERLINE); 
	field_opts_off(field[1], O_AUTOSKIP);

	set_field_back(field[2], A_UNDERLINE); 
	field_opts_off(field[2], O_AUTOSKIP);
	/* Create the form and post it */
	my_form = new_form(field);
	post_form(my_form);
	refresh();
	mvprintw(4, 5, "First name:");
	mvprintw(6, 5, "Last name:");
	mvprintw(8, 5, "Subject (Empty = Delete Student):");
    mvprintw(LINES - 2, 0, "F1 to Exit - Enter to perform operation");
	refresh();
    pos_form_cursor(my_form);
	/* Loop through to get user requests */
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_DOWN:
				/* Go to next field */
				form_driver(my_form, REQ_NEXT_FIELD);
				/* Go to the end of the present buffer */
				/* Leaves nicely at the last character */
				form_driver(my_form, REQ_END_LINE);
				break;
			case KEY_UP:
				/* Go to previous field */
				form_driver(my_form, REQ_PREV_FIELD);
				form_driver(my_form, REQ_END_LINE);
				break;
		    case 10:
			    form_driver(my_form, REQ_NEXT_FIELD);
			    form_driver(my_form, REQ_PREV_FIELD);
			    move(LINES-9, 0);
                removeStudent(field_buffer(field[0],0),field_buffer(field[1],0),field_buffer(field[2],0));
			    break;

			default:
				/* If this is a normal character, it gets */
				/* Printed				  */	
				form_driver(my_form, ch);
				break;
		}
	}

	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]); 
	free_field(field[2]); 
	endwin();
}

char* trim_whitespaces(char *str){
	char *end;

	// trim leading space
	while(isspace(*str))
		str++;

	if(*str == 0) // all spaces?
		return str;

	// trim trailing space
	end = str + strnlen(str, 128) - 1;

	while(end > str && isspace(*end))
		end--;

	// write new null terminator
	*(end+1) = '\0';

	return str;
}
