---
title: "Multi ESC"
author: "Someonelse"
description: "A custom 4 in 1 drone ESC"
created_at: "2026-10-7"
---

# October 10: Selected initial parts

I started by selecting the parts. Since there will be four identical motor driver circuits I will be trying kicad's sheets feature to make one driver circuit and copy it four times. I want this circuit to do two functions: to drive four brushless motors and to provide a stable 3.3v to the rest of the drone. Because this is the board connected to the battery it makes sense to also put the primary regulator on it too. For this I chose the LMR51450FN as has the specs I need with 5 amps out and is pretty cheap. I had to make a custom symbol for this because kicad didn't have one.

![Regulator symbol](images/LMR51450FN-symbol.png)


For the mcu for each driver I chose the STM32F318K8U6 as it was one of the cheapest ones I could find from ST's F3 or G4 lines which are made for signal processing. Even still each mcu is $5 and if I find a cheaper one that will do the job I'll use that instead. For the gate driver I chose the DRV8320S as I've worked with TI gate drivers before and this one was also fairly cheap. Kicad didn't have a footprint for it so I modified the foot print for the DRV8311S. 

![Gate driver symbol](images/DRV8320S-symbol.png)

I then chose a mosfet for the actual gates. I found the DI030N10PT-AQ on digikey which was surprisingly cheap and was rated for 30A and 100V which is plenty. 

![initial esc schematic](images/schematic-1.png)

**Total time spent: 3 hours**

# October 13: Wired regulator schematic

I decided to start wiring the regulator first. TI has a really nice tool that generates a schematic which I used.

![Regulator reference schematic](images/reg_ref_circuit.png)

I then copied this over to kicad.

![Regulator circuit](images/reg_circuit-1.png)

**Total time spent: 1 hours**

# October 13: Wired MCU

Next I went to routing the mcu for the driver. After looking over the datasheet the mcu needs a separate 1.8v digital supply so I added a simple ldo regulator. The analog voltage will still be 3.3v because the mcu supports that and because I will be measuring high voltage which will be steped down and the lower the max voltage the less accurate it is. I opened up STM32CubeMX to get the pinout and tried a few times to get everything I need. It was a bit tricky because the mcu doesn't have many pins and I need a lot of different functions. After a few tries I managed to get everything I wanted. At first I wasn't sure if I should add SPI for the gate driver because I thought I wouldn't have enough pins and I might need a level shifter. After checking the gate driver datasheet it does support 1.8v digital supply so I chose to add in the SPI.

![STM32CubeMX pinout](images/mcu_pinout-1.png)

![MCU circuit](images/mcu_circuit-1.png)

**Total time spent: 2 hours**
