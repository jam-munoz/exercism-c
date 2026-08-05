#include "scrabble_score.h"

unsigned int score(const char *word)
{
	unsigned int score = 0;

	for (int i = 0; word[i]; i++)
	{
		switch(word[i])
		{
			case 'q': case 'Q': case 'z': case 'Z': score += 10;
				break;
			case 'j': case 'J': case 'x': case 'X': score += 8;
				break;
			case 'k': case 'K': score += 5;
				break;
			case 'f': case 'F': case 'h': case 'H': case 'v': case 'V': case 'w': case 'W': case 'y': case 'Y': score += 4;
				break;
			case 'b': case 'B': case 'c': case 'C': case 'm': case 'M': case 'p': case 'P':  score += 3;
				break;
			case 'd': case 'D': case 'g': case 'G': score += 2;
				break;
			case 'a': case 'A': case 'e': case 'E': case 'i': case 'I': case 'o': case 'O': case 'u': case 'U': case 'l': case 'L': case 'n': case 'N': case 'r': case 'R': case 's': case 'S': case 't': case 'T': score += 1;
				break;
			default:
				break;
		}
	}
	return score;
}

