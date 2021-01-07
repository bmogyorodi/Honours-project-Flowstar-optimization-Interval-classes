#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar  3 16:21:57 2020

@author: s1655560
"""
import os
import random
def spaceing():
    print("\n"*5)
def differenceTest(version1,version2):
    print("Differences between "+version1+" and "+version2)
    os.system("diff "+version1+".txt "+version2+".txt")
    spaceing()
def main():
    flow_versions=['original','otherInter','myInter','sse_test']
    double_inputs=[]
    input_str=""
    for i in range(10):
        double_inputs.append(random.uniform(-100,100))
        print(double_inputs[i])
        input_str+=str(double_inputs[i])+" "
    for flow in flow_versions:
        outputLines=os.popen(flow+"/./Tester "+input_str)
        outF=open(flow+'.txt', "w")
        outF.writelines(outputLines)
        outF.close()
    #print("Differences between flip and double implementation:")
    #os.system("diff otherInter.txt myInter.txt")
    differenceTest(flow_versions[0],flow_versions[1])
    differenceTest(flow_versions[0],flow_versions[2])
    differenceTest(flow_versions[0],flow_versions[3])
    differenceTest(flow_versions[1],flow_versions[2])
    differenceTest(flow_versions[1],flow_versions[3])
    differenceTest(flow_versions[2],flow_versions[3])
    
if __name__== "__main__":
  main()
