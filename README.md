# Programme d'affichage des informations de la batterie

Programme permettant d'afficher les informations de la batterie sur l'écran tft.

## Installation

### Logiciel

[Arduino](https://www.arduino.cc/en/Main/Software)

### Librairies
    
Installer les librairies Adafruit GFX et ST7735 via l'application Arduino (Croquis->Include Library->Manage Libraries) ou les télécharger:

[GFX](http://www.arduinolibraries.info/libraries/adafruit-gfx-library)

[ST 7735](http://www.arduinolibraries.info/libraries/adafruit-st7735-library)

### Matériel

 - Utilisation de l'arduino DUE et de son programming port.

![alt text](https://raw.githubusercontent.com/WalkingMachine/wm_battery_screen/master/Ressources/Arduino%20DUE%20programming%20port.jpg)

 - Utilisation d'un écran tft 1.8", communication SPI.

![alt text](https://raw.githubusercontent.com/WalkingMachine/wm_battery_screen/master/Ressources/tft128par160.jpeg)

 - PCBs avec boutons poussoirs.

todo image pcbs

### Cablâge

|  Borne de l'écran  |  Pin de l'Arduino  |
|:------------------:|:------------------:|
|        VCC         |         3.3V       |
|        GND         |         SPI 6      |
|        LED         |         3.3V       |
|        CS          |         Pin 10     |
|        RESET       |         Pin 9      |
|        A0          |         Pin 8      |
|        SDA         |         SPI 4      |
|        SCK         |         SPI 3      |

   - Numérotation Pins SPI :
   
   ![alt text](https://raw.githubusercontent.com/WalkingMachine/wm_battery_screen/master/Ressources/Arduino%20DUE%20SPI%20pins.jpg)

   - 4 Boutons poussoirs avec pull down (R = 20k Ohms) :

   - Signal 5V en provenance de l'Arduino (Voir image) :
   
   ![alt text](https://raw.githubusercontent.com/WalkingMachine/wm_battery_screen/master/Ressources/Arduino%20Due%205V.jpg)
   
   - Cablâge des boutons : 

      | Bouton |    Pin   |
      |:------:|:--------:|
      |    1   |     5    |
      |    2   |     4    |
      |    3   |     3    |
      |    4   |     2    |


   - Fonction des boutons :
   
      | Bouton | Fonction |
      |:------:|:--------:|
      |    1   |   Next   |
      |    2   | Previous |
      |    3   |    Up    |
      |    4   |   Down   |


## Crédits

[Adafruit ST7735](https://learn.adafruit.com/1-8-tft-display?view=all)

## License

MIT
