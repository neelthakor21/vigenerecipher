// vigenere cipher....

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str()
{
   char *string, c;
   int j = 0;

   string = (char *)malloc(sizeof(char));

   do
   {
      j++;

      c = getchar();

      string = (char *)realloc(string, j * sizeof(char));

      string[j - 1] = c;

   } while (c != '\n');

   string[j - 1] = '\0';

   return string;
}

char *newkey(char msg[], char key[])
{
   int len = strlen(key);
   int str_len = strlen(msg);
   char *newkey = (char *)malloc(str_len * sizeof(char));
   int i, j;

   for (i = 0, j = 0; i < strlen(msg); i++, j++)
   {
      if (j == strlen(key))
      {
         j = 0;
      }

      newkey[i] = key[j];
   }
   newkey[i] = '\0';

   return newkey;
}

char *encryption(char msg[], char nkey[])
{
   int len = strlen(msg);
   char *cipher_text = (char *)malloc(len * sizeof(char));
   int i;

   for (i = 0; i < len; i++)
   {
      cipher_text[i] = ((msg[i] + nkey[i]) % 26) + 'A';
   }
   cipher_text[i] = '\0';

   return cipher_text;
}

char *decryption(char cipher_text[], char key[])
{
   char *msg = (char *)malloc(strlen(cipher_text) * sizeof(char));
   int i;

   for (i = 0; i < strlen(cipher_text); i++)
   {
      msg[i] = ((cipher_text[i] - key[i] + 26) % 26) + 'A';
   }
   msg[i] = '\0';

   return msg;
}

int main()
{
   int n;
   char *key, *msg, *nkey, *cipher_text;

   printf("Enter your choise : \n 1. encrypt message\n 2. decrypt message\n");
   scanf("%d", &n);

   switch (n)
   {
   case 1:
      printf("Enter the key : ");
      getchar();
      key = str();

      printf("Enter your message : ");
      msg = str();

      nkey = newkey(msg, key);

      cipher_text = encryption(msg, nkey);

      printf("|--------------------------------------------------------------------------|\n");
      printf("            encrypted message : %s\n", cipher_text);
      printf("|--------------------------------------------------------------------------|\n");

      break;

   case 2:
      printf("Enter the cipher text : ");
      getchar();
      cipher_text = str();

      printf("Enter the key : ");
      key = str();

      nkey = newkey(cipher_text, key);

      msg = decryption(cipher_text, nkey);

      printf("|--------------------------------------------------------------------------|\n");
      printf("            decrypted message : %s\n", msg);
      printf("|--------------------------------------------------------------------------|\n");

      break;

   default:
      printf("Enter the proper choise!!!");
      break;
   }
}
