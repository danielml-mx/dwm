# dwm - dynamic window manager

## Introducción

Este es mi fork personal de [suckless
dwm](https://dwm.suckless.org/). Incluye un total de 27
parches que extienden la funcionalidad de este manejado de
ventadas rápido y minimalista. Entre las mejores
modificaciones se encuentran las siguientes:

- Espacios entre las ventanas (gaps)
- 14 layouts con soporte de gaps
- "Window swallowing"
- Configuración estética a través de Xresources

Debajo se encuentra una lista con todos los parches añadidos
y su utilidad. Además, estos ser consultados bajo el
directorio `patches/`, o bien en el archivo `patches.txt`.

## Configuración

La configuración, como de costumbre, se hace a través del
archivo `config.def.h`. En este caso este incluye varias
modificaciones personales, particularmente a las
combinaciones de teclas (keybindings) así como programas y
scripts de uso frecuente a los que puedo acceder rápidamente
al presionar una combinación de teclas específica. Sin
embargo, también he incluido un archivo de configuración más
depurado, `default.config.def.h`, que funciona como base
para quienes quieran hacer modificaciones extensas a sus
combinaciones de teclas y no prefieren utilizar las que yo
he establecido.

## Combinaciones de teclas (keybindings)
| Teclas | Descripción |
                        |--|--|
        | Movimiento de etiquetas (tags) |
|`Mod + [1..9]`             |Ver el tag [1..9]|
|`Mod + Ctrl + [1..9]`      |Añadir tag [1..9] a la vista|
|`Mod + 0`                  |Añadir todos los tags a la vista|
|`Mod + Ctrl + H`           |Ver el anterior tag (n-1)|
|`Mod + Ctrl + L`           |Ver el siguiente tag (n+1)|
                    | Ventanas |
|`Mod + Shift + [1..9]`     |Enviar la ventana activa al tag [1..9]|
|`Mod + J`                  |Cambiar el enfoque a la siguiente ventana|
|`Mod + K`                  |Cambiar el enfoque a la anterior ventana|
|`Mod + Shift + J`          |Mover la ventana activa al siguiente lugar|
|`Mod + Shift + K`          |Mover la ventana activa al anterior lugar|
                    | Programas |
|`Mod + R`                  |Abrir terminal|
|`Ctrl + Shift + T`         |Nueva pestaña en el directorio de la actual pestaña|
|`Ctrl + W`                 |Cerrar pestaña|
|`Ctrl + Tab`               |Siguiente pestaña|
|`Ctrl + Shift + Tab`       |Anterior pestaña|
|`Ctrl + [1..9]`            |Ver la pestaña [1..9]|
|`Ctrl + Shift + H`         |Mover la actual pestaña hacia la izquierda|
|`Ctrl + Shift + L`         |Mover la actual pestaña hacia la derecha|


