#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

//methods
void encrypt(string, string);
void decrypt(string, string);

int main(int argc, char* argv[])
{
  //variables
  string key = argv[2];
  string input;
  string newkey; //key without spaces

  for (int j = 0; j<key.length(); j++)
  {
      //check each char. if not a space, add it to newkey and make lowercase
      if(key[j] != ' ')
        newkey += tolower(key[j]);
  }
  while (1)
  {
      getline(cin, input);

      //parse command line
      if(!strcmp(argv[1], "-e"))
      {
        encrypt(input, newkey);
      }
      else if (!strcmp(argv[1], "-d"))
      {
        decrypt(input, newkey);
      }
  }
}

void encrypt(string input, string newkey)
{
  char encryption;
  int plaintext;
  int keytext;
  int keypos=0;

  //do this for each letter of input
  for(int i = 0; i < input.length(); i++)
  {
    //convert each letter in key to num 0-25, start key over when you get to the end
    keytext = newkey[keypos%newkey.length()];
    keytext = keytext - 'a';

    //check if lowercase
    if(input[i] >= 'a' && input[i] <= 'z')
    {
      //convert each letter in input to num 0-25
      plaintext = (int) input[i] - 'a';

      //change the plaintext letter to the new encrypted letter
      encryption = (char)(plaintext + keytext) % 26 + 97;

      //look at the next char in the key
      keypos++;
    }
    //check if uppercase
    else if (input[i] >= 'A' && input[i] <= 'Z')
    {
      //convert each letter to 0-25
      plaintext = (int) input[i] - 'A';

      //change plaintext to encrypted
      encryption = (char)(plaintext + keytext) % 26 + 65;

      //look at next char in key
      keypos++;
    }
    else
    {
      //if it's not a letter, print out whatever it is without doing anything
      //don't look at next letter in key
      encryption = input[i];
    }

    //print each character
    cout << encryption;
  }
  cout << "\n";
}

void decrypt(string input, string newkey)
{
  char decryption;
  int plaintext;
  int keytext;
  int keypos=0;

  //do this for each letter of input
  for(int i = 0; i < input.length(); i++)
  {
    //convert each letter in key to num 1-26, start key over when you get to the end
    keytext = newkey[keypos%newkey.length()];
    keytext = keytext - 'a';

    //check if lowercase
    if(input[i] >= 'a' && input[i] <= 'z')
    {
      //turn each letter into num 0-25
      plaintext = (int) input[i] - 'a';

      //use key to decrypt each letter, add 26 to avoid negative nums
      decryption = (char)(plaintext - keytext + 26) % 26 + 97;

      //look at next char in key
      keypos++;
    }

    //check if uppercase
    else if (input[i] >= 'A' && input[i] <= 'Z')
    {
      //turn letters into 0-25
      plaintext = (int) input[i] - 'A';

      //use key to decrypt, add 26 to avoid negative nums
      decryption = (char)(plaintext - keytext + 26) % 26 + 65;

      //look at next letter in key
      keypos++;
    }
    else
    {
      //if not a letter, print it
      //don't look at next letter in key
      decryption = input[i];
    }

    //print each decrypted character
    cout << decryption;
  }
  cout << "\n";
}
