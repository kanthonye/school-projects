#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Mar 29 10:09:37 2019

@author: kanthonye
"""
from KAE_CS381_HW1 import GenerateBinaryImage
import cv2
import matplotlib.pyplot as plt

bgimg = cv2.imread('bgimg.jpg')
fgimg = cv2.imread('fgimg.jpg')

bimg, count = GenerateBinaryImage(fgimg, bgimg, 30)
print('pixels that belong to the object of interes -> ', count)
plt.imshow(bimg)

cv2.imwrite('binary-image.jpg',bimg)



