cmd_/home/pi/Practica1/modules.order := {   echo /home/pi/Practica1/simple_module.ko; :; } | awk '!x[$$0]++' - > /home/pi/Practica1/modules.order
