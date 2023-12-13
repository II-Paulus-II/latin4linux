#include "../include/window.h"

#define _XOPEN_SOURCE_EXTENDED 1
#define ctrl(x) (x & 0x1F)

/*Test use of Form.h from Ncurses, to build form driver and 
 *test interaction with forms.h and std::string*/ 

void ncursesWINDOW()
{
  setlocale(LC_ALL, ""); //Enable use of unicode 
  FIELD *field[3];
	FORM  *my_form;
	int ch;
	
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE); //Don't forget to change this to use window when fields have uniq windo. 

	/* Initialize the fields */
	field[0] = new_field(1, 10, 4, 18, 0, 0);
	field[1] = new_field(1, 10, 6, 18, 0, 0);
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
	
  mvprintw(1, 1, "LaudÚ" ); //Test print of Unicode character

	mvprintw(4, 10, "Value 1:");
	mvprintw(6, 10, "Value 2:");
  form_driver(my_form, REQ_FIRST_FIELD);
	refresh();

	/* Loop through to get user requests */
	while((ch = getch()) != KEY_F(1))//F1 KEY -
	{	
    switch(ch)
		{
      case KEY_DC:
        form_driver(my_form, REQ_DEL_CHAR);
        break;
      case KEY_BACKSPACE://NEED TO CHECK NOT IN POSITION 0
        form_driver(my_form, REQ_DEL_PREV);
        break;
      case KEY_LEFT:
        form_driver(my_form, REQ_LEFT_CHAR);
        break;
      case KEY_RIGHT:
        form_driver(my_form, REQ_RIGHT_CHAR);
        break; //WHY ARENT THESE IN THE DEFAULT FORMS CODE SMH
      case KEY_DOWN:
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
			default:
				/* If this is a normal character, it gets */
				/* Printed				  */	
        if (ch == ctrl('a'))
        {
          form_driver_w(my_form, OK, L'\u00E1');
        }
        else if (ch == ctrl('e'))
        {
          form_driver_w(my_form, OK, L'\u00E9');
        }
        else if (ch == ctrl('i'))
        {
          form_driver_w(my_form, OK, L'\u00ED');
        }
        else if (ch == ctrl('o'))
        {
          form_driver_w(my_form, OK, L'\u00F3');
        }
        else if (ch == ctrl('u'))
        {
          form_driver_w(my_form, OK, L'\u00FA');
        }
        else {
				  form_driver(my_form, ch);
        }
				break;
		}
	}

  form_driver(my_form, REQ_VALIDATION);
  for (int i = 0; i < 2; i++)
  {
    mvprintw(7+i, 20, field_buffer(field[i], 0)); // is this even workable?
  }
  
  std::string myteststring = field_buffer(field[0], 0);

  char *mystring = field_buffer(field[0], 0);
  char *mysecondstr = field_buffer(field[1], 0);
  mvprintw(11, 20, "my test");
  mvprintw(12, 20, myteststring.c_str());
  //mvprintw(13, 20, mysecondstr);

  getch();
	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]); 

	endwin();
}
