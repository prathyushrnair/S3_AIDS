def analyze_file(filename):
    vowels = "aeiouAEIOU"
    num_vowels = 0
    num_upper = 0
    num_lower = 0
    num_sentences = 0
    num_special = 0
    num_digits = 0
    num_words = 0

    with open(filename, "r") as file:
        text = file.read()
        num_words = len(text.split())  # Simple word count

        for char in text:
            if char in vowels:
                num_vowels += 1
            if char.isupper():
                num_upper += 1
            if char.islower():
                num_lower += 1
            if char in ".!?":
                num_sentences += 1
            if not char.isalnum() and not char.isspace():
                num_special += 1
            if char.isdigit():
                num_digits += 1

    print("Vowels:", num_vowels)
    print("Uppercase letters:", num_upper)
    print("Lowercase letters:", num_lower)
    print("Sentences:", num_sentences)
    print("Special characters:", num_special)
    print("Digits:", num_digits)
    print("Words:", num_words)


# Example usage
analyze_file("yourfile.txt")
