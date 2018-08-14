import matplotlib.pyplot as plt
import csv
import numpy as np

filepathM = 'OP/output'
filepathCpp = 'Outputs/output'
ext =  '.csv'
ext_fig = '.png'
fileKey = '_10'
filenameM = filepathM + fileKey + ext
filenameCpp = filepathCpp + fileKey + ext
filepathFig = 'Figures/figure'
filenameFig = filepathFig + fileKey + ext_fig


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