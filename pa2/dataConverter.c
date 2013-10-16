#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "dataConverter.h"

#define MAX 1000

int main(int argc, char *argv[]) {

	if (argc > 4 || argc < 4) {
		printHelp();
		return 0;
	}


	if (argv[1][0] == '-') {
	    /* Use the next character to decide what to do. */
		if (argv[1][1] == 'b') {
			if (argv[3][1] == 'd') {
				bin2dec(argv[2]);   
			}
			else if(argv[3][1] == 'h') {
				bin2hex(argv[2]);

			}
			else if(argv[3][1] == 'o') {
				bin2oct(argv[2]);
			}
			else {
				printHelp();
			}
		}
		else if (argv[1][1] == 'd') {
			if (argv[3][1] == 'b') {
				dec2bin(argv[2]);   
			}
			else if(argv[3][1] == 'h') {
				dec2hex(argv[2]);

			}
			else if(argv[3][1] == 'o') {
				dec2oct(argv[2]);
			}
			else {
				printHelp();
			}
		}
		else if (argv[1][1] == 'h') {
			if (argv[3][1] == 'd') {
				hex2dec(argv[2]);
			}
			else if(argv[3][1] == 'b') {
				hex2bin(argv[2]);

			}
			else if(argv[3][1] == 'o') {
				hex2oct(argv[2]);
			}
			else {
				printHelp();
			}	
		}
		else if (argv[1][1] == 'o') {
			if (argv[3][1] == 'd') {
				oct2dec(argv[2]);
			}
			else if(argv[3][1] == 'b') {
				oct2bin(argv[2]);

			}
			else if(argv[3][1] == 'h') {
				oct2hex(argv[2]);
			}
			else {
				printHelp();
			}
		}
		else {
			printHelp();
		}
	}
	else {
		printHelp();
	}

	return 0;
}

void printHelp() {
	printf("\nError - argument(s) not recognized.\n");
	printf("\nHelp\n");
	printf("----\n");
	printf("\nUsage: dataConverter -input data -output\n\n");
	printf("Input/Output Types:\n");
	printf("-b : Binary\n");
	printf("-d : Decimal\n");
	printf("-h : Hexadecimal\n");
	printf("-o : Octal\n\n");
	return;
}

