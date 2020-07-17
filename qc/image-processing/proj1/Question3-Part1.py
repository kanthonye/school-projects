#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Mar 29 12:29:57 2019

@author: kanthonye
"""

from KAE_CS381_HW1 import GenerateFalseColorImage
from spectral import open_image
import cv2

img = open_image('TIPJUL1.LAN')
print (img)

simg = GenerateFalseColorImage(img)
cv2.imwrite('false-img.jpg',simg)



            