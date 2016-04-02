/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	int count1, count2, leap, year1, month1, day1, year2, month2, day2, temp = 0, res = 0;
	struct node *temp1 = date1head;
	if (date1head == NULL || date2head == NULL){
		return -1;
	}
	//temp1->data = 0;

	while (temp <= 8 && temp1->next != NULL){
		temp++;
		if (temp == 5){
			year1 = temp1->data;
		}
		if (temp >= 5){
			year1 = (year1)* 10 + temp1->next->data;

		}
		temp1 = temp1->next;
	}


	//temp1 = NULL;
	temp1 = date2head, temp = 0;
	while (temp <= 8 && temp1->next != NULL){
		temp++;
		if (temp == 5){
			year2 = temp1->data;
		}
		if (temp >= 5){
			year2 = (year2)* 10 + temp1->next->data;

		}
		temp1 = temp1->next;

	}

	temp1 = date1head;
	temp = 0;
	while (temp <= 4){
		temp++;
		if (temp == 3){
			month1 = temp1->data;
		}
		if (temp >= 3 && temp<4){
			month1 = (month1)* 10 + temp1->next->data;

		}
		temp1 = temp1->next;

	}


	temp1 = date2head;
	temp = 0;
	while (temp <= 4){
		temp++;
		if (temp == 3){
			month2 = temp1->data;
		}
		if (temp >= 3 && temp <4){
			month2 = (month2)* 10 + temp1->next->data;

		}
		temp1 = temp1->next;

	}

	temp1 = date1head;
	temp = 0;
	while (temp <= 2){
		temp++;
		if (temp == 1){
			day1 = temp1->data;
		};
		if (temp >= 1 && temp < 2){
			day1 = (day1)* 10 + temp1->next->data;

		}
		temp1 = temp1->next;

	}


	temp1 = date2head;
	temp = 0;
	while (temp <= 2){
		temp++;
		if (temp == 1){
			day2 = temp1->data;
		}
		if (temp >= 1 && temp<2){
			day2 = (day2)* 10 + temp1->next->data;

		}
		temp1 = temp1->next;

	}

	count1 = (year1 * 365) + (month1 * 31) + (day1);
	count2 = (year2 * 365) + (month2 * 31) + (day2);

	res = count2 - count1;
	return res-1;




	//return -1;
}