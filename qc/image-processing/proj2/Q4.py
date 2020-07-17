#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May 18 00:02:21 2019

@author: kanthonye
"""
import cv2
import numpy as np
from matplotlib import pyplot as plt
    
img = cv2.imread('q2-eql_hist-overexposed.jpg')
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
blr = cv2.GaussianBlur(img, (3,3), -10) # remove noise

cv2.imwrite('q4-spatial_filtering.jpg', blr)

#lap = cv2.Laplacian(blr, cv2.CV_64F) # convolute 

sob = cv2.Sobel(blr, cv2.CV_64F, 1, 1, ksize=3)
cv2.imwrite('q4-first_order_derivative.jpg', sob)

sob = cv2.Sobel(sob, cv2.CV_64F, 1, 1, ksize=3)
cv2.imwrite('q4-second_order_derivative.jpg', sob)

sob = cv2.convertScaleAbs(sob)
srp = cv2.addWeighted(sob, 1.5, sob, -0.75, 0) # unshapen 

cv2.imwrite('q4-unshapen.jpg', srp)