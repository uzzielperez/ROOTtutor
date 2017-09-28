
# coding: utf-8

#if __name__ == '__main__':
 # import sys


# In[1]:

import ROOT
from root_numpy import root2array, tree2array
from root_numpy.testdata import get_filepath
import pandas as pd 
import csv 


# In[ ]:

#if len(sys.argv) == 1:
  #print 'need filename'
  #sys.exit(-1)

#inputr = "out_GGJets_M-500To1000_Pt-50_13TeV-sherpa_RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1_numEvent100_1.root"
inputr = raw_input('Enter a filename: ')

#if __name__=="__main__":
 #   import sys
  #  print "argument:", sys.argv  

   # inputfile = sys.argv[1]
   # print "inputfile:", inputfile

    #outputfile = inputfile.split(".")[0] + "__output.csv"

    #print "outputfile:", outputfile

   # with open(outputfile, "wb" ) as fp:
       # fp.write("some content")

newfile = ROOT.TFile(inputr)
gree = newfile.Get("/diphoton/fTree")

import numpy as np
import matplotlib.pyplot as plt
newfile.ls()
import random

a=tree2array(gree)
al=a.tolist()
df = pd.DataFrame(a)
df.head()

outputfile = inputr.split(".")[0] + "__output.csv"

df.to_csv(outputfile, index=False)

