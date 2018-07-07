# IIS6WI - IIS 6 Website Information
A command line application written in _C + libXML_ to parse **IIS 6 MetaBase** files and dump all configured domains with their corresponding ASP version and associated Pool.

Mostly useful for checking if a domain's ASP version is in the right Pool.

I wrote this troubleshooting utility when I was working at an ISP, a few years ago.

# Build instructions
Any Linux distribution should have all the needed dependencies, so it will just be a matter of executing the following command:

`$ make`

# Usage
After compiling the binary, simply use it like:

`$ ./iis6wi <path to MetaBase.xml>`
