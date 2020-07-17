#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Apr  5 10:56:27 2019

@author: kanthonye
"""
import cv2
import numpy as np
from laspy.file import File

img = cv2.imread('lidar-image.jpg')
las = File('17258975.las', mode="r")
mmin = las.header.min
mmax = las.header.max

print("\n\n")
print("lidar-min ", mmin)
print("lidar-max ", mmax)

longitude = mmax[0] - mmin[0]
latitude = mmax[1] - mmin[1]
altitude = mmax[2] - mmin[2]

print("\n")
print("longitude ", longitude)
print("latitude  ", latitude)
print("altitude  ", altitude)

height = 170
width  = 350
qimg = np.zeros([height+1, width+1, 3], int)
position = [40,300]
y_end = position[1] + height
x_end = position[0] + width
total_pixel = 0
alti = 0
minx = longitude
miny = latitude
maxx = 0
maxy = 0
n = 0
for y in range(position[1], y_end):
    m = 0
    for x in range(position[0], x_end):
        q = img[y,x][0];
        if alti < q:
            alti = q
            
        if q >= 9:
            q = 1;
            if minx > x: minx = x
            if miny > y: miny = y
            if maxx < x: maxx = x
            if maxy < y: maxy = y
        else :
            q = 0;
            
        if q == 1:
            total_pixel = total_pixel + 1;
            
        qimg[n,m] = q * 255
        m = m+1;
    n = n+1;
 
alti = (alti / 255) * altitude
print("\n")
print("+---+------------------+")
print("|   |   min   | max    |")
print("+---+------------------+")
print("| x |  ", minx,"   |", maxx,"   |")
print("+---+------------------+")
print("| y |  ", miny,"  |", maxy,"   |")
print("+---+------------------+")

length = ((maxx - minx) / qimg.shape[0]) * longitude;
width  = ((maxy - miny) / qimg.shape[1]) * latitude;
print("building altitude: ", alti)
print("building length  : ", length)
print("building width   : ", width)
print("building area    : ", length*width)
print("building pixels  : ", total_pixel)
  
cv2.imwrite('lidar-subimg-image.jpg', qimg)
