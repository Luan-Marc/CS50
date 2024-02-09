def main():
    text = input("Text: ")
    size = len(text)
    n_letter = count_letter(size, text)
    n_word = count_word(size, text)
    n_sentences = count_sentences(size, text)
    print_grade(n_word, n_sentences, n_letter)


def count_word(size, text):
    word = 1
    for c in range(size):
        if text[c] == ' ':
            word += 1
    return word


def count_sentences(size, text):
    sentence = 0
    for c in range(size):
        if text[c] == '.' or text[c] == '!' or text[c] == '?':
            sentence += 1
    return sentence


def count_letter(size, text):
    letter = 0
    for c in range(size):
        if text[c].isalpha():
            letter += 1
    return letter


def print_grade(word, sentences, letter):
    L = float(letter) / float(word) * 100
    S = float(sentences) / float(word) * 100
    index = 0.0588 * L - 0.296 * S - 15.8

    if index > 16:
        print("Grade 16+")

    elif index < 1:
        print("Before Grade 1")

    else:
        print("Grade ", int(round(index)))


if __name__ == "__main__":
    main()
