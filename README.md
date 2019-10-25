# urandom patch experiment

Basically this was an experiment to provide a new kernel option
`CONFIG_SECURE_URANDOM=[yn]` so that when enabled - /dev/urandom
will block until the cryptographic RNG is initialised (i.e.
sufficient entropy is gathered and the boot-time entropy hole is
no more).


I haven't played with this in a long time.

This is just a code freeze so that I remember how I set up the
build/test system to play with the qemu. Look at the last
commit to see what changes were made.

This is all based on [wireguard.com](http://wireguard.com) build
system. Instead of testing the wireguard kernel module, I butchered
the code base specifically to use as a playground for experimenting
with urandom. Because it uses qemu, you can do nested qemu-kvm
with digitalocean, which means you can do cheap Linux kernel dev
work on the "cloud" for quick experiments like this.

Based on my bash history - the last few things I did was:

```
2019-05-27 22:30:49 | sudo rm -rf ../qemu-build/x86_64/linux-5.1.3
2019-05-27 22:30:58 | sudo make test-qemu 2>&1 | tee out
```

Hopefully after getting all the dependencies setup - the above is all
you need to do.
