#include<stdio.h>
#include<string.h>

void strMerge(const char *s1, const char *s2, char *output)
{
printf("string1 is %s\n", s1);
printf("string2 is %s\n", s2);
while (*s1 != '\0' && *s2 != '\0')
{*output++= *s1++;
*output++ = *s2++;
}
while (*s1 != '\0')
*output++=*s1++;
while (*s2 != '\0')
*output++ = *s2++;
*output='\0';
}
int main()
{
char *str1="abcdefg";
char *str2="1234";
char *output=malloc(strlen(str1)+strlen(str2)+1);
strMerge(str1,str2,output);
printf("%s",output);
return 0;
}
