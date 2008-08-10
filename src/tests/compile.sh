#!/usr/bin/sh
#
gcc -Wall $(pkg-config --cflags --libs gstreamer-0.10 gtk+-2.0) gst_test2.c -o gst_test2
