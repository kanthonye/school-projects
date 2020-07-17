#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Apr  5 11:41:41 2019

@author: kanthonye
"""
from KAE_CS381_HW1 import GenerateNDVIImage
from spectral import open_image
import cv2

img = open_image('TIPJUL1.LAN')
print (img)

simg = GenerateNDVIImage(img)
cv2.imwrite('NDVI.jpg',simg)