void bin2dec(char *bin) {

	int len =  strlen(bin);
	long long int sum = 0;
	for(int i=0; i<len; i++) {
	    int n = bin[i] - '0'; // numerical val of bin[i] 0 or 1
	      // check for a valid binary digit

	    if(n<0 || n>1) {
	    	if (bin[i] == '.') {
	    	}
	    	else {
	    		printf("\nError - invalid binary data.\n\n");
	    		return;	    		
	    	}

	    }

	    int pv=1;
	      for(int j=len; j>i+1; j--) // place value reversed
	      	pv *=2;
	      // sum it
	      sum += n*pv;
	  }	

	  printf("\n%s in decimal is %lli\n\n", bin, sum);

	  return;
	}

	void bin2hex(char* bin) {

		char hexaDecimal[1000];
		int temp;
		long int i=0,j=0;

		while(bin[i]){
			bin[i] = bin[i] -48;
			++i;
		}

		--i;
		while(i-2>=0){
			temp =  bin[i-3] *8 + bin[i-2] *4 +  bin[i-1] *2 + bin[i] ;
			if(temp > 9)
				hexaDecimal[j++] = temp + 55;
			else
				hexaDecimal[j++] = temp + 48;
			i=i-4;
		}

		if(i ==1)
			hexaDecimal[j] = bin[i-1] *2 + bin[i] + 48 ;
		else if(i==0)
			hexaDecimal[j] =  bin[i] + 48 ;
		else
			--j;

		printf("Hexadecimal: ");
		while(j>=0){
			printf("%c",hexaDecimal[j--]);
		}
		printf("\n\n");
	}

	void bin2oct(char* bin) {

		long int i=0, j=0;
		char octalNumber[MAX];
		while(bin[i]){
			if (bin[i] == '0' || bin[i] == '1'){
				bin[i] = bin[i] -48;
				++i;
			}
			else {
				printf("Error - not correct binary format.\n\n");
				return;
			}

		}

		--i;
		while(i-2>=0){
			octalNumber[j++] = bin[i-2] *4 +  bin[i-1] *2 + bin[i] ;
			i=i-3;
		}

		if(i ==1)
			octalNumber[j] = bin[i-1] *2 + bin[i] ;
		else if(i==0)
			octalNumber[j] =  bin[i] ;
		else
			--j;

		printf("Equivalent octal value: ");
		while(j>=0){
			printf("%d",octalNumber[j--]);
		}

		printf("\n\n");

		return;
	}

	int fnStringtoInt(char *cString){
		int nValue=0;
		while(*cString != 0)
		{
			nValue = (nValue*10)+(*cString-'0');
			cString++;
		}
		return nValue;
	}



	void hex2bin(char *hex) {

		int i;

		printf("Binary= ");
		for(i=0;hex[i]!=0;i++)
		{
			switch(hex[i])
			{
				case '0':
				printf("0000");
				break;
				case '1':
				printf("0001");
				break;
				case '2':
				printf("0010");
				break;
				case '3':
				printf("0011");
				break;
				case '4':
				printf("0100");
				break;
				case '5':
				printf("0101");
				break;
				case '6':
				printf("0110");
				break;
				case '7':
				printf("0111");
				break;
				case '8':
				printf("1000");
				break;
				case '9':
				printf("1001");
				break;
				case 'a':
				case 'A':
				printf("1010");
				break;
				case 'b':
				case 'B':
				printf("1011");
				break;
				case 'c':
				case 'C':
				printf("1100");
				break;
				case 'd':
				case 'D':
				printf("1101");
				break;
				case 'e':
				case 'E':
				printf("1110");
				break;
				case 'f':
				case 'F':
				printf("1111");
				break;
				default:
				printf("Number Is Not Hexadecimal");
				break;
			}
		}

		printf("\n\n");


		return;
	}

	void hex2dec(char *hex){

char *ptr;//pointer to char
int value = 0; // the value of the current hex char pointed to
int sum = 0;// the running sum
int power = -1;//power is what base 16 is raised to starts at -1 to count for 0

ptr = hex;//set the pointer to point at start of string ie 0xabcd

while(*ptr != (char)NULL)//while pointer is not null count a new char
{
	ptr++;
	power++;
}

ptr = &hex[0];

while(*ptr != (char)NULL)//while pointer is not equal to null
{
	switch(*ptr)
	{
		case '0': value = 0; break;
		case '1': value = 1; break;
		case '2': value = 2; break;
		case '3': value = 3; break;
		case '4': value = 4; break;
		case '5': value = 5; break;
		case '6': value = 6; break;
		case '7': value = 7; break;
		case '8': value = 8; break;
		case '9': value = 9; break;
		case 'a': value = 10; break;
		case 'b': value = 11; break;
		case 'c': value = 12; break;
		case 'd': value = 13; break;
		case 'e': value = 14; break;
		case 'f': value = 15; break;
		case 'A': value = 10; break;
		case 'B': value = 11; break;
		case 'C': value = 12; break;
		case 'D': value = 13; break;
		case 'E': value = 14; break;
		case 'F': value = 15; break;
		default: printf("Input Error: not 0-9 or a-f.\n\n"); return;
	}

sum += pow(16,power)*value;//this calculates the total until pointer points to null
ptr++;//moves the pointer along to the next char
power--;//decrements the power

}
printf("\nDecimal: %i \n", sum);
printf("\n");
return;
}

