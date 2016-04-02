/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (!arr || len < 3) {
		return NULL;
	}
	int ap1s = -1;
	int ap1e = -1;
	int ap2s = -1;
	int ap2e = -1;
	int gps = -1;
	int gpe = -1;
	int pd = -1;
	int cd;
	int count = 0;
	int i;
	for (i = 0; i < len - 1; i++) {
		cd = arr[i + 1] - arr[i];
		if (pd == cd) {
			if (ap1s == -1) {
				ap1s = i-1;
			}
			if (ap1s != -1 && ap1e != -1) {
				ap2s = i - 1;
			}
			if (gps != -1) {
				gpe = i;
			}
			count = 0;
		}
		else {
			pd = cd;
			if (ap1s != -1 && ap1e == -1) {
				ap1e = i;
			}
			if (ap2s != -1 && ap2e == -1) {
				ap2e = i;
			}
			count++;
			if (count == 2 && gps == -1) {
				gps = i - 1;
			}
		}
	}
	int final_arr[] = { ap1s, ap1e, ap2s, ap2e, gps, gpe };
	return 0;
}