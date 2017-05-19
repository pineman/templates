import matplotlib.pyplot as plt
import numpy as np

t = np.arange(0.0, 0.0006, 0.0000001)
s = 0.9*np.e**(-12500*t)*np.cos(111102*t + np.pi/2)
plt.plot(t, s)

plt.xlabel('t [s]')
plt.ylabel('u_C [V]')
plt.title('RLC paralelo - Tensão no condensador - Regime periódico amortecido')
plt.grid(True)
plt.savefig('duc.png')
plt.show()
