# Simulation of the model in my proposal to reforming the assembly line at ICL Techno LLC

To compile and run the simulation, go to simulation (`cd simulation`) and run simulate (`bash simulate`)

To compile and run the plot, go to plot (`cd plot`) and run plot (`bash plot`)


## Reorganization of assembly and quality assurance of computers at the ICL Techno LLC facility to increase manufacturing perfomance by ~23%

The current system is a series of consecutive handovers of devices via the assembly line, where each member of the brigade checks a part of the device's functionality, which is described in a check-list, that comes with every device.

I have proposed a system, where each member of the brigade checks a device's functionality in full. 

According to the simulation, with 6 people in the brigade, 232 seconds to check/assemble the device entirely, and 5 seconds for a single handover, the proposed system's performance is greater by ~10%. But the main potential of the new proposed system can be observed in practice. In the old system, if one member of the brigade has a problem, thus resluting in delays, the whole system halts. However, if the same case occurs in the proposed system, that only stops one member of the brigade. To simulate this, a 1% chance of delay (whenever a member of a brigade takes the device) was introduced. 

With the same conditions, the performance of the proposed system over 8 work hours is greater by *~23%*!

![graph](https://github.com/escape13/assembly-simulation/blob/master/images/graph.png?raw=true)
