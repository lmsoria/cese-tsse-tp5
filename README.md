# Trabajo Práctico Número 2 - Test Driven Development

Aplicar técnicas de TDD para el desarrollo de una API para controlar LEDs. Los requerimientos del driver son los siguientes:
* Maneja 16 LEDs de dos estados (encendido y apagado).
* Se puede cambiar el estado de un LED sin afectar a los otros.
* Se puede cambiar el estado de todos los LEDs en una sola
operación.
* Se puede recuperar el estado actual de un LED.
* Los LEDs están mapeados en una palabra de 16 bits en
memoria en una dirección a determinar
* Para encender el LED se debe escribir un `1` en el bit y para
apagarlo se debe escribir un `0`.
* El LED 1 corresponde al LSB y el LED 16 al MSB.
* El reset de hardware no define un estado conocido de los
LEDs, estos deben ser apagados por software.

## Uso del repositorio

Este repositorio usa [pre-commit](https://pre-comit.com) para validaciones de formato, y [ceedling](https://www.throwtheswitch.org/ceedling) para la ejecución de tests.
Para trabajar con el mismo usted debería tener instalado:

1. Instrucciones para instalar [`pre-commit`](https://pre-commit.com/#install)
2. Para instalar `ceedling`:
```
sudo apt install ruby
sudo gem install ceedling
```
3. Después de clonar el repositorio ejecutar el siguiente comando:
```
pre-commit install
```
4. Para compilar el código y correr los tests:
```
ceedling
```
