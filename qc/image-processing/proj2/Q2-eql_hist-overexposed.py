#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri May 10 23:57:10 2019

@author: K. Anthony E. (kanthonye)
"""
import cv2
import hw2lib as hw2

img = cv2.imread('q1-gamma-overexposed.jpg')
gry = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

eqh = cv2.equalizeHist( gry )
hw2.ShowHisto( eqh )
cv2.imwrite('q2-eql_hist-overexposed.jpg',eqh)