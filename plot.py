import matplotlib.pyplot as plt
import numpy as np

t = np.arange(0.0, 0.0006, 0.000001)
s = 0.0080505*np.e**(-12500*t)*np.cos(111102*t + np.pi/2 - 0.99373)
plt.plot(t, s)

plt.xlabel('Time [s]')
plt.ylabel('Coil Current [A]')
plt.title('RLC parallel circuit - underdamped response')
plt.grid(True)
plt.savefig('plot.png')
plt.show()
