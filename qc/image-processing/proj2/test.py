#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri May 17 23:01:06 2019

@author: kanthonye
"""
import numpy as np

def InsertionSort(arr, size):
    
    b = 0
    j = 1
    i = 1
    while (i < size):
        
        j = i;
        if (arr[j,2] < arr[j-1,2]):
            
            b = arr[j,2];
            while (b < arr[j-1,2] and j > 0):
        
                q          = arr[j,  0];
                arr[j,  0] = arr[j-1,0];
                arr[j-1,0] = q;
                q          = arr[j,  1];
                arr[j,  1] = arr[j-1,1];
                arr[j-1,1] = q;
                q          = arr[j,  2];
                arr[j,  2] = arr[j-1,2];
                arr[j-1,2] = q;
                
                j = j - 1;
                
            arr[j,2] = b;
            
        i = i + 1;

  
# Driver code to test above     
arr = np.zeros( [8, 3], int )
arr[0,0] = 7
arr[0,2] = 7

arr[1,0] = 9
arr[1,2] = 9

arr[2,0] = 5
arr[2,2] = 5

arr[3,0] = 4
arr[3,2] = 4

arr[4,0] = 8
arr[4,2] = 8

arr[5,0] = 1
arr[5,2] = 1

arr[6,0] = 3
arr[6,2] = 3

arr[7,0] = 2
arr[7,2] = 2

n = len(arr) 
InsertionSort(arr, n) 

print ("Sorted array is:") 
for i in range(n): 
    print ("%d" %arr[i,2])