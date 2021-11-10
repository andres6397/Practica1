cmd_/home/pi/Practica1/Module.symvers := sed 's/ko$$/o/' /home/pi/Practica1/modules.order | scripts/mod/modpost -m -a   -o /home/pi/Practica1/Module.symvers -e -i Module.symvers   -T -
