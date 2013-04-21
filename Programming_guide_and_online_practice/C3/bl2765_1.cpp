#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
  char octal[17];
  double decimal;
  int i;
  while(scanf("%s",octal)!=EOF)
  {
    decimal = 0.0;
    for( i=2 ; octal[i]!='\0' ; i++ )
    {
      decimal += (double)(octal[i]-'0')*pow(0.125,(i-1));
    }
    printf("%s [8] = %.45g [10]\n",octal,decimal);
  } 

  system("PAUSE");  
  return 0;
}

