#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May  4 15:50:45 2019

@author: K. Anthony E. (kanthonye)
"""
import cv2
import hw2lib as hw2

img = cv2.imread('q1-underexposed.jpg')

gimg = hw2.GrayScale(img)
cv2.imwrite('q1-gray-underexposed.jpg', gimg)
hw2.ShowHisto(gimg)

gimg = hw2.ApplyGamma(gimg, 2.2)
cv2.imwrite('q1-gamma-underexposed.jpg', gimg)
hw2.ShowHisto(gimg)