About
=====
iChuj is a simple packet flooder built to test speed of a local network.
It uses UDP and UDP Lite protocols over IPv6.

Usage
=====
 * ./iChuj udp destination_host_ipv6 - for UDP mode
 * ./iChuj udplite destination_host_ipv6 - for UDP Lite mode

If you want to test connectivity with IPv4 remote host, type
::ffff:ip.v4.host.addr (ex. ::ffff:127.0.0.1).

Compilation
===========

`$ make`
