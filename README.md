# Arduino-LED-rubik-s-cube

This is repository for my LED rubicks cube porject.
3d models and addional files can be found here: https://www.prusaprinters.org/prints/39223-led-rubiks-cube/files

**Materials**
 - Neopixels
    - I bought these from Adafruit
    - 54 needed
 - Arduino Nano
    - 1 needed
 - 1/4" x 1/4" x 1/8" N52 Magnets
    - I bought these from K&J Magnetics
    - 4 needed (get some extra, they break easily)

**Printed Parts**

All models sliced in PrusaSlicer 2.2, printed on the Pusa MK3s in Hatchbox black PLA.

- Panel
    - Final size: 90x90x90mm
    - 0.2mm quality preset
    - Support on build plate only
    - Color changes inserted at layers 67 and 419. This will pause the print, allowing magnets to be inserted in the pockets.


 - Control Stand
    - 0.3mm draft preset
    - no supports needed


 - Battery Holder
    - 0.3mm draft preset
    - no supports needed


**Assembly**
1. Print all parts. Each panel gets magnets inserted in the pockets. **Make sure the magnets are oriented so the completed panels will attract each other!**
2. Remove all supports from the panels.
3. Using a soldering iron with a clean, round tip, melt the edges of the control stand and battery holders to the inside of one panel. For PLA, I found 350deg C worked well.
4. Consult the provide sketch of the wiring diagram for the LED's. They will be wired in order from 0 to 53. 0-26 will be on one panel, 27-53 on the other. You will want to orient the LED such that the Data in (Din) and Data out (Dout) contacts are conveniently oriented. For example, Dout of LED_0  should be adjacent to Din of LED_1. The LED's can be inserted into the holes in the panel. They should press firmly in place, but a heat gun may come in handy. Careful, too much heat can deform the panel and make it look bad. A few seconds at 250deg C seemed to work well. Hot glue can also be used. 
5. Solder all the LED's on one panel together in series. Do the same on the other. Connect each panel to the Arduino and battery as shown in the diagram.

**Programming**

Arduino code for this project is cube.ino
