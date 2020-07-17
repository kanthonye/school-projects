#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri May 10 23:57:10 2019

@author: K. Anthony E. (kanthonye)
"""
import numpy as np
from matplotlib import pyplot as plt

def ApplyGamma(img, gamma):
    channels = img.shape[2]
    height   = img.shape[1]
    width    = img.shape[0]
    
    gamma = float( 1.0 / gamma ) 
    gamma = max( 0.0, gamma )# prevent negative input
    
    for h in range( height ):
        for w in range( width ):
            for i in range( channels ):
                v = float( img[w, h, i] / 255.0 );
                img[w, h,i] = int( 255 * pow(v, gamma ) )
    return img


def ShowHisto(img):      
    gry = img.flatten()
    hist,bins = np.histogram( gry, 256, [0,256] )
    plt.hist( gry, 256, [0,256] , color = 'r' )
    plt.show()

def GrayScale(img):
    h = img.shape[1]
    w = img.shape[0]
    m = np.zeros([w, h, 1], int);
    for y in range(h):
        for x in range(w):
            value = int( img[x,y,0] ) + int( img[x,y,1] ) + int( img[x,y,2] );
            m[x,y] = int( value / 3 ); 
    return m


def GrayImg(img):
    height = img.shape[1]
    width  = img.shape[0]
    gimg   = np.zeros([width, height, 3], int);
    
    for h in range(height):
        for w in range(width):
            value = int( img[w,h] );
            gimg[w,h,0] = value
            gimg[w,h,1] = value
            gimg[w,h,2] = value
            
    return gimg


def Histogram(img):
    fimg = img.flatten()
    size = fimg.shape[0]
    hist = np.zeros([256, 1], int);
    for i in range( size ):
        n = int( fimg[i] )
        hist[ n ] = hist[ n ] + 1     
    return hist



def InsertionSort(arr, size):
    
    b = 0
    j = 1
    i = 1
    while (i < size):
        
        j = i;
        if (arr[j,2] < arr[j-1,2]):
            
            b = arr[j,2];
            while (b < arr[j-1,2] and j > 0):
        
                q          = arr[j,  0];
                arr[j,  0] = arr[j-1,0];
                arr[j-1,0] = q;
                q          = arr[j,  1];
                arr[j,  1] = arr[j-1,1];
                arr[j-1,1] = q;
                q          = arr[j,  2];
                arr[j,  2] = arr[j-1,2];
                arr[j-1,2] = q;
                
                j = j - 1;
                
            arr[j,2] = b;
            
        i = i + 1;
        
        
        
def ApplyKernel( img ):
    h = img.shape[1]
    w = img.shape[0]
    size = w * h
    m = np.zeros( [size, 4], int )
    a = np.zeros( [9,1], int )
    
    for y in range( h ):
        for x in range( w ):
            x0 = x-1
            x1 = x;
            x2 = x+1
            
            y0 = y-1
            y1 = y;
            y2 = y+1
            
            if y0 >= 0:
                if x2 < w: a[2] = img[x2, y0]
                else: a[2] = 0
                
                a[1] = img[x1, y0]
                
                if x0 >= 0: a[0] = img[x0, y0]
                else: a[0] = 0
            else:
                a[0] = 0
                a[1] = 0
                a[2] = 0
            
            if y2 < h:
                a[7] = img[x1, y2]
                
                if x0 >= 0: a[6] = img[x0, y2]
                else: a[6] = 0
                
                if x2 < w: a[8] = img[x2, y2]
                else: a[8] = 0
            else:
                a[6] = 0
                a[7] = 0
                a[8] = 0
                
            if x0 >= 0: a[3] = img[x0, y1]
            else: a[3] = 0;

            if x2 < w: a[5] = img[x2, y1]
            else: a[5] = 0;
            
            a[4] = img[x1, y1]
            
            k0 = float(a[4])
            k1 = float(a[1]+a[3]+a[4]+a[5]+a[7]) / 5.0
            k2 = float(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]) / 9.0
            
            i = w * y + x
            
            # priority index - this value will be use to sort in accending order
            m[i, 0] = k0 * 1000000 + k1 * 1000 + k2 
            
            # storing the image coordinate
            m[i, 1] = x
            m[i, 2] = y
            m[i, 3] = k0 # pixel intensity
    return m



def HistMatch(img, inhist ):
    gray = GrayScale( img )
    hist = Histogram( gray )
    arry = ApplyKernel( gray )
    size = arry.shape[0]
    
    x = 0
    y = 0
    
    size = int(size / 256)
    print(size)
    
    for n in range( 256 ):
        a = n * size
        for i in range( size ):
            x = arry[a+i, 1]
            y = arry[a+i, 2]
            b = arry[a+i, 3]
            c = float( hist[b] )
            c = max(1.0, c)
            c = inhist[n] / c
            gray[x, y] = inhist[n] * c  
        
    return gray;
    
    

    
    

