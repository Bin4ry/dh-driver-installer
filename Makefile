.PHONY: clean libwdi

CFLAGS=-std=c11 -Wall -Wextra -Werror

WIN_TOOLCHAIN=x86_64-w64-mingw32
WIN_CFLAGS=-Wl,-Bstatic

INSTALLER_IN=driver_installer.c deps/libwdi-1.4.1/libwdi/.libs/libwdi.a gen/driver_installer.res
INSTALLER_LIBS=-I deps/libwdi-1.4.1/libwdi/ -lsetupapi -lole32 -lntdll

installer: $(INSTALLER_IN)
	mkdir -p bin
	$(WIN_TOOLCHAIN)-gcc $(WIN_CFLAGS) $(INSTALLER_IN) $(INSTALLER_LIBS) -o bin/driver_installer

libwdi:
	cd deps/libwdi-1.4.1/ &&\
	export CC_FOR_BUILD=gcc &&\
	./autogen.sh --disable-shared --enable-static --disable-32bit --enable-64bit  --host=x86_64-w64-mingw32 --with-libusb0=../../drivers/libusb-win32-bin-1.2.6.0/ --with-userdir=../../drivers/kedacom_adb/ --with-wdkdir=../../drivers/wdk-8.0 --with-wdfver=1011 --with-libusbk=../../drivers/libusbK-3.1.0.0-bin/bin/ &&\
	make

gen/driver_installer.res: driver_installer.rc driver_installer.exe.manifest
	mkdir -p gen
	x86_64-w64-mingw32-windres --input driver_installer.rc --output gen/driver_installer.res --output-format=coff

clean: 
	rm -rf bin/*
