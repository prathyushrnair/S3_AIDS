'''
This program replaces a word in a sentence with another word.
'''

# Input a sentence from the user
sentence = input("Enter a sentence: ")

# Input the word to be replaced and the new word
old_word = input("Enter the word to replace: ")
new_word = input("Enter the new word: ")

# Replace the word
new_sentence = sentence.replace(old_word,new_word)
print("UPDATED SENTENCE:",new_sentence)