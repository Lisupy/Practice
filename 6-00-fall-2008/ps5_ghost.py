# Problem Set 5: Ghost
# Name: 
# Collaborators: 
# Time: 
#



import random

TOTAL_PLAYER = 2

# -----------------------------------
# Helper code
# (you don't need to understand this helper code)
import string

WORDLIST_FILENAME = "words.txt"

def load_words():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print "Loading word list from file..."
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r', 0)
    # wordlist: list of strings
    wordlist = []
    for line in inFile:
        wordlist.append(line.strip().lower())
    print "  ", len(wordlist), "words loaded."
    return wordlist

def get_frequency_dict(sequence):
    """
    Returns a dictionary where the keys are elements of the sequence
    and the values are integer counts, for the number of times that
    an element is repeated in the sequence.

    sequence: string or list
    return: dictionary
    """
    # freqs: dictionary (element_type -> int)
    freq = {}
    for x in sequence:
        freq[x] = freq.get(x,0) + 1
    return freq


# (end of helper code)
# -----------------------------------

# Actually load the dictionary of words and point to it with 
# the wordlist variable so that it can be accessed from anywhere
# in the program.
wordlist = load_words()

print "Welcome to Ghost!"
player_i = 1
word = ""

def is_word_fragment_valid(word):
    for i in wordlist:
        if i.startswith(word):
            return True
    return False

while True:
    print "Current word fragment: '%s'"%word
    print "Player %d turn."%player_i
    print "Player %d says letter:"%player_i,
    letter = raw_input()
    print len(letter)
    if not letter.isalpha() or len(letter) != 1:
        print "'%s' is not a letter"%letter
        continue
    word = word + letter
    if word.lower() in wordlist:
        print "Player %d wins!"%player_i
        break;
    if not is_word_fragment_valid(word.lower()):
        print "Player %d loses because no word begins with '%s'"%(player_i,word)
        #print "Player %d wins!"%player_i
        break;
    player_i = player_i + 1
    if player_i > TOTAL_PLAYER:
        player_i = 1
    