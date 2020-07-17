#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Apr  5 11:25:02 2019

@author: kanthonye
"""
import numpy as np
def GenerateHistogram(img):
    height = img.shape[1]
    width  = img.shape[0]
    
    r = 0;
    g = 1;
    b = 2;
    G = 3;
    histo = np.zeros([4, 256], int);
    
    for h in range(height):
        for w in range(width):
            gray = int((int(img[w][h][r]) + int(img[w][h][g]) + int(img[w][h][b])) / 3);
            histo[r][ img[w][h][r] ] += 1
            histo[g][ img[w][h][g] ] += 1
            histo[b][ img[w][h][b] ] += 1
            histo[G][ gray ] += 1
            
    return histo;


def GenerateBinaryImage(bgimg, fgimg, threshold):
    bg_height = bgimg.shape[1]
    bg_width  = bgimg.shape[0]
    fg_height = fgimg.shape[1]
    fg_width  = fgimg.shape[0]
    height = 1
    width  = 1
    
    if fg_height < bg_height:
        height = fg_height
    else:
        height = bg_height
    
    if fg_width < bg_width:
        width = fg_width
    else:
        width = bg_width
        
    r = 0;
    g = 1;
    b = 2;
    count = 0
    bimg = np.zeros([width, height, 3], int)
    
    for h in range(height):
        for w in range(width):
            
            R = int(fgimg[w][h][r]) - int(bgimg[w][h][r])
            G = int(fgimg[w][h][g]) - int(bgimg[w][h][g])
            B = int(fgimg[w][h][b]) - int(bgimg[w][h][b])
            u = int((R + G + B) / 3)
            
            if u <= threshold:
                bimg[w][h][r] = 0;
                bimg[w][h][g] = 0;
                bimg[w][h][b] = 0;
            else:
                bimg[w][h][r] = 255;
                bimg[w][h][g] = 255;
                bimg[w][h][b] = 255;
                count += 1
    return bimg, count


def GenerateFalseColorImage(img):
    height = img.shape[1]
    width  = img.shape[0]
    
    simg = np.zeros([width, height, 3], int)
    
    for h in range(height):
        for w in range(width):
            #print(img[w,h,1])
            red = img[h,w,4] # nir
            grn = img[h,w,3] #red
            blu = img[h,w,2] # green
             
            simg[h,w,2] = red
            simg[h,w,1] = grn
            simg[h,w,0] = blu
    return simg


def GenerateNDVIImage(img):
    height = img.shape[1]
    width  = img.shape[0]
    
    simg = np.zeros([width, height, 3], int)
    
    for h in range(height):
        for w in range(width):
            nir = img[w,h,4]
            red = img[w,h,3]
            
            if nir < 0: 
                nir = -nir
            if red < 0: 
                red = -red
            
            g = (nir + red)
            
            if g != 0:
                g = (nir - red) / g
                
            g = (1.0 + g) * 0.5
            
            simg[w,h,0] = int(g * 255)
            simg[w,h,1] = int(g * 255)
            simg[w,h,2] = int(g * 255)
    return simg


def GenerateLidarImage(las, width, height):
    mmin = las.header.min
    mmax = las.header.max
    
    longitude = mmax[0] - mmin[0]
    latitude = mmax[1] - mmin[1]
    altitude = mmax[2] - mmin[2]
    
    simg = np.zeros([width+1, height+1, 3], int)
    
    for x, y, z, ite, c, nr, rn in np.nditer([las.x, las.y, las.z, las.Intensity, las.Classification, las.num_returns, las.return_num]):
        lx = x - mmin[0]
        ly = y - mmin[1]
        nx = lx / longitude
        ny = ly / latitude
        nz = ((z - mmin[2]) / altitude)
        mx = int(nx * width)
        my = int(ny * height)
        simg[mx,my] = nz * 255;
    return simg
    