#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char input[]);
void decrypt(char input[]);

int main(void)
{
	/* Encryption: l t x a h c b o y e k g v i z w f m j q n p r u s d 
	               a b c d e f g h i j k l m n o p q r s t u v w x y z */
	
	char buffer; // I was having troubles with the input buffer after using fgets or scanf, made this just to clear the buffer when needed to, without affecting the program.
	
	// Asks user for key.
	char key[26] = "The pineapple has grown.";
	char key_input[26];
	
	printf("Insert the key: ");
	fgets(key_input, 25, stdin);
	
	// If the key is wrong, ends the program.
	if (strcmp(key, key_input) != 0)
	{
		printf("\nWrong key.\n");
		return 1;
	}
	
	scanf("%c", &buffer);   // Clears input buffer

	// Asks user if he wants to encrypt, decrypt or quit.
	char choice;
	
	do
	{
		printf("\nDo you want to encrypt [e], decrypt [d] or quit [q]? ");
		scanf("%c", &choice);
		scanf("%c", &buffer);   // Clears input buffer
	}
	while (choice != 'q' && choice != 'e' && choice != 'd');
	
	// If user wants to quit, quit.
	if (choice == 'q')
	{
		return 0;
	}
	
	
	// Gets the text that will be encrypted or decrypted.
	char input_text[501];
	
	printf("\nInsert a text up to 500 characters: ");
	fgets(input_text, 500, stdin);
	
	// If the string is higher than the allowed, ends the program.
	if (strlen(input_text) > 500 || strlen(input_text) < 2)
	{
	    return 2;
	}
	
	// Switch/case to the encryption or decryption.
	switch (choice)
	{
		case 'e':
			encrypt(input_text);
			break;
			
		case 'd':
			decrypt(input_text);
			break;
			
		default:
			return 3;
	}

	system("pause");
}	

// Encryption function.
void encrypt(char input[])
{
	// Takes the lenght of the string, to use as a condition on the for loop.
    int size = strlen(input);
	
	// The encryption (works by substitution).    
    char crypt[] = "ltxahcboyekgvizwfmjqnprusd";
 
    // Main loop for the function.    
    int i;
    for (i = 0; i < size; i++)
    {
    	// If the character isn't an alphabetic character, ignore him and continue to the next character.
        if (!isalpha(input[i]))
        {
            continue;
        }
        
        // Turns the upper cased letters in to lower case. Also keeps track on which letter is upper cased, so it can be returned to its original casing.
        int upper_case_check = 0;
        
        if (!islower(input[i]))
        {
            input[i] = tolower(input[i]);
            upper_case_check = 1;
        }
        
        // Using ascii, subtracts 97 (97 = 'a' in ascii), so that a = 0, b = 1, etc.
        int j = input[i] - 97;
        
        // Switches it to the correct encyphered letter
        input[i] = crypt[j];
        
        // If the letter was upper cased, it will be returned to upper case.
        if (upper_case_check == 1)
        {
            input[i] = toupper(input[i]);
        }
    }
    
    // Prints the text.
	printf("\nCiphertext: %s\n", input);
}

// Decryption function
void decrypt(char input[])
{
	// Takes the lenght of the string, to use as a condition on the for loop.
    int size = strlen(input);
    
    // Has both the correct alphabet order, and the encrypted alphabet.
    char crypt[] =   "ltxahcboyekgvizwfmjqnprusd";
    char decrypt[] = "abcdefghijklmnopqrstuvwxyz";
    
    // Main loop for the function.
    int i = 0;
    for (i = 0; i < size; i++)
    {
    	// If the character isn't an alphabetic character, ignore him and continue to the next character.
        if (!isalpha(input[i]))
        {
            continue;
        }
        
        // Turns the upper cased letters in to lower case. Also keeps track on which letter is upper cased, so it can be returned to its original casing.
        int upper_case_check = 0;
        
        if (!islower(input[i]))
        {
            input[i] = tolower(input[i]);
            upper_case_check = 1;
        }
        
        // Loops through the entire alphabet.
        int j = 0;
        for (j = 0; j < 26; j++)
        {
        	// Checks if the encrypted letters match.
            if (input[i] == crypt[j])
            {
            	// If it matches, switches it to the correct alphabet letter, that is in the same array position.
                input[i] = decrypt[j];
                break;
            }
        }
        
        // If the letter was upper cased, it will be returned to upper case.
        if (upper_case_check == 1)
        {
            input[i] = toupper(input[i]);
        }
    }
    
    // Prints the text.
	printf("\nPlaintext: %s\n", input);
}
