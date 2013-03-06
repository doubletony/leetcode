import sys
import os
import glob
import subprocess
from sys import argv

import types
import math


def countLines(filename):
    fl = open(filename)
    counter = 0
    for line in fl:
        line = line.strip()
        if len(line) > 0:
            counter += 1
    fl.close()
    return counter

cpps = glob.glob("*.cpp")
print len(cpps), "problems are solved."
total = 0
for cpp in cpps:
    total += countLines(cpp)
print total, "lines of codes."
