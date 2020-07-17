#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Apr  5 11:26:37 2019

@author: kanthonye
"""
from KAE_CS381_HW1 import GenerateHistogram
import cv2

img = cv2.imread('under-expose.jpg')
histo = GenerateHistogram(img)

for i in range(256):
    print(str(histo[3][i]))