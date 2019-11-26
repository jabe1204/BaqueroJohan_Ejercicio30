import numpy as np
import matplotlib.pylab as plt

data = np.loadtxt("datos.dat")
Nx = data[:,0]
iteracion = data[:,1]
plt.figure(figsize=(14,4))

plt.subplot(1,3,1)
plt.plot(Nx,iteracion)
plt.xlabel("Nx")
plt.ylabel("#iteración")

plt.subplot(1,3,2)
plt.xlabel("Nx")
plt.ylabel("#iteración")

plt.subplot(1,3,3)
plt.xlabel("Nx")
plt.ylabel("#iteración")

plt.savefig("evolve_A.png")