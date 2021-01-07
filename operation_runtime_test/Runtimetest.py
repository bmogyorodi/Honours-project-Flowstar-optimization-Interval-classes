#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar  3 16:21:57 2020

@author: s1655560
"""
import os
import random

def main():
    flow_versions=['original','otherInter','myInter','sse_test']
    outF=open('runtimetest.txt', "w")
    for flow in flow_versions:
        outF.write(flow+' version runtime results:\n')
        outputLines=os.popen(flow+"/./Tester 20000")
        outF.writelines(outputLines)
        outF.write('\n');
    outF.close()
if __name__== "__main__":
  main()