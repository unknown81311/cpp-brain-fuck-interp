#include <stdio.h>
#include <Windows.h>
#include <string.h>



int main() {
	printf( "what is the BF? " );
	
	char bf[10000];

	scanf( "%s", bf );

	unsigned char bfArray[10000];
	int bfPointer=0;

	int bfFoundBrackets[10000];
	int bfCurrentBracket=0;
	int i=0;

	while( i < strlen(bf) ){
		char current = bf[i];

		switch(current){
			case '+':{
				bfArray[bfPointer]++;
				break;
			}
			case '-':{
				bfArray[bfPointer]--;
				break;
			}
			case '.':{
				printf("%c", bfArray[bfPointer]);
				break;
			}
			case ',':{
				scanf( "%c", &bfArray[bfPointer]);
				break;
			}
			case '<':{
				bfPointer--;
				break;
			}
			case '>':{
				bfPointer++;
				break;
			}
			case '[':{
				bfCurrentBracket++;
				bfFoundBrackets[bfCurrentBracket] = i;
				break;
			}
			case ']':{
				if(bfArray[bfPointer]==0){
					bfCurrentBracket--;
				}else{
					i=bfFoundBrackets[bfCurrentBracket]-1;
				}
				break;
			}
		}

		i++;
	}

	return 0;
}
