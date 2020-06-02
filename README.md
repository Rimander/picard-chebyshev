# Picard-Chebyshev Method

Demo function used to demonstrate how to use the Picard-Chebyshev method
This will propagate an orbit a total of one period and compare the solution to the analytical solution using kepler universal variable propagation.

This is a migration the original code (MatLab) to C


## C

Compile with:
```
gcc main.c src/kepleruniversal.c src/kepleruniversal.h src/picardchebyshevdemo.c src/picardchebyshevdemo.h src/vmpcm.c src/vmpcm.h src/matlab.c src/matlab.h
```

Execute to create files positionAndVelocity.txt and magnitudeErrors.txt

## Python
Require python 3.X
```
pip3 install requirements.txt
```

#### PlotPositionAndVelocity
```
python3 PlotPositionAndVelocity.py
```
Require file positionAndVelocity.txt

#### PlotMagnitudeErrors
```
python3 PlotMagnitudeErrors.py
```
Require file magnitudeErrors.txt