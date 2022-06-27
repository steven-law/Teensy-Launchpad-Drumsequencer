const byte START = 250;
const byte CONTINUE = 251;
const byte STOP = 252;
const byte CLOCK = 248;
const byte veloOn = 96;
const byte veloOff = 0;
byte app5channel = 1;
byte app5Outchannel = 10;
byte zaehler = 0;
byte zaehler2 = 0;
byte ledGreen = 32;
byte ledRed = 71;
byte ledOrange = 127;
byte ledOff = 4;
int lenghtDrum;

byte app5stepcount;
bool app5patternKick[16]  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool app5patternClap[16]  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool app5patternHatCl[16] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool app5patternHatOp[16] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int ledstate11 = 0;
bool app5Kickfill = 0;
bool app5Clapfill = 0;
bool app5HatClfill = 0;
bool app5HatOpfill = 0;
bool app5Kickmute = 0;
bool app5Clapmute = 0;
bool app5HatClmute = 0;
bool app5HatOpmute = 0;


void setup() {
  Serial.begin(9600);
  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleNoteOn(OnNoteOn);
  usbMIDI.setHandleRealTimeSystem(beatClock1);
}

void loop() {
  usbMIDI.read();
  Serial.print(app5stepcount);
  Serial.print(ledstate11);
  Serial.println(app5patternKick[0]);
}



