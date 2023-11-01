# Simple Terminal App for latin practice

At the current stage this should still compile and run in windows if you have make and g++ compiler installed. 

## Next stage TODO - 1stNov: 

### Frontend - ncurses.h, forms.h

Decide better way to end the form driver loop.
need 10 unicode characters [2 for each vowel] use keys F1 - F10?
- Ctrl + letter is out because keycode is equal to tabkey. 
Make seperate window to inform user of what keys to use. 
Make seperate form window.

### Backend

#### Dictionary data reader to distinguish between types of words

Trivial, all data will have 2nd to last entry determine word type 

#### Nouns

Need constructor with an extra argument to deal with genitive plural case from 3rd declension - rare but regular. 

#### Verbs

Abstract conjugation identifier from constructor
Make constructor for 3 Principle part verb entry and 4 Principle part entry
Don't let anyone see you didn't implement a for loop in conjugation functions instead of repeating yourself 



