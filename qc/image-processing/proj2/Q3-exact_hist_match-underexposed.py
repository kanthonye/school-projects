#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May 11 01:00:18 2019

@author: kanthonye
"""
import numpy as np
import hw2lib as hw2
import cv2

img  = cv2.imread('q1-gamma-underexposed.jpg')

hist = np.zeros( [256], int )
for n in range( 256 ): 
    hist[n] = n
    
hw2.ShowHisto( hist )

himg = hw2.HistMatch( img, hist )
hw2.ShowHisto( himg )
cv2.imwrite('q3-hist_match-overexposed.jpg', himg)