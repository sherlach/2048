#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 2048 command line game */

int numbers[4][4];
int slider[4][4];

int i, j, c, k, g;

void display(int inputs[][4]); 

int move(void); 

int checkpair(int move); 

int slide(int move);

void gennew(void);

void gennew(void) {
	
	while (1) {
	j = rand() % 4;
	i = rand() % 4;
	k = rand() % 10;	
	if (numbers[i][j] == 0) {
		if (k < 8)
			numbers[i][j] = 2;
		else
			numbers[i][j] =4;
		break;
		}
	}
}

int main(void) {
	for (i=0;i<4;i++) {
		for (j=0;j<4;j++)
			numbers[i][j]=0;
	}
	gennew(); gennew();
	k=1;
	srand(time(NULL));
	while (1) {
		display(numbers);
		c = move();
		checkpair(c);
		g = slide(c);
		if (g == 0) {
			display(numbers);
			gennew();
		}
	}
	return 0;

}



void display(int inputs[][4]) {
	for (i = 0;i < 4; i++) {
		for (j = 0;j < 4;j++) {
			printf("%4d", inputs[i][j]);	
		}
		printf("\n");
	} printf("\n");	
}



int move(void) {
	k = 1;
while (k == 1) {
	switch (j = getchar()) { 
		case 'h':
		case 'a':
			i = 3; //left
			k = 0;
			break;
		case 'j':
		case 's':
			i = 2; //down
			k = 0;
			break;
		case 'k':
		case 'w':
			i = 4; //up
			k = 0;
			break;
		case 'l':
		case 'd':
			i = 1; //right
			k = 0;
			break;
		case '\n':
			break;
		default:
			printf("Invalid move. Use vim keybindings \n");
			
	} 
}

	return i;
}

int checkpair(int move) {
	//[i][j] is the current square being evaluated, [i][k] is the most recent non-zero in the row
	if (move == 1) { //right
		for (i=0;i<4;i++) {
			k = 4;
			for (j=3; j>=0; j--) {
				if (numbers[i][j] == 0)
					;
				else if (k==4 || numbers[i][j] != numbers[i][k]) { //if we don't have a k, or if there's a new int
					k = j;
				}
				else { // [i][k] = [i][j]
					numbers[i][j] = 0;
					numbers[i][k] *= 2;
					j -= 1;
					k = 4;
				}
			}
				// if [i][k] is equal to the current [i][j], remove [i][j], and double the value in [i][k] 
				// then we want to change k 
				
				// if [i][k] is not equal to the current [i][j], and a relevant [i][k]
		}
	}

	if (move == 3) { //left

		for (i=0;i<4;i++) {
			k = 4;
			for (j=0; j<4; j++) {
				if (numbers[i][j] == 0)
					;
				else if (k == 4 || numbers[i][j] != numbers[i][k] )
					k = j;
				else if (k != 4 && numbers[i][j] == numbers[i][k]) {
					numbers[i][k]=0;
					numbers[i][j] *= 2;
					k = 4;
					}
			}
		}	
	}

	if (move == 2) { //down
		for (j=0;j<4;j++) {
			k = 4;
			for (i=3;i>=0;i--) {
				if (numbers[i][j] == 0)
					;
				else if (k == 4 || numbers[i][j] != numbers[k][j]) 
					k = i;
				else if ( k != 4 && numbers[i][j] == numbers[k][j]) {
					numbers[k][j]=0;
					numbers[i][j] *= 2;
					k = 4;
				}
			} 
		} 	
	} 

	if (move == 4) { //up
		for (j=0;j<4;j++) {
			k = 4;
			for (i=0;i<4;i++) {
				if (numbers[i][j] == 0)
					;
				else if (k == 4 || numbers[i][j] != numbers[k][j])
					k = i;
				else if (numbers[i][j] == numbers[k][j]) {
					numbers[k][j]=0;
					numbers[i][j] *= 2;
					k = 4;
				}
			}
		}
	}
}

int slide(int move) {
	c = 1;
	for (i=0;i<4;i++) {
		for (j=0;j<4;j++) {
			slider[i][j] = numbers[i][j];
			numbers[i][j] = 0;
		}
	}

	if ( move == 1 ) { //right
		for (i=0;i<4;i++) {
			k = 3;
			for (j=3;j>=0;j--) {
				if (slider[i][j] != 0) {
					numbers[i][k] = slider[i][j];
					k--;
					c = 0;
				}	
			}
		}

	}
	
	if (move == 2) { //down
		for (j=0;j<4;j++) {
			k = 3;
			for (i=3;i>=0;i--) {
				if (slider[i][j] != 0) {
					numbers[k][j] = slider[i][j];
					k--;
					c = 0;
				}
			}
		}
	
	}
	
	if (move == 3) { //left
		for (i=0;i<4;i++) {
			k = 0;
			for (j=0;j<4;j++) {
				if (slider[i][j] != 0) {
					numbers[i][k] = slider[i][j];
					k++;
					c = 0;
				}
			
			}
		
		}
	
	}

	if (move == 4) { //up
		for (j=0;j<4;j++) {
			k = 0;
			for (i=0;i<4;i++) {
				if (slider[i][j] != 0) {
					numbers[k][j] = slider[i][j];
					k++;
					c = 0;
				}
			
			}	
		}	
	}

	return c;
}

