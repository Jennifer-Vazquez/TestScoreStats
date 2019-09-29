/*
 ============================================================================
 Name        : JVazquezTestScoreStats.c
 Author      : Jennifer Vazquez
 Version     :
 Copyright   : 
 Description : Test Score Stats ; Asks user to insert scores and once the user presses <ENTER>
 then a statement is printed with the number of scores, the minimum, the maximum, the average,
 and the standard deviation
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); /*turns off output buffering*/

	int count = 0;
	float score = 0.0;
	float min = 1000000;
	float max = 0.0;
	float average, standardDeviation, sum, sumSquares;

	char text[BUFSIZ];
	puts(
					"Enter scores, one per line. Press <ENTER> on a blank line to end ");
	do {

		fgets(text, BUFSIZ, stdin);
		score = atof(text);
		if (text[0] != '\n') { /*if the user did not just press <ENTER> then execute the block of text*/
			sum += score;
			sumSquares += (score * score);
			count++;

			if (score > max) { /*if the current score the user inputed is more than the current max, set max to current score */
				max = score;
			}
			if (score < min) {/*if the current score the user inputed is less than the current min, set min to current score */
				min = score;
			}
		}
	} while (text[0] != '\n'); /*keep waiting for a score if the user did not press <ENTER>*/

	if (count > 0) { /*if the count is more than 0 then do the average and standard deviation or else it will make the equations undefined*/
		standardDeviation = sqrt((sumSquares - ((sum * sum) / count)) / count);
		average = sum / count;
	} else { /*set min to 0 if the count is 0 because we set min to a bigger number at the beginning*/
		min = 0;
	}
	printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t", count, min, max, average,
			standardDeviation);

	return EXIT_SUCCESS;
}
