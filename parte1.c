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
static unsigned int ledAzul = 20;
static unsigned int ledVerde = 16;
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
   //Comprobamos si el pin del led azul es valido
   if (!gpio_is_valid(ledAzul)){
      printk(KERN_INFO "parte1.c: invalid LED GPIO\n");
      return -ENODEV;
   }	
   //Comprobamos si el pin del led verde es valido
   if (!gpio_is_valid(ledVerde)){
      printk(KERN_INFO "parte1.c: invalid LED GPIO\n");
      return -ENODEV;
   }
   //Asignamos los leds como outputs
   ledOn = true;
   gpio_request(ledAzul, "sysfs");          
   gpio_direction_output(ledAzul, ledOn);   
   gpio_export(ledAzul, false);  

   ledOn = true;
   gpio_request(ledVerde, "sysfs");          
   gpio_direction_output(ledVerde, ledOn);   
   gpio_export(ledVerde, false); 
   //Asignamos los botones como inputs	
   gpio_request(boton1, "sysfs");       
   gpio_direction_input(boton1);        
   gpio_set_debounce(boton1, 200);      
   gpio_export(boton1, false);

   gpio_request(boton2, "sysfs");       
   gpio_direction_input(boton2);        
   gpio_set_debounce(boton2, 200);      
   gpio_export(boton2, false);

   gpio_request(boton3, "sysfs");       
   gpio_direction_input(boton3);        
   gpio_set_debounce(boton3, 200);      
   gpio_export(boton3, false);

   gpio_request(boton4, "sysfs");       
   gpio_direction_input(boton4);        
   gpio_set_debounce(boton4, 200);      
   gpio_export(boton4, false);
   //Mostramos el estado actual de cada boton
   printk(KERN_INFO "parte1.c: The button state is currently: %d\n", gpio_get_value(boton1));
   printk(KERN_INFO "parte1.c: The button state is currently: %d\n", gpio_get_value(boton2));
   printk(KERN_INFO "parte1.c: The button state is currently: %d\n", gpio_get_value(boton3));
   printk(KERN_INFO "parte1.c: The button state is currently: %d\n", gpio_get_value(boton4));
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

   gpio_set_value(ledAzul, 0);              // Turn the LED off, makes it clear the device was unloaded
   gpio_unexport(ledAzul);                  // Unexport the LED GPIO
   gpio_set_value(ledVerde, 0);              // Turn the LED off, makes it clear the device was unloaded
   gpio_unexport(ledVerde);                  // Unexport the LED GPIO

   free_irq(irqNumber, NULL);               // Free the IRQ number, no *dev_id required in this case

   gpio_unexport(boton1);               // Unexport the Button GPIO
   gpio_unexport(boton2);               // Unexport the Button GPIO

   gpio_free(ledAzul);                      // Free the LED GPIO
   gpio_free(ledVerde);                      // Free the LED GPIO
   gpio_free(boton1);                      // Free the button GPIO
   gpio_free(boton2);                      // Free the button GPIO
   gpio_free(boton3);                      // Free the button GPIO
   gpio_free(boton4);                   // Free the button GPIO
   printk(KERN_INFO "GPIO_TEST: Goodbye from the LKM!\n");
}

module_init(ebbgpio_init);
module_exit(ebbgpio_exit);
