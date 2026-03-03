*Este proyecto ha sido creado como parte del currículo de 42 por parenas-.*

# get_next_line

---

## Descripción

**get_next_line** es una función en C cuyo objetivo es leer un file descriptor y devolver **una línea completa por cada llamada**, incluyendo el carácter de salto de línea (`\n`) si existe.

El proyecto forma parte del currículo de 42 y tiene como finalidad profundizar en:

- Gestión de memoria dinámica
- Uso de variables estáticas
- Lectura desde file descriptors
- Manipulación de strings
- Control de memoria y prevención de leaks

La función permite leer archivos, entrada estándar o cualquier fuente de datos accesible mediante `fd`, sin cargar todo el contenido en memoria de una sola vez.

---

## Objetivo del proyecto

Implementar la función:

```c
char *get_next_line(int fd);
```

Que:

- Devuelva la siguiente línea del `fd` en cada llamada.
- Mantenga el estado entre llamadas.
- Maneje correctamente EOF y errores.
- No produzca memory leaks.

---

## Instrucciones

### Compilación

Compilar junto con tus archivos auxiliares:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

Puedes modificar `BUFFER_SIZE` en compilación:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 *.c
```

Hay un alias creado que permite compilar directamente el get_next_line y poner de primer argumento el BUFFER_SIZE
```bash
gnl [BUFFER_SIZE]
```

---

### Ejemplo de uso

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

---

## Explicación del algoritmo y justificación

La implementación se basa en un **buffer dinámico acumulativo con almacenamiento estático del sobrante**.

### 1. Uso de variable estática

```c
static char *left_c;
```

Se utiliza para almacenar el contenido restante después de devolver una línea.  
Esto permite que la función recuerde información entre llamadas sucesivas.

**Justificación:**  
Sin una variable estática, no sería posible continuar leyendo correctamente desde donde terminó la llamada anterior.

---

### 2. Lectura progresiva hasta encontrar `\n`

La función `_fill_line_buffer`:

- Lee del `fd` en bloques de tamaño `BUFFER_SIZE`.
- Concatena lo leído al contenido previo.
- Se detiene cuando encuentra `\n` o cuando `read()` devuelve 0 (EOF).

**Justificación del enfoque:**

- Evita leer todo el archivo en memoria.
- Funciona correctamente incluso con `BUFFER_SIZE` pequeño.
- Es eficiente para archivos grandes.

---

### 3. Separación de línea y resto

La función `_set_line`:

- Busca el primer `\n`.
- Corta el string en ese punto.
- Devuelve el contenido posterior como nuevo `left_c`.

Esto divide el buffer en:

- Línea a devolver
- Resto para la siguiente llamada

---

### 4. Gestión de memoria

- Uso de `malloc` para buffers dinámicos.
- Liberación inmediata cuando la memoria ya no es necesaria.
- Uso de `free_ptr` para liberar memoria, evitar punteros colgantes y return NULL.

Esto garantiza que la función no produzca memory leaks.

---

## Estructura del proyecto

Funciones principales:

```c
char	*get_next_line(int fd);
char	*_fill_line_buffer(int fd, char *left_c, char *buffer);
char	*_set_line(char *line_buffer);
```

Organización modular:

- `get_next_line` → Control principal
- `_fill_line_buffer` → Lectura y acumulación
- `_set_line` → División de línea

---

## Características

- Soporta cualquier tamaño de `BUFFER_SIZE`
- Funciona con archivos grandes
- Gestión correcta de EOF
- Manejo de errores de `read`
- Sin memory leaks
- Código modular y claro

---

## Recursos

Documentación utilizada:

- `man 2 read`
- `man 2 open`
- Documentación oficial del lenguaje C (ISO C)
- Material del proyecto proporcionado por 42

---

### Uso de Inteligencia Artificial

Se ha utilizado IA como herramienta de apoyo para:

- Ayuda en la redacción de este README.
- Revisión conceptual del algoritmo.
- Mejora de explicaciones técnicas.
- Validación teórica del flujo lógico.
