import matplotlib.pyplot as plt
import csv
import numpy as np

ext =  '.csv'
ext_fig = '.png'

with open('IO_source.csv', 'r') as csvfile:
	lineA = csv.reader(csvfile, delimiter = ' ')
	for row in lineA:
		IP = row[0]
		OP = row[1]

filenameM = "OP/" + OP + ext
filenameCpp = "Outputs/" + OP + ext
filenameFig = "Figures/figure_" + OP + ext_fig

print filenameM, filenameCpp, filenameFig

#fileIP, fileOP = np.loadtxt("IO_source.csv", delimiter = ' ', unpack = True)

x1, y1, theta1 = np.loadtxt(filenameM, delimiter = ',', unpack = True)
x2, y2, theta2 = np.loadtxt(filenameCpp, delimiter = ' ', unpack = True)

plt.figure(figsize=(8.0, 5.0))
plt.subplot(211)
plt.plot(x1,y1, '-b', label = 'MATLAB')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Kinematics Estimation Results from MATLAB')
plt.legend()

plt.subplot(212)
plt.plot(x2,y2, '-r', label = 'C++')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Kinematics Estimation Results from C++')
plt.legend()

plt.savefig(filenameFig)
plt.show()