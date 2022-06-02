#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int GetGCD();
int GetMultInv(int);
int main()
{
 int i,j,k,gcd,lamda,choice,K,numstr[100],numcipher[100],alphaInverse;
 char str[100],cipher[100];
 printf("\n   *******WELCOME TO THE AFFINE CYPHER CALCULATOR*************\n   This CALCULATOR works according to the equation Y = (lamda*X + K)mod26\n");
 while(1){
     printf("   What do you want\n   Enter 1 for Encryption\n   Enter 2 for decryption\n   -->");
scanf("%d",&choice);
if(choice==1){
    printf("   Enter the plain text:  \n   --> ");
    while ((getchar()) != '\n');
    fgets(str, 100, stdin);
    break;
}
if(choice==2){
    printf("   Enter the Encoded text:  \n   --> ");
    while ((getchar()) != '\n');
    fgets(str, 100, stdin);
    break;
}
else{
    printf("   ERROR!!! Please Enter a valid number\n");
    continue;}
 }
 
 //converting entered string to Capital letters
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);   
   j++;
  }
  else
  {
   str[j]=' ';
   j++;
  }
 }
 str[j]='\0';
 printf("   Entered string is : %s \n",str);
 while(1){
     printf("   Enter the value of lamda\n   -->");
 scanf("%d",&lamda); 
 
 //Checking for satifactory conditions
 if(lamda<1 || lamda>25)
 {
  printf("   Alpha should lie in between 1 and 25\n   Sorry Try again !\n");
  continue;
 } 
 gcd=GetGCD(lamda, 26);
 if(gcd!=1)
 {
  printf("   ERROR!!! lamda and 26 must be coprime\n");
   continue;
 }
 printf("   Enter the value of K\n   -->");
 scanf("%d",&K);
 if(K<0 || K>25)
 {
  printf("   k should lie between 0 and 25\n   Sorry Try again !\n");
  continue;
 }
 if(GetGCD(lamda, k)!=1){
     printf("   ERROR!!!1... lamda and K must be coprime!!! try again\n");
     continue;
 }
 else{
     break;
 }
 }

 //comverting string to ascii and to restoring spaces
 for(i=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  numstr[i]=str[i]-'A';
  else
  numstr[i]=-20;
 }
  //Encryption Process
 if(choice==1){
    printf("   Affine Cipher text is\n");   
    for(i=0;i<strlen(str);i++)
    {
     if(numstr[i]!=-20)
     {
     numcipher[i]=((lamda*numstr[i])+K)%26;
     printf("%c",(numcipher[i]+'A'));         
     }
     else
     {
          printf(" ");      
     }
    }
printf("\n");
 }
  //Deciphering 
if(choice==2){
 alphaInverse=GetMultInv(lamda);
    printf("   Affine plain text is\n");   
    for(i=0;i<strlen(str);i++)
    {
     if(numstr[i]!=-20)
     {
     numcipher[i]=(alphaInverse*(numstr[i]-K))%26;
     if(numcipher[i]<0)
     {
      numcipher[i]=numcipher[i]+26;//To avoid negative numbers
     }
          printf("%c",(numcipher[i]+'A'));         
     }
     else
     {
          printf(" ");      
     }
    }
printf("\n");
}
 
 
}
//function to calculate gcd
int GetGCD(int a, int b)
{
 int x;
   int temp1=a;
   int temp2=b;

     while(temp2!=0)
      {
        x=temp2;
        temp2=temp1%temp2;
        temp1=x;
      }
     return(temp1);
}

int GetMultInv(int lamda)
{
    int i,MI;
 for(i=1;i<=lamda;i++)
 {
  MI=((i*26)+1);
  if(MI%lamda==0)
  {
   break;
  }
 }
 MI=MI/lamda;
 return(MI);
}
