#!/bin/sh
#

g++ -Wall -g -o clock main.cc clock.cc `pkg-config --cflags --libs gtkmm-2.4 cairomm-1.0`

