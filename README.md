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

todo images arduino due

 - Utilisation d'un écran tft 1.8", communication SPI.

todo images ecran

 - PCBs avec boutons poussoirs.

todo image pcbs

### Cablâge (Voir images)

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

   - 4 Boutons poussoirs avec pull down (R = 20k Ohms) :

   - Signal 5V en provenance de l'Arduino (Voir image).
   
   - Cablâge des boutons : 

      | Bouton |    Pin   |
      |:------:|:--------:|
      |    1   |     5    |
      |    2   |     4    |
      |    3   |     3    |
      |    4   |     2    |


   - Fonction des boutons : TODO
  


## Crédits

Exemples Adafruit ST7735

## License

MIT
