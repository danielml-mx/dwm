# dwm - dynamic window manager

![screenshot-032125-152009](https://github.com/user-attachments/assets/b0209cfd-f026-4094-9b32-742d3ff4616b)

## Introducción

Esta es mi versión personal de [suckless
dwm](https://dwm.suckless.org/). Incluye un total de 26
parches que extienden la funcionalidad de este rápido y
minimalista manejador de ventanas. Entre las mejores
modificaciones se encuentran las siguientes:

- 14 esquemas con soporte para espacios entre ventanas
- Configuración estética y dinámica a través de Xresources
- Modularidad en el uso de programas preferidos
- Diseño intuitivo basado en las combinaciones de teclas de
  Vim

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

## Funcionalidad y parches 

### dwm-alwayscenter
- Todas las ventanas flotantes se generan en el centro de la
  pantalla.

### dwm-noborderfloatingfix
- Si sólo hay una ventana visible, esta no tendrá borde.

### dwm-6.3-tagintostack-onemaster
- Cuando se activa la vista de varios tags, mantén la ventana
  maestra en su lugar.

### dwm-pertag-6.5
- El esquema (layout), el tamaño de la zona maestra (mfact)
  y si la barra está activa o no son atributos
  independientes para cada etiqueta.

### dwm-pertag-togglelayout-6.5
- Los esquemas activados a través de una combinación de
  teclas pueden ser "desactivados" al volver a presionar la
  misma combinación (alterna al esquema anterior).
- La implementación de esta funcionalidad fue extensamente
  modificada. Dejé la función `setlayout` intacta y los
  cambios los puse en una función que llamé
  `setlayouttoggle`, a fin de que este parche no cause
  conflicto con el parche de `resetlayout`. En en archivo de
  configuración hago la llamada a `setlayouttoggle` explícitamente para los
  esquemas para los que quiero que el alternado aplique.
  Esto último en realidad lo hago más que nada para tener un
  flujo de trabajo en torno al esquema `deck`.

### dwm-resetnmaster-pertag-6.3
- Restablece la cantidad de ventanas en la zona maestra con
  una combinación de teclas.
- Combinación predeterminada: `Mod + Escape`

### dwm-6.0-winview
- Cuando se están visualizando varias etiquetas, se puede
  utilizar una combinación de teclas para ir al esquema de
  la ventana activa.
- Combinación predeterminada: `Mod + S`

### dwm-actualfullscreen-20211013-cb3f58a
- Implementa correctamente la funcionalidad de visualizar
  una pantalla en modo completo a través de una combinación
  de teclas.
- Combinación predeterminada: `Mod + Shift + S`

### dwm-resetlayout-6.2
- Restablece el esquema y el tamaño de la zona maestra a
  través de una combinación de teclas o bien cuando sólo
  haya una ventana en la etiqueta.
- La parte del código que restablece el esquema (y el tamaño
  de la zona maestra) cuando queda una sola ventana en vista
  ha sido comentada, pues este comportamiento no es de mi
  agrado. Quizá después lo modifique para que al menos la
  zona maestra sí se restablezca.
- Combinación predeterminada: `Mod + Escape`

### dwm-focusmaster-return-6.2
- Desde cualquier ventana, regresa el enfoque a la ventana
  maestra a través de una combinación de teclas. Si la
  ventana maestra está enfocada, enfoca la última ventana
  desde la cual se hizo el salto.
- Le hice unas ligeras modificaciones al código al llamar
  `restack()` cuando se hace la combinación de teclas, cosa
  que obliga a que el cliente enfocado siempre esté por
  encima del resto de las ventanas.
- Combinación predeterminada: `Mod + Enter`

### dwm-zoomswap-6.2
- Cambiar la ventana activa con la ventana maestra con una
  combinación de teclas.
- Combinación predeterminada: `Mod + Shift + Enter`

### dwm-resizecorners-6.5
- Las ventanas flotantes pueden ser [reajustadas] desde
  cualquier esquina, no sólo la inferior derecha.

### dwm-cyclelayouts-20180524-6.2
- Añade la posibilidad de alternar entre esquemas según la
  lista establecida en la configuración.
- Combinación predeterminada: 
    - Siguiente esquema: `Mod + Plus`
    - Anterior esquema: `Mod + Minus`

### dwm-attachbelow-6.2
- Las nuevas ventanas se generarán debajo de la activa en la
  jerarquía.

### dwm-movestack-20211115-a786211
- Introduce combinaciones de teclas para mover la ventana
  seleccionada a través de la jerarquía.
- Combinación predeterminada: 
    - Decrementar: `Mod + Shift + J`
    - Incrementar: `Mod + Shift + H`

### dwm-colorbar-6.3
- Expande la configurabilidad de los colores de la barra,
  permitiendo configurar cada sección por separado.

### dwm-preserveonrestart-6.3
- Al reiniciar, las ventanas se mantendrán en sus
  respectivas etiquetas.

### dwm-alternativetags-6.3
- Permite establecer un segundo arreglo de nombres para las
  etiquetas, los cuales pueden ser activados a través de una
  combinación de teclas.
- Combinación predeterminada: `Mod + N`

### dwm-hide_vacant_tags-6.4
- Omite las etiquetas que no tienen ventanas de la barra.

### dwm-xresources-6.2
- Permite configurar ciertos aspectos de la configuración a
  través del protocolo de Xresources.
- He expandido un poco lo que se puede configurar a través
  de Xresources, sin embargo lo he limitado a cuestiones
  exclusivamente estéticas.

### dwm-alpha-20230401-348f655
- Añade la propiedad de transparencia a la barra.
- Algunos cambios se hicieron según [esta
  publicación](https://www.reddit.com/r/suckless/comments/spdfwn/dwm_alpha_and_colorbar_patch_issue/)
  para que sea compatible con el parche de `colorbar`.

### dwm-winicon-6.3-v2.1
- Añade un ícono de programa a la barra.
- Cambios hechos según [la
  documentación](https://dwm.suckless.org/patches/winicon/)
  para que sea compatible con el parche de `alpha`.

### dwm-swallow-6.5
- Optimiza el uso del espacio en pantalla al "devorar" las
  ventanas generadas por las terminales declaradas en la
  configuración.

### dwm-vanitygaps-6.4
- Añade propiedades para controlar los espacios externos e
  internos, verticales y horizontales entre las ventanas y
  las esquinas de la pantalla para 14 esquemas compatibles.
  Añade además combinaciones de teclas para
  incrementar/decrementar estos espacios durante la
  ejecución, o bien para restablecerlos a su valor
  predeterminado o desactivarlos.
- La verdad nunca me he visto en la necesidad de incrementar
  o decrementar los espacios dinámicamente, por lo cual he
  comentado todas las combinaciones de teclas relacionadas a
  ello.
- He modificado las variables que controlan el tamaño y
  comportamiento de los espacios (`gappih`, `gappiv`,
  `gappoh`, `gappov` y `smartgaps`) para que sean
  configurables a través de Xresources.

### dwm-monocle-patch.c
- Añade los espacios al esquema `monocle`.
- Dado que este archivo no es un parche, añadí la
  nueva función `monocle` a `vanitygaps.c` y comenté la
  original en el archivo `dwm.c`.

### shift-tools.c
- Permite ver la anterior/siguiente etiqueta que tenga
  ventanas.
- Las combinaciones de teclas fueron añadidas manualmente al
  archivo de configuración.
- Combinación predeterminada:
    - Anterior etiqueta (con ventanas): `Mod + Ctrl + H`
    - Siguiente etiqueta (con ventanas): `Mod + Ctrl + L`
- En realidad este parche puede hacer muchas cosas más, pero
  me he acostumbrado a sólo cambiar entre las etiquetas con
  ventanas.

### dwm-add-docks.patch
- Parche muy oscuro, recuperado de las conversaciones de
  correo de los diseñadores de hace unos años.
- Añade la función de tener ventanas "docks", de tal manera
  que el resto de las ventanas se acomodan a estas.
- Este parche fue añadido para poder tener un teclado
  virtual.

## Combinaciones de teclas (keybindings)

| Teclas | Descripción |
|--|--|
|**Etiquetas (Tags)**
|`Mod + [1..9]`         |   Ver la etiqueta [1..9]|
|`Mod + Ctrl + [1..9]`  |   Añadir etiqueta [1..9] a la vista|
|`Mod + 0`              |   Añadir todas las etiquetas a la vista|
|`Mod + Ctrl + H`       |   Ver la anterior etiqueta (que tenga ventanas) (n-1)|
|`Mod + Ctrl + L`       |   Ver la siguiente etiqueta (que tenga ventanas) (n+1)|
|`Mod + S`              |   Ir a la etiqueta de la ventana activa (útil con Mod+0)|
|**Ventanas**
|`Mod + Shift + [1..9]` |   Enviar la ventana activa a la etiqueta [1..9]|
|`Mod + J`              |   Cambiar el enfoque a la siguiente ventana|
|`Mod + K`              |   Cambiar el enfoque a la anterior ventana|
|`Mod + Shift + J`      |   Mover la ventana activa al siguiente lugar|
|`Mod + Shift + K`      |   Mover la ventana activa al anterior lugar|
|`Mod + Enter`          |   Alternar enfoque hacia la ventana maestra|
|`Mod + Shift + Enter`  |   Alternar posición con la ventana maestra |
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
|`Mod + M`              |   Activar esquema `monocle`|
|`Mod + V`              |   Activar/desactivar esquema horizontal (`bstackhoriz`)|
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
