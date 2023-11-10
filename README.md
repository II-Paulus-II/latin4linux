# Simple Terminal App for latin practice

Latin Grammar is weird when you first encounter it. Certain english words are missing and the ending of various words is what determines the meaning.

In English, we might say, "I love" & "you love", but latin will say "amo" & "amas", so the endings determine who is doing the loving. Similarly with nouns the ending determines who is doing what to whom.

e.g. 
Regina(queen) regem(king) amat(he/she/it loves) - means - the queen loves the king. 
Regem amat Regina - means - the queen loves the king. 
Reginam(queen) rex(king) amat(he/she/it loves) - means - the king loves the queen.

As the above example shows, word order is also less important - its the ending that determines the meaning. Hence a grammar practice app where one practices the various endings of words is a good idea at least initially when one wants to learn some latin.


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

Abstract conjugation identifier from constructor.

Don't let anyone see you didn't implement a for loop in conjugation/declining functions instead of repeating yourself 

#### Words 
Create Words Class and then make verbs and noun constructors private. 

