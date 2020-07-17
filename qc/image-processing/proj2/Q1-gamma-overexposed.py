#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May  4 15:50:45 2019

@author: K. Anthony E. (kanthonye)
"""
import cv2
import hw2lib as hw2

img = cv2.imread('q1-overexposed.jpg')

gimg = hw2.GrayScale(img)
cv2.imwrite('q1-gray-overexposed.jpg', gimg)
hw2.ShowHisto(gimg);

gimg = hw2.ApplyGamma(gimg, 0.165)
cv2.imwrite('q1-gamma-overexposed.jpg', gimg)
hw2.ShowHisto(gimg);
