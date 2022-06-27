# Teensy-Launchpad-Drumsequencer
Teensy Launchpad Drumsequencer 


This is a Teensy sketch for using the Launchpad mini (mk1) 
as a drum sequencer in your daw or other production studio.
As the Launchpad offers an 8x8 matrix i choosed to make 
a 16-Step sequencer with 4 Tracks.
The most upper Row lets you see the counter of the steps. 
Green LED´s are the upper rows, Orange are the bottom rows 
of the tracks.
Each Track has a fill option, it is accessibla on the circled 
button next to each tracks last step.

to Do:
Mute function on the circled button next to the 8th step


You will need 3 Tracks
1) A Midi track with the teensy as (MIDI)-input and Launchpad as Output. (MIDI channel = 1)
   So the Teensy can talk to the launchpad, like switching on/off the Led´s
2) A Midi Track with the Launchpad as (MIDI)-input and Teensy as Output. (MIDI channel = 1) 
   So the Launchpad can tell the Teensy that a button is pushed
3) An Instrument track with a drumplugin loaded with the Teensy as (MIDI)-input. (MIDI channel = 10)
   Notes are 36, 37, 38, 39. 
   
   
