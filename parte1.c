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
static unsigned int ledVerde = 20;
static unsigned int boton1 = 21;
static unsigned int boton2 = 26;
static unsigned int boton3 = 19;
static unsigned int boton4 = 13;
static unsigend int contador1 = 0; 
static unsigend int contador2 = 0; 
static unsigend int contador3 = 0; 
static unsigend int contador4 = 0; 
static bool     ledOn = 0; //Esta apagado por defecto

static int __init ebbgpio_init(void){
   printk(KERN_INFO "parte1.c: Initializing parte1.c LKM\n");
   //Comprobamos si el pin del led rojo es valido
   if (!gpio_is_valid(ledRojo)){
      printk(KERN_INFO "parte1.c: invalid LED GPIO\n");
      return -ENODEV;
   }	
}

static void __exit ebbgpio_exit(void){
   printk(KERN_INFO "parte1.c: The button state is currently: %d\n", gpio_get_value(boton1));
   printk(KERN_INFO "parte1.c: The button was pressed %d times\n", contador1);
   printk(KERN_INFO "parte1.c: The button state is currently: %d\n", gpio_get_value(boton2));
   printk(KERN_INFO "parte1.c: The button was pressed %d times\n", contador2);
   printk(KERN_INFO "parte1.c: The button state is currently: %d\n", gpio_get_value(boton3));
   printk(KERN_INFO "parte1.c: The button was pressed %d times\n", contador3);
   printk(KERN_INFO "parte1.c: The button state is currently: %d\n", gpio_get_value(boton4));
   printk(KERN_INFO "parte1.c: The button was pressed %d times\n", contador4);

   gpio_set_value(ledRojo, 0);              // Turn the LED off, makes it clear the device was unloaded
   gpio_unexport(ledRojo);                  // Unexport the LED GPIO
   gpio_set_value(ledVerde, 0);              // Turn the LED off, makes it clear the device was unloaded
   gpio_unexport(ledVerde);                  // Unexport the LED GPIO

   free_irq(irqNumber, NULL);               // Free the IRQ number, no *dev_id required in this case

   gpio_unexport(boton1);               // Unexport the Button GPIO
   gpio_unexport(boton2);               // Unexport the Button GPIO

   gpio_free(ledRojo);                      // Free the LED GPIO
   gpio_free(ledVerde);                      // Free the LED GPIO
   gpio_free(boton1);                      // Free the button GPIO
   gpio_free(boton2);                      // Free the button GPIO
   gpio_free(boton3);                      // Free the button GPIO
   gpio_free(boton4);                   // Free the button GPIO
   printk(KERN_INFO "GPIO_TEST: Goodbye from the LKM!\n");
}

module_init(ebbgpio_init);
module_exit(ebbgpio_exit);
