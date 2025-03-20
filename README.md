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
pueden ser cambiadas. Al final de este README se encuentra
una lista con todas las combinaciones de teclas.

También he incluido un archivo de configuración más
depurado, `default.config.def.h`, que funciona como base
para quienes quieran hacer modificaciones extensas a sus
combinaciones de teclas y no prefieren utilizar las que yo
he establecido.

## Parches

### dwm-alwayscenter
- Todas las ventanas flotantes se generan en el centro de la
  pantalla.

### dwm-noborderfloatingfix
- Si sólo hay una ventana visible, esta no tendrá borde.

### dwm-6.1-tagintostack-allmaster
- Cuando se activa la vista de dos tags, mantén la ventana
  maestra en su lugar. (Desafortunadamente, no se mantiene)

dwm-pertag-6.5.diff
    -A pesar de ser de mayor tamaño, se aplica antes porque
    otros parches comienzan a depender de ella. También tuve
    que hacer una modificación pues tagintostack maneja una
    variable del mismo nombre en la misma función.
dwm-pertag-togglelayout-6.5.diff
    -Aplicada algo manualmente. Dejé la función
    setlayout intacta y los cambios los puse en una
    función que llamé setlayouttoggle, a fin de que este
    parche no cause conflicto con el parche de
    resetlayout. En config.def.h, hago la llamada a
    setlayouttoggle explícitamente para los layouts que
    quiero que el toggle aplique.
dwm-resetnmaster-pertag-6.3.diff
dwm-6.0-winview.diff
dwm-actualfullscreen-20211013-cb3f58a.diff
dwm-resetlayout-6.2.diff
    -La parte del código que resetea el layout cuando queda
    una sola ventana en vista ha sido comentada, pues este
    comportamiento no es de mi agrado.
dwm-zoomswap-6.2.diff
dwm-resizecorners-6.5.diff
dwm-cyclelayouts-20180524-6.2.diff
dwm-attachbelow-6.2.diff
dwm-movestack-20211115-a786211.diff
dwm-colorbar-6.3.diff
dwm-preserveonrestart-6.3.diff
dwm-alternativetags-6.3.diff
dwm-canfocusfloating-20210724-b914109.diff
dwm-xresources-6.2.diff
dwm-alpha-20230401-348f655.diff
    -Cambios hechos según [esta publicación](https://www.reddit.com/r/suckless/comments/spdfwn/dwm_alpha_and_colorbar_patch_issue/)
    para que sea compatible con el parche de colorbar.
dwm-winicon-6.3-v2.1.diff
    -Cambios hechos según [la
    documentación](https://dwm.suckless.org/patches/winicon/)
    para que sea compatible con el parche de alpha.
dwm-swallow-6.5.diff
dwm-vanitygaps-6.4.diff
shiftview.diff
    -Keybindings añadidos manualmente a config.def.h
## Combinaciones de teclas (keybindings)

| Teclas | Descripción |
|--|--|
|**Etiquetas (Tags)**
|`Mod + [1..9]`         |   Ver la etiqueta [1..9]|
|`Mod + Ctrl + [1..9]`  |   Añadir etiqueta [1..9] a la vista|
|`Mod + 0`              |   Añadir todas las etiquetas a la vista|
|`Mod + Ctrl + H`       |   Ver la anterior etiqueta (n-1)|
|`Mod + Ctrl + L`       |   Ver la siguiente etiqueta (n+1)|
|`Mod + S`              |   Ir a la etiqueta de la ventana activa (útil con Mod+0)|
|**Ventanas**
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
|**Esquemas (Layouts)**
|`Mod + T`              |   Activar esquema `tile` (predeterminado)|
|`Mod + D`              |   Activar/desactivar esquema `deck`|
|`Mod + M`              |   Activar esquema horizontal (`bstackhoriz`)|
|`Mod + Plus`           |   Siguiente esquema de la lista|
|`Mod + Minus`          |   Anterior esquema de la lista|
|`Mod + Escape`         |   Restablecer esquema (y número de ventanas maestras y tamaño de zona maestra)|
|**Programas y scripts (configurables en config.def.h)**
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
|**Otros**
|`Mod + B`              |   Activar/desactivar la barra|
|`Mod + N`              |   Activar/desactivar las etiquetas alternativas|
|`Mod + Shift + Q`      |   Cerrar (reiniciar) dwm|
