# dwm - dynamic window manager

## Introducción

Esta es mi fork personal de [suckless
dwm](https://dwm.suckless.org/). Incluye un total de 27
parches que extienden la funcionalidad de este rápido y
minimalista manejador de ventanas. Entre las mejores
modificaciones se encuentran las siguientes:

- Espacios entre las ventanas (gaps)
- 14 esquemas (layouts) con soporte de gaps
- Las nuevas ventanas se añaden debajo de la activa
  (attachbelow)
- Uso eficiente de ventanas de terminal (window swallowing)
- Configuración estética a través de Xresources

Debajo se encuentra una lista exhaustiva de todos los
parches aplicados y de las funciones que proveen.

## Configuración

La configuración, como de costumbre, se hace a través del
archivo `config.def.h`, el cual es bastante intuitivo. En
este caso incluye varias modificaciones personales,
particularmente a las combinaciones de teclas (keybindings)
así como programas y scripts de uso frecuente a los que
puedo acceder rápidamente al presionar una combinación de
teclas específica. Todos los programas y las combinaciones
pueden ser cambiadas.

Aun así, también he incluido un archivo de configuración
más depurado, `default.config.def.h`, que funciona como base
para quienes quieran hacer modificaciones extensas a sus
combinaciones de teclas y no prefieren utilizar las que yo
he establecido.

## Combinaciones de teclas (keybindings)

### **Etiquetas (Tags)**
| Teclas | Descripción |
|--|--|
|`Mod + [1..9]`         |   Ver la etiqueta [1..9]|
|`Mod + Ctrl + [1..9]`  |   Añadir etiqueta [1..9] a la vista|
|`Mod + 0`              |   Añadir todas las etiquetas a la vista|
|`Mod + Ctrl + H`       |   Ver la anterior etiqueta (n-1)|
|`Mod + Ctrl + L`       |   Ver la siguiente etiqueta (n+1)|
|`Mod + S`              |   Ir a la etiqueta de la ventana activa (útil con Mod+0)|

### **Ventanas**
| Teclas | Descripción |
|--|--|
|`Mod + Shift + [1..9]` |   Enviar la ventana activa a la etiqueta [1..9]|
|`Mod + J`              |   Cambiar el enfoque a la siguiente ventana|
|`Mod + K`              |   Cambiar el enfoque a la anterior ventana|
|`Mod + Shift + J`      |   Mover la ventana activa al siguiente lugar|
|`Mod + Shift + K`      |   Mover la ventana activa al anterior lugar|
|`Mod + Enter`          |   Alternar enfoque hacia la ventana maestra|
|`Mod + Shift + Enter`  |   Alternar posición con la ventana maestra|
|`Mod + H`              |   Decrementar tamaño de zona maestra (mfact)|
|`Mod + L`              |   Aumentar tamaño de zona maestra (mfact)|
|`Mod + }`              |   Eliminar una ventana de la zona maestra|
|`Mod + {`              |   Añadir una ventana a la zona maestra|
|`Mod + Escape`         |   Restablecer número de ventanas maestras y tamaño de zona maestra (y esquema)|
|`Mod + Shift + F`      |   Ver la ventana en pantalla completa (fullscreen)|
|`Mod + X`              |   Cerrar la ventana activa|

### **Esquemas (Layouts)**
| Teclas | Descripción |
|--|--|
|`Mod + T`              |   Activar esquema `tile` (predeterminado)|
|`Mod + D`              |   Activar/desactivar esquema `deck`|
|`Mod + M`              |   Activar esquema horizontal (`bstackhoriz`)|
|`Mod + Plus`           |   Siguiente esquema de la lista|
|`Mod + Minus`          |   Anterior esquema de la lista|
|`Mod + Escape`         |   Restablecer esquema (y número de ventanas maestras y tamaño de zona maestra)|

### **Programas y scripts (configurables en config.def.h)**
| Teclas | Descripción |
|--|--|
|`Alt + Space`          |   Abrir dmenu|
|`Mod + R`              |   Abrir la terminal|
|`Mod + W`              |   Abrir el navegador web|
|`Mod + Shift + W`      |   Abrir el navegador web (modo privado)|
|`Mod + Shift + P`      |   Selector de contraseñas|
|`Mod + Shift + E`      |   Selector de scripts personales|
|`Mod + Alt + Period`   |   Selector de emojis|
|`Mod + Shift + S`      |   Captura de pantalla|
|`Mod + Shift + R`      |   Videocaptura de pantalla|
|`Mod + Space`          |   Cambiar el formato del teclado|
|`Mod + Shift + L`      |   Bloquear pantalla|
|`Ctrl + Alt + Shift + PgUp`      | Reiniciar|
|`Ctrl + Alt + Shift + PgDn`      | Apagar|

### **Otros**
|--|--|
| Teclas | Descripción |
|`Mod + B`              |   Activar/desactivar la barra|
|`Mod + N`              |   Activar/desactivar las etiquetas alternativas|
|`Mod + Shift + Q`      |   Cerrar dwm\*\*|
