#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>         
#include <linux/interrupt.h>

MODULE_LICENSE("");
MODULE_AUTHOR("Andres Restrepo");
MODULE_DESCRIPTION("Controlar 2 LEDS mediante 4 botones");
MODULE_VERSION("0.1");

//Variables botones y LEDS
static unsigned int ledRojo = 16;
static unsigned int ledAzul = 20;
static unsigned int boton1 = 21;
static unsigned int boton2 = 26;
static unsigned int boton3 = 19;
static unsigned int boton4 = 13;
static bool     ledOn = 0; //Esta apagado por defecto



