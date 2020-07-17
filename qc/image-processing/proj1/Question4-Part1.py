#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Mar 31 16:04:17 2019

@author: kanthonye
"""
from KAE_CS381_HW1 import GenerateLidarImage
from laspy.file import File
import cv2

las = File('17258975.las', mode="r")

height = 1023
width  = 1023
simg   = GenerateLidarImage(las, 1023, 1023)

cv2.imwrite('lidar-image.jpg', simg)

