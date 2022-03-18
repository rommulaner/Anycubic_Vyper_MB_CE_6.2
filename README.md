# Community firmware for Anycubic Vyper

## Downloads

At present there are no binary downloads since the STM license conditions for some of the libraries used restrict execution to STM devices only, the Vyper mainboard uses a non-STM device. 
You may take this source and build for your board but it is your responsibility to ensure it is running in accordance with the license conditions.


### Development and compile-it-yourself

If you have the Platform.io plugin installed in Visual Studio code you can open the folder to start compiling with the code.
Please note if you have previously compiled the Anycubic source and followed their instructions then you will have a modified ArduinoSTM32 framework and this will give an error during the compile, please rename or delete the framework file and the correct version should be downloaded and compiled successfully.
Framework file can be found here:
```
C:\Users\<user>\.platformio\packages\framework-arduinoststm32@4.10900.200819
```


There are several configurations for the build of the source and they can be found at line 75 onwards of the configuration.h file:

```
// %%%% Options for building Vyper image %%%%

// select build type here
//#define VYPER_BUILD         // standard
#define VYPER_BUILD_LA      // with linear advance and junction deviation enabled
//#define VYPER_BUILD_LA_T    // as above but with uart connection to TMC2209's for x, y, z and z2
//#define VYPER_BUILD_LA_TE   // as above but with software serial connection to e stepper

// Leave undefined to home Z using two Z sensors (stock configuration)
//#define VYPER_NOZZLE_HOMING // home Z using nozzle sensor at middle of bed

// NOTE to use nozzle sensor any adjustable Z sensors must be set to maximum
// extended length so sensor is detected before nozzle reaches bed
```
Most users will probably want to use the VYPER_BUILD_LA option since this runs on the stock main board and gives the extra linear advance and junction deviation options for better prints (once calibrated).

The _T and _TE options are for use with a modified main board where the main board has been user modified to add uart connections to the TMC2209 drivers.

There are also two options for homing of the Z axis;
1. The standard way as used by Anycubic which uses the two Z axis photo sensors, one on each side, to determine the home position of each of the Z axes. 
	The home sequence is lift Z to avoid anything on the bed, 
	move head on X gantry until the X limit switch is triggered and stop, 
	move bed towards back of printer until the Y limit switch is triggered and stop, 
	the z motors lower the axis until the sensor associated with each motor is triggered to stop that motor, so each motor is independant, e.g. left motor triggers left sensor and stops, right motor continues until right sensor triggers and stops.
2. The alternative way which uses the nozzle probe sensor to determine the home position of the Z axes at the centre of the bed. 
	The home sequence here is the same as for the standard way above except after the Y limit is triggered the head is moved to the centre of the bed,
	the Z motors then lower the head until the left Z sensor is triggered,
	the Z motors continue until the nozzle probe is triggered, i.e. bed is detected, and both Z motors stop,
	the Z motors will raise the head slightly and then lower it again until the bed is again detected, this is the home position for Z.
	
There are advantages and disadvantages to using the nozzle as Z home position, the mesh values will be closer to 0 and thus will show less red or blue but homing will not complete without a working sensor. Also the Z 'flags' used to trigger the Z axis sensors need to be lower than the nozzle, this is the case with fixed flags but the adjustable ones MUST be set to protrude as far below as possible else the nozzle will impact the bed.


## Purpose of this community firmware

Initially started with the goal of providing an alternative firmware for the Anycubic Vyper motherboard

- Providing better firmware than the default firmwares provided by Anycubic
- [Expanding the features](https://github.com/Pmatsol58/CR-6-touchscreen/tree/v2.0.8.1-vyper-community-release-6.1) of the limited default touch screens delivered with 3d printers

Once upstream Marlin supports the strain gauge, [currently being whipped into shape in this PR @Sebazzz has submitted](https://github.com/MarlinFirmware/Marlin/pull/19958), the future of this project will probably be:

- Still expanding the features of the touch screen and merge upstream
- Continuously update this fork to the latest Marlin stable versions
- Provide builds for some printers by default, for the less technically inclined

## Community firmware support & communities

Get in touch with the developers! We [have our own Discord server](https://discord.gg/RKrxYy3Q9N).


### Anycubic Vyper Community

- [Facebook](https://www.facebook.com/groups/anycubicvyper)

### Creality CR-6 communities
The following CR-6 communities exist:

- [Facebook independend CR-6 community](https://www.facebook.com/groups/cr6community)
- [Reddit /r/CR6](https://www.reddit.com/r/CR6/)

Communities hosted by Creality:

- [Official CR-6 user group](https://www.facebook.com/groups/CR6SECR6MAX)
- [Official Creality user group](https://www.facebook.com/groups/creality3dofficial)

### Other communities:

- [Reddit /r/3dprinting](https://www.reddit.com/r/3dprinting/)

### General Marlin support

For general Marlin support, please check:

- [Marlin Documentation](http://marlinfw.org) - Official Marlin documentation
- [Marlin Discord](https://discord.gg/n5NJ59y) - Discuss issues with Marlin users and developers
- Facebook Group ["Marlin Firmware"](https://www.facebook.com/groups/1049718498464482/)
- RepRap.org [Marlin Forum](http://forums.reprap.org/list.php?415)
- Facebook Group ["Marlin Firmware for 3D Printers"](https://www.facebook.com/groups/3Dtechtalk/)
- [Marlin Configuration](https://www.youtube.com/results?search_query=marlin+configuration) on YouTube


## Reporting issues

- Submit **bug fixes** as pull requests to the current active default branch (`extui`)
- Follow the [coding standards](https://marlinfw.org/docs/development/coding_standards.html)
- Please submit your questions and concerns in the [issue tracker](https://github.com/MarlinFirmware/Marlin/issues)

## Credits

The current core Community firmware dev team consists of:

 - Sebastiaan Dammann [[@Sebazzz](https://github.com/Sebazzz)] - Netherlands &nbsp; ([Donate](https://www.paypal.com/donate?hosted_button_id=YCH72S6WZQ5X4) ([Profile](https://www.paypal.com/paypalme/sebastiaandammann)) | [Website](https://damsteen.nl))
 - Juan Rodriguez [[@Nushio](https://github.com/Nushio)] - Mexico
 - Romain [[@grobux](https://github.com/grobux)] - France ([Donate](https://www.paypal.com/donate?hosted_button_id=CP2SAW4W9RBT4))
 - Nick Acker [[@nickacker](https://github.com/nickacker)] - USA
 - And more...

We stand on the shoulders of giants. Don't forget to send your love [upstream too](https://github.com/MarlinFirmware/Marlin)!

## License

Marlin and the Community Firmware is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
