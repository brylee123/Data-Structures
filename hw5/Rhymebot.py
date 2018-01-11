
dictionary = {}
phraseDictionary = {}

# =====================================================================================
# Parsing Dictionary

parsingDictionary = open("pronunciationDictionary/cmudict-0.7b", "r")
data = parsingDictionary.read()

for line in data.split("\n"):
    # print(line)
    if line[0:3] == ";;;":
        continue
    dict = line.split("  ")
    wordName = dict[0]
    wordPro = str(dict[1:])
    wordPro = wordPro[2:-2]

    if wordPro.find(" ", 0, len(wordPro)) != -1:  # Multi-syllable words
        dict[1] = [None]*len(wordPro.split(" "))
        index = 0
        for syl in wordPro.split(" "):
            dict[1][index] = str(syl)
            index += 1
            continue
        # print("WORD: ", wordName)
        # print("PRO : ", dict[1])
        dictionary[wordName] = dict[1]

    elif wordPro.find(" ", 0, len(wordPro)) == -1:  # SINGLE-syllable words
        # print("WORD: ",wordName)
        # print("PRO : ", dict[1])
        dictionary[wordName] = dict[1]

        continue

    if line[0:3] == "}RI":  # To ensure no lines after }RIGHT-BRACE
        print("Reached end of line")
        break

# print(dictionary)

# =====================================================================================
# Parsing Phrases

parsingPhrases = open("pronunciationDictionary/phrases.txt", "r")
data = parsingPhrases.read()

for line in data.split("\n"):
    if line.find(" ", 0, len(line)) > 0:
        for word in line.split(" "):
            phrase = line.split(" ")
        # print("First word:", phrase)  # phrase has all the words
        # print(len(line)) # Number of chars
        # print(len(phrase)) # Number of words
        phraseDictionary[line] = phrase, line

    if line[0:13] == "incisive hour":  # To ensure no lines after "incisive hour"
        # print("Reached end of line")
        break

    # print(phrase)

print(phraseDictionary)

for keys,values in phraseDictionary.items():
    #print(keys)
    continue
# =====================================================================================
# Comparing Individual Words in Phrases with Dictionary

'''
wordList = ['aydt', 'coombs', 'schuhmacher', 'claypoole', 'exhume', 'forehands', 'carin', 'plaits', 'alfonsin', 'hometowns', 'pedestals', 'emad', 'hourly', 'purchaser', 'spogli', 'combativeness', 'henningsen', 'luedke', 'duchin', 'koglin', 'teason', 'bumpings', 'substantially', 'lamendola', 'cecola', 'henze', 'tutti', 'dills', 'satirical', 'jetted', 'intertwine', 'predict', 'breezes', 'cyclist', 'ancillary', 'schaumburg', 'viewer', "bay's", 'emissions', 'kincheloe', 'trees', 'vipperman', 'exhale', 'ornamental', 'repeated']

inputWord = 'foreshadow'

longestPrefix = 0
bestWord = ''

for word in wordList:
    index = 0
    while word[index] == inputWord[index] and index < len(word) and index < len(inputWord):
        index += 1
    if index > longestPrefix:
        longestPrefix = index
        bestWord = word

print(bestWord)
'''