void beatClock1(byte realtimebyte) {
  if (realtimebyte == START || realtimebyte == CONTINUE) {

  }
  if (realtimebyte == STOP) {                              //clear upper led row when stop
    usbMIDI.sendControlChange(110, ledOff, app5channel);
    usbMIDI.sendControlChange(111, ledOff, app5channel);
    usbMIDI.sendControlChange(104, ledRed, app5channel);
    usbMIDI.sendControlChange(105, ledOff, app5channel);
    usbMIDI.sendControlChange(106, ledOff, app5channel);
    usbMIDI.sendControlChange(108, ledOff, app5channel);
    usbMIDI.sendControlChange(107, ledOff, app5channel);
    usbMIDI.sendControlChange(109, ledOff, app5channel);
    zaehler = 0;
    app5stepcount = -1;
  }
  if (realtimebyte == CLOCK) {
    zaehler++;                             //clockcounter to handle the stepcounts
    zaehler2++;
    app5stepcount = ((zaehler) / 6);

    if (zaehler2 == 6) {                   //zaehler2 handles the notelenght
      zaehler2 = 0;
    }

    if (app5stepcount == 16) {            //resetting stepcounter
      app5stepcount = 0;
      zaehler = 0;

    }


    switch (app5stepcount) {     //upper led row and note sending on each step
      case 8:
        if (app5patternKick[0] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[0] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[0] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[0] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(111, ledOff, app5channel);
        usbMIDI.sendControlChange(104, ledOrange, app5channel);
        break;
      case 9:
        if (app5patternKick[1] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[1] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[1] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[1] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(104, ledOff, app5channel);
        usbMIDI.sendControlChange(105, ledOrange, app5channel);
        break;
      case 10:
        if (app5patternKick[2] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[2] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[2] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[2] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(105, ledOff, app5channel);
        usbMIDI.sendControlChange(106, ledOrange, app5channel);
        break;
      case 11:
        if (app5patternKick[3] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[3] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[3] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[3] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(106, ledOff, app5channel);
        usbMIDI.sendControlChange(107, ledOrange, app5channel);
        break;
      case 12:
        if (app5patternKick[4] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[4] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[4] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[4] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(107, ledOff, app5channel);
        usbMIDI.sendControlChange(108, ledOrange, app5channel);
        break;
      case 13:
        if (app5patternKick[5] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[5] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[5] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[5] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(108, ledOff, app5channel);
        usbMIDI.sendControlChange(109, ledOrange, app5channel);
        break;
      case 14:
        if (app5patternKick[6] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[6] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[6] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[6] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(109, ledOff, app5channel);
        usbMIDI.sendControlChange(110, ledOrange, app5channel);
        break;
      case 15:
        if (app5patternKick[7] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[7] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[7] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[7] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(110, ledOff, app5channel);
        usbMIDI.sendControlChange(111, ledOrange, app5channel);
        break;
      case 0:
        if (app5patternKick[8] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[8] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[8] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[8] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(111, ledOff, app5channel);
        usbMIDI.sendControlChange(104, ledGreen, app5channel);
        break;
      case 1:
        if (app5patternKick[9] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[9] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[9] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[9] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(104, ledOff, app5channel);
        usbMIDI.sendControlChange(105, ledGreen, app5channel);
        break;
      case 2:
        if (app5patternKick[10] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[10] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[10] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[10] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(105, ledOff, app5channel);
        usbMIDI.sendControlChange(106, ledGreen, app5channel);
        break;
      case 3:
        if (app5patternKick[11] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[11] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[11] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[11] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(106, ledOff, app5channel);
        usbMIDI.sendControlChange(107, ledGreen, app5channel);
        break;
      case 4:
        if (app5patternKick[12] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[12] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[12] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[12] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(107, ledOff, app5channel);
        usbMIDI.sendControlChange(108, ledGreen, app5channel);
        break;
      case 5:
        if (app5patternKick[13] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[13] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[13] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[13] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(108, ledOff, app5channel);
        usbMIDI.sendControlChange(109, ledGreen, app5channel);
        break;
      case 6:
        if (app5patternKick[14] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[14] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[14] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[14] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(109, ledOff, app5channel);
        usbMIDI.sendControlChange(110, ledGreen, app5channel);
        break;
      case 7:
        if (app5patternKick[15] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
          }
        }
        if (app5patternClap[15] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatOp[15] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
          }
        }
        if (app5patternHatCl[15] == 1) {
          if (zaehler2 == 0) {
            usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
          }
        }
        usbMIDI.sendControlChange(110, ledOff, app5channel);
        usbMIDI.sendControlChange(111, ledGreen, app5channel);
        //                app5stepcount = 0;
        break;
    }
    usbMIDI.sendNoteOff(36, veloOff, app5Outchannel); //just to make sure we have clean note Off´s
    usbMIDI.sendNoteOff(37, veloOff, app5Outchannel); //just to make sure we have clean note Off´s
    usbMIDI.sendNoteOff(38, veloOff, app5Outchannel); //just to make sure we have clean note Off´s
    usbMIDI.sendNoteOff(39, veloOff, app5Outchannel); //just to make sure we have clean note Off´s

    if (app5Kickfill == 1) {   // Note fill handling
      if (zaehler2 == 0) {
        usbMIDI.sendNoteOn(36, veloOn, app5Outchannel);
      }
      else {
        usbMIDI.sendNoteOff(36, veloOff, app5Outchannel);
      }
    }
    if (app5Clapfill == 1) {
      if (zaehler2 == 0) {
        usbMIDI.sendNoteOn(37, veloOn, app5Outchannel);
      }
      else {
        usbMIDI.sendNoteOff(37, veloOff, app5Outchannel);
      }
    }
    if (app5HatClfill == 1) {
      if (zaehler2 == 0) {
        usbMIDI.sendNoteOn(38, veloOn, app5Outchannel);
      }
      else {
        usbMIDI.sendNoteOff(38, veloOff, app5Outchannel);
      }
    }
    if (app5HatOpfill == 1) {
      if (zaehler2 == 0) {
        usbMIDI.sendNoteOn(39, veloOn, app5Outchannel);
      }
      else {
        usbMIDI.sendNoteOff(39, veloOff, app5Outchannel);
      }
    }
    if (app5Kickmute == 1) {
      usbMIDI.sendNoteOff(36, veloOff, app5Outchannel); //just to make sure we have clean note Off´s
    }
  }
}
void OnNoteOn(byte channel, byte note, byte velocity) {      //noteon handling Apps
  if (channel == app5channel) {
    if (note == 112) {
      if (app5patternKick[0] == 0) {
        app5patternKick[0] = 1;
        usbMIDI.sendNoteOn(112, ledOrange, app5channel);
      }
      else {
        app5patternKick[0] = 0;
        usbMIDI.sendNoteOff(112, ledOff, app5channel);
      }
    }
    if (note == 113) {
      if (app5patternKick[1] == 0) {
        app5patternKick[1] = 1;
        usbMIDI.sendNoteOn(113, ledOrange, app5channel);
      }
      else {
        app5patternKick[1] = 0;
        usbMIDI.sendNoteOff(113, ledOff, app5channel);
      }
    }
    if (note == 114) {
      if (app5patternKick[2] == 0) {
        app5patternKick[2] = 1;
        usbMIDI.sendNoteOn(114, ledOrange, app5channel);
      }
      else {
        app5patternKick[2] = 0;
        usbMIDI.sendNoteOff(114, ledOff, app5channel);
      }
    }
    if (note == 115) {
      if (app5patternKick[3] == 0) {
        app5patternKick[3] = 1;
        usbMIDI.sendNoteOn(115, ledOrange, app5channel);
      }
      else {
        app5patternKick[3] = 0;
        usbMIDI.sendNoteOff(115, ledOff, app5channel);
      }
    }
    if (note == 116) {
      if (app5patternKick[4] == 0) {
        app5patternKick[4] = 1;
        usbMIDI.sendNoteOn(116, ledOrange, app5channel);
      }
      else {
        app5patternKick[4] = 0;
        usbMIDI.sendNoteOff(116, ledOff, app5channel);
      }
    }
    if (note == 117) {
      if (app5patternKick[5] == 0) {
        app5patternKick[5] = 1;
        usbMIDI.sendNoteOn(117, ledOrange, app5channel);
      }
      else {
        app5patternKick[5] = 0;
        usbMIDI.sendNoteOff(117, ledOff, app5channel);
      }
    }
    if (note == 118) {
      if (app5patternKick[6] == 0) {
        app5patternKick[6] = 1;
        usbMIDI.sendNoteOn(118, ledOrange, app5channel);
      }
      else {
        app5patternKick[6] = 0;
        usbMIDI.sendNoteOff(118, ledOff, app5channel);
      }
    }
    if (note == 119) {
      if (app5patternKick[7] == 0) {
        app5patternKick[7] = 1;
        usbMIDI.sendNoteOn(119, ledOrange, app5channel);
      }
      else {
        app5patternKick[7] = 0;
        usbMIDI.sendNoteOff(119, ledOff, app5channel);
      }
    }
    if (note == 80) {
      if (app5patternClap[0] == 0) {
        app5patternClap[0] = 1;
        usbMIDI.sendNoteOn(80, ledOrange, app5channel);
      }
      else {
        app5patternClap[0] = 0;
        usbMIDI.sendNoteOff(80, ledOff, app5channel);
      }
    }
    if (note == 81) {
      if (app5patternClap[1] == 0) {
        app5patternClap[1] = 1;
        usbMIDI.sendNoteOn(81, ledOrange, app5channel);
      }
      else {
        app5patternClap[1] = 0;
        usbMIDI.sendNoteOff(81, ledOff, app5channel);
      }
    }
    if (note == 82) {
      if (app5patternClap[2] == 0) {
        app5patternClap[2] = 1;
        usbMIDI.sendNoteOn(82, ledOrange, app5channel);
      }
      else {
        app5patternClap[2] = 0;
        usbMIDI.sendNoteOff(82, ledOff, app5channel);
      }
    }
    if (note == 83) {
      if (app5patternClap[3] == 0) {
        app5patternClap[3] = 1;
        usbMIDI.sendNoteOn(83, ledOrange, app5channel);
      }
      else {
        app5patternClap[3] = 0;
        usbMIDI.sendNoteOff(83, ledOff, app5channel);
      }
    }
    if (note == 84) {
      if (app5patternClap[4] == 0) {
        app5patternClap[4] = 1;
        usbMIDI.sendNoteOn(84, ledOrange, app5channel);
      }
      else {
        app5patternClap[4] = 0;
        usbMIDI.sendNoteOff(84, ledOff, app5channel);
      }
    }
    if (note == 85) {
      if (app5patternClap[5] == 0) {
        app5patternClap[5] = 1;
        usbMIDI.sendNoteOn(85, ledOrange, app5channel);
      }
      else {
        app5patternClap[5] = 0;
        usbMIDI.sendNoteOff(85, ledOff, app5channel);
      }
    }
    if (note == 86) {
      if (app5patternClap[6] == 0) {
        app5patternClap[6] = 1;
        usbMIDI.sendNoteOn(86, ledOrange, app5channel);
      }
      else {
        app5patternClap[6] = 0;
        usbMIDI.sendNoteOff(86, ledOff, app5channel);
      }
    }
    if (note == 87) {
      if (app5patternClap[7] == 0) {
        app5patternClap[7] = 1;
        usbMIDI.sendNoteOn(87, ledOrange, app5channel);
      }
      else {
        app5patternClap[7] = 0;
        usbMIDI.sendNoteOff(87, ledOff, app5channel);
      }
    }
    if (note == 48) {
      if (app5patternHatOp[0] == 0) {
        app5patternHatOp[0] = 1;
        usbMIDI.sendNoteOn(48, ledOrange, app5channel);
      }
      else {
        app5patternHatOp[0] = 0;
        usbMIDI.sendNoteOff(48, ledOff, app5channel);
      }
    }
    if (note == 49) {
      if (app5patternHatOp[1] == 0) {
        app5patternHatOp[1] = 1;
        usbMIDI.sendNoteOn(49, ledOrange, app5channel);
      }
      else {
        app5patternHatOp[1] = 0;
        usbMIDI.sendNoteOff(49, ledOff, app5channel);
      }
    }
    if (note == 50) {
      if (app5patternHatOp[2] == 0) {
        app5patternHatOp[2] = 1;
        usbMIDI.sendNoteOn(50, ledOrange, app5channel);
      }
      else {
        app5patternHatOp[2] = 0;
        usbMIDI.sendNoteOff(50, ledOff, app5channel);
      }
    }
    if (note == 51) {
      if (app5patternHatOp[3] == 0) {
        app5patternHatOp[3] = 1;
        usbMIDI.sendNoteOn(51, ledOrange, app5channel);
      }
      else {
        app5patternHatOp[3] = 0;
        usbMIDI.sendNoteOff(51, ledOff, app5channel);
      }
    }
    if (note == 52) {
      if (app5patternHatOp[4] == 0) {
        app5patternHatOp[4] = 1;
        usbMIDI.sendNoteOn(52, ledOrange, app5channel);
      }
      else {
        app5patternHatOp[4] = 0;
        usbMIDI.sendNoteOff(52, ledOff, app5channel);
      }
    }
    if (note == 53) {
      if (app5patternHatOp[5] == 0) {
        app5patternHatOp[5] = 1;
        usbMIDI.sendNoteOn(53, ledOrange, app5channel);
      }
      else {
        app5patternHatOp[5] = 0;
        usbMIDI.sendNoteOff(53, ledOff, app5channel);
      }
    }
    if (note == 54) {
      if (app5patternHatOp[6] == 0) {
        app5patternHatOp[6] = 1;
        usbMIDI.sendNoteOn(54, ledOrange, app5channel);
      }
      else {
        app5patternHatOp[6] = 0;
        usbMIDI.sendNoteOff(54, ledOff, app5channel);
      }
    }
    if (note == 55) {
      if (app5patternHatOp[7] == 0) {
        app5patternHatOp[7] = 1;
        usbMIDI.sendNoteOn(55, ledOrange, app5channel);
      }
      else {
        app5patternHatOp[7] = 0;
        usbMIDI.sendNoteOff(55, ledOff, app5channel);
      }
    }
    if (note == 16) {
      if (app5patternHatCl[0] == 0) {
        app5patternHatCl[0] = 1;
        usbMIDI.sendNoteOn(16, ledOrange, app5channel);
      }
      else {
        app5patternHatCl[0] = 0;
        usbMIDI.sendNoteOff(16, ledOff, app5channel);
      }
    }
    if (note == 17) {
      if (app5patternHatCl[1] == 0) {
        app5patternHatCl[1] = 1;
        usbMIDI.sendNoteOn(17, ledOrange, app5channel);
      }
      else {
        app5patternHatCl[1] = 0;
        usbMIDI.sendNoteOff(17, ledOff, app5channel);
      }
    }
    if (note == 18) {
      if (app5patternHatCl[2] == 0) {
        app5patternHatCl[2] = 1;
        usbMIDI.sendNoteOn(18, ledOrange, app5channel);
      }
      else {
        app5patternHatCl[2] = 0;
        usbMIDI.sendNoteOff(18, ledOff, app5channel);
      }
    }
    if (note == 19) {
      if (app5patternHatCl[3] == 0) {
        app5patternHatCl[3] = 1;
        usbMIDI.sendNoteOn(19, ledOrange, app5channel);
      }
      else {
        app5patternHatCl[3] = 0;
        usbMIDI.sendNoteOff(19, ledOff, app5channel);
      }
    }
    if (note == 20) {
      if (app5patternHatCl[4] == 0) {
        app5patternHatCl[4] = 1;
        usbMIDI.sendNoteOn(20, ledOrange, app5channel);
      }
      else {
        app5patternHatCl[4] = 0;
        usbMIDI.sendNoteOff(20, ledOff, app5channel);
      }
    }
    if (note == 21) {
      if (app5patternHatCl[5] == 0) {
        app5patternHatCl[5] = 1;
        usbMIDI.sendNoteOn(21, ledOrange, app5channel);
      }
      else {
        app5patternHatCl[5] = 0;
        usbMIDI.sendNoteOff(21, ledOff, app5channel);
      }
    }
    if (note == 22) {
      if (app5patternHatCl[6] == 0) {
        app5patternHatCl[6] = 1;
        usbMIDI.sendNoteOn(22, ledOrange, app5channel);
      }
      else {
        app5patternHatCl[6] = 0;
        usbMIDI.sendNoteOff(22, ledOff, app5channel);
      }
    }
    if (note == 23) {
      if (app5patternHatCl[7] == 0) {
        app5patternHatCl[7] = 1;
        usbMIDI.sendNoteOn(23, ledOrange, app5channel);
      }
      else {
        app5patternHatCl[7] = 0;
        usbMIDI.sendNoteOff(23, ledOff, app5channel);
      }
    }
    if (note == 96) {
      if (app5patternKick[8] == 0) {
        app5patternKick[8] = 1;
        usbMIDI.sendNoteOn(96, ledGreen, app5channel);
      }
      else {
        app5patternKick[8] = 0;
        usbMIDI.sendNoteOff(96, ledOff, app5channel);
      }
    }
    if (note == 97) {
      if (app5patternKick[9] == 0) {
        app5patternKick[9] = 1;
        usbMIDI.sendNoteOn(97, ledGreen, app5channel);
      }
      else {
        app5patternKick[9] = 0;
        usbMIDI.sendNoteOff(97, ledOff, app5channel);
      }
    }
    if (note == 98) {
      if (app5patternKick[10] == 0) {
        app5patternKick[10] = 1;
        usbMIDI.sendNoteOn(98, ledGreen, app5channel);
      }
      else {
        app5patternKick[10] = 0;
        usbMIDI.sendNoteOff(98, ledOff, app5channel);
      }
    }
    if (note == 99) {
      if (app5patternKick[11] == 0) {
        app5patternKick[11] = 1;
        usbMIDI.sendNoteOn(99, ledGreen, app5channel);
      }
      else {
        app5patternKick[11] = 0;
        usbMIDI.sendNoteOff(99, ledOff, app5channel);
      }
    }
    if (note == 100) {
      if (app5patternKick[12] == 0) {
        app5patternKick[12] = 1;
        usbMIDI.sendNoteOn(100, ledGreen, app5channel);
      }
      else {
        app5patternKick[12] = 0;
        usbMIDI.sendNoteOff(100, ledOff, app5channel);
      }
    }
    if (note == 101) {
      if (app5patternKick[13] == 0) {
        app5patternKick[13] = 1;
        usbMIDI.sendNoteOn(101, ledGreen, app5channel);
      }
      else {
        app5patternKick[13] = 0;
        usbMIDI.sendNoteOff(101, ledOff, app5channel);
      }
    }
    if (note == 102) {
      if (app5patternKick[14] == 0) {
        app5patternKick[14] = 1;
        usbMIDI.sendNoteOn(102, ledGreen, app5channel);
      }
      else {
        app5patternKick[14] = 0;
        usbMIDI.sendNoteOff(102, ledOff, app5channel);
      }
    }
    if (note == 103) {
      if (app5patternKick[15] == 0) {
        app5patternKick[15] = 1;
        usbMIDI.sendNoteOn(103, ledGreen, app5channel);
      }
      else {
        app5patternKick[15] = 0;
        usbMIDI.sendNoteOff(103, ledOff, app5channel);
      }
    }
    if (note == 64) {
      if (app5patternClap[8] == 0) {
        app5patternClap[8] = 1;
        usbMIDI.sendNoteOn(64, ledGreen, app5channel);
      }
      else {
        app5patternClap[8] = 0;
        usbMIDI.sendNoteOff(64, ledOff, app5channel);
      }
    }
    if (note == 65) {
      if (app5patternClap[9] == 0) {
        app5patternClap[9] = 1;
        usbMIDI.sendNoteOn(65, ledGreen, app5channel);
      }
      else {
        app5patternClap[9] = 0;
        usbMIDI.sendNoteOff(65, ledOff, app5channel);
      }
    }
    if (note == 66) {
      if (app5patternClap[10] == 0) {
        app5patternClap[10] = 1;
        usbMIDI.sendNoteOn(66, ledGreen, app5channel);
      }
      else {
        app5patternClap[10] = 0;
        usbMIDI.sendNoteOff(66, ledOff, app5channel);
      }
    }
    if (note == 67) {
      if (app5patternClap[11] == 0) {
        app5patternClap[11] = 1;
        usbMIDI.sendNoteOn(67, ledGreen, app5channel);
      }
      else {
        app5patternClap[11] = 0;
        usbMIDI.sendNoteOff(67, ledOff, app5channel);
      }
    }
    if (note == 68) {
      if (app5patternClap[12] == 0) {
        app5patternClap[12] = 1;
        usbMIDI.sendNoteOn(68, ledGreen, app5channel);
      }
      else {
        app5patternClap[12] = 0;
        usbMIDI.sendNoteOff(68, ledOff, app5channel);
      }
    }
    if (note == 69) {
      if (app5patternClap[13] == 0) {
        app5patternClap[13] = 1;
        usbMIDI.sendNoteOn(69, ledGreen, app5channel);
      }
      else {
        app5patternClap[13] = 0;
        usbMIDI.sendNoteOff(69, ledOff, app5channel);
      }
    }
    if (note == 70) {
      if (app5patternClap[14] == 0) {
        app5patternClap[14] = 1;
        usbMIDI.sendNoteOn(70, ledGreen, app5channel);
      }
      else {
        app5patternClap[14] = 0;
        usbMIDI.sendNoteOff(70, ledOff, app5channel);
      }
    }
    if (note == 71) {
      if (app5patternClap[15] == 0) {
        app5patternClap[15] = 1;
        usbMIDI.sendNoteOn(71, ledGreen, app5channel);
      }
      else {
        app5patternClap[15] = 0;
        usbMIDI.sendNoteOff(71, ledOff, app5channel);
      }
    }
    if (note == 32) {
      if (app5patternHatOp[8] == 0) {
        app5patternHatOp[8] = 1;
        usbMIDI.sendNoteOn(32, ledGreen, app5channel);
      }
      else {
        app5patternHatOp[8] = 0;
        usbMIDI.sendNoteOff(32, ledOff, app5channel);
      }
    }
    if (note == 33) {
      if (app5patternHatOp[9] == 0) {
        app5patternHatOp[9] = 1;
        usbMIDI.sendNoteOn(33, ledGreen, app5channel);
      }
      else {
        app5patternHatOp[9] = 0;
        usbMIDI.sendNoteOff(33, ledOff, app5channel);
      }
    }
    if (note == 34) {
      if (app5patternHatOp[10] == 0) {
        app5patternHatOp[10] = 1;
        usbMIDI.sendNoteOn(34, ledGreen, app5channel);
      }
      else {
        app5patternHatOp[10] = 0;
        usbMIDI.sendNoteOff(34, ledOff, app5channel);
      }
    }
    if (note == 35) {
      if (app5patternHatOp[11] == 0) {
        app5patternHatOp[11] = 1;
        usbMIDI.sendNoteOn(35, ledGreen, app5channel);
      }
      else {
        app5patternHatOp[11] = 0;
        usbMIDI.sendNoteOff(35, ledOff, app5channel);
      }
    }
    if (note == 36) {
      if (app5patternHatOp[12] == 0) {
        app5patternHatOp[12] = 1;
        usbMIDI.sendNoteOn(36, ledGreen, app5channel);
      }
      else {
        app5patternHatOp[12] = 0;
        usbMIDI.sendNoteOff(36, ledOff, app5channel);
      }
    }
    if (note == 37) {
      if (app5patternHatOp[13] == 0) {
        app5patternHatOp[13] = 1;
        usbMIDI.sendNoteOn(37, ledGreen, app5channel);
      }
      else {
        app5patternHatOp[13] = 0;
        usbMIDI.sendNoteOff(37, ledOff, app5channel);
      }
    }
    if (note == 38) {
      if (app5patternHatOp[14] == 0) {
        app5patternHatOp[14] = 1;
        usbMIDI.sendNoteOn(38, ledGreen, app5channel);
      }
      else {
        app5patternHatOp[14] = 0;
        usbMIDI.sendNoteOff(38, ledOff, app5channel);
      }
    }
    if (note == 39) {
      if (app5patternHatOp[15] == 0) {
        app5patternHatOp[15] = 1;
        usbMIDI.sendNoteOn(39, ledGreen, app5channel);
      }
      else {
        app5patternHatOp[15] = 0;
        usbMIDI.sendNoteOff(39, ledOff, app5channel);
      }
    }
    if (note == 0) {
      if (app5patternHatCl[8] == 0) {
        app5patternHatCl[8] = 1;
        usbMIDI.sendNoteOn(0, ledGreen, app5channel);
      }
      else {
        app5patternHatCl[8] = 0;
        usbMIDI.sendNoteOff(0, ledOff, app5channel);
      }
    }
    if (note == 1) {
      if (app5patternHatCl[9] == 0) {
        app5patternHatCl[9] = 1;
        usbMIDI.sendNoteOn(1, ledGreen, app5channel);
      }
      else {
        app5patternHatCl[9] = 0;
        usbMIDI.sendNoteOff(1, ledOff, app5channel);
      }
    }
    if (note == 2) {
      if (app5patternHatCl[10] == 0) {
        app5patternHatCl[10] = 1;
        usbMIDI.sendNoteOn(2, ledGreen, app5channel);
      }
      else {
        app5patternHatCl[10] = 0;
        usbMIDI.sendNoteOff(2, ledOff, app5channel);
      }
    }
    if (note == 3) {
      if (app5patternHatCl[11] == 0) {
        app5patternHatCl[11] = 1;
        usbMIDI.sendNoteOn(3, ledGreen, app5channel);
      }
      else {
        app5patternHatCl[11] = 0;
        usbMIDI.sendNoteOff(3, ledOff, app5channel);
      }
    }
    if (note == 4) {
      if (app5patternHatCl[12] == 0) {
        app5patternHatCl[12] = 1;
        usbMIDI.sendNoteOn(4, ledGreen, app5channel);
      }
      else {
        app5patternHatCl[12] = 0;
        usbMIDI.sendNoteOff(4, ledOff, app5channel);
      }
    }
    if (note == 5) {
      if (app5patternHatCl[13] == 0) {
        app5patternHatCl[13] = 1;
        usbMIDI.sendNoteOn(5, ledGreen, app5channel);
      }
      else {
        app5patternHatCl[13] = 0;
        usbMIDI.sendNoteOff(5, ledOff, app5channel);
      }
    }
    if (note == 6) {
      if (app5patternHatCl[14] == 0) {
        app5patternHatCl[14] = 1;
        usbMIDI.sendNoteOn(6, ledGreen, app5channel);
      }
      else {
        app5patternHatCl[14] = 0;
        usbMIDI.sendNoteOff(6, ledOff, app5channel);
      }
    }
    if (note == 7) {
      if (app5patternHatCl[15] == 0) {
        app5patternHatCl[15] = 1;
        usbMIDI.sendNoteOn(7, ledGreen, app5channel);
      }
      else {
        app5patternHatCl[15] = 0;
        usbMIDI.sendNoteOff(7, ledOff, app5channel);
      }
    }
    if (note == 120) {
      app5Kickfill = 1;
    }
    if (note == 88) {
      app5Clapfill = 1;
    }
    if (note == 56) {
      app5HatClfill = 1;
    }
    if (note == 24) {
      app5HatOpfill = 1;
    }
    if (note == 104) {
      app5Kickmute = 1;
    }
  }
}
void OnNoteOff(byte channel, byte note, byte velocity) {      //noteoff handling Apps
  if (channel == app5channel) {
    if (note == 120) {
      app5Kickfill = 0;
    }
    if (note == 88) {
      app5Clapfill = 0;
    }
    if (note == 56) {
      app5HatClfill = 0;
    }
    if (note == 24) {
      app5HatOpfill = 0;
    }
    if (note == 104) {
      app5Kickmute = 0;
    }
  }
}
