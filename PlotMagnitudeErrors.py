import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

file_name = "magnitudeErrors.txt"
file_path = "./" + file_name

file = Path(file_path)
if not file.is_file():
    raise FileNotFoundError("Fichero no encontrado " + file_path)

with open(file_path) as fp:
    # Num items
    line = fp.readline()
    m = int(line)

    # White line
    fp.readline()

    # t
    t = np.zeros(m)
    line = fp.readline()
    cols = line.split(",")
    for i in range(0, m):
        t[i] = float(cols[i])

    # White line
    fp.readline()

    # PosErr
    posErr = np.zeros(m)
    line = fp.readline()
    print(line)
    cols = line.split(",")
    for i in range(0, m):
        posErr[i] = float(cols[i])

    # White line
    fp.readline()

    # VelErr
    velErr = np.zeros(m)
    line = fp.readline()
    cols = line.split(",")
    for i in range(0, m):
        velErr[i] = float(cols[i])

    figure = plt.figure(figsize=(30, 10))

    # -- 1
    ax1 = figure.add_subplot(2, 1, 1)
    p_x = np.divide(t, 60)

    # plot(t./60,PosErr.*1e6,'k');
    p_y = posErr * 1e6
    ax1.plot(p_x, p_y, label='PosErr', color="grey")

    plt.legend(loc='upper left')

    # -- 2
    ax2 = figure.add_subplot(2, 1, 2)
    p_x = np.divide(t, 60)

    # plot(t./60,VelErr.*1e6,'k');
    p_y = velErr * 1e6
    ax2.plot(p_x, p_y, label='PosErr', color="grey")

    plt.legend(loc='upper left')

    plt.show()
