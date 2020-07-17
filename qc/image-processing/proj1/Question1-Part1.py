# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
from KAE_CS381_HW1 import GenerateHistogram
import cv2

img = cv2.imread('over-expose.jpg')
histo = GenerateHistogram(img)

for i in range(256):
    print(str(histo[3][i]))


