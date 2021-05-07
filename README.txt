Circuit Analysis Tool
By Group 7
Lonis Peter Haney
Junior Dos Santos
Jonathan Goodman

Summary
This program was created to perform basic AC Circuit Analysis.
The user will be asked to input the number and values for resistors, capacitors, inductors, a single voltage or current source, and the nodes that connect them.
The program will then attempt to evaluate each of the voltages and currents across each of the elements.
The program will then display the voltage and current values for each of the elements.
This program will only solve simpler circuits, it is capable of solving multiple problems in series and parallel combined but it isn’t capable of solving delta or Y transformations (any case where there is not anything in series or parallel).
This program will simplify the circuit down to a thevenin’s equivalent circuit, then work backwards solving the voltages for the elements using ohm's law.

Inputs and Outputs:
In this program, the user will input all of the necessary information needed to create a full circuit. Every step of the input process is prompted by the text which the program outputs.
The first thing that the program asks for is the circuit’s omega value. The omega value is the value (in radians per second) that is used to calculate the impedance at each capacitor and inductor in the form of a complex number. This value is constant throughout the entire circuit.
Next, the program will prompt the user to enter the number of nodes, resistors, capacitors and inductors in that order.
The program will then prompt the user to name each node.
Next, the user will enter whether they want to use a voltage or current source. The user will then enter the magnitude and phase angle of the source, as well as the nodes which the source is connected to.
Finally the user will be asked to input the value of any resistors, capacitors, and inductors as well as what nodes they connect to.
After this the Program will output the thevenin impedance, and then all of the voltages and currents through each imputed element.

Good things to know:
 - DO NOT INPUT CHARACTERS UNLESS IT ASKS FOR NAMES
        The program will terminate and you will have to run it again

 - Be careful what units everything is in (it will ask for radians but output degrees)


Example 1 (Working Circuit):

Enter a value for Omega:1

Enter Number of Nodes:4

Enter Number of Resistors:2

Enter Number of Capacitors:1

Enter Number of Inductors:1

Enter Node name:A

Enter Node name:B

Enter Node name:C

Enter Node name:GND

What type of source
Enter V for Voltage and I for Current:V

Enter Magnitude:5

Enter Phase (in rad):0

Enter positive/forward current Nodes Name:A

Enter negative/reverse current Nodes Name:GND

Enter Resistance:10

Enter First Nodes Name:A

Enter Second Nodes Name:B

Enter Resistance:20

Enter First Nodes Name:B

Enter Second Nodes Name:GND

Enter Capacitance:0.0025

Enter First Nodes Name:C

Enter Second Nodes Name:GND

Enter Inductance:30

Enter First Nodes Name:B

Enter Second Nodes Name:C

User Inputted:
  A -> B   : Resistor  : (10,0)
-------------------------------------
  B -> GND : Resistor  : (20,0)
-------------------------------------
  C -> GND : Capacitor : (0,-40)
-------------------------------------
  B -> C   : Inductor  : (0,30)
-------------------------------------
Voltage Source
  Magnitude -- 5.000 V
  Angle ------ 0.000 rad
-------------------------


Values Found:
GND -> A   : Thevenin Impedance :  14-j8   : (5, 0°) V : (0.31, 29.7°) A
---------------------------------------------------------------------------
---------------------------------------------------------------------------
  A -> B   : Resistor  :  10+j0   : (3.1, 29.7°) V : (0.31, 29.7°) A
---------------------------------------------------------------------------
  B -> GND : Resistor  :  20+j0   : (2.77, -33.7°) V : (0.139, -33.7°) A
---------------------------------------------------------------------------
  C -> GND : Capacitor :   0-j40  : (11.1, -33.7°) V : (0.277, 56.3°) A
---------------------------------------------------------------------------
  B -> C   : Inductor  :   0+j30  : (8.32, 146°) V : (0.277, 56.3°) A
---------------------------------------------------------------------------

Process finished with exit code 0


Example 2 (Bad Circuit):

Enter a value for Omega:1

Enter Number of Nodes:4

Enter Number of Resistors:1

Enter Number of Capacitors:2

Enter Number of Inductors:2

Enter Node name:A

Enter Node name:B

Enter Node name:C

Enter Node name:GND

What type of source
Enter V for Voltage and I for Current:I

Enter Magnitude:2

Enter Phase (in rad):0

Enter positive/forward current Nodes Name:A

Enter negative/reverse current Nodes Name:GND

Enter Resistance:2.5

Enter First Nodes Name:B

Enter Second Nodes Name:C

Enter Capacitance:.25

Enter First Nodes Name:A

Enter Second Nodes Name:B

Enter Capacitance:.5

Enter First Nodes Name:A

Enter Second Nodes Name:C

Enter Inductance:6

Enter First Nodes Name:B

Enter Second Nodes Name:GND

Enter Inductance:7

Enter First Nodes Name:C

Enter Second Nodes Name:GND

User Inputted:
  B -> C   : Resistor  : (2.5,0)
-------------------------------------
  A -> B   : Capacitor : (0,-4)
-------------------------------------
  A -> C   : Capacitor : (0,-2)
-------------------------------------
  B -> GND : Inductor  : (0,6)
-------------------------------------
  C -> GND : Inductor  : (0,7)
-------------------------------------
Current Source
  Magnitude -- 2.000 A
  Angle ------ 0.000 rad
-------------------------


Values Found:
Bad circuit detected
Circuit could not be simplified
Process finished with exit code -1

