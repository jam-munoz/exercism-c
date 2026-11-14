def find_anagrams(word, candidates):
    lst = []
    word = word.casefold()
    sorted_word = sorted(word)
    for i in range(len(candidates)):
        if candidates[i].casefold() != word:
            if sorted(candidates[i].casefold()) == sorted_word:
                lst.append(candidates[i])
    return lst
