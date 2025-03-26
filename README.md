C_Read_Ram_and_Storage_Memory_Size_lite is a C library for determining the total and free size of RAM and hard disk for Windows64 and Windows32 systems as well as for Linux/Unix-based systems.

<div align="center">
_____How do I use it?_____
<div>

You can use it by calling the appropriate functions:

The following functions return the value by using the unit to calculate the unit.

get_total_ram(unit) = Returns the total amount of RAM as an unsinged long.

get_free_ram(unit) = Returns the amount of free RAM as an unsinged long value.

get_total_memory(unit) = Returns the total size of the hard disk as an unsigned long (under Unix/Linux-based systems, the hard disk with the “/” root directory is always selected; under Windows, the hard disk on which the program was executed is always selected).

get_free_storage_memory(unit) = Returns the free hard disk size as an unsigned long.

Note: Unit is a parameter with the data type enum:

BYTE = returns the content in bytes.
KILOBYTE = returns the content in kilobytes.
MEGABYTE = returns the content in megabytes.
GIGABYTE = returns the content in gigabytes.

<div align="center">
__Use libraries:__
<div>
GNU C Libary.
Windows API.