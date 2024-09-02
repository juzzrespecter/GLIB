# Notas sobre la libreria

## Estructura de la libreria
- Encapsulacion en una clase, la generacion de una clase implica un nuevo
contexto o ventana.
- Llamamos **escena** al conjunto de configuraciones que se renderizan en una ventana.
- La escena puede ser **dinamica** o **estatica**
- Una escena **dinamica** trabaja con opengl para la insercion, eliminado y movimiento de los objetos desde OpenGL
- Una escena **estatica** es el renderizado con el algoritmo de RayTracing de un archivo de configuracion.
- Solo es posible tener una configuracion de escena dinamica, es posible tener mas de una configuracion de escena estatica (una para cada configuracion de camara)

Instancia del canvas: necesitamos la textura para renderizar.
Los shaders deben soportar de salida la textura, inconvenientes? Solo deberia ser problema si no se ha
bindeado la textura con `glVertexAttribPointer` antes de la llamada a glDrawElements. La textura debe seguir siendo
independiente del shader (competencia del canvas)

PROCESOS QUE SON FIJOS EN LA RENDERIZACION ESTATICA:
- ShaderProgram
- VBO
- IBO

PROCESOS DINAMICOS:
- Textura

### glVertexAttribPointer

### glTexture

### Generacion de textura a traves de un buffer

### Cambio de tipos de escena
Hook en un boton de la Gui.

### Investigar
- Distintas clases para el renderizado dinamico y estatico

### TODO
- Abstraer todos los objetos nativos de OpenGL
- Clase logger
- Clase VAO: que abstraemos aqui, como hace conflicto con canvas
- Replantear clase canvas
