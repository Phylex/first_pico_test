# first_pico_test
My first experiments with the rpi pico. I want to use the pico to control plant pots. For that it needs to read a humidity sensor (capacitive) and a
sunlight sensor (i2c1) and then report that to the master device (probably a raspberry pi zero w)
The i2c slave code is based on the `i2c_ram` code at: https://www.raspberrypi.org/forums/viewtopic.php?p=1823225
