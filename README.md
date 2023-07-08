# Emco Compact 5 CNC Modernization

*ME462 Mechatronic Design Project by group Despacito*

<u>Group Members:</u> Egemen İlikmen, Yalın Şahin, Mehmet Furkan Doğan

## Objective

The objective of this project is to revive an old cnc lathe (Emco Compact 5 CNC). There are three parts of this project:

1. Controlling the X and Z axes

2. Controlling the Speed of the Spindle

3. Automatic Tool Changing

## Controlling the X and Z axis

---

Two steppers motors are used for controlling the X and Z axis. Those motors are driven in unipolar configuration by TB6600 stepper motor drivers.

### Motor Info - Warner Electric Brake & Clutch sm-072-0060-ra

![z-step-specs.jpeg](/Documents/z-step-specs.jpeg)

| Date Submitted     | Nov 03, 1999                   |
| ------------------ | ------------------------------ |
| Motor Manufacturer | Warner Electric Brake & Clutch |
| Motor Part Number  | sm-072-0060-ra                 |

 **<u><font face="Arial">Electrical Specifications</font></u>**

|                                    |       |                |
| ---------------------------------- | ----- | -------------- |
| Phase Resistance                   | 4.6   | ohms           |
| Phase Inductance                   |       | mH             |
| Nominal Phase Current (1 Phase On) | 2     | A              |
| Nominal Phase Voltage              | 9 vdc | V              |
| Electrical Time Constant           |       | ms             |
| Back EMF Amplitude                 |       | V / ksteps / s |

 **<u><font face="Arial">Mechanical Specifications</font></u>**

| Holding Torque @ Nominal Current |     | oz-in       |
| -------------------------------- | --- | ----------- |
| Detent Torque                    |     | oz-in       |
| Step Angle                       |     | deg/step    |
| Angular Acceleration             |     | rad/s^2     |
| Angular Accuracy                 |     | % full-step |
| Resonant Frequency               |     | Hz          |
| Shaft Diameter                   | 1/4 | in          |

| Mounting Frame (NEMA Standard) | 17/8X17/8" holes |
| ------------------------------ | ---------------- |

### Step Motor Driver Info - TB6600

Motor connections is made using the unipolar configuration.

![stepper_motor_diagram.png](/Documents/stepper_motor_diagram.png)

### Programming

An arduino with grbl is used to control the axes. The g-code can be sent directly through the serial port to the arduino. Universal Gcode Sender can be used to send gcodes easily.

## Controlling the Speed of the Spindle

---

### Measuring the Spindle Speed

There is a beam breaker and a disc on the spindle to measure rotational speed.

### Driving the Spindle Motor

A dimmer and a full bridge rectifier is used to drive the spindle motor. The speed of the motor can be controlled by the potentiometer of the dimmer. The speed can be controlled closed loop by rotating the potentiometer using a servo motor.

## Automatic Tool Changing

---

There is a 12 V DC motor and a rachet mechanism inside the gearbox to control the tool changer. Since there is no sensor in this system, the motor is controlled open loop using a seperate arduino. The desired tool number is sent to that arduino through serial port to change the tool.
