import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

file_name = "positionAndVelocity.txt"
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

    # vMag
    line = fp.readline()
    vMag = float(line)

    # White line
    fp.readline()

    # a
    line = fp.readline()
    a = float(line)

    # White line
    fp.readline()

    # rvPCM
    rvPCM = np.zeros((m, 6))
    for i in range(0, m):
        line = fp.readline()
        cols = line.split(",")
        for j in range(0, 6):
            rvPCM[i][j] = float(cols[j])

    # White line
    fp.readline()

    # xg
    xg = np.zeros((m, 6))
    for i in range(0, m):
        line = fp.readline()
        cols = line.split(",")
        for j in range(0, 6):
            xg[i][j] = float(cols[j])

    # White line
    fp.readline()

    # rA
    rA = np.zeros((3, m))
    for i in range(0, 3):
        line = fp.readline()
        cols = line.split(",")
        for j in range(0, m):
            rA[i][j] = float(cols[j])

    # White line
    fp.readline()

    # vA
    vA = np.zeros((3, m))
    for i in range(0, 3):
        line = fp.readline()
        cols = line.split(",")
        for j in range(0, m):
            vA[i][j] = float(cols[j])

    # White line
    fp.readline()

    # t
    t = np.zeros(m)
    line = fp.readline()
    cols = line.split(",")
    for i in range(0, m):
        t[i] = float(cols[i])

    figure = plt.figure(figsize=(30, 10))

    # -- 1
    ax1 = figure.add_subplot(3, 2, 1)
    p_x = np.divide(t, 60)

    # plot(t./60,xg(:,1),'b');
    p_y = xg[:, 0]
    ax1.plot(p_x, p_y, label='xg', color="blue")

    # plot(t./60,rvPCM(:,1),'ok'); hold on;
    p_y = rvPCM[:, 0]
    ax1.plot(p_x, p_y, "o", label='rvPCM', color="black", mfc='none', markersize=10)

    # plot(t./60,rA(1,:),'+r');
    p_y = rA[0, :]
    ax1.plot(p_x, p_y, "+", label='rA', color="red", markersize=10)
    plt.legend(loc='upper left')

    # -- 2
    ax2 = figure.add_subplot(3, 2, 2)
    p_x = np.divide(t, 60)

    # plot(t./60,xg(:,4),'b');
    p_y = xg[:, 3]
    ax2.plot(p_x, p_y, label='xg', color="blue")

    # plot(t./60,rvPCM(:,4),'ok'); hold on;
    p_y = rvPCM[:, 3]
    ax2.plot(p_x, p_y, "o", label='rvPCM', color="black", mfc='none', markersize=10)

    # plot(t./60,vA(1,:),'+r');
    p_y = vA[0, :]
    ax2.plot(p_x, p_y, "+", label='vA', color="red", markersize=10)
    plt.legend(loc='upper left')

    # -- 3
    ax3 = figure.add_subplot(3, 2, 3)
    p_x = np.divide(t, 60)

    # plot(t./60,xg(:,2),'b');
    p_y = xg[:, 1]
    ax3.plot(p_x, p_y, label='xg', color="blue")

    # plot(t./60,rvPCM(:,4),'ok'); hold on;
    p_y = rvPCM[:, 1]
    ax3.plot(p_x, p_y, "o", label='rvPCM', color="black", mfc='none', markersize=10)

    # plot(t./60,rA(1,:),'+r');
    p_y = rA[1, :]
    ax3.plot(p_x, p_y, "+", label='rA', color="red", markersize=10)
    plt.legend(loc='upper left')

    # -- 4
    ax4 = figure.add_subplot(3, 2, 4)
    p_x = np.divide(t, 60)

    # plot(t./60,xg(:,5),'b');
    p_y = xg[:, 4]
    ax4.plot(p_x, p_y, label='xg', color="blue")

    # plot(t./60,rvPCM(:,5),'ok'); hold on;
    p_y = rvPCM[:, 4]
    ax4.plot(p_x, p_y, "o", label='rvPCM', color="black", mfc='none', markersize=10)

    # plot(t./60,vA(2,:),'+r');
    p_y = vA[1, :]
    ax4.plot(p_x, p_y, "+", label='vA', color="red", markersize=10)
    plt.legend(loc='upper left')

    # -- 5
    ax5 = figure.add_subplot(3, 2, 5)
    p_x = np.divide(t, 60)

    # plot(t./60,xg(:,3),'b');
    p_y = xg[:, 2]
    ax5.plot(p_x, p_y, label='xg', color="blue")

    # plot(t./60,rvPCM(:,3),'ok'); hold on;
    p_y = rvPCM[:, 2]
    ax5.plot(p_x, p_y, "o", label='rvPCM', color="black", mfc='none', markersize=10)

    # plot(t./60,rA(2,:),'+r');
    p_y = rA[2, :]
    ax5.plot(p_x, p_y, "+", label='rA', color="red", markersize=10)
    plt.legend(loc='upper left')

    # -- 6
    ax6 = figure.add_subplot(3, 2, 6)
    p_x = np.divide(t, 60)

    # plot(t./60,xg(:,6),'b');
    p_y = xg[:, 5]
    ax6.plot(p_x, p_y, label='xg', color="blue")

    # plot(t./60,rvPCM(:,6),'ok'); hold on;
    p_y = rvPCM[:, 5]
    ax6.plot(p_x, p_y, "o", label='rvPCM', color="black", mfc='none', markersize=10)

    # plot(t./60,vA(2,:),'+r');
    p_y = vA[2, :]
    ax6.plot(p_x, p_y, "+", label='vA', color="red", markersize=10)
    plt.legend(loc='upper left')

    plt.show()
