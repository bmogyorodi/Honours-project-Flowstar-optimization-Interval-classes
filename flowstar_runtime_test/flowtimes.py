#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Feb 26 11:12:14 2020

@author: s1655560
"""
#!/usr/bin/pyton
import struct
import os
import time
import csv
from subprocess import PIPE, Popen

def main():
    fileNames=os.popen('ls models').readlines()   
    flows=['originaltest','doubleinttest','minusdoubleinttest','sse_version']   
    real = open("flowrealtime.csv", "w")
    user= open("flowusertime.csv","w")
    systime=open("flowsystemtime.csv","w")
    roundF=open("rounding.txt","w")
    writer1=csv.writer(real)
    writer2=csv.writer(user)
    writer3=csv.writer(systime)
    writer1.writerow(fileNames)
    writer2.writerow(fileNames)
    writer3.writerow(fileNames)
    for flowversion in flows:
        row1=list()
        row2=list()
        row3=list()
        for file in fileNames:
            payload='models/'+file
            header="Rounding mode switches in version "+flowversion+" on model: "+file
            roundF.write(header+"\n")
            cmd="time "+flowversion+'/'+'./flowstar < '+payload
            print("Running command: "+cmd)
            p = Popen(cmd, shell=True, stdout=PIPE, stderr=PIPE)
            flowlines=p.stdout.readlines()
            intermid_time=[i for i in flowlines if "time cost" in i]
            runtimes=p.stderr.readlines()
            print(runtimes)
            realrun=runtimes[1][5:-1]
            userrun=runtimes[2][5:-1]
            sysrun=runtimes[3][4:-1]
            row1.append(realrun)
            row2.append(userrun)
            row3.append(sysrun)
            print(flowlines[-1])
            os.system("gprof "+flowversion+"/flowstar gmon.out > "+flowversion+"/gprofs/"+file[0:len(file)-7]+".txt")
            if len(intermid_time)!=0:
                roundF.write(intermid_time[0])
            roundF.write(flowlines[-1]+"\n")
        outputs=os.popen("ls outputs/").readlines()
        for output in outputs:
            command="cp outputs/"+output[0:len(output)-1]+" outputtest/"+flowversion+"/"
            os.system(command)  
        writer1.writerow(row1)
        writer2.writerow(row2)
        writer3.writerow(row3)
    real.close()
    user.close()
    systime.close()
             
    
     

  
  
    
   


if __name__== "__main__":
  main()