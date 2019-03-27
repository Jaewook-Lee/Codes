import numpy as np
import matplotlib.pyplot as plt


m = np.linspace(40, 200, 100)
G = 9.8
Cd = 0.25

v = np.sqrt(m*G/Cd)*np.tanh(np.sqrt(G*Cd/m) * 4) # Using Differential Equation
v1 = np.sqrt(m*G/Cd)*np.tanh(np.sqrt(G*Cd/m) * 4) - 36
#v0 = 0
#v1 = v0 + (G - Cd*v0**2/m) # Using Euler's method
#v2 = v1 + (G - Cd*v1**2/m)
#v3 = v2 + (G - Cd*v2**2/m)
#v4 = v3 + (G - Cd*v3**2/m)
#vel_euler = [v0, v1, v2, v3, v4]
k = np.linspace(0, 0, 100)

plt.title('Velocities that jumper feels at 4s')
plt.xlabel('weight (kg)')
plt.ylabel('velocity (m/s)')
plt.plot(m, v, 'bo-')
plt.grid(True)
plt.show()

plt.title("Weight that doesn't allow")
plt.xlabel('weight (kg)')
plt.ylabel('velocity - 36 (m/s)')
plt.plot(m, v1, 'r*--')
plt.grid(True)
plt.show()

plt.figure(2)
plt.plot(m, v1, m, k)
plt.grid(True)
plt.show()