void hex2oct(char *hex) {

	int count;
	char bin[100];
	//convert hex to binary first
	for(count=0;hex[count]!=0;count++)
	{
		switch(hex[count])
		{
			case '0':
			strcat(bin, "0000");
			break;
			case '1':
			strcat(bin, "0001");
			break;
			case '2':
			strcat(bin, "0010");
			break;
			case '3':
			strcat(bin, "0011");
			break;
			case '4':
			strcat(bin, "0100");
			break;
			case '5':
			strcat(bin, "0101");
			break;
			case '6':
			strcat(bin, "0110");
			break;
			case '7':
			strcat(bin, "0111");
			break;
			case '8':
			strcat(bin, "1000");
			break;
			case '9':
			strcat(bin, "1001");
			break;
			case 'a':
			case 'A':
			strcat(bin, "1010");
			break;
			case 'b':
			case 'B':
			strcat(bin, "1011");
			break;
			case 'c':
			case 'C':
			strcat(bin, "1100");
			break;
			case 'd':
			case 'D':
			strcat(bin, "1101");
			break;
			case 'e':
			case 'E':
			strcat(bin, "1110");
			break;
			case 'f':
			case 'F':
			strcat(bin, "1111");
			break;
			default:
			printf("Number Is Not Hexadecimal");
			break;
		}
	}

	//Convert binary to octal
	long int i=0, j=0;
	char octalNumber[MAX];
	while(bin[i]){
		bin[i] = bin[i] -48;
		++i;
	}

	--i;
	while(i-2>=0){
		octalNumber[j++] = bin[i-2] *4 +  bin[i-1] *2 + bin[i] ;
		i=i-3;
	}

	if(i ==1)
		octalNumber[j] = bin[i-1] *2 + bin[i] ;
	else if(i==0)
		octalNumber[j] =  bin[i] ;
	else
		--j;

	printf("Equivalent octal value: ");
	while(j>=0){
		printf("%d",octalNumber[j--]);
	}

	printf("\n\n");

	return;

}




void oct2bin(char* bin) {
	char octalNumber[MAX];
	long int i=0;

	printf("Equivalent binary value: ");
	while(bin[i]){
		switch(bin[i]){
			case '0': printf("000"); break;
			case '1': printf("001"); break;
			case '2': printf("010"); break;
			case '3': printf("011"); break;
			case '4': printf("100"); break;
			case '5': printf("101"); break;
			case '6': printf("110"); break;
			case '7': printf("111"); break;
			default:  printf("\nInvalid octal digit %c ",octalNumber[i]); return;
		}
		i++;
	}
	printf("\n\n");
	return;
}


void oct2dec(char* bin){

	long digit, result=0, place=1, dec;
	long oct = fnStringtoInt(bin);
	while(oct!=0) {
		digit = oct % 10;
		if(digit>7) {
			printf("Incorrect input.\n\n");
			return; 
		}
		oct = oct/10;
		result += digit * place;
		place *= 8;
	}
	dec = result;
	printf("Octal %s in decimal: %li\n\n", bin, dec);
	return;

}

void oct2hex(char* bin) {

	unsigned long n,i=0,a,p=1;
	for (int i = 0; i < strlen(bin); i++) {
		if (bin[i] >='0' && bin[i]<='8') {

		}
		else {
			printf("Number entered is not octal.\n\n");
			return;
		}
	}
	n = fnStringtoInt(bin);
	i=0;
	while(n!=0) {
		a=n%10;
		n=n/10;
		i=i+a*p;
		p=p*8;
	}

	printf("Hexadecimal = %lu\n\n", i);

	return;
}


void dec2bin(char* bin) {
	showbits(fnStringtoInt(bin));
	printf("\n\n");

	return;
}

void showbits(int h) {
	if(h==1)
		printf("%i",h);
	else
	{
		showbits(h/2);
		printf("%i",h%2);
	}
}

void dec2oct(char* bin) {
	int num = fnStringtoInt(bin);
	print_oct(num);
	printf("\n");
	return;
}

void print_oct(int n) {
	if (n != 0) {
		print_oct(n / 8);
		printf("%i", n % 8);
	}
}


void dec2hex(char* bin) {

	char hex[17]={"0123456789ABCDEF"};
	int i=0,j;
	char result[1000];

	long long int num = fnStringtoInt(bin);

	while(num)
	{
		result[i]=hex[num%16];
		num=num=num/16;
		i++;
	}
	printf("Decimal: ");
	for(j=i-1;j>=0;j--)
		printf("%c",result[j]);
	printf("\n\n");

	return;
}