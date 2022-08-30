#include "headers.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))  // Auto calculation of the number of choices, useful for "calloc(n-choices + 1, sizeof(ITEM *))

// Function prototypes


char *choices[] = {
                        "Search student",
                        "Search student in subject",
                        "Add student",
                        "Update student",
                        "Remove student",
                  };

int main(void){	
    // Variable declaration    
    ITEM **my_items; 
	int c;				
	MENU *my_menu;
	int n_choices, i;
	
	// Initialize ncurses
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	// Set n_choices
	n_choices = ARRAY_SIZE(choices);
	// Allocate space for the items
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

    // Initialize items
	for(i = 0; i < n_choices; ++i)
	        my_items[i] = new_item(choices[i], "");
	my_items[n_choices] = (ITEM *)NULL;

    // Create menu
	my_menu = new_menu((ITEM **)my_items);
	// Print these at bottom
	mvprintw(LINES - 2, 0, "F1 to Exit - Enter to perform operation");
	// Post menu and refresh so it's visible.
	post_menu(my_menu);
	refresh();

	while((c = getch()) != KEY_F(1)) // While character is not F1 continue inside while loop
	{
	    switch(c)    // Basic switch to enter each menu item or move inside of it. 
	    {	
	        case KEY_DOWN:
		        menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
		    case 10:
				//clrtoeol();
				if (strncmp(item_name(current_item(my_menu)),"Search student in subject",strlen("Search student in subject"))==0){
				    doFormSearch();
				} else if (strncmp(item_name(current_item(my_menu)),"Search student",strlen("Search student"))==0) {
				    doFormSearchNoGrade();
				} else if (strncmp(item_name(current_item(my_menu)),"Add student",strlen("Add student"))==0){
				    doFormAdd();
				} else if (strncmp(item_name(current_item(my_menu)),"Update student",strlen("Update student"))==0) {
				    changeStudent();
				} else if (strncmp(item_name(current_item(my_menu)),"Remove student",strlen("Remove student"))==0){
				    doFormRemove();
				}
                break;
		}
		// Refresh menu when someones exit a function
		unpost_menu(my_menu);
		post_menu(my_menu);
		mvprintw(LINES - 2, 0, "F1 to Exit - Enter to perform operation");
	    refresh();
	    
	}	
    // Free items space
	free_item(my_items[0]);
	free_item(my_items[1]);
	free_item(my_items[2]);
	free_item(my_items[3]);
	free_item(my_items[4]);
	free_menu(my_menu);
	// End ncurses
	endwin();
}
