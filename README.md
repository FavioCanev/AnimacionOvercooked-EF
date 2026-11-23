# AnimacionOvercooked-EF (Escenas 1 a 4 en 3D)

Proyecto de Computación Gráfica y Visual en **C++ con OpenGL / GLUT (`nupengl.core`)**, construido sobre el avance grupal original completando las 4 escenas en **3D puro** (sin fondos 2D ni texturas externas).

## Cómo abrir y ejecutar

1. Descarga o clona este repositorio.
2. Abre `AnimaciónOvercooked_EF.sln` en **Visual Studio**.
3. Selecciona la plataforma **`x64`** (`Debug` o `Release`) y presiona **F5** (o **Ctrl + F5**).
   - La carpeta `packages/` con `nupengl.core` ya viene incluida en el repositorio, así que no hace falta instalar paquetes adicionales.
   - Si abres el proyecto en **Visual Studio 2022** y te pide el conjunto de herramientas `v145` (VS 2026), haz clic derecho sobre el proyecto en el Explorador de soluciones → **Volver a dirigir proyectos** (Retarget Projects) y selecciona `v143`.

## Escenas incluidas

- **Escena 1 (`Escena1.cpp`)**: Playa en 3D con mar, olas con espuma, arena, rocas, sombrilla, toalla, sol con rayos, nubes, aves y Piter el dinosaurio mirando el mar.
- **Escena 2 (`Escena2.h`)**: Exterior de la tienda en la playa con 3 montañas cónicas 3D, vereda, ventana 3D, puerta con rejas 3D, letrero `TIENDA` en 3D y Piter afuera.
- **Escena 3 (`Escena3.h`)**: Interior de la tienda con piso 3D cuadriculado, estantes de 5 niveles, puerta de salida con letrero `EXIT` en 3D y Piter conversando con su amigo el muñeco de nieve.
- **Escena 4 (`Escena4.h`)**: Mostrador de la tienda con repisas de madera, ventana 3D abierta hacia la playa exterior en 3D (sol, mar, olas y arena), botella 3D de `AGUA`, el muñeco de nieve detrás y Piter comprando.

## Controles

| Tecla | Acción |
| --- | --- |
| `1`, `2`, `3`, `4` | Cambiar de escena y volver a su encuadre inicial |
| `Flecha izquierda` / `derecha` | Girar la escena en 3D alrededor del eje vertical |
| `Flecha arriba` / `abajo` | Subir o bajar la cámara |
| `RePág` / `AvPág` | Acercar o alejar la cámara |
| `E` | Mostrar u ocultar los ejes `X, Y, Z` |
| `R` | Reiniciar la cámara al encuadre inicial de la escena actual |

## Capturas

En la carpeta `Capturas/` están las vistas iniciales y rotadas en 3D de las 4 escenas (`Escena1.png` a `Escena4_3D.png`).
