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

To program the CNC lathe, an Arduino related software GRBL is used. The g-code can be sent directly through the serial port to the Arduino. Universal Gcode Sender is another way to send g-code to Arduino easily.



## Controlling the Speed of the Spindle

---

### Measuring the Spindle Speed

In the spindle assembly, there is a disc that has 100 holes equidistant form origin. A beam breaker sensor is put on this circle to count the number of holes that are being passed in a time interval during operation. 

Arduino board is used for this application. The main idea is to count the number of holes during a specific time interval. This time interval is adjusted with the interrupt frequency settings of the timer interrupt and is adjusted to 0.1 seconds (or 10 Hz interrupt frequency) in this application. It can be changed as instructed in the speed control code written in Arduino. During operation, the hole count per second, which is also equal to revolution of the spindle per second (rps), is calculated using another interrupt. With proper unit conversions, rotational speed of the spindle in revolutions per minute (rpm) is found and published via a display screen.

### Driving the Spindle Motor

The spindle motor has 180 VDC nominal voltage rate. As this is a high voltage rate supplying necessary voltage to the motor is challenging. To change and regulate the AC power coming from the grid, an AC  dimmer and a full bridge rectifier is planned to be used. The speed can be controlled closed loop by rotating the potentiometer using a servo motor. In this system, the measured spindle speed is aimed to be used as the feedback of the control loop.



## Automatic Tool Changing

---

There is a 12 V DC motor and a rachet mechanism inside the gearbox to control the tool changer. Since there is no sensor in this system, the motor is controlled open loop using a seperate Arduino board. The desired tool number is sent to that Arduino through serial port to change the tool.





# Electrical Scheme & Wiring

## Electrical Sub-System

After preparing the sub-systems of the lathe, the electrical system is designed to distribute the required power to every component. The general scheme is shared below:

(Figure)

For safety measures, an emergency stop button is connected to the main power line coming from the grid. Once pushed, it cuts all the power on the lathe but the socket's. The socket can be used for any application, it does not harm the lathe's electric system.

Secondly, a fuse is equipped to the electrical system, after the emergency stop button and the power distribution terminal. Considering the power need of the lathe, 8A rated fuse is selected.



A fan is used in the system to cool the electrical components. It is powered by 220VAC, so it is connected to the main line, after the fuse.



Apart from the emergency stop button, two serial connected switches are present also. For the machine to work fully, the key switch must be turned on and a casette should be in its box. If both switches are off, the AC power reaches to the power supply and converted to DC. From its different output wires, 12V voltage is transferred to the buck converters and regulated to 9V, which is the rated voltage of the stepper motors and the drivers. At last, the output of the converter is connected to the drivers and after that to the stepper motors.

The power supply is taken from an old computer and its specifications are shared below:

 (specifications of the power supply)



The two controller boards (Arduino Uno) are powered differently. The below one, the main board which is controlling the axes, is powered from the computer via a cable. And the above one, which is used to control the tool changer and measure speed control, is fed from the main arduino, from Vin pin.

# Wiring

The connections of the lathe with its electronic components is shown with a picture and tabulated below:

(Arka kısmın fotosu)

| From | To  | Number |
|:----:|:---:| ------ |
|      |     |        |
|      |     |        |
|      |     |        |
|      |     |        |









# Possible Improvements

## Spindle Motor & Drive

The spindle motor has a high nominal voltage rate (180VDC). The motor can be changed with a lower voltage motor that supplies the same power and speed. That way, the effort on the power electronics side may be less.

For the motor drive, an industrial motor driver may be selected and used, for a reliable operation. The motor voltage and current limits of the driver are important parameters for choosing the most suitable motor driver.

## Stepper Motors

## X axis Limitation

## GRBL Limitations
